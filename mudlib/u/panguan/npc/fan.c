//make by yx
//99.9.5
//qiaofu.c

inherit NPC;
#include <ansi.h>
void create()
{
 set("title",HIG"喜迎千禧"NOR);
set_name("礼物贩子",({"fanzi","fanzi"}) );
set("gender", "男性");
set("long",
     "这个贩子看起来很神秘的一样呀。(ask fanzi about 礼物)\n");
set("age", 35);
set("shen_type",1);
set("attitude", "friendly");
set("str", 25);
set("int", 25);
set("con", 30);
set("dex", 30);
  set("chat_chance", 5);
set("chat_msg", ({
      "我是快乐的礼物使者。大甩卖了，一文钱就。。。\n",
        }) );
set("inquiry",([
             "礼物" : "我可不敢坏了规矩，不能白送，你给个成本钱吧(1 coin)",
]) );
setup();
}
int accept_object(object who, object ob)
{
      object obb;
             if ((ob->query("money_id") && ob->value() == 1) && (! who->query_temp("tanxin") ==1))
      {
       message_vision("贩子眉开眼笑的对$N说：谢了，这就给你 \n", who);
     message_vision("贩子眉开眼笑的对$N说：谢了，这就给你 \n", who);
       obb = new("/u/panguan/obj/jiaozi");
     obb->move(this_player());
     message_vision("贩子对$N说:你得到了礼物了 \n", who);
         who->set_temp("tanxin",1);
     return 1;
      }
         if ((int)who->query_temp("tanxin")==1)
{
           message_vision("贩子阴笑着对$N说：如果你还想吃的话就得花200gold才能买一个了! \n", who);
           if (ob->query("money_id") && ob->value() >= 2000000)
   {
                 command("chat 恭喜「"+who->query("name")+"」也上当受骗了！\n");
            return 1;
   }
}
    else message_vision("贩子对$N说：一文钱就可以买个饺子吃,多和算呀！！\n", who);
      return 1;
}
