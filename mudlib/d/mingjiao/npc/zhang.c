//zhangwuji.c

#include <ansi.h>

inherit F_MASTER;
inherit NPC;

void greeting(object ob);
void create()
{
    seteuid(getuid());
        set_name("张无忌", ({ "zhang wuji", "zhang", "wuji" }));
        set("long", "明教教主张无忌，统领天下十万教众，豪气干云，叱咤千秋，\n"
               +"「九阳神功」、「乾坤大挪移」独步天下，是江湖中不世出的\n"
               +"少年英雄。\n");
    set("title",HIG"明教教主"NOR);
        set("gender", "男性");
    set("age", 20);
        set("shen_type",1);
    set("attitude", "friendly");

    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("qi", 3050);
    set("max_qi", 3050);
    set("jing", 3050);
    set("max_jing", 3050);
    set("neili", 5000);
    set("max_neili", 5000);
    set("jiali", 150);

    set("combat_exp", 3000000);
    set("score", 1000000);

    set_skill("force", 200);
    set_skill("unarmed",200);
    set_skill("dodge", 200);
    set_skill("parry", 200);
    set_skill("hand",200);
    set_skill("sword",250);
    set_skill("blade", 200);
    set_skill("jiuyang-shengong", 200);
    set_skill("qiankundanuoyi", 300);
    set_skill("qishang-quan", 200);
//  set_skill("wuxue-xinfa", 485);
    set_skill("taiji-quan",200);
    set_skill("taiji-jian",200);
    set_skill("taiji-dao",200);

        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "qiankundanuoyi");
        map_skill("unarmed", "qishang-quan");
         map_skill("parry","taiji-jian");
        map_skill("hand", "taiji-quan");
        map_skill("sword","taiji-jian");
        map_skill("blade","taiji-dao");

    create_family("明教",1, "教主");

        set("chat_chance",3000);

                setup();
                carry_object("/d/mingjiao/obj/sword")->wield();

}
void attempt_apprentice(object ob)
{
object me;
        mapping ob_fam, my_fam;
        string name, new_name;

        me = this_object();
        my_fam  = me->query("family");

        name = ob->query("name");

        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "明教")

        {
                command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不
知此话从何谈起？");
                return;
        }
        if((int)ob->query("int")<40)
        {
                command("say 你的悟性太低了，不适合学习我的功夫。");
                return 0;
        }
        if(ob->query("score") <1000)
        {
                command("say 你对本门贡献不够，我不能收你。");
                return 0;
        }
        if((int)ob->query("shen") <= 100000)
        {
                command("say 你应当多作些行侠仗义的事，以修身心。");
                return 0;
        }
        command("say 好，我就收下你这位好兄弟");
        command("say 再接再砺！");
        command("recruit " + ob->query("id"));

}
