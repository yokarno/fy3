// music   yangzhou's 赌场小二

inherit NPC;

void create()
{
	set_name("赌场小二", ({ "xiaoer","xiao","er" }) );
	set("gender", "男性" );
	set("age", 20);
	set("long",
		"赌场小二恭恭敬敬的站着。\n");
	set("mingwang", 1);
	set("combat_exp", 8000);
        set("int", 31);
        set_skill("unarmed",80);
        set_skill("dodge",40);
	set("attitude", "peaceful");
	setup();
        carry_object("/obj/cloth")->wear();
	add_money("coin", 100);
}

