
inherit ROOM;
void create()
{
set("short","段誉居");
	set("long",@LONG
这是一间雅致的书房，一张书桌摆在南边靠窗处，角上
摆着一摞线装书。只见一个青年正在认真地看书。
LONG);
	set("objects",([
                "/daemon/class/dali/duanyu": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
              "south"  : __DIR__"chahua10",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

