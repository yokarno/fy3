// Room: /d/chengdu/tocd.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
这是条石板铺成的大道，由于靠近成都，所以来往行人多了
起来。西面不远就是成都。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"qingshidadao1",
  "east" :"/d/wudang/road3",
]));
set("outdoors","成都");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
