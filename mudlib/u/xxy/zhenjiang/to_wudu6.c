// By Mr.music  zhenjiang's 山路

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
	这里是一条山路，不知通向哪。。
LONG
        );

        set("valid_startroom", 1);
        set("no_sleep_room",1);

   //   set("item_desc", ([
   //           "chuan" : "这些小船也许可以上。\n",
   //             "船":     "这是些小船，好象没人管理，也许可以自己划.\n",    
   //                    ]));
        set("objects", ([
         //       __DIR__"npc/shusheng" : 1,
        ]));

        set("exits", ([
                "northeast" : __DIR__"to_wudu5" ,
                "south" : __DIR__"to_wudu7",
//          "west" : "/d/lake/road5" ,   
        ]));

        setup();
//      "/obj/board/mainboard"->foo();
}

