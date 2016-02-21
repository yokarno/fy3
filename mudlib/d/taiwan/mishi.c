// Room: /d/taiwan/mishi
inherit ROOM;
int have_sword=1;
void create ()
{
  set ("short", "密室");
  set ("long", @LONG
一间大理石砌成的房间,四壁雕刻着天上地下各类神魔,一道灵泉从 
壁顶滴下来,落在石室中间的一个四方水池(chi)中.池的四周插着九把剑 
其中一把看上去特别的沉重. 
LONG);

  set("item_desc", ([ /* sizeof() == 2 */
  "chi" : "池水很清澈,如果你饥渴的话,不妨喝几口. 
        (drink water) 
",
  "剑" : "九把剑式样各自不同,其中八把都发出青幽的光,一看而知乃是神兵 
利器,只是中间的一把,却黑沉沉的一点不起眼,不知能不能拔起来. 
         (ba sword) 
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"boss",
]));
set("valid_startroom",1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/master.c" : 1,
//	"/obj/money/gold.c" : 2,
]));

  setup();
}
void init()
{
   add_action("do_drink","drink");
   add_action("do_ba","ba");
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
int do_ba(string str)
{
   object ob,ob1;
   ob=this_player();
   if (!ob||environment(ob)!=this_object()) return 0;
   if (str!="sword") return 0;
   if (have_sword==0)
    {  tell_object(ob,"地上空空如也,看来有人已经先你来过了!\n");
       return 1;
    }
  ob1=present("dongming zi",this_object());
  if ((ob1)&&(ob->query("family/family_name")!="幽冥山庄"))
  {
     message_vision("$N大喝一声:胆敢窥探我镇教之宝,去死吧你!\n",ob1);
     ob1->kill_ob(ob);
     return 1;
  }
if (ob->query("str")<21)
{  message_vision("$N抓住剑柄,用力拔得脸红耳赤,剑柄一动不动!\n",ob);
   return 1;
}
message_vision("$N伸手拔剑,大喝一声:[起],一把长剑应声破地而出!\n",ob);
clone_object(__DIR__"obj/youming")->move(ob);
have_sword=0;
return 1;
}
