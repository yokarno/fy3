// Room: /u/swordman/yangzhou/bingying2.c
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "兵营");
  set ("long", @LONG
这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操练有
的独自在练功，有的坐着、躺着正在休息。南墙下坐着主帅，不动声色地巡
视着四周。看到你进来，他们全都向你包围了过来，形势看来不太妙。北边
有一个铁门。 
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"bingqiku",
  "south" : __DIR__"bingying",
]));
       create_door("northwest", "铁门", "southeast", DOOR_CLOSED);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/guanbing" : 3,
  __DIR__"npc/duan" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
                dir == "northwest")
                return notify_fail("官兵拦住了你的去路。\n");
        return ::valid_leave(me, dir);
}

