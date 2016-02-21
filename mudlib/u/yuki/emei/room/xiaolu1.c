// Room: /u/yuki/emei/xiaolu1.c

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
这里是一条弯弯曲曲的小路，通向娥眉的后山。路边杂
草丛生，路面坑坑洼洼的，走起来十分艰难。路边的杂草中
时不时的发出一两声虫鸣，让你觉得很是凄凉。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"xiaolu2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
