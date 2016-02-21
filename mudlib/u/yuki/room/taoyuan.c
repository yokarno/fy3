// Room: /u/yuki/room/taoyuan.c

inherit ROOM;

void create()
{
        set("short", "世外桃园");
        set("long", @LONG
眼前豁然开朗，这里是一个地下大溶洞，但是不知道为什么光
线很充足。四壁全是钟乳石，地上长着齐腰高的从来没见过的植物。
在郁郁葱葱的植物中间，隐约有个十分美丽的女孩子轻盈的和一只
小白猫玩耍。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"taoyuan1",
]));
        set("objects", ([
                "/u/yuki/npc/girl" : 1,
                  "/u/yuki/npc/cat" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
