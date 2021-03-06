// Room: /d/huanggon/cininggon.c

inherit ROOM;

void create()
{
	set("short", "慈宁宫");
	set("long", @LONG
慈宁宫是皇太后的居处,你现在所处的是个大院子,院中池塘边植满
柳树,院中假山之边是几株腊梅.西边是个月洞门通向御花园,东面是皇太
后的寝宫.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/ruichu.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/huanggon");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yuhuayuan2",
  "east" : __DIR__"ciqinggon",
]));

	setup();
	replace_program(ROOM);
}
