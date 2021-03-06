// qianfu.c 千夫长  16/6/98 

inherit NPC;

void create()
{
	set_name("蒙古千夫长", ({ "qianfu","jiangjun", "jiang" }));
	set("age", random(15)+30);
	set("gender", "男性");
	set("long", "满脸横肉,眯缝的眼里不时露出狠毒的光.\n");
	set("attitude", "peaceful");

	set("str", 34);
	set("dex", 36);
	set("combat_exp", random(30000)+70000);
	set("mingwang", 2);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("blade", 80);
	set_skill("force", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 80);
	set_temp("apply/armor", 80);

    set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"千夫长拍了拍暴涨的啤酒肚,打了个隔,差点把你熏倒!\n",
		"千夫长对你笑嘻嘻地到:我看你能撑多久!说着打了个隔.\n",
	}));
	set("inquiry", ([
		"三王爷" : "闭嘴！王爷是你能提的吗？",
		"rumors" : "听说这地底下埋着宝呢！",
		]) );	
	setup();
	carry_object("obj/weapon/blade")->wield();
	carry_object("obj/cloth")->wear();
}

void init()
{
	object ob;
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say 呆会你就会知道我的利害了。\n");
       command("hehe\n");
	me->apply_condition("killer", 100);
	kill_ob(me);
	return 1;
}
