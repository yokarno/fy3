// Room: /d/hangzhou/shilu.c

inherit ROOM;

void create()
{
	set("short", "石子路");
	set("long", @LONG
一条五彩石子铺就的小路,道旁彩蝶纷飞,花团锦簇.透过道边林木,一
座高塔就在眼前不远.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hangzhou");
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"nanping",
  "westup" : __DIR__"leifeng",
]));

	setup();
	replace_program(ROOM);
}
