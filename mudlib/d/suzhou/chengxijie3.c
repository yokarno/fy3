// Room: /d/suzhou/chengxijie3.c

inherit ROOM;

void create()
{
	set("short", "城西街");
	set("long", @LONG
好一个热闹的街道，来来往往尽是行人。卖杂货的小贩、打巴式卖艺的艺人、
前来游玩的路人、偷鸡摸狗的地痞，真是集天下各式各样的人物。你的脑海中
不时闪现出“上有天堂，下有苏杭”这句话。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "suzhou");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"chengxijie2",
  "south" : __DIR__"gongyuan",
  "east" : __DIR__"chengzhong",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wantong" : 1,
]));

	setup();
	replace_program(ROOM);
}
