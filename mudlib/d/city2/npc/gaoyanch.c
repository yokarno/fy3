// gaoyanchao.c 高彦超

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("高彦超", ({ "gao yanchao", "gao", "yanchao" }));
	set("banghui","天地会");
	set("gender", "男性");
	set("age", 32);
	set("str", 25);
	set("dex", 20);
	set("long", "他不过三十出头，却显得异常老练。一言不发地往那儿一站，\n"
            "真是威风凛凛。\n");
	set("combat_exp", 800000);
	set("score", 5000);
	set("mingwang",5000);
	set("attitude", "peaceful");

	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("literate", 50);
	set_skill("yunlong-xinfa", 100);
	set_skill("yunlong-shenfa", 100);
	set_skill("yunlong-shou",150);

	map_skill("force", "yunlong-xinfa");
	map_skill("dodge", "yunlong-shenfa");
	map_skill("parry", "yunlong-shou");
	map_skill("unarmed","yunlong-shou");

	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set_temp("apply/armor", 5);
	set_temp("apply/damage", 25);
	set("kee", 1500);
	set("max_kee", 1500);
	set("gin", 300);
	set("max_gin", 300);
	set("force", 1200); 
	set("max_force", 1200);
	set("force_factor", 80);
        set("inquiry", ([
		"陈近南" :  "\n想见总舵主可不容易啊。\n",
		"天地会" :  "\n入我天地会，得去找贾老六问问。\n",
                "反清复明" : "去棺材店内室仔细瞧瞧吧！\n",
                
       ]) );
	setup();
	carry_object("/obj/cloth")->wear();
	add_money("gold", 1);
}

void recognize_apprentice(object ob)
{
        string banghui;
        if(! stringp(banghui=ob->query("banghui")) ||
                banghui!=query("banghui"))
        return notify_fail(query("name")+"摇头道：非我天地会兄弟不教。\n");
        if(ob->query("score")<1000)
                return notify_fail(query("name")+"道：你要多为天地会出力啊。\n")
;
        return 1;
}
