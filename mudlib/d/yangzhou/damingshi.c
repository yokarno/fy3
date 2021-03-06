// Room: /u/swordman/yangzhou/damingshi.c

inherit ROOM;

void create ()
{
  set ("short", "大名寺");
  set ("long", @LONG
这里是大明禅寺，寺门石壁刻着：淮东第一观。寺内香烟缭绕，
木鱼声声，寺内古朴典雅，庄严肃默。向西是仙人旧馆，向东就是
“栖陵塔”。正前方就是雄伟的“大雄宝殿”。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhikeseng" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"xiling",
  "north" : __DIR__"damingshi1",
  "south" : __DIR__"jiedao4",
]));
  set("light_up", 1);

  setup();
}
