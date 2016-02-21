
inherit ROOM;
void create()
{
        set("short", "碧水潭畔");
        set("long", @LONG
    你来到了碧水潭畔，望眼看去，潭水如玉，深不可测。站在
    潭畔也能感到一阵阵的寒意。遥想当年光明顶上，碧水潭畔，
    黛绮丝紫衫如花，长剑胜雪，不知倾倒了多少英雄豪杰。
    现在是正午时分，太阳高挂在你的头顶正上方。
LONG
        );

        set("exits", ([
                "east" : __DIR__"huayuan",
                ]));
set("objects",([
                 __DIR__"npc/daiqisi":1,
                 ]));
        setup();
        replace_program(ROOM);
}
