#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;
        if( target != me ) return 
   notify_fail("你只能提升自身的战斗力。\n");
        if( (int)me->query("force") < 300 )     return 
notify_fail("你的内力不够。\n");
        if( (int)me->query_skill("duzun-gong",1) < 40 )     return 
   notify_fail("你的独尊功不够火候，不能加力。\n");
        if( (int)me->query_temp("lingjiu_jiali") ) return 
notify_fail("你已经在运功中了。\n");
        if ((me->query("family/family_name") != "灵鹫宫")) return
         notify_fail("你不是灵鹫宫弟子不能使用这个功法。\n");
        skill = me->query_skill("force");

        me->add("bellicosity", 100 + skill/2 );
        me->add("force", -300);
        me->add("eff_sen", -50);
        me->receive_damage("kee", skill/10);
         message_vision(HIW"左手指天，右手掐剑诀，全身骨骼一阵暴响 ...\n"NOR, me);
        me->add_temp("apply/attack", skill/4);
        me->add_temp("apply/dodge", skill/6);
        me->add_temp("apply/parry", skill/6);
        me->set_temp("lingjiu_jiali", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
        skill/4 + random(10) :), skill);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
}
void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->add_temp("apply/parry", - amount);
        me->delete_temp("lingjiu_jiali");
        tell_object(me, WHT"你的神功加力逐渐消失，恢复到原状态。\n"NOR);
}

