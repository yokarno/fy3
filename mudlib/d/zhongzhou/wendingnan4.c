//wendingnan4
  

inherit ROOM;

void create()
{
	set("short", "文定南街");
	set("long", @LONG
这是中州城文定南街，宽敞的街道看的人不竟心情一畅。就快到中州
的南城门了。路边有一家驿站。
LONG
	);
set("outdoors","/d/zhongzhou");

	set("exits", ([
		 "south" : __DIR__"nanmeng",
		"west" : __DIR__ "shuyuan",
		 "north" : __DIR__"wendingnan3",
		"east" : __DIR__"yizhan",
]));
//        set("objects", ([
//                "/npc/npc": 2,
//	]));

	setup();
	replace_program(ROOM);
}

