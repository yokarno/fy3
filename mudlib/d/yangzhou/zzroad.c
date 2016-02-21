// Room: /u/swordman/yangzhou/zzroad.c

inherit ROOM;

void create()
{
	set("short", "扬州大道");
	set("long", @LONG
这里是通往中州府的一条大道，由于离城市比较远，经常有盗
匪出没。走在大道上隐隐有一丝杀气,远远传来,令人不寒而栗。
LONG
	);
	set("light_up", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"yzroad",
  "southeast" : __DIR__"zzroad1",
]));
	set("outdoors", "/u/swordman");

	setup();
	replace_program(ROOM);
}
