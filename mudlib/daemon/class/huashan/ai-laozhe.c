// ai-laozhe.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("矮老者", ({ "ai laozhe", "ai" }));
	set("title", HIG"华山第十二代长老"NOR);
	set("long", 
"他就是华山的长老矮老者。一张严肃威严的脸，望而生畏。\n");
	set("gender", "男性");
	set("age", 66);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("kee", 3800);
	set("max_kee", 3800);
	set("gin", 3600);
	set("max_gin", 2000);
	set("force", 2400);
	set("max_force", 2400);
	set("force_factor", 100);

	set("combat_exp", 1250000);
	set("score", 200000);

	set_skill("force", 170);
	set_skill("blade", 180);
	set_skill("sword", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("unarmed", 180);
	set_skill("zixia-shengong", 200);
	set_skill("poyu-quan", 160);
	set_skill("fanliangyi-dao", 180);
	set_skill("huashan-sword", 180);
	set_skill("hunyuan-zhang", 160);
        set_skill("feiyan-huixiang",160);
	set_skill("literate", 100);

	map_skill("force", "zixia-shengong");
        map_skill("dodge", "feiyan-huixiang");
        map_skill("parry", "fanliangyi-dao");
	map_skill("blade", "fanliangyi-dao");
	map_skill("sword", "huashan-sword");
	map_skill("unarmed", "hunyuan-zhang");

	create_family("华山派", 12, "弟子");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "blade.sanshen" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
	int student_num;
	string temp;
	string line;

	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "华山派")
	{
		command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜老朽呢？");
		return;
	}

        if (((int)ob->query_skill("force",1) < 80) || ((int)ob->query_skill("zixia-shengong",1) < 80))
	{
		command("say 我看" + RANK_D->query_respect(ob) + "的紫霞神功还没学到家吧。");
		return;
	}
        if (((int)ob->query_skill("dodge",1) < 80) || ((int)ob->query_skill("feiyan-huixiang",1) < 80))
	{
                command("say 我看" + RANK_D->query_respect(ob) + "的飞燕回翔还没学到家吧。");
		return;
	}

        if ((int)ob->query("mingwang") < 50000)
	{
		command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "fighter")
		ob->set("class", "fighter");

}
