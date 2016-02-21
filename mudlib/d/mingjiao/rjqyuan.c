//RJQYUAN.C

inherit ROOM;

void create()
{
	set("short", "大院");
	set("long", @LONG
你走进了锐金旗的大院，却发现这里人影稀疏，虽听见叮
叮咚咚的打铁声，却见不到打铁铺，那声音似乎是从深远的地
下传来的。向西走，就要进入门楼了。院子左首可能是练武场，
隐约传来打斗声；右首是一座大厅，象是锐金旗的议会场所。
LONG
	);

	set("exits", ([
//              "west" : __DIR__"rjqmenlou1",
		"north" : __DIR__"rjqdating",
		"south" : __DIR__"rjqlwch",
		"out":__DIR__"rjqmen",
	]));
/*
        set("objects",([__DIR__"npc/lengqian":1,
        		__DIR__"npc/shuobude":1,
		        __DIR__"npc/zhangzhong":1,
		        __DIR__"npc/pengyingyu":1,
		        __DIR__"npc/zhoudian":1,
		        __DIR__"npc/yinyewang":1,
			]));
*/
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
