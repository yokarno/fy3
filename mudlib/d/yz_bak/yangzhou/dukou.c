// Room: /d/yangzhou/dukou.c

inherit ROOM;

void create()
{
	set("short", "渡口");
	set("long", @LONG
这里是通往去中州城的渡口，前面就是滚滚长江，向北就是扬州城。
江边停着些[33m小船[37m。不远处是中州大桥。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dukoulu",
  "south" : "/d/zhongzhou/daqiao",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shusheng" : 1,
]));
	set("item_desc", ([ /* sizeof() == 2 */
  "船" : "这是些小船，好象没人管理，也许可以自己划.
",
  "chuan" : "这些小船也许可以上。
",
]));
	set("no_sleep_room", 1);
	set("valid_startroom", 1);

	setup();
	replace_program(ROOM);
}
