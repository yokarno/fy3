// Room: /u/xxy/room/shuzhuang
inherit ROOM;

void create()
{
  set ("short", "梳妆留月");
  set ("long", @LONG
在箭竹杜鹃丛中,有一观音岩,岩上有方型巨石,远观很象一台,右
临险壑,左与坡道拐弯处相连.传说万历皇帝之母朝山到此,见金顶即至
便在这里梳妆打扮,以表其礼佛之心.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"xixiang",
  "westup" : __DIR__"jushich",
]));
set("outdoors","/d/emei");
  setup();
  replace_program(ROOM);

}
