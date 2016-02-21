// thd:hill8.c

inherit ROOM;

void create()
{
      set("short", "山路");
	set("long", @LONG
这里已经很高了，风也很大。走在山道上，你都会有摇摇欲坠之感。
山路两旁一草一石，一花一木虽都平常，确处处显现出一派自然风光，决
不是俗世中的花红柳绿、残花败叶所能比拟的。在这里连残叶都能成为一
道风景。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 2 */
          "eastup" : __DIR__"yun_jian",
          "southdown" : __DIR__"table",
	]));
      
	set("outdoors", "thd");

	setup();
	replace_program(ROOM);
}

