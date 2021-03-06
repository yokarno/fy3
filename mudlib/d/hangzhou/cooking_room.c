// Room: /d/hangzhou/cooking_room 
inherit ROOM; 
 
void create ()
{
  set ("short", "小厨房");
  set ("long", @LONG
小屋的东,北两面贴墙是两排半高的木案,一些冒着热气的饭菜和刚洗 
净的大白菜摆在一起,案下大一排大箩筐里摆满了东西.靠西的一口大锅正 
在煮着些什么,散发诱人香气. 
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"front_yard",
]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/cooking.c" : 1,
  __DIR__"npc/obj/pot.c" : 1,
  __DIR__"npc/obj/baozi.c" : 5,
]));

  setup();
}
int valid_leave(object me, string dir)
{
	object ob;
	if (present("bao zi",me)) 
	{
		ob = present("chushi", this_object());
	if(objectp(ob)&&!userp(ob)&&living(ob))
		{
			message_vision("\n$N伸手把$n拦住说：又吃又揣,不象话吧！\n", ob, me);
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}