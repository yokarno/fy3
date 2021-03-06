// Room: /d/kaifeng/eroad1.c

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
东大街是开封府内东街区的主要通道。道路两端店铺府第不断。行
人如缕，观光的，作生意的，攀交情的，走亲访友的，喧闹无比。北边
不远就是山陕甘会馆。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/hanzi.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"eroad",
  "north" : __DIR__"eroad2",
]));
	set("outdoors", "/d/kaifeng");

	setup();
	replace_program(ROOM);
}
