// thd:hill7.c

inherit ROOM;

void create()
{
      set("short", "山路");
	set("long", @LONG
山路在这里在此分叉。西边是一个山崖，东边在上去就是啸天台了。
在此处生长着一棵大松树，这在桃花岛的桃红竹绿之中着实令人耳目一新
，这棵松树枝叶繁盛，树冠庞大看来有不少年的历史了。但在这海岛之上
是如何出现松树的呢，这就不得而知了。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 2 */
          "northwest" : __DIR__"chiff",
          "northeast" : __DIR__"table",    
          "southdown" : __DIR__"hill6",
	]));
      
	set("outdoors", "thd");

	setup();
	replace_program(ROOM);
}

