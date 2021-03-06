// taiji-jian.c 太极剑
// cleansword 2/15/96
// Marz 5/21/96

inherit SKILL;

mapping *action = ({
([	"action" : "$N虚步提腰，一招「蜻蜓点水」，手中$w轻轻颤动，一剑剑点向$n的$l",
	"damage":120,
	"damage_type" : "刺伤"
]),
([	"action" : "$N向前跨上一步，左手剑诀，右手$w使出一式「指南针」直刺$n的$l",
	"damage":120,
	"damage_type" : "刺伤"
]),
([	"action" : "$N身形往右一挫，左手剑诀，右手$w使出一式「大魁星」刺向$n的$l",
	"damage":120,
	"damage_type" : "刺伤"
]),
([	"action" : "$N双膝下沉，右手$w使出一式「探海式」，由下而上疾刺$n的$l",
	"damage":120,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「燕子掠波」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
	"damage":120,
	"damage_type" : "刺伤"
]),
([	"action" : "$N上身往左侧一拧，一招「乌龙摆尾」，右手$w反手向$n的$l挥去",
	"damage":140,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「右拦扫」，一招「左拦扫」，剑锋平指，一气呵成横扫$n的$l",
	"damage":140,
	"damage_type" : "刺伤"
]),
([	"action" : "$N左腿提膝，手中$w斜指，一招「宿鸟投林」刺向$n的$l",
	"damage":140,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「青龙出水」，$w自下而上划出一个大弧，平平地挥向$n的$l",
	"damage":140,
	"damage_type" : "刺伤"
]),
([	"action" : "$N使出「三环套月」，$w划出三个圆圈，剑锋直出，绵绵不断划向$n的$l",
	"damage":140,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「风卷荷叶」，$w轻灵地划出几个圆弧，迅速地向$n的$l挥去",
	"damage":160,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「虎抱头」，$w划出一个左低右高的大弧，斜斜地斩向$n的$l",
	"damage":160,
	"damage_type" : "刺伤"
]),
([	"action" : "$N使出「狮子摇头」，$w由右向左划出一个大８字，将$n圈在其中",
	"damage":160,
	"damage_type" : "刺伤"
]),
([	"action" : "$N左脚踏实，右脚虚点，一招「仙人指路」，右手$w带着一团剑花，逼向$n的$l",
	"damage":160,
	"damage_type" : "刺伤"
]),
([	"action" : "$N轻轻跃起，一招「野马跳涧」，$w在半空中化为一圈银芒，落向$n的$l",
	"damage":160,
	"damage_type" : "刺伤"
]),
([	"action" : "$N两腿前箭后弓，一招「射雁式」，右手$w直刺$n的$l",
	"damage" : 185,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「小魁星」，身形往左一挫，左手剑诀，右手$w平平地向$n的$l挥去",
	"damage" : 187,
	"damage_type" : "刺伤"
]),
([	"action" : "$N猱身扑上，一招「白猿献果」，手中$w斜斜地向$n的$l挥去",
	"damage" : 189,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「迎风掸尘」，$w看似随意地一挥，$n却陡觉一股劲气迎面袭来。",
	"damage" : 191,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「顺水推舟」，$w自上而下划出一个大弧，平平地向$n的$l挥去。",
	"damage" : 193,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「流星赶月」，$w疾刺$n的$l",
	"damage" : 195,
	"damage_type" : "刺伤"
]),
([	"action" : "$N突然盘蹲下身来，一招「海底捞月」，$w自下而上地向$n的$l挥去",
	"damage" : 197,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「挑帘式」，$w自下而上徐徐划出一个大弧，平平地向$n的$l挥去",
	"damage":200,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「黄蜂入洞」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
	"damage" : 202,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「大鹏展翅」，身形跃起，右手$w刺向$n的$l",
	"damage" : 206,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「车轮剑」，$w化作一片银盘，平平地向$n的$l卷去",
	"damage" : 220,
	"damage_type" : "刺伤"
]),
([	"action" : "$N左脚轻点地面，身形往前一扑，一招「天马行空」，$w向$n的$l挥去",
	"damage":200,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「风扫梅花」，身体跃在半空，手中$w扫向$n的$l",
	"damage" : 230,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「却步抽剑」，左脚跃步落地，$w回抽，反手勾向$n的$l",
	"damage" : 240,
	"damage_type" : "刺伤"
]),
([	"action" : "$N右腿半屈般蹲，一招「如封似闭」，剑尖虚指，转身撩向$n的$l",
	"damage" : 250,
	"damage_type" : "刺伤"
]),
([  "action" : "$N回身拧腰，右手虚抱，一招「拨云瞻日」，$w中宫直进，刺向$n的$l",
	"damage" : 260,
	"damage_type" : "刺伤"
]),
});

int valid_learn(object me)
{
        object ob;

                if( (int)me->query_skill("taiji-shengong", 1) < 20 )
			return notify_fail("你的太极神功火候不足，无法练太极剑法。\n");

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练太极剑法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return
notify_fail("你的内力或气不够，没有办法练习太极剑法。\n");
        me->receive_damage("kee", 20);
        me->add("force", -3);
        write("你按著所学练了一遍太极剑法。\n");
        return 1;
}

string perform_action_file(string action)
{
       return __DIR__"taiji-jian/" + action;
}
int power_point()	{	return 1.75;	}
int hard_point()	{	return 3;	}
