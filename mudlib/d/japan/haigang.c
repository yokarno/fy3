// Room: /d/japan/haigang
inherit ROOM;

void create()
{
  set ("short", "海港");
  set ("long", @LONG
面对着波涛汹涌的日本海,这个海港显得十分平静,高大的双桅木船
挤满了这片海域,大多是各类的渔船,有许多式样奇特的船只,显然是从外
国而来的.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road",
]));
  set("outdoors", "/d/japan");
  setup();
}
