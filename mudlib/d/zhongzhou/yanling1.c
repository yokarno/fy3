//yanling1
inherit ROOM;
void create()
{
  set ("short", "延陵西路");
  set ("long", @LONG
这里就是延陵东路，是中州的一条老街。两边的房屋看上去已经很陈
旧了。路上冷冷清清的，偶尔有一两个人路过。再往前走，就能隐隐的看
见西城楼了。路北面有间杂货铺，开在这偏僻的地方，估计生意不会太好.
LONG);

set("outdoors","/d/zhongzhou");

  set("exits", ([  
    "west" : __DIR__"yanling2",
    "north" : __DIR__"zahuopu",
    "east"  : __DIR__"yanling",
]));
	set("objects",([
		__DIR__"npc/fushang":1,
		__DIR__"npc/poorman":1,
	]));
       
	 setup();
        replace_program(ROOM);
}
