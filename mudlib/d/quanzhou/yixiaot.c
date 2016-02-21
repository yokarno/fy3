// Room: /d/quanzhou/yixiaot.c

inherit ROOM;

void create()
{
	set("short", "一啸台");
	set("long", @LONG
沿山道向上,你登上一个平台,山势至此渐转平缓,眼前群山历历,在 
旁边陡峭的石壁上,鬼斧神工般的开了个石室,内壁上,是一个栩栩如生 
弥勒佛浮雕像. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/quanzhou");
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"laojun-stone",
  "southdown" : __DIR__"bixiao-stone",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yunyouseng.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
