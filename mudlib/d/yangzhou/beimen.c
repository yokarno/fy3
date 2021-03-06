// Room: /u/swordman/yangzhou/beimen.c

inherit ROOM;

void create ()
{
  set ("short", "扬州北门");
  set ("long", @LONG
这里是扬州城的北大门。向南面就到了城中，远望人山人海，往来行人车
流不绝。北面一条大路通向远方。城门下有一些执勤的兵士。时下虽
已天下太平，但一干兵将还是英姿勃勃，警惕的盯着往来人士。
LONG);

  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/d/quanzhou/npc/bing" : 3,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/taishan/yidao",
  "south" : __DIR__"beijie2",
]));
  set("outdoors", "/u/swordman");

  setup();
}
