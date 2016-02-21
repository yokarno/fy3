// Room: /d/new/tianxia/stone1
inherit ROOM;

void create()
{
  set ("short", "石板路");
  set ("long", @LONG
一条平整的青石板路，一直通向北面山壁下的一个动口，两边整齐的
绿树掩映，使此地平添几分阴凉。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"outcave",
  "north" : __DIR__"1guan2",
]));
  set("outdoors", "/d/new");
  setup();
}
