// poqi.c 破气式
 
#include <ansi.h>
 
inherit SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, force_wound, kee_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("dugu-jiujian",1);

	if( !(me->is_fighting() ))
		return notify_fail("「破气式」只能对战斗中的对手使用。\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( skill < 90)
		return notify_fail("你的独孤九剑等级不够, 不能使用「破气式」！\n");

	if( me->query("force") < 150 )
		return notify_fail("你的内力不够，无法运用「破气式」！\n");
 
	msg = HIC "$N潜运独孤九剑「破气式」，运气贯剑使其由利返钝，毫无花俏地直刺$n的丹田。\n";
	message_vision(msg, me, target);
 
	ap = me->query_skill("sword") + skill;
	dp = target->query_skill("force") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("force",-150);
		msg = "$N运起「破气式」, $n顿时觉得眼前一花，气海穴上微微一痛，\n";
		msg += "全身真气狂泄而出！\n" NOR;

		force_wound = 300 + random(skill);
		if(force_wound > target->query("force"))
			force_wound = target->query("force");

		kee_wound = force_wound / 5;
		if(kee_wound > target->query("kee"))
			kee_wound = target->query("kee");

		target->add("force", -force_wound);
		target->add("kee", -kee_wound);
		target->add("eff_kee", -kee_wound);
		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		if(userp(me))
			me->add("force",-100);
		msg = "可是$n看破了$N的企图，立刻守紧门户，几经艰难终于还招挡开。\n"NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}
