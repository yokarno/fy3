// Room: /d/quanzhou/houdian.c

inherit ROOM;

void create()
{
	set("short", "后殿");
	set("long", @LONG
后殿供奉的是天后,不过当地人都称其为'妈祖',据说是保佑出海的 
人平安归来. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "northdown" : __DIR__"zhendian",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/shenxiang.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
