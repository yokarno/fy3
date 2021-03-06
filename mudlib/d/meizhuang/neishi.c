// Room: /d/suzhou/meizhuang/neishi.c
#include <ansi.h>
inherit ROOM;
string status();
void create()
{
	set("short", "内室");
	set("long", @LONG
室内一床一几，陈设简单，床上挂了纱帐，甚是陈旧已呈黄色。几上
放着一张短琴，通体黝黑，似是铁制，当是数百年甚至是上千年以上的古
物。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"huangzhonggongju",
]));
	set("no_clean_up", 0);
	set("item_desc",([
		"床"	:	(: status :),
		"chuang":	(: status :),
]));
	setup();
}
void init()
{
	add_action("do_la","la");
	add_action("do_la","拉");
}
int do_la()
{
	object me;
	me=this_player();
	if(query("exits/down"))
	return notify_fail("密道早已被人打开了。\n");
	if(!me->query_temp("oldsix_flag/look"))
	return notify_fail("你要干什么？\n");
	me->delete_temp("oldsix_flag/look");
	message_vision(CYN"$N小心翼翼的将床边的拉环拉了一下。\n几声闷响过后，床上露出个密道来！\n"NOR,me);
	set("exits/down",__DIR__"midao1");
	return 1;
}
string status()
{
	object me;
	me=this_player();
	me->set_temp("oldsix_flag/look",1);
	return "你仔细在床上搜巡了一遍，发现床角处有个拉环！\n";
}
int valid_leave(object me,string dir)
{
	if(query("exits/down"))	{
		message_vision(CYN"机关触动几声清响过后，床上的密道消失了！\n"NOR,me);
		delete("exits/down");
	}
	if(me->query_temp("oldsix_flag/look"))
		me->delete_temp("oldsix_flag/look");
	return ::valid_leave(me,dir);
}

