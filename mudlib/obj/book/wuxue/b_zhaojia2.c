// 

inherit ITEM;

void create()
{
	set_name("《招架防御中卷》",({"zhaojiazhong","zhong"}));
        set_weight(100);
        set("unit", "本");
        set("long",
	 "一本记载格斗防御术的武学书籍。\n"
             );
	set("value",2000);
        set("skill", ([
	"name":"parry",
        "exp_required":5000,
        "max_skill":40,
        "sen_cost":20,
        ]) );
}
 
