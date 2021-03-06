// Room: /d/quanzhen/fu-houyuan.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
	这里是后院。走到这里，花香味更加浓烈了。你仔细一看，东
南边有一道圆形门，似乎花香是从那里传出来的。从这里再往南走，就
是侯员外的卧室了。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  "/d/yandang/npc/puren.c" : 1,
  "/d/yandang/npc/yahuan.c" : 1,
]));
	set("outdoors", "/d/quanzhen");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"fu-woshi",
  "north" : __DIR__"fu-datang",
  "southeast" : __DIR__"houhuayuan",
]));

	setup();
	replace_program(ROOM);
}
