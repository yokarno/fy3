// Room: /d/quanzhou/laojun-stone.c

inherit ROOM;

void create()
{
	set("short", "老君岩");
	set("long", @LONG
沿着山势你拐了个弯,道旁一座巨大的石雕吸引了你,这是一块数丈 
高的巨石,整体雕刻成太上老君的模样,造型生动,刻工非常精巧. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/quanzhou");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"qinyuan-hill",
  "southup" : __DIR__"yixiaot",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bodaoren.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
