// Room: /u/swordman/yangzhou/beijie.c

inherit ROOM;

void create ()
{
  set ("short", "北大街");
  set ("long", @LONG
这里的路相当的宽，能容好几匹马车并行，长长的道路通向北方。远
远的能看到北面的北城门。南边是城中心，游人相当的多。东边是城
中有名的是家木器铺。
LONG);

  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaofan" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"muqipu",
  "north" : __DIR__"beijie1",
  "south" : __DIR__"guangchang",
]));
  set("outdoors", "/u/swordman");

  setup();
}
