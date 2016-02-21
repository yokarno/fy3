// Room: /d/sandboy/to_sandboy2.c

inherit ROOM;

void create()
{
	set("short", "叉路口");
	set("long", @LONG
此地因为来往人多,形成了一个数十丈方圆的地盘.南面有片杂树林,
通过树林可以直接到达武当山,向东可到江南名城--苏州，北边则是中州。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"to_sandboy",
  "south" : __DIR__"trees2",
  "east" : "/d/suzhou/guandao4",
]));
	set("outdoors", "/d/sandboy");

	setup();
	replace_program(ROOM);
}
