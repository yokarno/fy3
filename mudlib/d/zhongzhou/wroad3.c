// Room: /d/zhongzhou/wroad1.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
此处是个叉路，往西不远是开封，往东可到中州，西北通往北岳恒
山。则时正是游玩时节，不少游人顺着这条路往恒山而去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest":"/d/hengshan/tohs",
  "west":"/d/kaifeng/tokaifeng",
  "east":__DIR__"wroad2",
]));
	set("outdoors", "zhongzhou");
	set("objects",([
		"/npc/man5":1,
		"npc/man4":2,
	]));

	setup();
	replace_program(ROOM);
}
