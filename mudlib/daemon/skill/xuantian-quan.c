//����ȭ��
#include <ansi.h>
inherit SKILL;

mapping *action = ({
	([  "action":       "$Nʹһ�С������пա�����׼$n��$l��������һȭ",
		"damage":50,
		"damage_type":	"����"
	]),
	 ([  "action":       "$N����$w��һ�С��������졹����$n��$l�к���ȥ",
		"weapon":	"ȭͷ",
		"damage":	100,
		"damage_type":	"����"
	]),
	([  "action":       "$N������Σ�$w��������ա���$n��$l����",
		"weapon":	"��ȭ",
		"damage":	150,
		"damage_type":	"����"
	]),
	([  "action":       "$N����һ������ȭ������ʹ�������ĺ��ǡ�$w����$n$l",
		"weapon":	"��ȭ",
		"damage":	200,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("������ȭ��������֡�\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("kee", 30);
	return 1;
}
string perform_action_file(string action)
{
return "/daemon/class/meizhuang/xuantian-quan/"+action;
}
void skill_improved(object me)
{
	if(me->query_skill("xuantian-quan",1)==20)
	tell_object(me,HIC"�������ˡ�����ָ����ָ����(xuantianzhi)\n"NOR);
}