// Room: /d/suzhou/huangqiu1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "荒丘");
	set("long", @LONG
这片荒丘地带处于两府交接之处，也不知到底归哪府管辖。正是官府势力的
空缺处。因而盗寇带窜至此处。这时树上的乌鸦“嘎嘎”叫了两声，你心中发毛，
不由的加快了步伐。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"east":__DIR__"huangqiu2",
	"westdown" :__DIR__"guandao3",
]));
	set("no_clean_up", 0);
	set("outdoors","suzhou");
	setup();
}
int valid_leave(object me,string dir)
{
	if(!userp(me)&&me->query("home")==1&&dir=="westdown")	{
	tell_room(__DIR__"guandao3",RED"\n荒丘上传来土匪的怒喝声：跑得过初一跑不过十五！！\n"NOR);
	return 0;
	}
return 1;
}
