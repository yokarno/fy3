// 

inherit ITEM;

void create()
{
	set_name("《徒手格斗中卷》",({"gedouzhong","zhong"}));
        set_weight(100);
        set("unit", "本");
        set("long",
		"一本记载格斗术的武学书籍。\n"
             );
	set("value",2000);
        set("skill", ([
	"name": "unarmed",
        "exp_required":5000,
        "max_skill":40,
        "sen_cost":20,
        ]) );
}
 
