// Room: /d/suzhou/meizhuang/midao1.c
#include <ansi.h>
inherit ROOM;
string status();
void create()
{
	set("short", "密道");
	set("long", @LONG
密道内阴暗异常，只有墙壁上点着一盏油灯，发出淡黄色光芒。远处
传来滴达滴达的水声，你不由的戒备起来。西面一道石门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"down":__DIR__"midao4",
]));
	set("item_desc",([
	"石门":	(: status :),
	"shimen":	(: status :),
]));
	set("no_clean_up", 0);

	setup();
}
void init()
{
	add_action("do_tui","tui");
}

int do_tui()
{
	object me,room;
	me=this_player();
	room=load_object(__DIR__"midao2.c");
	if(query("exits/west"))
	return notify_fail("石门早已被推开了。\n");
	if(me->query_str()<45)	{
		 message_vision(CYN"$N使出吃奶的劲用力推石门。\n结果石门纹丝不动！\n"NOR,me);
		return 1;
	}
	message_vision(CYN"$N气沉丹田，双臂一振缓缓的将石门推开！\n"NOR,me);
	tell_object(room,CYN"不知是谁在对面把石门推开了。\n"NOR);
	set("exits/west",__DIR__"midao2");
	room->set("exits/east",__FILE__);
	return 1;
}
string status()
{
	if(query("exits/west"))
	return "一座厚厚的石门，已被推开。\n";
	return "一座厚厚的石门，看样子只好推推（tui）看了。\n";
}
int valid_leave(object me,string dir)
{
	object room;
	room=load_object(__DIR__"midao2.c");
	if(query("exits/west"))
	{
	 tell_object(this_object(),CYN"只听得几声闷响，石门恢复原状。\n"NOR);
	delete("exits/west");
	tell_object(room,CYN"不知是谁触动了机关，几声闷响之后石门恢复原状。\n"NOR);
	room->delete("exits/east");
	}
	return ::valid_leave(me,dir);
}
