// Room: /d/taiwan/zhuanyuan.c

inherit ROOM;

void create()
{
	set("short", "庄家老屋");
	set("long", @LONG
你的面前是一栋黑沉沉的大屋子,高大的屋子依稀显现以前的辉煌. 
两扇大门已经显得十分破烂,在风中发出吱吱的响声.墙角屋檐下长满 
了茅草,随风飘舞. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/taiwan");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"chitang",
  "south" : __DIR__"tree8",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/shizi.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
