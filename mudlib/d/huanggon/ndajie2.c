// Room: /d/huanggon/ndajie2
inherit ROOM;

void create()
{
  set ("short", "北大街");
  set ("long", @LONG
北大街横贯东西,从皇宫的后门穿过.这条街道位于京城的北面,店铺
较少,所住的都是些穷苦人.来往的人多面带菜色.街道北面是家茶馆,里边
时不时暴起两声喝采.
LONG);

  set("outdoors", "/d/huanggon");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"ndajie3",
  "east" : __DIR__"guangchang1",
  "north" : __DIR__"chaguan",
]));
  setup();
  replace_program(ROOM);
}
