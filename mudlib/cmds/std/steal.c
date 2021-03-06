#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   string what, who;
   object ob, victim,*guards;
   int sp, dp,i;

   if( !wizardp(me) && environment(me)->query("no_fight") )
     return notify_fail("这里禁止行窃。\n");

   if( me->query_temp("stealing") )
     return notify_fail("你已经在找机会下手了！\n");

   if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
     notify_fail("指令格式：steal <物品> from <人物>\n");

   victim = present(who, environment(me));
    if( !victim) return notify_fail("你想行窃的对象不在这里。\n");
     if( victim == me ) return notify_fail("你打算行窃自己?别惹人笑掉大牙啦。\n");

guards=victim->query_temp("guarded");
        if(sizeof(guards))      {
        for(i=0;i<sizeof(guards);i++)   {
                if(! objectp(guards[i]))        guards[i]=0;
                else if( environment(victim)!=environment(guards[i]))      guards[i]=0;
                else if( guards[i]==me) guards[i]=0;
        }
        guards-=({ 0 });
        }
        if(sizeof(guards))      
                return notify_fail(victim->query("name")+"正被"+
                guards[0]->query("name")+"看守着，你无法从中拿取东西。\n");

   if( !wizardp(me) && wizardp(victim) )
     return notify_fail("玩家不能偷巫师身上的东西。\n");
    if( !wizardp(me) && victim->is_corpse() )
      return notify_fail("尸体上的东西直接用 get 指令。\n");

   if( !ob = present(what, victim) ) {
     object *inv;
     inv = all_inventory(victim);
     if( !sizeof(inv) )
        return notify_fail( victim->name() + "身上看起来没有什么值钱的东西好偷。\n");
     ob = inv[random(sizeof(inv))];
   }
   sp = (int)me->query_skill("stealing",1) * 5 +((int)me->query("kar")+(int)me->query("age"))*2
     - (int)me->query("thief") * 20;
   if( sp < 1 ) sp = 1;
   if( me->is_fighting() ) {
     sp /= 2;
     me->start_busy(3);
   }
   dp = ((int)victim->query("sen")+(int)victim->query("age")+(int)victim->query_kar())*2+(int)ob->weight()/25;
   if( victim->is_fighting() ) dp *= 10;
   if( ob->query("equipped") ) dp *= 10;

   write("你不动声色地慢慢靠近" + victim->name() + "，等待机会下手 ...\n\n");

   me->set_temp("stealing", 1);
   call_out( "compelete_steal", 3, me, victim, ob, sp, dp);

   return 1;
}

private void compelete_steal(object me, object victim, object ob, int sp, int dp)
{
        if(!me || !victim) return;
   me->delete_temp("stealing");

   if( environment(victim) != environment(me) ) {
     tell_object(me, "太可惜了，你下手的目标已经走了。\n");
     return;
   }

        if(!ob) {
     tell_object(me, "你要偷的东西不见了。\n");
     return;
          }   // mon 8/31/97
      if (ob->query("no_steal"))  {
      tell_object(me,"你摸到一"+ob->query("unit")+ob->name()+",却发现拿不起来.\n");
      return;
      }

   if( !living(victim) || (random(sp+dp) > dp) ) {
     if( !ob->move(me) ) {
        tell_object(me, "你摸到一" + ob->query("unit") + ob->name() 
          + "，可是对你而言太重了，不得不放弃。\n");
        return;
     }
     tell_object(me, HIW "得手了！\n\n" NOR);
     tell_object(me, "你成功地偷到一" + ob->query("unit") + ob->name() + "！\n");
     if( living(victim) )
        me->improve_skill("stealing", random(me->query("int")));
     if( random(sp) < dp/2 )
        message("vision", "你看到" + me->name() + "鬼鬼祟祟地从"
          + victim->name() + "身上偷走了一" + ob->query("unit")
          + ob->name() + "！\n", environment(me), ({ me, victim }) );
   } else {
     if( random(sp) > dp/2 ) {
        tell_object(me, victim->name() + "不经意地一转头，你急忙将手缩了回去！\n"
          "还好，没有被发现。\n");
        return;
     }
     tell_object(me, HIR "糟糕！你失手了！\n\n" NOR);
     message_vision("$N一回头，正好发现$n的手正抓着$P身上的" + ob->name() + "！\n\n"
        + "$N喝道：「干什么！」\n\n", victim, me);
     me->improve_skill("stealing", 1, 1);
     if( userp(victim) ) victim->fight_ob(me);
     else victim->kill_ob(me);
     me->fight_ob(victim);
     me->start_busy(5);
     me->add("thief", 1);
   }
}

int help(object me)
{
write(@HELP
指令格式 : steal <某物> from <某人>

这个指令让你有机会偷到他人身上的东西。成功了, 当然你就能获得
该样物品。可是, 马有失蹄, 人总有失风的时候, 当你失败时当然就
得付出代价, 至于是什么代价......靠你自己去发掘罗。
HELP
    );
    return 1;
}
