// bye enter

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "温记钱庄");
        set("long", @LONG
这里是城里最有名的钱庄--温记钱庄，利息虽低但决不拖欠。
听说主人温老板是曾经在江湖中很有名气的任务，流氓土匪一般
都不来这找麻烦。所以这里一向是生意很好。
LONG
        );

        set("exits", ([ 
                "east" : __DIR__"chunxilu2",
        ]) );
        set("objects", ([
                __DIR__"npc/wenlaoban": 1,
                   ]));

        setup();
}

int valid_leave(object me, string dir)
{
        tell_object(this_player(),WHT "你拍了拍口袋，叹了口气，走出了钱庄. \n"NOR,this_player());
        return 1;
}
