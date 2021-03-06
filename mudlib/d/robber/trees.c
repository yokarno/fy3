// Room: /d/robber/trees.c

inherit ROOM;

void create()
{
	set("short", "松柏林");
	set("long", @LONG
稀疏的一片树林,脚下铺了一层树叶,大多数树的叶子早已掉光了,在一
棵柏树顶上,一个老大的鸟巢摇要欲坠,旁边的横枝上孤独地站着一只乌鸦.
向东看去,是一片坟场,
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"trees2",
  "west" : __DIR__"trees1",
  "east" : __DIR__"tomb",
]));
set("outdoors","/d/jiangnan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wuya.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
