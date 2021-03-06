// zhen.c 太极拳「震」字诀

#include <ansi.h>
inherit SSERVER;

mapping *action=({
	([	"action":HIC"$N突然眼中精光大盛，施展「虎爪手」右手直抓向$n的$l。"NOR,
		"damage":300,
		"damage_type":"内伤",
	]),
	([	"action":HIY"$N大喝一声，使出「虎爪手」右手划道弧线，直抓向$n的$l。"NOR,
		"damage":400,
		"damage_type":"内伤",
	]),
	([	"action":HIR"$N突然使出「虎爪手」，左手呼啸而出，直抓向$n的$l。"NOR,
		"damage":500,
		"damage_type":"内伤",
	]),

});


int perform(object me, object target)
{
	int damage,attack_power,lv;
	object weapon;
	string *limbs,limb;
	mapping act;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("虎爪手只能对战斗中的对手使用。\n");

		
	if( (int)me->query_skill("taiji-quan",1)<40)
	return notify_fail("你的太极拳不够娴熟，不会使用「虎爪手」。\n");
	if( (int)me->query_skill("taiji-shengong",1)<40)
	return notify_fail("你的太极神功不够深厚，不会使用「虎爪手」。\n");
			
	if( (int)me->query("force",1)<100)
	return notify_fail("你现在内力太弱，不能使用「虎爪手」。\n");
			
	if( (int)me->query_temp("have_pfm"))
	return notify_fail("你刚展施完特殊招式，内息还没调整过来。\n");

	me->set_temp("have_pfm",1);
	limbs=target->query("limbs");
	limb=limbs[random(sizeof(limbs))];
	weapon=me->query_temp("weapon");

	lv=me->query_skill("unarmed");
	attack_power=lv*lv*lv/3;
	attack_power+=(int)me->query("combat_exp");
	attack_power*=2;
	act=action[random(sizeof(action))];
	COMBAT_D->do_attack_now(me,target,weapon,2,act,limb,attack_power);
	me->add("force",-100);
	call_out("do_reset",5,me);
	return 1;
}

void do_reset(object me)
{
	if( !objectp(me))	return;
	if( (int)me->query_temp("have_pfm"))
		me->delete_temp("have_pfm");
}
