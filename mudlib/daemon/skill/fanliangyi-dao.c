// fanliangyi-dao.c 反两仪刀法

inherit SKILL;

mapping *action = ({
([	"action" : "$N手中$w斜指，一招「混沌一破」，反身一顿，一刀向$n的$l撩去",
	"damage":100,
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「太乙生萌」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
	"damage":150,
	"damage_type" : "割伤"
]),
([	"action" : "$N展身虚步，提腰跃落，一招「两仪合德」，刀锋化作两股斩向$n",
	"damage":200,
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「日月晦明」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
	"damage":250,
	"damage_type" : "割伤"
]),
([	"action" : "$N手中$w一沉，一招「无色无相」，双手持刃拦腰反切，砍向$n的胸口",
	"damage":300,
	"damage_type" : "割伤"
]),
([	"action" : "$N挥舞$w，使出一招「万劫不复」，上劈下撩，左挡右开，齐齐罩向$n",
	"damage":350,
	"damage_type" : "割伤"
])
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 10)
		return notify_fail("你的「紫霞神功」火候太浅。\n");
	return 1;
}


 mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练「反两仪刀法」。\n");
	me->receive_damage("kee", 25);
	return 1;
}

string perform_action_file(string action)
{
return "/daemon/class/huashan/fanliangyi-dao/" + action;
}
int power_point()       {       return 1.5;     }
int hard_point()        {       return 3;       }
