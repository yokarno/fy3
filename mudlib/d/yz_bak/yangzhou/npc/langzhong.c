//music yangzhou' 郎中

inherit NPC;

void create()
{
	set_name("郎中", ({ "langzhong","lang zhong", "lang","zhong" }) );
	set("gender", "男性" );
	set("age", 40);
	set("int", 28);
        set("mingwang",1);
        set("combat_exp",1100);
	set("long",
		"江湖郎中。\n");

	set("attitude", "peaceful");
	set_skill("literate", 0);
        set_skill("parry",10);
        set_skill("dodge",20);
        set_skill("unarmed",10);
	setup();
carry_object("/obj/cloth")->wear();
}

