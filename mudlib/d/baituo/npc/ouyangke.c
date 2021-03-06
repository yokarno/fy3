///ouyangfeng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("欧阳克", ({ "ouyang ke", "ouyang", "ke" }));
	set("long", "白驼山少庄主，欧阳锋的私生子。"
		   +"一生风流成性。\n");
	set("title", "风流公子");
	set("gender", "男性");
	set("age", 33);
	set("shen_type",-1);
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 29);
	set("con", 30);
	set("dex", 28);

	set("kee",1500);
	set("max_kee",1500);
	set("gin",600);
	set("max_gin",600);
	set("force",1000);
	set("max_force",1000);
	set("force_factor",50);

	set("combat_exp", 500000);

	set_skill("force", 120);
	set_skill("unarmed",120);
	set_skill("dodge",120);
	set_skill("parry",120);
	set_skill("staff",120);
	set_skill("hamagong", 120);
	set_skill("chanchu-bufa",120);
	set_skill("shexing-diaoshou",120);
	set_skill("lingshe-zhangfa",120);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

	create_family("白驼山派",2, "弟子");
        set("chat_chance",2);
        set("chat_msg",({
         "欧阳克轻摇手中折扇，神情甚是得意。\n",
         "欧阳克冲你微一点，脸上神情甚是奇怪。\n",
         "欧阳克嘴里轻哼小曲，脸上洋洋自得。\n",
        }));
	setup();
	carry_object("/obj/cloth")->wear();
	add_money("silver",20);
}

void attempt_apprentice(object ob)
{
  if((int)ob->query("combat_exp")<50000)
        {
          message_vision("欧阳克对$N笑道：你的经验太低了,我还不能收你！\n",ob);
	return ;
         }
   message_vision("欧阳克拍拍$N的头，微微点了点头。\n",ob);
   command("recruit " + ob->query("id"));
   return;
}

