// Room: /d/new/tianxia/incave1
inherit ROOM;

void create ()
{
  set ("short", "麒麟洞内");
  set ("long", @LONG
洞中比较阴暗，能听到滴答的滴水声，离洞口不远有座石雕像，朦胧中
看不清是什么。再向深处似乎有座石桥，在阴暗的洞中发出萤萤的光。两侧
黑呼呼的，不知有多深。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/obj/qiling.c" : 1,
]));
  set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"outcave",
  "southwest" : __DIR__"incave2",
  "southeast" : __DIR__"incave3",
  "south" : __DIR__"bridge1",
]));

  setup();
}
