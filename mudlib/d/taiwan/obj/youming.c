#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(RED"幽冥剑"NOR, ({"youming jian", "youming", "jian", "sword" }));
	set_weight(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "一把剑身"+RED+"通红"+NOR",剑尾饰有小骷髅头的长剑。\n");
		set("value", 50000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
              set("mask","庄");
	}
	init_sword(100);
	setup();
}
int move(mixed dest)
{
        if(! userp(dest))       return ::move(dest);
        if( ::move(dest)==0)    return 0;
        message("channel:rumor",YEL"【谣言】"+ "某人：幽冥剑被"+
        dest->query("name")+"抢到手了！\n"NOR,users());
        return 1;
}
