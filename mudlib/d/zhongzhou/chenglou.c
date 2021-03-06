// Room: /d/zhongzhou/chenglou.c

inherit ROOM;

void create()
{
	set("short", "西城楼");
	set("long", @LONG
      不觉你已到了中州的西城门。高高的城楼看上去坚不可摧。西面有一楼梯可以上
城楼的二层。据说这里守城的将军武功不俗，而却很好比武。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/quanzhou/npc/bing.c" : 2,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"xijiao",
  "east" : __DIR__"yanling2",
  "up" : __DIR__"chenglouup",
]));
	set("outdoors", "/d/zhongzhou");

	setup();
	replace_program(ROOM);
}
