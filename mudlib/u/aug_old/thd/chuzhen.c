// thd:chuzhen.c
//#include <localtime.h>

inherit ROOM;

void create()
{
      set("short", "桃树林");
	set("long", @LONG
这里是桃树的海洋，抬头望去，到处都是满枝的桃花，在桃树的间隙
中有几条弯弯曲曲的幽径穿行于其中，周围静悄悄地只闻鸟鸣。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/jiading" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"bulletin" : "...\n",
//    ]));

      set("exits", ([ /* sizeof() == 1 */
          "north": __DIR__"in_road1",
	]));
      
	set("outdoors", "thd");

	setup();
	replace_program(ROOM);
}

