#include <room.h>
inherit ROOM;

void create()
{
      set("short","山洞");
      set("long",@LONG
昏暗的山洞中你看到一个白衣人在那里负剑而立，口中喃喃的不知
说些什么，见你进来先是一愣，眼中闪现出一丝惊喜，但随后神色
又黯淡了下来！
LONG);
                     
                set("objects",([
         "/u/legato/npc/yunqing":1,
         ]));
           set("exits",([ /* sizeof() == 2 */
          "south" : __DIR__"hole1",
          ]));
      setup();
}

