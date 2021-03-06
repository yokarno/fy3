// lin-pingzhi.c

inherit NPC;
#include <ansi.h>;
void create()
{
        set_name("林平之", ({ "lin pingzhi","lin","pingzhi"}));
        set("gender", "男性");
        set("age", 18);
        set("long",
                "林平之是岳不群最小的一个弟子，也是他的东床快婿。\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("con", 30);
        set("int", 24);
        set("dex", 35);

        set("max_kee",1500);
        set("max_gin",1500);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 100);

        set("combat_exp", 100000);
        set("shen_type", -1);
        set("score", 200000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 60);
        set_skill("sword", 50);
        set_skill("force", 60);
        set_skill("parry", 50);
        set_skill("dodge", 60);
        set_skill("literate", 70);

        set_skill("huashan-jianfa", 80);
        set_skill("pixie-jianfa", 80);
        set_skill("zixia-shengong", 60);
        set_skill("huashan-quanfa", 60);
        set_skill("feiyan-huixiang", 60);

        map_skill("sword", "pixie-jianfa");
        map_skill("parry", "pixie-jianfa");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-quanfa");
        map_skill("dodge", "pixie-jianfa");

        create_family("华山派", 14, "弟子");
        setup();

carry_object("/obj/weapon/sword")->wield();
carry_object("/obj/cloth")->wear();
}
