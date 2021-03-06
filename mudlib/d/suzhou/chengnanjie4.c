// Room: /d/suzhou/chengnanjie4.c

inherit ROOM;

void create()
{
	set("short", "城南街");
	set("long", @LONG
街西乃苏州府学，又称“文庙”，苏州城内不少文人雅士常聚于此吟诗做对。
街东一泓清水绕园而过，隔岸相望廊阁起伏波光倒影。你向路人打听了一下，此园
名为沧浪亭。街道南北延伸，南面已可望见盘门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" :__DIR__"panmen",
		"north" :__DIR__"chengnanjie3",
		"west" :__DIR__"wenmiao",
		"east" :__DIR__"canglangting",
]));
	set("objects",([
		"/npc/man1":2,
	]));
	set("outdoors","suzhou");
	setup();
	replace_program(ROOM);
}
