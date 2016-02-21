// Room: /d/huizhu/jiayuguan.c

inherit ROOM;

void create()
{
	set("short", "嘉峪关");
	set("long", @LONG
嘉峪关长城环抱，控扼大荒，蜿蜒如线，俯视肃州城方如斗.远处大
漠风沙起，遮天蔽日。出了关就不再是中原地面。嘉峪关就是西行的屏障
看守的兵卫仔细盘差着出入的人员。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/hangzhou/npc/man.c" : 2,
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/huizhu");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"guanwai",
  "east" : __DIR__"guandao1",
]));

	setup();
	replace_program(ROOM);
}
