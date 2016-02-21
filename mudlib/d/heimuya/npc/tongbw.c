//tonbaixiong.c
inherit NPC;

void greeting(object);
void create()
{
	set_name("ͯ����", ({ "tongbai xiong","xiong"}) );
	set("gender", "����" );
	set("age", 75);
	set("banghui", "���½�");
	set("bh_rank","�����ó���");
	set("long", "���׷���ɢ, �������, ���ϵļ���ǣ��, \n"
                    "Բ��˫��, ���ϵ���Ѫ��Ȼ����, �������ǿɲ���\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_kee", 1000);
	set("max_gin",1000);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 200);
	set("combat_exp", 350000);
	set("score", 30000);

	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("taiji-shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("huntian-cuifa",100);
	set_skill("taiji-quan",100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");

	map_skill("parry","huntian-cuifa");
	map_skill("hammer","huntian-cuifa");
	map_skill("unarmed","taiji-quan");

	set("chat_chance", 3);
	set("chat_msg", ({
		 "ͯ����ŭ��˫�۵�: ����û��, ��û���ѽ�! �����ֵ��㲻��ԩ����ѽ! ��\n",
	         "ͯ����̾��һ����˵�����ҺͶ����ֵܳ�������, �������ѵ�ʱ��, ���ǻ�û��������!��\n"
        }) );
	setup();
        carry_object(__DIR__"obj/zijinchui")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/card1")->wear();

}
