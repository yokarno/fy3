// feifeng-whip.c 飞凤鞭法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":  "$N向上跃起，一招「凤凰展翅」，手中$w自下而上，击向$n的脸颊",
	"damage":50,
	"damage_type":	"刮伤"
]),
([	"action":  "$N一招「彩凤栖梧」，手中$w直绕向$n的$l",
	"damage":80,
	"damage_type":	"内伤"
]),
([  "action":  "$N一招「鸾凤和鸣」，手中$w腾空一卷，一声脆响入磬，猛地向
$n劈头打下",
	"damage":110,
	"damage_type":	"劈伤"
]),
([  "action":  "$N踏上一步，冲着$n轻佻一笑，手中$w却毫不停留，一招「游龙
戏凤」，扫向$n的$l",
	"damage":140,
	"damage_type":	"刺伤"
]),
([  "action":  "$N跃在半空，一招「龙飞凤舞」，手中$w如游龙洗空，长凤戏羽，
乱雨倾盆般分点$n左右",
	"damage":170,
	"damage_type":	"刺伤"
]),
([  "action":  "$N向前急进，手中$w圈转如虹，一招「龙凤呈祥」，罩向$n前胸",
	"damage":200,
	"damage_type":	"内伤"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if ((int)me->query_skill("kurong-changong", 1) < 20)
		return notify_fail("你的枯荣禅功火候太浅。\n");
	if ( me->query("gender") != "女性")
		return notify_fail("大老爷们学这飞凤鞭？天资不足吧。\n");
	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条长鞭才能练鞭法。\n");

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
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练飞凤鞭法。\n");
        me->receive_damage("kee",20);
        return 1;
}
