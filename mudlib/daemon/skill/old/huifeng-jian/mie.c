#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

void check_fight(object me, object target, int improve);
private void remove_effect(object me, int improve);

int perform(object me)
{
      string msg;    
      object target;                               
      object weapon = me->query_temp("weapon");
      int skill;
      if( !target ) target = offensive_target(me);
     
      if( !target || !target->is_character() ||!me->is_fighting(target) )
      return notify_fail("灭剑只能在战斗中对对手使用。\n");
             
      if( (int)me->query_skill("huifeng-jian",1) < 100 )
      return notify_fail("你的回风拂柳剑不够娴熟，不会使灭剑！\n");
      if( (int)me->query_skill("emei-xinfa",1) < 100 )
      return notify_fail("你的峨眉心法等级不够，不能使用灭剑！\n");  
      
      if (!weapon || weapon->query("skill_type") != "sword"
      || me->query_skill_mapped("sword") != "huifeng-jian")
      return notify_fail("你现在无法使用「以柔克刚」提高防御力。\n");
      
      if( (int)me->query_str() < 20 )
      return notify_fail("你的臂力不够高，不能使用灭剑！\n");
      
      if( (int)me->query("max_force") < 500 )
      return notify_fail("你的内力太弱，不能使用灭剑！\n");
      
      if( (int)me->query("force") < 350 )
      return notify_fail("你的内力太少了，无法使用出灭剑！\n");   
                                                                                 
      if( me->query_temp("mie")   )
      return notify_fail("你正在使用灭剑！\n");
       
      msg = HIY"$N清啸一声，身形腾空丈许，将峨嵋绝技「灭剑」心法融入回风拂柳剑招之中，
手中软剑挽起无数剑花，$n眼花缭乱，被攻了个措手不及！\n" NOR;
      message_vision(msg, me, target);                                                                   
      skill = (int)me->query_skill("huifeng-jian", 1);

      me->add_temp("apply/defense",  skill/10);
      me->add_temp("apply/attack",   skill/10);
  
      me->start_call_out( (: call_other, this_object(), "check_fight",  me, target, skill :), 1);
      me->add("force", -200);
      me->set_temp("mie", 1);
      me->start_busy(1);
      return 1;                                                   

}

void check_fight(object me, object target, int improve) 
{ 
        object weapon;                                                                      
             
        if ( me->query_temp("mie") && !me->is_fighting(target))             
        {
                remove_effect(me, improve);
        }
        else if( target->query("kee") <= 50 && me->is_fighting(target) ) 
{
                remove_effect(me, improve);
        }
        else if( !target->is_fighting() || !me->is_fighting() 
        || !living(me) || target->is_ghost() || me->is_ghost() ) 
        {
                remove_effect(me, improve);
        }
        else if( !objectp(weapon = me->query_temp("weapon")) 
        || me->query_skill_mapped("sword") != "huifeng-jian"
        || (string)weapon->query("skill_type") != "sword" ) 
        {
                remove_effect(me, improve);
        }
        else 
        {
                call_out("check_fight", 1, me, target, improve); 
                return;
        }
        tell_object(me, HIR"你的[灭剑]已经使用过了。\n"NOR); 
}

private void remove_effect(object me, int improve)

{     
      me->delete_temp("mie");
      me->add_temp("apply/defense", -improve/10);                                                        
      me->add_temp("apply/attack", -improve/10);
      return 0;
}
