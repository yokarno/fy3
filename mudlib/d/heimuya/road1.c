//road1.c 黄土路
// by Xiang

inherit ROOM;

void create()
{
        set("short", "乱石坡");
	set("long", @LONG
这是一处乱石怪异的小山岗，向东南是通往成都的小路。
据说前方经常有野兽出没，不可久留。
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
	    "southeast" : __DIR__"to_cd",
            "west"  : __DIR__"linjxd1",
            "east"  : __DIR__"dating4",
        ]));
        set("objects",([  
            __DIR__"npc/wangcheng" : 1,
            __DIR__"npc/heiyiren" : 2,
        ])); 
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
