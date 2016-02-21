// hp cmds (Mon  09-04-95)
// 
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
string status_color(int current, int max);
 
string *npc_banghui=({
	"明教",
	"日月教",
	"天地会",
	"丐帮",
});

int main(object me, string arg)
{
	object ob,lp;
	mapping my,data;
	string banghui;
        seteuid(getuid(me));
 
        if(!arg)
                ob = me;
        else if ( arg == me->query("marry") )
            {
              ob = present(arg, environment(me));
		if(!ob || !ob->is_character())
		return notify_fail("这儿没有这么个人。\n");
              printf("你的伴侣状态如下:\n");
            }
        else if (wizardp(me)) {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
		if (!ob || !ob->is_character()) return notify_fail("你要察看谁的状态？\n");
                               }

	else if ( stringp(banghui=me->query("banghui")))	{
		ob =present(arg,environment(me));
		if(! ob)	return notify_fail("这儿没有这么个人。\n");
		if( ! ob->is_character())
			return notify_fail("你不能查看这样东西。\n");
		if( ob->query("banghui")!=me->query("banghui"))
			return notify_fail("你只能查看本帮会帮众的状态。\n");
		}
	else return notify_fail("只有巫师或同帮会的人才能察看别人的状态。\n");
        my = ob->query_entire_dbase();
 
printf(" 精  ： %s%4d/ %4d %s(%3d%%)" NOR "    道行： %s%4d / %4d (+%d)\n" NOR,
                status_color(my["gin"], my["eff_gin"]), my["gin"],      my["eff_gin"],
                status_color(my["eff_gin"], my["max_gin"]),     my["eff_gin"] * 100 / my["max_gin"],
                status_color(my["atman"], my["max_atman"]),     my["atman"], my["max_atman"],
                my["atman_factor"] );
    printf(" 气  ： %s%4d/ %4d %s(%3d%%)" NOR "    内力： %s%4d / %4d (+%d)\n" NOR,
                status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
                status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
                status_color(my["force"], my["max_force"]),     my["force"], my["max_force"],
                my["force_factor"] );
printf(" 神  ： %s%4d/ %4d %s(%3d%%)" NOR "    佛法： %s%4d / %4d (+%d)\n" NOR,
                status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
                status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"],
                status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
                my["mana_factor"] );
	if(userp(ob))	{
	if(member_array((string)ob->query("banghui"),npc_banghui)!=-1)
printf(" 食物： %s%4d/ %4d      " NOR "     评价：� %s%d\n"NOR,
        status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),
        HIY,
	(int)ob->query("score"));
	else
printf(" 食物： %s%4d/ %4d      " NOR "     评价：� %s%s\n"NOR,
        status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),
        HIY,
	"???");
	}
	else
printf(" 食物： %s%4d/ %4d      " NOR "     忠诚： %s%4d / %4d\n"NOR,
	status_color(my["food"], ob->max_food_capacity()),
	my["food"], ob->max_food_capacity(),
	status_color(ob->query("zhongcheng"),ob->query("max_zhongcheng")),
	ob->query("zhongcheng"),ob->query("max_zhongcheng"));
    printf(" 饮水： %s%4d/ %4d      " NOR "     经验： %s%d\n" NOR,
        status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),
        HIM,
        my["combat_exp"] );
        return 1;
}
 
string status_color(int current, int max)
{
        int percent;
 
        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
 
int help(object me)
{
        write(@HELP
指令格式 : hp
           hp <对象名称>                   (巫师专用)
           hp <伴侣名称>                   (夫妻专用)
 
这个指令可以显示你或指定对象(含怪物)的精, 气, 神数值。
 
see also : score
HELP
    );
    return 1;
}

