// music   yangzhou's ����

inherit NPC;

void create()
{
	set_name("�����", ({ "duan", "tiande", "duan tiande" }) );
	set("gender", "����" );
	set("age", 40);
	set("long",
		"���ݵ��سǽ��١�\n");
	set("mingwang", -1000);
	set("combat_exp", 180000+random(1000000));
        set("str", 30+random(20));
        set("cps", 20);
        set("con", 20);
        set("int", 20);
        set("max_kee",1000);
        set("max_force",500);
        set("force",500);
        set("max_gin",600);
        set("max_sen",500);
        set("force_factor",30);
        set_skill("dodge",60+random(100));
        set_skill("unarmed",50+random(100));
	set_skill("parry",80+random(100));
	set_skill("blade",70+random(100));
	set_skill("force",100);
	set("attitude", "peaceful");
	setup();
        carry_object("/obj/armor/tiejia")->wear();
        carry_object(__DIR__"obj/gangdao")->wield();
	add_money("gold", 2);
}

