// Room: /d/jinling/shanglin3.c

inherit ROOM;

void create()
{
	set("short", "上林道");
	set("long", @LONG
这是一条连接东西城门及上林苑的宽括街道，一直延伸到城外。道上
道上行人很多，不时有马和车飞驰而过。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jingling");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"chengmen3.c",
  "east" : __DIR__"shanglin2.c",
]));

	setup();
	replace_program(ROOM);
}
