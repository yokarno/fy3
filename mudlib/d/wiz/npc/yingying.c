// music  yangzhou's  ��ݺݺ

inherit NPC;

void create()
{
        set_name("��ݺݺ", ({ "cui yingying", "cui", "cyy" }));
        set("long", "�㿴���������ﲻ��һ����ֻ���������һ�����\n");
        set("title", "��������");
        set("gender", "Ů��");
        set("age", 19);
        set("per",90);

        set_skill("unarmed", 70);
        set_skill("dodge", 90);
        set_skill("parry", 40);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 5);

        set("inquiry", ([
              "music":   "�������ҿ��ϰ�����ϰ�ƽ�պ�æ������������.",
             "oldsix":   "�Һþ�û�����ˣ��������ޡ�",
                "ssssh":   "����һ�ƴ�ү��������֪������д��ȥ��! " ,
              "danny":   "!@#$ ���ûͷ��! @#$" ,
               "czgq":   "�Ҷ��������˽� ....",
               "cmoc":   "����̵����ǣ��ú�ѧϰ,��������.",
               "ukyo":   "ࡣ�������������ð���̫˧�ˣ��ɱ����������!",  
        ]) );


        set("combat_exp", 20000);
        set("shen_type", 1);
        setup();
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
add_action("do_post","post");
add_action("do_discard","discard");
add_action("do_kiss","kiss");
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
                        say( "��ݺݺգգ�۵���" + 
                            RANK_D->query_respect(ob)
                                + "���þò�����? \n");
}


void do_post(string arg)
{
if(!wizardp( this_player(1)))
  {
  say ("\n[1;33m��ݺݺЦ������"+this_player(1)->query("name")+": �����д��! д�˿ɾͲ���ɾȥ��. [0;37m\n\n");
  }
}


int do_discard(string arg)
{
// this line only want to remove normal discard process 
// but i do not know how to do it normally .  -- music
if( arg != this_player()->query("name"));

 if(!wizardp( this_player(1)))
  {
   say (this_player(1)->query("name")+"��ɾ����\n");
   say ("��ݺݺ�����ҡҡͷ: ɾ������ , ����˵��Ҫ�����д�ġ� \n");
   say ("[36m��ݺݺ���ε������ʼ硣[37m\n");
   return 1;
  }
}

void do_kiss(string arg)
{

 if(wizardp( this_player(1)))
   {
   say ("��ݺݺ����Ŀ���"+ this_player(1)->query("name") +",΢΢һЦ.\n");
   }
 else 
   {
   say("��ݺݺ�����ҡҡͷ: "+this_player(1)->query("name")+", ������ ... \n");
   }
}
