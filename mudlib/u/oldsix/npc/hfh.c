// oldsix 黄飞鸿
#include <ansi.h>
inherit NPC;
inherit F_BH;

int check_name(string str);
int create_banghui(string str);
int write_to_file(string str,object me);

void create()
{
	set_name("黄飞鸿",({"huang feihong","huang","huangfeihong"}));
	set("long","广东十虎之一，专门负责武林帮会(banghui)的建立。\n");
	set("title","武状元");
	set("gender","男性");
	set("age",30);
        set("per",90);

	set_skill("unarmed",200);
	set_skill("dodge",200);
	set_skill("parry",200);
	set_temp("apply/attack",100);
	set_temp("apply/defense",100);
	set_temp("apply/damage",50);

        set("inquiry", ([
		"banghui"	:"要创建帮会请create <帮会名>\n",
		"帮会"		:"要创建帮会请create <帮会名>\n",
        ]) );


	set("combat_exp",2000000);
        setup();
}
int check_name(string name)
{
        int i;

        i = strlen(name);

	if( (strlen(name) < 4) || (strlen(name) > 16 ) ) {
		command("say 帮会名称请定在二到八个字\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
			command("say 对不起，你的帮会名中不能用控制字符。\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
			command("say 请用「中文」命名你的帮会。\n");
                        return 0;
                }
        }
	return 1;
}


void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
                {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
                }
	add_action("create_banghui","create");
}

int create_banghui(string str)
{
	object me,lingpai;
	int count;

	me=this_player();
	if((string)me->query("banghui"))	{
		command("say 你已经是"+me->query("banghui")+"的人了，不能另创帮会。\n");
		return 1;
	}
	if(me->query("combat_exp")<100000)	{
		command("say "+RANK_D->query_respect(me)+"的实战经验还差"+
		(string)(100000-me->query("combat_exp"))+"点，暂时无法开帮立会。\n");
		return 1;
	}
	if(! count=me->query("oldsix/have_create"))	count=0;
	if(count>=2)	{
		message_vision("$N怒道："+me->query("name")+
		"！你以为帮会是创着玩吗？想再建帮会，下辈子吧！！\n",
		this_object());
		return 1;
	}
	
	if(! str)	{
		command("say 你要创建什么名字的帮会？\n");
		return 1;
	}
	if(! check_name(str))	return 1;

	if(file_size("/data/guild/"+str+".o")!=-1) {
		command("say 非常抱歉，你起的帮会名早就有了。\n");
		return 1;
	}
	lingpai=new("/obj/lingpai");
	lingpai->create(str);
	lingpai->set("bangzhu",me->query("name"));
	lingpai->set("bangzhu_id",me->query("id"));
	lingpai->set("player",([me->query("id"):me->query("name")]));
	lingpai->set("npc",([]));
	lingpai->set("area",([]));
	lingpai->set("money",0);
	lingpai->save();
	destruct(lingpai);

	me->set("banghui",str);
	me->set("bh_rank","领袖");
	count++;
        me->set("oldsix/have_create",count);
	me->save();
	command("say 恭喜"+RANK_D->query_respect(me)+"，你的<"+str+">帮会创建成功！\n");
	return 1;
}

void greeting(object ob)
{
	string banghui;
	object lingpai;
	if( !ob || environment(ob) != environment() ) return;
	if((string)(banghui=ob->query("banghui")))      {
		lingpai=new("/obj/lingpai");
		lingpai->create(banghui);
		if(lingpai->query("no_use"))	{
			command("say "+ob->query("name")+"，你的帮会文件有问题，快与巫师联系吧。");
		}
		else if(lingpai->query("bangzhu_id")!="???")
			command("say 这位"+RANK_D->query_respect(ob)+
			"贵帮帮主身体可好？\n");
		else command("say "+banghui+"帮主失踪多日，"+
                        RANK_D->query_respect(ob)+"只需花一千两黄金就可以买下帮主之位。\n");
		destruct(lingpai);
	}
	else	command("say 这位"+RANK_D->query_respect(ob)+"是来创建帮会的吗？\n");
}
int accept_object(object who,object obj)
{
	string banghui;
	object lingpai;
	if(! banghui=who->query("banghui"))	{
		command("say 我可不敢平白无故接受你的东西。\n");
		return 0;
	}
	lingpai=new("/obj/lingpai");
	lingpai->create(banghui);
	if(lingpai->query("no_use"))	{
		command("say "+who->query("name")+"，你的帮会文件有问题，快与巫师联系吧。");
		destruct(lingpai);
		return 0;
	}
	if(lingpai->query("bangzhu_id") != "???")	{
		command("say 贵帮帮主还活的好好的，我可不改把帮主之位卖给"+
		RANK_D->query_respect(who)+"啊。\n");
		destruct(lingpai);
		return 0;
	}
	if(! obj->query("money_id"))	{
		command("say 这些破烂我没兴趣。\n");
		destruct(lingpai);
		return 0;
	}
	if(obj->value()<10000000)	{
		command("say 至少一千两黄金，不然我如何向上面交待？\n");
		destruct(lingpai);
		return 0;
	}
	lingpai->set("bangzhu",who->query("name"));
	lingpai->set("bangzhu_id",who->query("id"));
	lingpai->save();
	destruct(lingpai);
	message("channel:rumor",YEL"【谣言】某人："+who->query("name")+
	"花了一千两黄金，买下了"+banghui+"帮主之位。\n"NOR,users());
	return 1;
}

