// Room: /d/tianxia/1road2
inherit ROOM;

void create()
{
  set ("short", "小路");
  set ("long", @LONG
一条鹅卵石小道，从遮盖小道的树枝上飘落的树叶铺了一层。道上
时能见到点点干涸的血迹，从北面传来声声惨叫，东南方向可以通
向三分教场。
LONG);

  set("outdoors", "/d/tianxia");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"1road3",
  "southeast" : __DIR__"1road",
]));
  setup();
}
