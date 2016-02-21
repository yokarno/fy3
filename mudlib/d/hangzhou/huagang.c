// Room: /d/hangzhou/huagang.c

inherit ROOM;

void create()
{
	set("short", "花港观鱼");
	set("long", @LONG
这是一个极大的水池,周边用太湖石装饰,池中数千条红鲤往来
穿梭,一条小溪流从池的一端流入,又从另一端流出园子,这就是花港
了.池周繁花锦缀,千姿百态，绚丽多姿，别有情趣。 
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mameipo.c" : 1,
]));
	set("outdoors", "/d/hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wuyuan.c",
  "south" : __DIR__"xiaolu.c",
]));

	setup();
	replace_program(ROOM);
}
