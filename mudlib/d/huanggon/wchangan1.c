// Room: /d/huanggon/wchangan1
inherit ROOM;

void create()
{
  set ("short", "西长安街");
  set ("long", @LONG
西长安街是条东西走向的街道,因为正当城中,两边店铺很多,招牌林
立,游人不绝,街道的南边是家客栈,来京都的人多到此处投宿.西边是西铁
门,通向回族地区.
LONG);

  set("outdoors", "/d/huanggon");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"xitiemen",
  "south" : __DIR__"jingdukezhan",
  "east" : __DIR__"wchangan",
]));
  setup();
  replace_program(ROOM);
}
