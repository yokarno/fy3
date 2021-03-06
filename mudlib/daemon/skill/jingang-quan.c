// jingang-quan.c -大金刚拳

inherit SKILL;

mapping *action = ({
([	"action" : "$N盘膝而坐，二手合十，一式「莲花座」，双拳蓄势而发，击向$n的$l",
	"damage":60,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一式「烈火锥」，双掌轮流下击，拳势如焰，吡啪爆响",
	"damage":80,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N腾空飞起，一式「八方雨」，双手双腿齐出，令$n无可躲藏",
	"damage":100,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双掌虚含，掌缘下沉，一式「掌心雷」，缓缓向$n推出",
	"damage":120,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一臂前伸，一臂后指，一式「五指山」，攻向$n的身前身后",
	"damage":140,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一式「观音渡」，两手十指虚点$n的全身三十六道要穴",
	"damage":160,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N两目内视，双手内笼，一式「天龙唱」，四面八方响起震人心魄的龙吟",
	"damage":180,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N似笑非笑，双拳无形无定，一式「如来笑」，骤然击向$n的前胸",
	"damage":200,
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return  usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练大金刚拳必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("你的混元一气功火候不够，无法学大金刚拳。\n");
	if ((int)me->query("max_force") < 50)
		return notify_fail("你的内力太弱，无法练大金刚拳。\n");
	return 1;
}


mapping query_action(object me, object weapon)
{
                        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练大金刚拳。\n");
	me->receive_damage("kee", 20);
	me->add("force", -6);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jingang-quan/" + action;
}
