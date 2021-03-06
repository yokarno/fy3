#include <ansi.h>

inherit NPC;

void create()
{
        set_name("静道师太", ({ "jingdao shitai","jingdao","shitai"}));
        set("long",
      "她是一位中年出家道姑，道冠高拢，慈眉善目。\n");
        set("gender", "女性");
        set("age", 42);
        set("attitude", "peaceful");
        set("mingwang", 10000);
        set("class", "bonze");

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("per", 30);

        set("max_kee", 2000);
        set("max_gin", 500);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 15);

        set("combat_exp", 250000);
        set("score", 1000);
        set_skill("foxuexinde", 80);
        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("blade", 100);
        set_skill("literate", 100);
        set_skill("sword",100);
        set_skill("sixiang-zhang", 100);
        set_skill("anying-fuxiang", 100);
        set_skill("huifeng-jian", 100);
        set_skill("emei-xinfa", 100);
        map_skill("force","emei-xinfa");
        map_skill("dodge","anying-fuxiang");
        map_skill("unarmed","sixiang-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","sixiang-zhang");

        create_family("峨嵋派", 4, "弟子");

        setup();
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/ni-cloth.c")->wear();
        carry_object("/obj/armor/ni-xie")->wear();
}
void attempt_apprentice(object ob)
{
    command ("say 阿弥陀佛！贫尼不收弟子。\n");
    command ("say 你若想继续学峨嵋派的功夫，还是找我师姐吧。\n");
    return;
}

