// daobaifeng.c 刀白凤

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("刀白凤", ({ "dao baifeng", "dao" }));
	set("title",  "大理国王妃" );
	set("nickname",  CYN"玉虚散人"NOR );
	set("gender", "女性");
	set("long", "这是个容貌秀丽的中年道姑，是个摆夷族女子，颇有雍容气质。
她本是大理国皇帝段正淳的正房原配夫人。
因恼丈夫风流不羁，沾花惹草，一怒之下跑到这里出了家。她看起来约三十多岁。\n");
	set("age", 35);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 28);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 1800);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 200000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
set_skill("unarmed",100);
	set_skill("whip", 100);
	set_skill("kurong-changong", 100);
	set_skill("duanjia-sword", 100);
	set_skill("tiannan-step", 100);
	set_skill("jinyu-quan", 100);
	set_skill("wuluo-zhang", 100);
set_skill("feifeng-bian",100);
	set_skill("literate", 60);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
map_skill("whip","feifeng-bian");
map_skill("unarmed","wuluo-zhang");
	map_skill("parry", "feifeng-whip");
	map_skill("sword", "duanjia-sword");

	setup();
	carry_object("/d/dali/npc/obj/cynrobe")->wear();
	carry_object("/d/dali/obj/fuchen")->wield();
	add_money("silver", 10);

}

