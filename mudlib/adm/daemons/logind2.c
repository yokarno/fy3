//
// logind.c
// last modify bu music 97.1.25

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_DBASE;

int new_player = 0;
int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name = ({
        "��", "��", "��", "��", "��","��", 
        "������","Ц��","����","Ī��","�Ϲ���",
});

string *open_site = ({
        "202.102.7.141",
        "202.100.192.%*d",
        "202.100.193.%*d",
        "202.102.7.14%*d",
});


string *banned_site = ({
        "140.127.86.250",
        "140.128.1.%*d",
        "140.128.99.50",
        "140.128.122.%*d",
        "140.129.%*d",
        "192.192.140.%*d",
        "192.192.141.%*d",
        "192.192.190.9",
});

private void get_id(string arg, object ob);
private void confirm_id(string yn, object ob);
object make_body(object ob);
private void init_new_player(object user);
//void init_new_player(object user);

varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);

void create() 
{
        seteuid(getuid());
        set("channel_id", "���߾���");
}

void logon(object ob)
{
        object *usr;
        int i, wiz_cnt, ppl_cnt, login_cnt;

//add by music 

          string ip;
          ip = query_ip_number(ob);

          i=0;
          if ( ! ((ip == open_site[i]) || sscanf(ip, open_site[i])) ) 
            if ( ! ((ip == open_site[i+1]) || sscanf(ip, open_site[i+1])) )
             if ( ! ((ip == open_site[i+2]) || sscanf(ip, open_site[i+2])) )
                 if ( ! ((ip == open_site[i+3]) || sscanf(ip, open_site[i+3])) )
                    {         
                      for(i=0; i<sizeof(banned_site); i++)
                        if( (ip == banned_site[i])
                        ||      sscanf(ip, banned_site[i])) {
                                write("�Բ���Ŀǰ��վ�����⿪��.\n");
                                destruct(ob);
                                return;
                    }                                             }
// ----

        cat(WELCOME);
        UPTIME_CMD->main();
        usr = users();
        wiz_cnt = 0;
        ppl_cnt = 0;
        login_cnt = 0;
        for(i=0; i<sizeof(usr); i++) {
                if( !environment(usr[i]) ) login_cnt++;
                else if( wizardp(usr[i]) ) wiz_cnt++;
                else ppl_cnt++;
        }
//        printf("Ŀǰ���� %d λ��ʦ��%d λ��������ϣ��Լ� %d 
// λʹ���߳��������С�\n\n",
//                wiz_cnt, ppl_cnt, login_cnt );
        printf("Ŀǰ���� %d λ̽�ռ������ϣ��Լ� %d λ̽����׼����...\n\n",
                wiz_cnt+ppl_cnt, login_cnt );


        write("����Ӣ�����֣�");
        input_to( (: get_id :), ob );
}

private void get_id(string arg, object ob)
{
        object ppl;


        arg = lower_case(arg);
        if( !check_legal_id(arg)) {
                write("����Ӣ�����֣�");
                input_to("get_id", ob);
                return;
        }

#ifdef MAX_USERS
        if( (string)SECURITY_D->get_status(arg)=="(player)"
        && sizeof(users()) >= MAX_USERS ) {
                ppl = find_body(arg);
        // Only allow reconnect an interactive player when MAX_USERS exceeded.
                if( !ppl || !interactive(ppl) ) {
                        write("�Բ���" + MUD_NAME + 
"��̽�����Ѿ�̫���ˣ������������\n");
                        destruct(ob);
                        return;
                }
        }
#endif

// ��ʱ�������� wizlock ����
//       if(wiz_lock_level<1)  wiz_lock_level=1;
//
        if( wiz_level(arg) < wiz_lock_level ) {
                write("�Բ���" + MUD_NAME + "Ŀǰ������ʦ�ȼ� " + 
// WIZ_LOCK_LEVEL
wiz_lock_level
                        + " ���ϵ��˲������ߡ�\n");
                destruct(ob);
                return;
        }
        
        if( (string)ob->set("id", arg) != arg ) {
                write("Failed setting user name.\n");
                destruct(ob);
                return;
        }

        if( arg=="guest" ) {
                // If guest, let them create the character.
                confirm_id("Yes", ob);
                return;
        } else if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 
) {
                if( ob->restore() ) {
                        write("���������룺");
                        input_to("get_passwd", 1, ob);
                        return;
                }
                write("�������ﴢ�浲����һЩ���⣬������ guest ����֪ͨ��ʦ������\n");
                destruct(ob);
                return;
        }

        write("ʹ�� " + (string)ob->query("id") + " ������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
        input_to("confirm_id", ob);
}

private void get_passwd(string pass, object ob)
{
        string my_pass;
        object user;

        write("\n");
        my_pass = ob->query("password");
        if( crypt(pass, my_pass) != my_pass ) {
                write("�������\n");
                destruct(ob);
                return;
        }

        // Check if we are already playing.
        user = find_body(ob->query("id"));
        if (user) {
                if( user->query_temp("netdead") ) {
                        reconnect(ob, user);
                        return;
                }
                
write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }

        if( objectp(user = make_body(ob)) ) {
                if( user->restore() ) {
                        log_file( "USAGE", sprintf("%s loggined from %s %s)\n",
user->query("name"),
                                query_ip_name(ob), ctime(time()) ) );
                        enter_world(ob, user);
                        return;
                } else {
                        destruct(user);
                }
        }
        write("�������´���������\n");
        confirm_id("y", ob);
}

private void confirm_relogin(string yn, object ob, object user)
{
        object old_link;

        if( yn=="" ) {
                
write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }       

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("�ðɣ���ӭ�´�������\n");
                destruct(ob);
                return;
        } else {
                tell_object(user, "���˴�( " + query_ip_number(ob)
                        + " )ȡ���������Ƶ����\n");
                log_file( "USAGE", sprintf("%s replaced by %s (%s)\n", 
user->query("name"),
                        query_ip_name(ob), ctime(time()) ) );
        }

        // Kick out tho old player.
        old_link = user->query_temp("link_ob");
        if( old_link ) {
                exec(old_link, user);
                destruct(old_link);
        }

        reconnect(ob, user);    
}

private void confirm_id(string yn, object ob)
{
        if( yn=="" ) {
                write("ʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
                input_to("confirm_id", ob);
                return;
        }       

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("�ðɣ���ô��������������Ӣ�����֣�");
                input_to("get_id", ob);
                return;
        }

        write( @TEXT

������һ���и��Ե��������֣�������ֽ������㣬�������󽫲���������ģ�
��������ء�����Ϸ����ɾ�����ֲ�����ҵ�Ȩ����(��������֮�⣬����ȡ��
�š���ƣ����Խ�����ȡһ���Ƚ������ֵ��������֡�)

TEXT
        );
        write("�����������֣�");
        input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{
        if( !check_legal_name(arg) ) {
                write("�����������֣�");
                input_to("get_name", ob);
                return;
        }

        printf("%O\n", ob);
        ob->set("name", arg);
        write("���趨�������룺");
        input_to("new_password", 1, ob);
}

private void new_password(string pass, object ob)
{
        write("\n");
        if( strlen(pass)<3 ) {
                write("����ĳ�������Ҫ��λ���������������룺");
                input_to("new_password", 1, ob);
                return;
        }
        ob->set("password", crypt(pass,0) );
        write("��������һ���������룬��ȷ����û�Ǵ���");
        input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
        string old_pass;
        write("\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write("��������������벢��һ�����������趨һ�����룺");
                input_to("new_password", 1, ob);
                return;
        }

        write("���ĵ����ʼ���ַ��");
        input_to("get_email",  ob);
}

private void get_email(string email, object ob)
{
        object user;

        ob->set("email", email);

  // If you want do race stuff, ask player to choose one here, then you can
  // set the user's body after the question is answered. The following are
        // options for player's body, so we clone a body here.
        ob->set("body", USER_OB);
        if( !objectp(user = make_body(ob)) )
                return;

        user->set("title", "��ͨ��ʦ");
        user->set("birthday", time() );
        user->set("potential", 100);

        user->set("str", 13 + random(19));
        user->set("cps", 13 + random(19));
        user->set("int", 13 + random(19));
        user->set("cor", 13 + random(19));
        user->set("con", 13 + random(19));
        user->set("spi", 13 + random(19));
        user->set("per", 13 + random(19));
        user->set("kar", 13 + random(19));

        user->set("mingwang",0);
        user->set("balance",200);
        user->set("channels", ({ "chat", "rumor" }) );
        user->set("food", 100);
        user->set("water",100);


        write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
        input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{
        if( gender=="" ) {
                write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
                input_to("get_gender", ob, user);
                return;
        }

        if( gender[0]=='m' || gender[0]=='M' )
                user->set("gender", "����");
        else if( gender[0]=='f' || gender[0]=='F' )
                user->set("gender", "Ů��" );
        else {
                write("�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
                input_to("get_gender", ob, user);
                return;
        }

        log_file( "USAGE", sprintf("%s was created from %s (%s)\n", 
user->query("id"),
                query_ip_name(ob), ctime(time()) ) );
        init_new_player(user);
        enter_world(ob, user);
}

object make_body(object ob)
{
        string err;
        object user;
        int n;

        user = new(ob->query("body"));
        if(!user) {
                
write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
                write(err+"\n");
                return 0;
        }
        seteuid(ob->query("id"));
        export_uid(user);
        export_uid(ob);
        seteuid(getuid());
        user->set("id", ob->query("id"));
        user->set_name( ob->query("name"), ({ ob->query("id")}) );
        return user;
}

private void init_new_player(object user)
{

        user->set("title", "��ͨ����");
        user->set("birthday", time() );
        user->set("potential", 100);

        user->set("str", 13 + random(19));
        user->set("cps", 13 + random(19));
        user->set("int", 13 + random(19));
        user->set("cor", 13 + random(19));
        user->set("con", 13 + random(19));
        user->set("spi", 13 + random(19));
        user->set("per", 13 + random(19));
        user->set("kar", 13 + random(19));

        user->set("mingwang",0);
        user->set("balance",200);
        user->set("channels", ({ "chat", "rumor" }) );
        user->set("food", 100);
        user->set("water",100);

        new_player=1;
}

varargs void enter_world(object ob, object user, int silent)
{
        object cloth,shoe, room;
        string startroom;

        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);

        write("ĿǰȨ�ޣ�" + wizhood(user) + "\n");
        user->setup();

        // In case of new player, we save them here right aftre setup 
        // compeleted.
        user->save();
        ob->save();
        user->apply_condition("autosave", 1);
        if ( user->query("gender")=="Ů��")
       {
	  shoe = new("/obj/armor/female-shoe.c");
          switch (random(8))
	      {
	case 1:
	   cloth = new("/obj/armor/female1-cloth.c");
	   break;
	case 2:
	   cloth = new("/obj/armor/female2-cloth.c");
	   break;
	case 3:
	   cloth = new("/obj/armor/female3-cloth.c");
	   break;
        case 4:
	   cloth = new("/obj/armor/female4-cloth.c");
	   break;
	case 5:
	   cloth = new("/obj/armor/female5-cloth.c");
	   break;
	case 6:
	   cloth = new("/obj/armor/female6-cloth.c");
	   break;
	case 7:
	   cloth = new("/obj/armor/female7-cloth.c");
	   break;
	default:
	  cloth = new("/obj/armor/female8-cloth.c");
		}
		   }
	  else
		{
	shoe = new("/obj/armor/male-shoe.c");
	switch (random(8))
	{
          case 1:
	     cloth = new("/obj/armor/male1-cloth.c");
	     break;
	  case 2:
	     cloth = new("/obj/armor/male2-cloth.c");
	     break;
	  case 3:
	     cloth = new("/obj/armor/male3-cloth.c");
	     break;
	  case 4:
	     cloth = new("/obj/armor/male4-cloth.c");
	     break;
	  case 5:
	     cloth = new("/obj/armor/male5-cloth.c");
	     break;
	  case 6:
	     cloth = new("/obj/armor/male6-cloth.c");
	     break;
	  case 7:
	     cloth = new("/obj/armor/male7-cloth.c");
	     break;
	  default:
	     cloth = new("/obj/armor/male8-cloth.c");
		}
				}
        cloth->move(user);
        cloth->wear();
        shoe->move(user);
        shoe->wear();

        if(!user->query("mingwang")) user->set("mingwang",0);

        if( !silent ) {
                if (new_player == 1 ) {
                        F_MORE->start_more(read_file("/adm/etc/new_player"));
                                        new_player=0;
                                      } 
                F_MORE->start_more(read_file(MOTD));
                if( user->is_ghost() )
                        startroom = DEATH_ROOM;
                else if( !stringp(startroom = user->query("startroom")) )
                        startroom = START_ROOM;

                if( !catch(load_object(startroom)) )
                        user->move(startroom);
                else {
                        user->move(START_ROOM);
                        startroom = START_ROOM;
                        user->set("startroom", START_ROOM);
                }
                tell_room(startroom, user->query("name") + 
"���߽���������硣\n",
                        ({user}));
        }
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s��%s���߽��롣", user->name(), 
query_ip_name(user)) );
        UPDATE_D->check_user(user);
                if( user->query("new_mail") ) {
           write("\n[1;36m��ͻȻ����Ԥ�У����������� ...[0;37m\n\n");
//                        user->set("new_mail", 0);
// ���ڶ��ź�ȡ��
                                            }

}

varargs void reconnect(object ob, object user, int silent)
{
        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);

        user->reconnect();
        if( !silent ) {
                tell_room(environment(user), user->query("name") + 
"�������߻ص�������硣\n",
                ({user}));
        }
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s��%s�������߽��롣", user->query("name"), 
query_ip_name(user)) );
        UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
        int i;

        i = strlen(id);
        
        if( (strlen(id) < 3) || (strlen(id) > 8 ) ) {
                write("�Բ������Ӣ�����ֱ����� 3 �� 8 ��Ӣ����ĸ��\n");
                return 0;
        }
        while(i--)
                if( id[i]<'a' || id[i]>'z' ) {
                        write("�Բ������Ӣ������ֻ����Ӣ����ĸ��\n");
                        return 0;
                }

        return 1;
}

int check_legal_name(string name)
{
        int i;

        i = strlen(name);
        
        if( (strlen(name) < 4) || (strlen(name) > 12 ) ) {
                write("�Բ�������������ֱ����� 2 �� 6 �������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ��������á����ġ�ȡ���֡�\n");
                        return 0;
                }
        }
        if( member_array(name, banned_name)!=-1 ) {
                write("�Բ����������ֻ���������˵����š�\n");
                return 0;
        }

        return 1;
}

object find_body(string name)
{
        object ob, *body;

        if( objectp(ob = find_player(name)) )
                return ob;
        body = children(USER_OB);
        for(int i=0; i<sizeof(body); i++)
                if( clonep(body[i])
                &&      getuid(body[i]) == name ) return body[i];

        return 0;
}

int set_wizlock(int level)
{
        if( wiz_level(this_player(1)) <= level )
                return 0;
        if( geteuid(previous_object()) != ROOT_UID )
                return 0;
        wiz_lock_level = level;
        return 1;
}
 