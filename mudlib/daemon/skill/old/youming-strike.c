inherit SKILL;

mapping *action = ({
	([	"action":		"$N突然转身,以背向$n撞去,同时右足反踢,左手掌攻向$n的$l",
		"dodge":		-5,
		"parry":		-5,
		"force":		60,
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N身形飘乎不定，双手相缚,由内而外,再外而内,变幻不定向$n击去",
		"dodge":		10,
		"parry":		-10,
		"force":		120,
		"damage_type":	"砸伤",
	]),
	([	"action":		"只见$N身形前扑,左手虚托右手,拳变指,指变掌,血掌击向$n的$l",
		"dodge":		-5,
		"parry":		10,
		"force":		80,
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N双掌一错,遥对$n,掌势一发即收,一股赤热内力扑向$n",
		"dodge":		-15,
		"parry":		10,
		"force":		60,
		"damage_type":	"灼伤",
	]),
            ([	"action":		"只见$N阴阴一笑,面上浮现一道青气,拍到$n面前的手掌陡地变为血红!",
		"dodge":		15,
		"parry":		-5,
		"force":		60,
		"damage_type":	"内伤",
	]),
            ([	"action":		"$N左手一圈,右掌从圈中击向$n的$l",
		"dodge":		-5,
		"parry":		-5,
		"force":		70,
		"damage_type":	"灼伤",
	]),
});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练幽冥血掌必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("sen", 20);
	me->receive_damage("kee", 20);
	me->add("force", -10);

	return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("xiake") + "/youming-strike/" + action;
}

