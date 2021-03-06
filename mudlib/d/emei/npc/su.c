// su.c 苏梦清
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("苏梦清", ({ "su mengqing","su","mengqing"}));
        set("long",
                "她是峨嵋派的第四代俗家弟子。\n");
        set("gender", "女性");
        set("age", 22);
        set("attitude", "peaceful");
        set("mingwang", 1000);
        set("class", "fighter");

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("per", 30);

        set("max_kee", 1000);
        set("max_gin", 500);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 15);
        set("max_sen", 1500);

        set("combat_exp", 150000);
        set("score", 1000);
        set_skill("foxuexinde", 40);
        set_skill("force", 60);
        set_skill("dodge", 80);
        set_skill("parry", 70);
        set_skill("unarmed", 70);
        set_skill("sword", 80);
        set_skill("sixiang-zhang", 70);
        set_skill("anying-fuxiang", 70);
        set_skill("huifeng-jian", 80);
        set_skill("emei-xinfa", 80);

        map_skill("force","emei-xinfa");
        map_skill("dodge","anying-fuxiang");
        map_skill("unarmed","sixiang-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        create_family("峨嵋派", 4, "弟子");

        setup();
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/d/obj/cloth/skirt.c")->wear();
}
void init()
{
  object ob;
  ::init();
  if (interactive(ob=this_player())&&!is_fighting()) {
  	remove_call_out("greeting");
  	call_out("greeting",1,ob);
       }
 }
void greeting(object ob)
{
	if((string)ob->query("family/family_name")!="峨嵋派")	{
  	command("say 掌门有令:擅闯九老洞府者,死!\n");
  	kill_ob(ob);
  	return;
    }
 else 
   command("say 周师妹正在里面清修,你不要打扰她.\n");
   return;
}
