//Mr.music yangzhou 啃的鸡

inherit ROOM;

void create()
{
	set("short", "啃的鸡");
	set("long", @LONG
	这是是啃的鸡......

LONG
	);

	set("exits", ([ 
		      "west" : __DIR__"pishijie2",
	             ]));
	set("objects", ([
                __DIR__"npc/xiaogongji": 1
	]) );

	setup();
}

