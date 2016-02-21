// Room: /d/chengdu/cdta.c

inherit ROOM;

void create()
{
	set("short", "百花潭");
	set("long", @LONG
潭面平静得象一块明晃晃的镜子，倒映着红瓦绿树；潭面的几
片荷叶，又给潭水增添了几分姿色。往北就是浣花溪。
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/youke" : 2,
]));
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"cdcc",
  "west" : __DIR__"caotang",
]));
	set("outdoors", "chengdu");

	setup();
	replace_program(ROOM);
}
