// 

inherit ITEM;

void create()
{
	set_name("《内功心法上卷》",({"neigongshang","shang"}));
        set_weight(100);
        set("unit", "本");
        set("long",
	"一本记载着呼吸吐纳运气法门的武学书籍。\n"
             );
	set("value",1000);
        set("skill", ([
	"name":"force",
        "exp_required":100,
        "max_skill":20,
        "sen_cost":10,
        ]) );
}
 
