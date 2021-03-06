//玄天拳之天玄地冥 
// tianson
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「天玄地冥」？\n");

        if((int)me->query("force") < 200+(int)me->query("force_factor") )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("sen") < (int)me->query("max_sen")/2 )
                return notify_fail("你的精神无法集中，施用不出「天玄地冥」！\n");

	if((int)me->query_skill("xuantian-quan", 1) <40)
		return notify_fail("你的玄天拳级别还不够！\n");

        me->add("force", -200-(int)me->query("force_factor"));
        me->receive_damage("sen", 20);

	msg = HIC
"\n$N身子向后一挫，动作突然停住，脸上闪过一道玄色的光芒，双拳缓慢抬起，拳心相对，\n"
"看似慢，实则快，一晃便欺到$n的面前，无声无息的使出玄天拳之绝学--「天玄地冥」！\n\n" 
"$n只觉得一股劲气迎面而来，睁眼和呼吸都感到困难，更不用说如何招架了！\n" NOR;

        ap = me->query_skill("xuantian-quan", 1);
// + me->query_skill("parry");
        ap = ( ap * ap * ap / (4 * 400) );
// + (int)me->query("kee");
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
	dp = ( dp * dp * dp / (4 * 400) );
// + (int)target->query("kee");
	dp = dp*250 + target->query("combat_exp"); 
        if( random((ap + dp)/1000+1) <  dp/1000 ) {
		msg += HIC "谁知$n竟身居险中而不惧，身随气而急退，飘飘然落在三丈之外，毫发无损。\n\n"NOR;
	        message_vision(msg, me, target);
	} else {
                damage = (int)me->query_skill("xuantian-quan",1) / 5 +
                  (int)me->query("force") / 100 + (int)me->query("force_factor")/5 +
			(int)me->query("sen") / 400 + random((int)me->query("sen") / 200 ) +
			(int)me->query("kee") / 400 + random((int)me->query("kee") / 200 ); 
		msg += HIC "一股玄天阴凉之气直接穿透$n的身体，$n只觉得经脉凝结，血液倒流，看来内伤不轻！\n" NOR;
                        target->receive_damage("sen", me->query("eff_sen")*damage/100, me);
                        target->receive_wound("sen", me->query("eff_sen")*damage/100-
                                                 (int)target->query("max_force")/100, me);
                        target->receive_damage("kee", me->query("eff_kee")*damage/70, me);
                        target->receive_wound("kee", me->query("eff_sen")*damage/80-
                                                 (int)target->query("max_force")/100, me);
                        me->improve_skill("xuantian-quan", 1, 1);
	        message_vision(msg, me, target);
                COMBAT_D->report_status(target);
	 }

        me->start_busy(3);
        return 1;
}
