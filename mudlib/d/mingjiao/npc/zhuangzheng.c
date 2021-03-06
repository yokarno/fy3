#include "ansi.h"

inherit NPC;

void create()
{
        set_name("庄铮", ({ "zhuang zheng", "zhuang", "zheng", }));
        set("long",
        "他是一位高大魁伟的中年男子，身穿一件白布长袍。\n"
        "他天生神力，有万夫不当之勇，真是一条威风凛凛的汉子。\n"
        );

        set("banghui","明教");
	set("bh_rank","锐金旗掌旗使");
        set("level",7);

        set("gender", "男性");
        set("attitude", "friendly");

        set("age", 40);
        set("shen_type", 1);
        set("str", 35);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_kee", 1000);
        set("max_gin", 1000);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 20);
        set("combat_exp", 50000);
        set("score", 5000);

       set_skill("force", 50);
        set_skill("sanyang-shengong", 50);
        set_skill("dodge", 50);
	set_skill("tianlong-bu",50);
         set_skill("unarmed", 50);
        set_skill("qishang-quan", 50);
        set_skill("parry", 50);

        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "tianlong-bu");
        map_skill("unarmed", "qishang-quan");
        map_skill("parry", "qishang-quan");


        setup();

    carry_object("/d/mingjiao/obj/baipao")->wear();
}

