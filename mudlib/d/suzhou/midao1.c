// Room: /u/xizhen/room/chufang.c

inherit ROOM;

void create()
{
	set("short","密道");
	set("long", @LONG
这是条连接金风庄与参合山庄的密道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"north":__DIR__"midao2",
	"out":__DIR__"jinfengzhuang",
]));

	setup();
	replace_program(ROOM);
}
