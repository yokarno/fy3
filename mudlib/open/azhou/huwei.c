
inherit NPC;

string ask_me();

void create()
{
        set_name("护卫", ({ "huwei" }));
        set("nickname", "阿周的贴身护卫");
        set("long", 
                "他就是阿周的贴身护卫。\n"
                "身穿一件干干净净的灰色长袍。\n"
                "他大约二十出头，身材修长，满脸红光。\n");
        set("gender", "男性");
        set("age", 23);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);

        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 100000);
        set("score", 60000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
//      set_skill("literate", 100);

        set("inquiry", ([
                "阿周" : "我主人阿周是个了不起的大英雄，能做他的护卫，是我天大的福分！",
         ]));
        setup();
        carry_object("/open/azhou/obj/suoyi")->wear();
        carry_object(__DIR__"obj/tiepian")->wield();
        
}

