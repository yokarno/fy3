// Room: /d/suzhou/dacunlou1.c

inherit ROOM;

void create()
{
	set("short", "大春楼");
	set("long", @LONG
一股浓烈的香味扑鼻而来，你不禁皱了皱眉。地上铺着腥红的地毯，墙壁上
挂着的刺绣尽是些投怀送抱妖艳异常的美女图。迎面的楼梯口上的四个大红灯笼
随风飘荡，上书“春色满堂”。这时传来老鸨的阵阵浪笑，你不禁面红耳赤。  
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" :__DIR__"taijiannong2",
]));
	set("objects",([
		__DIR__"npc/laobao":1,
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
