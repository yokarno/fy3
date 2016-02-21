// Room: /d/xxy/zoulang2.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
一条靠着墙的回廊,另一边就是花园,从此看去,花园中一栋高楼十分威武.
正是'我'级高手所住的天风楼.廊沿下的铁马在风中当当作响.从此向南可以进
入花园,向北有一排高楼.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/xxy");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"zoulang3",
  "east" : __DIR__"zoulang1",
  "south" : __DIR__"gardon",
]));

	setup();
	replace_program(ROOM);
}
