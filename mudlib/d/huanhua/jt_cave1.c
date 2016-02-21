// Room: /d/huanhua/jt_cave1.c

inherit ROOM;

void create()
{
	set("short", "见天洞内");
	set("long", @LONG
见天洞内偏房,里面空间很大,摆满了数百副棺材,沿墙的一排架子上,
点着长明灯,几根白色蜡烛已经被吹熄了.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/obj/9arrow.c" : 3,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"injt_cave",
]));

	setup();
	replace_program(ROOM);
}
