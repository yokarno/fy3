inherit ITEM;
void create()
{
        string *names = ({
                "「干蛇皮」"
        });
        set_name("干蛇皮", ({ "gan shepi" , "shepi"}));
        set_weight(600);
        set("unit", "张");
        set("long", "这是一张干蛇皮，上边写着密密麻麻的小字。\n");
       set("value",1);
        set("skill", ([
                "name":                 "shexing-diaoshou",             // name of the skill
                "exp_required": 50000,                              // minimum combat experience required
                                                                                // to learn this skill.
             "sen_cost":             8,                             // gin cost every time study this
                "difficulty":   50,                             // the base int to learn this skill
                                                                                // modify is gin_cost's (difficulty - int)*5%
                "max_skill":    50                              // the maximum level you can learn
                                                                                // from this object.
        ]) );
}
