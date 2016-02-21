// Room: /d/city2/shancharoad
inherit ROOM;

void create ()
{
  set ("short", "官道");
  set ("long", @LONG
此处是个三叉路口，官道通到此处也就到了尽头。西北通往塞外蒙
古，东北则是冰雪覆盖的燕京。
LONG);

  set("outdoors", "/d/city2");
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"guandao2",
  "northwest":"/d/menggu/huanglu1",
"northeast":"/d/yanjing/to_yj",
]));

  setup();
}
