// Room: /d/tianxia/sword
inherit ROOM;

void create()
{
  set ("short", "剑室");
  set ("long", @LONG
这个房间约三丈见方，一面石壁上挂着些图幅，上面是些挺剑作
刺的人形，东面的墙壁下一个兵器架上，长剑，短剑，细剑，阔剑
都摆满了，甚至还有一把石头雕凿而成的剑。四面壁上都有点点的
剑痕，
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"1guan7",
]));
  setup();
}
