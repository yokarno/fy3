// By Mr.music  zhenjiang's 南街

inherit ROOM;

void create()
{
        set("short", "南街");
        set("long", @LONG
这里是镇江的南街，一直向南通往中州。

LONG
        );

        set("valid_startroom", 1);
        set("no_sleep_room",1);

   //   set("item_desc", ([
   //           "chuan" : "这些小船也许可以上。\n",
   //             "船":     "这是些小船，好象没人管理，也许可以自己划.\n",    
   //                    ]));
        set("objects", ([
                __DIR__"npc/shusheng" : 1,
        ]));

        set("exits", ([
                "north" : __DIR__"chaguan" ,
                "south" : __DIR__"to_wudu1",
        ]));

        setup();
//      "/obj/board/mainboard"->foo();
}

