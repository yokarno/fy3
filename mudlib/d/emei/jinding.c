// Room: /d/emei/jinding.c

inherit ROOM;

void create()
{
	set("short", "金顶");
	set("long", @LONG
终于登上了金顶,你胸中一畅.据说,明朱元璋的儿子朱模,赐金三
千两给五台的妙峰和尚,要其在峨眉最高处建'大额山金殿',自此,该处
以金殿而明,金顶四奇则是'破晓','云海','佛光','圣灯'.
LONG
	);
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"hongchun",
]));
	set("outdoors", "/d/emei");
	set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/miejue.c" : 1,
__DIR__"npc/huifan.c" : 1,
]));

	setup();
"/obj/board/emei_board"->foo();
	replace_program(ROOM);
}
