// Room: /d/kaifeng/yushi.c

inherit ROOM;

void create()
{
	set("short", "浴室");
	set("long", @LONG
每年的五月初五日，寺中都会用清水清洗那些佛像。称为『洗佛』。
用洗佛的残水从人的头顶浇灌而下，称沐佛恩。虽然水很脏，但大家
都抢了来淋水。当然达官贵人是不会当众狼狈的，所以里面辟有专门
的小浴室供他们使用。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhangzao.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"zhongyuan",
  "west" : __DIR__"yushi2",
]));

	setup();
	replace_program(ROOM);
}
