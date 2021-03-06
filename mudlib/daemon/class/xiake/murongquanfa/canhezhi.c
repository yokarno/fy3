// zhen.c 太极拳「震」字诀

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("参合指只能对战斗中的对手使用。\n");

		
	if( (int)me->query_skill("murongquanfa",1)<20)
	return notify_fail("你的慕容拳法不够娴熟，不会使用「参合指」。\n");
	if( (int)me->query_skill("murongxinfa",1)<20)
	return notify_fail("你的慕容心法不够深厚，不会使用「参合指」。\n");
			
	if( (int)me->query("force",1)<100)
	return notify_fail("你现在内力太弱，不能使用「参合指」。\n");
			
	msg = CYN "$N突然伸出左手，用出「参合指」向$n连点数下。\n"NOR;

	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
	me->start_busy(3);
		target->start_busy(random(3));
		
	damage= (int)me->query_skill("murongquanfa",1);
		
		damage = damage/2 + random(damage);
		
	target->receive_damage("kee",damage);
	target->receive_wound("kee",damage/3);
	me->add("force",-damage/10);
	if( damage < 20 ) msg += HIY"结果$n被$N点中了一指，闷哼一声。\n"NOR;
	else if( damage < 40 ) msg += HIY"结果$n被$N连点两指，「嘿」地一声退了两步。\n"NOR;
	else if( damage < 80 ) msg += RED"结果$n被$N重重的连点数指，有如受到数记重锤，连退了五六步！\n"NOR;
	else msg += HIR"结果$n被$N的「参合指」指力穿心，眼前一黑，身子向后飞出丈许！！\n"NOR;
		
	} else 
	{
		me->start_busy(1);
		msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
