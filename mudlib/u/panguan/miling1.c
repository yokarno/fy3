//make by temp
//ROOM: miling1.c
//99.12.20

inherit ROOM;

void create()
{
        set("short", "密林");
        set("long",@LONG
好一片茂密是森林，在这里连阳光都不能透进来，你仔细的向东
边的山脚观望，那里似乎有一个小湖，还是过去看看吧。
LONG
        );
        set("exits", ([
                "northup" : __DIR__"sanlu2",
                "eastdown" : __DIR__"xuesf"
        ]));
        setup();
        replace_program(ROOM);
}
