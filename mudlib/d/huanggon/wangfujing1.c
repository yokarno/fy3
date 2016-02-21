// Room: /d/huanggon/wangfujing1
inherit ROOM;

void create()
{
  set ("short", "王府井");
  set ("long", @LONG
王府井的店铺在京城最多,也是生意人最多的地方,全国各地的商贩
都把货物弄到此地交易,街道两边的招牌一个接一个,排得密密麻麻的.东
面是条东西向的街道,就是东长安街.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"echangan",
  "north" : __DIR__"wangfujing2",
  "south" : __DIR__"wangfujing",
]));
  set("outdoors", "/d/huanggon");
  setup();
  replace_program(ROOM);
}
