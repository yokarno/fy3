// Room: /d/yandang/guanyin8
inherit ROOM;

void create ()
{
  set ("short", "第九层");
  set ("long", @LONG
正中供奉的是一尊千手观音,仪态安祥,使人顿生慈悲之心,左边的
山壁旁有一个水池(chi),正中的善缘箱上摆着签筒,你可以问一下此处
的师傅,据说此处的签是很灵的.
LONG);

  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"guanyin7",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "chi" : "洗心泉从上面石缝中滴落到洗心池中,据说这水驱邪避魔,很有神效
不防喝一口.
",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xueshan.c" : 1,
  __DIR__"obj/gongdexiang.c" : 1,
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
if ((sss!="chi")&&(sss!="shui")&&(sss!="water"))
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
 say(ob->query("name")+"趴在水池边，一口气喝了够饱. \n");
 tell_object(ob,"你趴在水池边，一口气喝了够饱. \n");
 ob->set("water",((int)ob->query("str")-10)*10+200);

  return 1;
 }

 }
int valid_leave(object me, string dir)
{
        object ob1;
        ob1 = present("qiantong",me);
        if(ob1)
        {       message_vision("$N把签筒还给上人,走了下去\n",me);
                destruct(ob1);
}
        me->delete_temp("kick");
        me->delete_temp("oldsix_flag/money");  
         return ::valid_leave(me, dir);

}
