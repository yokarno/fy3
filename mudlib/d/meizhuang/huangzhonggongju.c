// Room: /d/suzhou/meizhuang/huangzhonggongju.c

inherit ROOM;

void create()
{
	set("short", "黄钟公居");
	set("long", @LONG
一进屋内，便闻到一股檀香。东面的墙壁上挂着一杆玉箫通身碧绿，
竟是上好的翠玉。室内檀木椅上端坐着一位六十来岁的老者，骨瘦如柴，
脸上肌肉都凹了进去，直如一具骷髅。一名青衣小童立于下首。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"enter":__DIR__"neishi",
	"south":__DIR__"chuangongfang4",
]));
	set("no_clean_up",0);
	set("objects",([
		__DIR__"npc/huangzhonggong":1,
		__DIR__"npc/qingyixiaotong":1,
]));
	setup();
	replace_program(ROOM);
}
