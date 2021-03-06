// Room: /d/suzhou/zhuozhengmen.c

inherit ROOM;

void create()
{
	set("short", "拙政园");
	set("long", @LONG
此园乃四大名园之一，相传曾是唐代某位诗人的住宅，后曾作为寺院。现已
被朝庭返乡的大员买下，据说这位大员对政事心灰意冷，特为此庄园取名“拙政”
。你四下打量了一下，只见围墙环绕大门紧闭，也不知这位大员主人是否在家。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" :__DIR__"chengbeijie4",
]));
	set("item_desc",([
		"围墙"	: "围墙上隐约有些足印，不知谁从这儿爬过。\n",
		"weiqiang":"围墙上隐约有些足印，不知谁从这儿爬过。\n",
]));
	set("objects",([
		__DIR__"npc/jieba":2,
]));
	set("no_clean_up", 0);
	set("outdoors","suzhou");
	setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string dir)
{
	object me=this_player();

	if( !living(me))	return 0;
	if( ! dir || (dir!="weiqiang"&&dir!="围墙"))
		return notify_fail("你要爬什么？\n");
	if( (int)me->query("kee")<50)
		return notify_fail("你的气力不够，爬不动。\n");
	if( (int)me->query_skill("dodge")<50)
		return notify_fail("你的轻功太低了。\n");
	message_vision("$N沿着围墙爬了进去。\n",me);
	me->move(__DIR__"yuannei1");
	return 1;
}

