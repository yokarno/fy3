// Mr.music yangzhou's 秋香

inherit NPC;

void create()
{
	set_name("秋香", ({ "qiuxiang", "xiang" ,"qiu"}));
	set("long", "一代才女，唐伯虎的夫人。\n");
	set("gender", "女性");
	set("age", 25);
        set("per", 90);

	set_skill("literate", 50);
        set("title","江南第一才女");
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 100000);
	set("mingwang", 1);

        set("inquiry", ([
               "suzhou" : 
                     "我也好想回去哦，在御码头乘船沿运河一直向东就到了。\n",
               "苏州" : 
                     "我也好想回去哦，在御码头乘船沿运河一直向东就到了。\n",
               "御码头" : "在小东门桥下面吧? \n",
               "yumatou" : "在小东门桥下面吧? \n",
               "跟我走" : "这 .... , 秋香望了望唐伯虎。 \n",
                       ]) );
	set("chat_chance",1);
	set("chat_msg", ({
		"秋香朝你笑了笑，你觉得地球仿佛突然停止转动了。\n",
		"秋香含情脉脉的看了唐伯虎一眼。\n",
                "秋香拉了拉唐伯虎，小声说：啥时咱回苏州看看？\n",
	}) );
setup();
}


int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/唐"))
		return 0; 
	ob->add_temp("mark/唐", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	if (!(int)who->query_temp("mark/唐"))
		who->set_temp("mark/唐", 0);
	if (ob->query("money_id") && ob->value() >= 500) {
		message_vision("秋香笑了笑，朝$N点点头。\n", who);
		who->add_temp("mark/唐", ob->value() / 20);
		return 1;
	}
	return 0;
}
