//xiaoxiang
  

inherit ROOM;

void create()
{
	set("short", "小巷");
	set("long", @LONG
一条小巷不知通到何处，两边高墙院落，更显的小巷的昏暗。谁也不
想在这种地方多呆，你只想往前走走，看看前面到底通到哪里。 
LONG
	);
set("outdoors","/d/zhongzhou");

	set("exits", ([
		"east" : __DIR__"wendingbei1",
		"west" : __DIR__"xiaoxiang1",
		
	]));
	set("objects",([
		__DIR__"npc/dipi":1,
	]));

	setup();
	replace_program(ROOM);
}

