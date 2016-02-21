// Room: /d/wudang/shilu1.c

inherit ROOM;

void create()
{
	set("short", "石路");
	set("long", @LONG
一条幽静的石子路，几乎见不到什么人。往西通向武当，东北方面可到苏
州、杭州、中州府等地，继续往西南走可到成都、大理。
LONG
	);
set("outdoors","/d/wudang");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"shilu2",
  "west" : __DIR__"shulin2",
  "southwest": __DIR__"road1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
