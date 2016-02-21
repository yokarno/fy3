// Room: /d/menggu/huanglu1.c

inherit ROOM;

void create()
{
	set("short", "荒路");
	set("long", @LONG
这是条连接关内外的荒路，由于远离城镇，人烟稀少。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/menggu");
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/huanggon/andingmen",
  "northwest" : __DIR__"damo2",
]));

	setup();
	replace_program(ROOM);
}
