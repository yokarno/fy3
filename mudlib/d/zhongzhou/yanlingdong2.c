//yanglingdong2

inherit ROOM;

void create()
{
  set ("short", "延陵东路");
  set ("long", @LONG
这是中州的一条老路延陵路。它东西横跨中州城。再往东就可以出
中州城了。因到了城东了比较偏僻，这里的本地人大都把房子租给外地
的人住了。
LONG);

set("outdoors","/d/zhongzhou");

  set("exits", ([
    "northwest" : __DIR__"yanlingdong1",
    "east"  : __DIR__"dongmeng",
]));
	set("objects",([
		__DIR__"npc/gugong":1,
		__DIR__"npc/laogugong":2,
	]));

         setup();
        replace_program(ROOM);
}
