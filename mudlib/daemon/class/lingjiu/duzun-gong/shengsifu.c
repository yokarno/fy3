#include <ansi.h>
inherit SSERVER;
int exert(object me, object target)
{
        string msg;       
        if (me->query("family/family_name")!="灵鹫宫")
                return notify_fail("你不是灵鹫宫的弟子，不能使用生死符！\n");
        if (!target)target=offensive_target(me);
        if (!target||!target->is_character() || !me->is_fighting(target))
                return notify_fail("「生死符」只能对战斗中的对手使用。\n");
        if ((int)me->query_skill("duzun-gong",1) <80)
                return notify_fail("你[唯我独尊功]功夫还不到家，使不出「生死符」。\n");
        if ((int)me->query("force")<200)
                return notify_fail("你的内力不够。\n"); 
        message_vision(HIR"$N右掌暗运内功，逆转真气，使了出逍遥派的绝学生死符法，向$n飕飕飕连拍三掌!\n" NOR,me,target);      
        me->start_busy(2);
        me->add("force",-200);                
        if (random(me->query("combat_exp"))>(int)target->query("combat_exp")/3*2 ) {                                   
                target->start_busy(1);                    
COMBAT_D->do_attack(me,target);
COMBAT_D->do_attack(me,target);
COMBAT_D->do_attack(me,target);
                message_vision(HIC"$n只觉寒风袭体,惊慌中无处可躲，被$N的掌风击中!\n"NOR,me,target);             
                target->apply_condition("shengsifu_poison",1+random(20));
                tell_object(target,HIB"猛地里你肩头，小腹，背心三处微微一寒，便如碰上一片雪花。\n"NOR); 
        } else {        
                message_vision(HIC"可是$n看破了$N的招式,倒纵丈许躲开了生死符，但也被吓出一身冷汗。\n"NOR,me,target);
                me->start_busy(3);
        }
        return 1;
}
