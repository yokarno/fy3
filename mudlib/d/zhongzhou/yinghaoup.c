//yinghaoup
  

inherit ROOM;

void create()
{
	set("short", "英豪酒家二楼");
	set("long", @LONG
这是英豪酒家二楼雅座，如果靠窗坐的话，街上行人可以尽收眼底，
你如果喜欢清净一点，就在里面包间。边上还有一个单间，喝多了可以上
里面小酣片刻。
LONG
	);

	set("exits", ([
		"up":"/d/wiz/meeting",
		"east":__DIR__"gonggao",
		"west" : __DIR__"xiuxishi",
		"down" : __DIR__"yinghao",
	]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/laotou" : 1,
]));
set("no_fight",1);


	setup();
}
int valid_leave(object who,string dir)
{
	if(dir!="up")	return ::valid_leave(who,dir);
	if(! wizardp(who))
		return notify_fail("只有巫师才能上去。\n");
	return ::valid_leave(who,dir);
}

