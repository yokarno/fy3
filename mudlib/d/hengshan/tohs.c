// Room: /d/hengshan/tohs.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是条连接恒山、开封与中州之间官道的山路。西北是恒山方
向，东南可至开封与中州间的官道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast":"/d/zhongzhou/wroad3",
  "northwest" : __DIR__"shanlu2",
]));
	set("outdoors", "hengshan");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
