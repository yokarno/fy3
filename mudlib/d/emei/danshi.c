// Room: /d/emei/danshi.c

inherit ROOM;

void create()
{
	set("short", "丹室");
	set("long", @LONG
这里是天心老人日常炼丹的地方,室中的一座炼丹炉正熊熊燃烧,有
个青衣小童拿着把蒲扇正有一搭,没一搭地扇着,据说老人所炼的天心丹
有起死回生之效,对炼武之人更是大有裨益.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"tianju",
  "north" : __DIR__"liangong",
]));

	setup();
	replace_program(ROOM);
}
