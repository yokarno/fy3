// Room: /d/suzhou/kezhan.c

inherit ROOM;

void create()
{
	set("short", "悦来客栈");
	set("long", @LONG
苏州是江南名城，南来北往的客商着实不少。悦来客栈的名声则响誉江南，
不少客商都慕名而来。苏州城内的生意大都被这家客栈包揽。你一进房门，店小
二便满面笑容的迎了上来。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" :__DIR__"chengnanjie1",
		"up" :__DIR__"woshi",
]));

	set("objects",([
		__DIR__"npc/xiaoer" :1,
]));
	setup();
}
int valid_leave(object who,string dir)
{
	object npc;
	npc=present("xiao er",this_object());
	if(dir=="east")	{
		who->delete_temp("rent_paid");
		return ::valid_leave(who,dir);
	}
	if(dir=="up"&& ! (int)who->query_temp("rent_paid")
		&& objectp(npc))	{
	return notify_fail("店小二奸笑道：没付银子就想住宿，天下哪有这个道理？\n");
			}
	return ::valid_leave(who,dir);
}
