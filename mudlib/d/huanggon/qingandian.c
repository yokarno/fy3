// Room: /d/huanggon/qingandian
inherit ROOM;

void create()
{
  set ("short", "钦安殿");
  set ("long", @LONG
钦安殿建于明朝,殿中摆放元始天尊的神像,乃是一道教所在,雕梁画
栋,神像之前一只大铁香炉,不过看来并无多大用处,因为清满人信佛,多有
因此出家的.西边是千秋亭,东是万春亭.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"qianqiutin",
  "east" : __DIR__"wanchuntin",
  "north" : __DIR__"shenwumen",
  "south" : __DIR__"yuhuayuan2",
]));
  setup();
}
int valid_leave(object ob,string dir)
{
   if (!userp(ob)&&dir=="south"&&ob->query("home")==1) 
   return notify_fail("侍卫想了想道:还是保卫皇上去.\n");
   return ::valid_leave(ob,dir);
}