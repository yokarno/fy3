// Room: /d/suzhou/meizhuang/midao1.c
#include <ansi.h>
inherit ROOM;
string status();
void create()
{
	set("short", "密道");
	set("long", @LONG
密道内阴暗异常，只有墙壁上点着一盏油灯，发出淡黄色光芒。地势
不断倾斜，只怕已深入地底百丈有余。北面似乎有道铁门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"up":__DIR__"midao3",
]));
	set("no_clean_up", 0);
	set("item_desc",([
		"铁门":	(: status :),
		"tiemen":	(: status :),
]));
	setup();
}
void init()
{
	add_action("do_yong","shiyong");
}
int do_yong(string str)
{
	object me,room;
	me=this_player();
	room=load_object(__DIR__"midao5.c");
	if(!str)
	return notify_fail("你要使用什么？\n");
	if(!present(str,me))
	return notify_fail("你身上没有这样东西。\n");
	if(str!="yaoshi")
	return notify_fail("你在这儿只能使用钥匙。\n");
	if(query("exits/north"))
	return notify_fail("铁门早已被打开了。\n");
	message_vision(CYN"$N掏出钥匙插入钥匙孔中转了几下。\n只听得“卡挞”一声轻响，铁门被打开了！\n"NOR,me);
	tell_object(room,CYN"不知谁从对面打开了铁门。\n"NOR);
	set("exits/north",__DIR__"midao5");
	room->set("exits/south",__DIR__"midao4");
	return 1;
}
string status()
{
	if(query("exits/north"))	{
		return "一道铁门，已被打开了。\n";
	}
	 return "上面有个钥匙孔，看样子得使用（shiyong）钥匙开了。\n";
}
int valid_leave(object me,string dir)
{
	object room;
	room=load_object(__DIR__"midao5.c");
	if(query("exits/north"))	{
	tell_object(this_object(),CYN"“卡啦啦”铁门不知怎么被关上了！\n"NOR);
	delete("exits/north");
	tell_object(room,CYN"“卡啦啦”响声过后，不知谁触动机关，铁门被关上了！\n"NOR);
	room->delete("exits/south");
	}
	return ::valid_leave(me,dir);
}
