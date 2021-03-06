// 慕容拳法之参合指 by oldsix
//modify by ksusan 7/29/97 16:55

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
	int damage,k;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("参合指只能对战斗中的对手使用。\n");

		
	if( (int)me->query_skill("murongquanfa",1)< 50)
	return notify_fail("你的慕容拳法不够娴熟，不会使用「参合指」。\n");
	if( (int)me->query_skill("murongxinfa",1)< 50)
	return notify_fail("你的慕容心法不够深厚，不会使用「参合指」。\n");
			
	if( (int)me->query("force")<200)
	return notify_fail("你现在内力太弱，不能使用「参合指」。\n");
	if(me->query_temp("have_pfm"))
	return notify_fail("你刚展施完特殊招式，内息还没调整过来。\n");
	me->set_temp("have_pfm",1);

	msg = CYN "$N突然伸出左手，用出「参合指」向$n连点数下。\n"NOR;
	k=me->query("oldsix_flag/canhezhi");
	if(!k||k==0)	k=3;
	if(random(me->query("combat_exp"))>target->query("combat_exp")/k)	{

	target->start_busy(random(3));
	damage=(me->query_str()-target->query_con())*random(me->query_cor());
	if(damage<0)	damage=10;
	if( damage>500)	damage=500;
		
	target->receive_damage("kee",damage,me);
	target->receive_wound("kee",damage/3,me);
	me->add("force",-damage/5);
	if( (int)me->query("force")<0)	me->set("force",0);

	if( damage < 40 ) msg += HIY"结果$n被$N点中了一指，闷哼一声。\n"NOR;
	else if( damage < 60 ) msg += HIY"结果$n被$N连点两指，「嘿」地一声退了两步。\n"NOR;
	else if( damage < 120 ) msg += RED"结果$n被$N重重的连点数指，有如受到数记重锤，连退了五六步！\n"NOR;
	else msg += HIR"结果$n被$N的「参合指」指力穿心，眼前一黑，身子向后飞出丈许！！\n"NOR;
		
	} else 
	{
	me->start_busy(1);
	me->add("force",-10);
		msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
	}
	message_vision(msg, me, target);
	call_out("do_reset",3,me);
	return 1;
}

void do_reset(object me)
{
        if( !objectp(me))       return;
        if( (int)me->query_temp("have_pfm"))
                me->delete_temp("have_pfm");
}
