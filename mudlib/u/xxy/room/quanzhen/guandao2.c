// guandao2.c 官道


inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
	这是一条官府修建的大道，西面隐约可以看见长安镇的东门。远
处好象可以看见巍峨的城墙。往东是通往中原的路。走在这里，你似乎有
了一种‘劝君更进一杯酒，西出阳关无故人’的感觉。
LONG
	);

	set("exits", ([
		"east" : __DIR__"guandao1",
		"west" : __DIR__"dongmen",
	]));

	setup();
	replace_program(ROOM);
}