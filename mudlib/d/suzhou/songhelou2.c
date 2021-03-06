// Room: /d/suzhou/songhelou2.c

inherit ROOM;

void create()
{
	set("short", "二楼");
	set("long", @LONG
你站在楼上四处眺望，古城美景尽收眼底。西北处虎丘山上古塔隐约可见，
微风拂面似乎送来太湖的阵阵水香。楼上摆着几张雅座，不少文人墨客土豪富商
也常来此处。跑堂的见你上得楼来，立刻满脸堆欢的迎了过来。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" :__DIR__"songhelou",
]));
	set("objects",([
		__DIR__"npc/paotang" :1,
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
