// qianlaob.c
#include <ansi.h>

inherit NPC;
void create()
{
	set_name("钱老本", ({"qian laoben", "qian", "laoben"}));
	set("banghui","天地会");
	set("gender", "男性");
	set("age", 34);

	set("str", 22);
	set("int", 24);
	set("con", 18);

	set("kee", 800); 
	set("max_kee", 800);
	set("gin", 100);
	set("max_gin", 100);
	set("mingwang",500);
	set("max_force",800);
	set("force",800);
	set("force_factor",80);

	set("combat_exp", 100000);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 5);
	set("chat_msg", ({
	"钱老本说道：我叫钱老本，就是因为做生意连老本也赔了。\n",
	"钱老本笑着说道：小店的猪肉大多是供奉的。\n",
	"钱老本说：韦香主来了之后,青木堂可露了脸了.\n",
	"钱老本道:要入天地会,去找贾老六。\n",
        "钱老本突然说：五人分开一首诗，身上洪英无人知。\n",
	}));
        set("inquiry", ([
		"贾老六" :  "这小子天天在天桥一带闲逛.\n",
		"陈近南" :  "总舵主在城西的山庄中。\n",
		"天地会" :  "只要是英雄好汉，都可以入我天地会。\n",
		"入会":"要入天地会,去找贾老六.\n",
   ]));
	set_skill("unarmed", 80);
	set_skill("yunlong-shou",80);
	set_skill("force",80);
	set_skill("yunlong-xinfa",80);
	set_skill("dodge", 80);
	set_skill("yunlong-shenfa",80);
	set_skill("parry",80);

	map_skill("unarmed","yunlong-shou");
	map_skill("parry","yunlong-shou");
	map_skill("dodge","yunlong-shenfa");
	map_skill("force","yunlong-xinfa");
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);

	setup();
	carry_object("/obj/cloth")->wear();
	add_money("gold", 3);
}
int recognize_apprentice(object ob)
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
