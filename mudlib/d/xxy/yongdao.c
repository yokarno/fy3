// Room: /d/xxy/yongdao 
inherit ROOM; 
 
void create() 
{ 
  set ("short", "甬道");
  set ("long", @LONG
一条长长的甬道,在甬道的南北两面是两间小房间,两边的房间门上都
挂了牌子,南面是[扬级考场],而北面是[威级考场].
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"weiwu",
  "south" : __DIR__"yangwu",
  "west" : __DIR__"yongdao1",
  "east" : __DIR__"datang",
]));
  setup();
}
