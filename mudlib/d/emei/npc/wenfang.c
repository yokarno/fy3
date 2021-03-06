// wenfang.c 文方小师太

inherit NPC;
inherit F_MASTER;
inherit F_VENDOR;
void create()
{
        set_name("文方小师太", ({ "wenfang","wenfang xiaoshitai","xiaoshitai"}));
        set("long",
                "她是峨嵋派的第五代弟子。\n");
        set("gender", "女性");
        set("age", 15);
        set("attitude", "peaceful");
        set("class", "bonze");
        set("mingwang", 100);

        set("str", 20);
        set("int", 20);
        set("con", 22);
        set("per", 30);

        set("max_kee", 150);
        set("max_gin", 100);
        set("force", 150);
        set("max_force", 150);

        set("combat_exp", 2000);
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 5);
         
        set("chat_chance",5);
        set("chat_msg",({
        "文方皱了皱眉,从布袋中取出一盘菜闻了闻,点点头.\n",
        "文方自语道:有吃有喝,生活快乐.\n",
        "你闻到一股菜香从文方身上传来.\n",
        }));
        set("vendor_goods",([
        "菠菜粉条":"/d/emei/obj/bocai-fentiao.c",
        "琉璃茄子":"/d/emei/obj/liuli-qiezi.c",
        "麻辣豆腐":"/d/emei/obj/mala-doufu.c",
        "珊瑚白菜":"/d/emei/obj/shanhu-baicai.c",
        "清水葫芦":"/d/emei/obj/qingshui-hulu.c",
        ]));
        create_family("峨嵋派", 5, "弟子");

        setup();
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/ni-cloth.c")->wear();
        carry_object("/obj/armor/ni-xie")->wear();
}
void init()
{
  object ob;
  ::init();
  if (interactive(ob=this_player())&&!is_fighting()) {
  	remove_call_out("greeting");
  	call_out("greeting",1,ob);
    }
    add_action("do_vendor_list","list");
}
void greeting(object ob)
{
   command("say 是不是想买我作的菜呀,价钱好商量的.\n");
   return;
}