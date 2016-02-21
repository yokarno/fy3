// Room: /d/dali/toemei.c

inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long", @LONG
此处是北上峨嵋山、南下大理国的必经之路，不少劫匪常藏身此
处，做些不要本钱的买卖。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"todali",
  "north":"/d/emei/xiaolu2",
]));
	set("outdoors", "dali");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
