// BaiGuiShou.c
// pal 1997.05.11

#include <ansi.h>

inherit NPC;

string ask_me();

void create()
{
    set_name("�׹���", ({ "bai guishou", "bai", "guishou", }));
	set("long",
        "����һλ���ް߰׵����ߣ�����һ���ײ����ۡ�\n"
        "���������Ǹ��ֳ����׵�΢Ц������ʱ��͸��һ˿���ܡ�\n"
	);

    	set("banghui","����");
	set("bh_rank","����̳̳��");

	set("gender", "����");
	set("attitude", "friendly");

    set("age", 56);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_kee", 450);
	set("max_gin", 300);
	set("force", 600);
	set("max_force", 600);
	set("force_factor", 50);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("unarmed",70);
	set_skill("nianhua-zhi", 68);
	set_skill("parry", 70);
	set_skill("sword", 80);
	set_skill("damo-jian", 80);
set_skill("daoxuexinde",70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "damo-jian");
	map_skill("sword", "damo-jian");
	map_skill("unarmed","nianhua-zhi");

	set("inquiry", ([
		"����" :    (: ask_me :),
	]));

	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
}


string ask_me()
{
	return "������ �������ֲ�ȱ���� ǰ�����ǲ��Ǹ�����һ�����飬������ʲ��ĸ����𣿣�";
}