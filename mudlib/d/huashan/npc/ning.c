// ning.c 宁中则

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("宁中则", ({ "ning zhongze", "ning", "zhongze", "shiniang" }));
	set("long", 
"宁中则女士是掌门人岳不群的师妹兼妻子，虽然已步入\n"
"中年，但风韵依旧。其武功只比岳不群略逊而已。\n");

	set("gender", "女性");
	set("age", 38);
	set("attitude", "peaceful");
	set("mingwang",1);
	set("str", 20);
	set("int", 35);
	set("con", 30);
	set("dex", 30);
	
	set("kee", 2200);
	set("max_kee", 2200);
	set("gin", 1600);
	set("max_gin", 1600);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 30);

	set("combat_exp", 1000000);
	set("score", 150000);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("zixia-shengong", 200);
	set_skill("huashan-jianfa", 200);
	set_skill("feiyan-huixiang", 200);
	set_skill("huashan-quanfa", 200);
	set_skill("literate", 90);
	set_skill("unarmed", 200);

	map_skill("dodge", "feiyan-huixiang");
	map_skill("force", "zixia-shengong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("unarmed", "huashan-quanfa");

	
	create_family("华山派", 13, "弟子");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jianzhang" :),
		(: perform_action, "sword.wushuang" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}

void attempt_apprentice(object ob)
{
	string family;

	family=(string)ob->query("family/family_name");
	if(! family || family !="华山派")		{
		command("say 你并非我华山弟子呀。");
		return;
	}
	if(family=="华山派" && (int)ob->query("family/generation")<=(int)query("family/generation"))	{
		command("say 哎，这我可不敢当啊。");
		return;
	}
	if ((string)ob->query("gender") != "女性") {
		command("say 阁下开什么玩笑！我怎么能够收男子为徒呢？真是羞人嗒嗒的。");
		return;
	}

	if ((int)ob->query("mingwang") < 5000) {
		command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "xiake")
		ob->set("class", "xiake");
}
