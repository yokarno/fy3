// Room: /u/swordman/yangzhou/zahuopu.c

inherit ROOM;

void create ()
{
  set ("short", "杂货铺");
  set ("long", @LONG
你正走在城南引市街的中段的小杂货铺，街上人声鼎沸，车马如龙。
不时有游方郎中，算命打卦的来回游荡。这里地生意通常不太好，但老板
好象并不在意。
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"nandaj3",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/lanjinglin" : 1,
]));

  setup();
}
