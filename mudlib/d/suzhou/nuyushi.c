// Room: /d/suzhou/nuyushi.c

inherit ROOM;

void create()
{
	set("short", "女浴室");
	set("long", @LONG
专供女子洗澡的地方，室中摆放了不少大圆桶，几个青年丫环在一旁侍侯。
LONG
	);
	set("bath_room",1);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yushi",
]));
	set("no_clean_up", 0);
	set("hotel",1);
	setup();
	replace_program(ROOM);
}
