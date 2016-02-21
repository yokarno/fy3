// Room: /u/swordman/yangzhou/chaguan
inherit ROOM;

void create ()
{
  set ("short", "扬州茶馆");
  set ("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌一字 
排开，坐满了客人，或高声谈笑，或交头接耳。这里就是扬州最大的一个茶馆
了，南来北往的江湖人物差不多都要到这里来座一座。你要想打听江湖掌故和
谣言这里是个好所在。 在墙角还放着一个大水缸(pot)。
LONG);

  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/aqingsao" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"nandaj2",
]));
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  setup();
}
void init()
{
    add_action("do_drink", "drink");
    add_action("do_drink", "he");
}

int do_drink(string sss)
{

object ob;
ob=this_player();
if ((sss!="pot")&&(sss!="shui")&&(sss!="water"))
  {
   return 0;
  }
if(ob->query("water")> ((int)ob->query("str")-10)*10+150 )
 {
  tell_object(ob,"你喝足了还要喝啊！\n");
  return 1;
 } 
else
 {  
 say(ob->query("name")+"趴在水缸边，一口气喝了够饱. \n");
 tell_object(ob,"你趴在水缸边，一口气喝了够饱. \n");
 ob->set("water",((int)ob->query("str")-10)*10+200);

  return 1;
 }

}
