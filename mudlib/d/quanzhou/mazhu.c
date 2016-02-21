// Room: /d/quanzhou/mazhu.c

inherit ROOM;

void create()
{
	set("short", "天后宫大门");
	set("long", @LONG
天后宫的大门敞开着,隐隐看到里面的烟雾缭绕,两扇红色的大门高
达两丈,上面还补满了大铁钉子.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"estreet2",
  "south" : __DIR__"zhendian",
]));
	set("outdoors", "/d/quanzhou");

	setup();
	replace_program(ROOM);
}
