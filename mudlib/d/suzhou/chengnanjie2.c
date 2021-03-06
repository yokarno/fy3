// Room: /d/suzhou/chengnanjie2.c

inherit ROOM;

void create()
{
	set("short", "城南街");
	set("long", @LONG
你刚走到这里，立刻被东边传来的朗朗书声给吸引了。抬头望去，只见一座
古色古香的书院坐落于东首，“天龙阁”三字在晨光中隐隐放光。与它相对的是
苏州首富开的钱庄。街道南北延伸，路上行人不断。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north" :__DIR__"chengnanjie1",
		"south" :__DIR__"chengnanjie3",
		"west" :__DIR__"qianzhuang",
		"east" :__DIR__"tianlongge",
]));
	set("objects",([
		"/npc/man4":1,
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
