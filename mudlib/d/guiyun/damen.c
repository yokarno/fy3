inherit ROOM;

void create()
{
        set("short", "大门");
        set("long", @LONG
面前是一座庄院，门楼不甚高大，青砖绿瓦，灰色底的匾上写
着『归云庄』三个大黑字。牌匾较为陈旧，边角处的漆皮已剥落，
露出暗黄色的木质。看来挂在那已不下二十个春秋了。
LONG );
        set("outdoors", "guiyun");

        set("exits", ([
                "enter" : __DIR__"qianyuan",
                "south" : __DIR__"matou",
        ]));
        set("objects", ([
                __DIR__"obj/jiading" : 2,
        ]));
        setup();
}



