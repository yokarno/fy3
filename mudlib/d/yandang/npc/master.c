#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("落雁老人", ({ "luoyan master", "master", "luoyan" }) );

        set("gender", "男性");
        set("age", 74);
        set("class", "xiake");
        set("title","庄主");
	set("max_gin", 3000);
	set("max_kee", 3000);
	set("max_sen", 3000);
	set("food",250);
	set("water",250);
	set("mingwang",200000);

        set("str", 50);
        set("int", 100);
        set("con", 30);
        set("per", 30);
        set("cps", 30);
        set("cor", 30);
        set("spi", 30);
        set("car", 50);
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.luoyan" :),
        }) );
        set("force", 4000);
        set("max_force", 4000);
        set("force_factor", 50);
        set("combat_exp", 1500000);
        set("score", 10000);
        set_skill("sword", 200);
	set_skill("luoyan-jianfa",200);
        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("tianfeng-xuan", 200);
        set_skill("parry", 200);
        set_skill("yuxuan-guizhen", 200);
        set_skill("tiangang-zhi", 200);
        map_skill("dodge","tianfeng-xuan");
        map_skill("sword","luoyan-jianfa");
        map_skill("parry","tiangang-zhi");
        map_skill("unarmed","tiangang-zhi");
        map_skill("force","yuxuan-guizhen");
        create_family("雁荡派", 1, "掌门");
        setup();
        carry_object(__DIR__"obj/zizhuzhang")->wield();
	carry_object("/obj/cloth")->wear();
        carry_object("/obj/zijin");
}
void attempt_apprentice(object ob)
 {  if (ob->query_skill("yuxuan-guizhen",1)>119)   {
        command("nod");
        command("say " + RANK_D->query_respect(ob) + 
 "，你既然诚心加入我雁荡一派,我就收你作个弟子吧！。\n");
        command("recruit " + ob->query("id") );
        return;
   }
 else command("say 你的玉玄归真练得还不到家呀,再努力吧.\n");
 return;
 }
 void recruit_apprentice(object ob)
 {
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xiake");
		message("channel:rumor", 
YEL"【谣言】"+ "某人："+ob->query("name")+"今日加入雁荡一派。\n"NOR,users());
return;
 }
void init()
{      object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");

                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
  if (ob&&environment(ob)!=environment()) return;
if (ob->query("mingwang")>0)
message_vision("落雁老人赞赏的看了$N一眼,摸着胡子点了点头!\n",ob);
  else 
 message_vision("落雁老人失望的看着$N,深深叹了口气,嘴边的胡子都飞了起来!\n",ob);
}
