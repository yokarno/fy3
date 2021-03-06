#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「三连剑式」？\n");

        if(!me->is_fighting())
                return notify_fail("「三连剑式」只能在战斗中使用！\n");
         
        if(!objectp(weapon = me->query_temp("weapon"))
           ||(string)weapon->query("skill_type")!="sword")
                return notify_fail("「三连剑式」要用剑才能发挥威力。\n");

        if((int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够！\n");

	if((int)me->query("force") < 300 )
		return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < (int)(me->query("max_sen")/2) )
                return notify_fail("你的精神不足，没法子施展三连剑式！\n");

        if((int)me->query_skill("shibapan-jianfa", 1) < 30)
                return notify_fail("你的十八盘剑法级别还不够，使用这一招会有困难！\n");

        me->delete("env/brief_message");
	target->delete("env/brief_message");

message_vision(HIC"\n$N运足精神，身形一转，闪电般连续向$n攻出了三招，一剑更快一剑！\n"NOR,me,target);

        me->set_temp("QJB_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 1);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->receive_damage("sen", 15);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(2);
        return 1;
}


