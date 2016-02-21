// Room: /u/uuui/guandao2.c

inherit ROOM;

void create()
{
        set("short", "官道");
        set("long", @LONG
这是通往凝王寝殿的官道。倒不如说是一片树林更
为贴切。树林的两旁各有几座类似于“议事厅”的房子
但是除了凝王府的人以外没有人能进去了。因为树林里
面各有一座九宫八卦阵。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"huihong",
  "north" : __DIR__"workroom",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

