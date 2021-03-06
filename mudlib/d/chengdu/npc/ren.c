// kongkong.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	seteuid(getuid());
        set_name("测试人物", ({ "kong kong","beggar","qi gai","kong" }) );
	set("title", "妙手神丐");
	set("gender", "男性" );
        set("age", 32);
	set("long", "一个满脸风霜之色的老乞丐。\n");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);

        set("qi", 220);
        set("max_qi", 220);
        set("jing", 220);
        set("max_jing", 220);
        set("neili", 300);
        set("max_neili", 300);

        set("shen_type", 1);
        set("startroom",__DIR__"chengzhong");
	set("thief", 0);
        set("combat_exp", 20000);

	set_skill("force", 40); 
	set_skill("unarmed", 60);
	set_skill("sword", 50);
	set_skill("dodge", 80);
	set_skill("parry", 50);

	set("chat_chance", 20);
	set("chat_msg", ({
		"空空儿说道: 好心的大爷哪～ 赏我要饭的几个铜板吧～\n",
		"空空儿懒洋洋地打了个哈欠。\n",
		"空空儿伸手捉住了身上的虱子，骂道: 老子身上没几两肉，全叫你们给咬糜了。 \n",
		(: random_move :)
	}) );

	setup();

carry_object("/d/yangzhou/npc/obj/jitui");
carry_object("/d/yangzhou/npc/obj/jiuhu");
        add_money("silver", 2);
        
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("stealing");
		call_out("stealing", 1, ob);
	}
}

