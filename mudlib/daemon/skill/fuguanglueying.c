inherit SKILL;

string *dodge_msg = ({
	"只见$n一招[似来还往],双脚一前一后,似进又腿,在$n一愣间躲过了攻击。\n",
	"但是$n使出[蜻蜓点水],脚尖站地,身形东倒西歪间,破天冲起。\n",
	 "$n一招[飞黄腾达],身随意转,刹那间在原地转了七八十圈,突然往地
	 上一坐,原是转晕了,却使$N落了空。\n",
	"可是$n一个[白驹过隙],身形微侧,提气直纵,躲过$N攻击。\n",
	"却见$n使出[浮光掠影],在原地留下一个幻象,真身躲到了一边。\n",
	"$n身形一顿,[逝者如斯],身形平平掠出,在空中留下一道弧形。\n"
});

int valid_enable(string usage) { return (usage == "dodge"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 45 )
		return notify_fail("你的体力太差了，不能练浮光掠影。\n");
	me->receive_damage("kee", 35);
	return 1;
}

