// hunyuan-yiqi.c 少林 混元一气功
// dts@xkx, cleansword@xkx

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	if((int)me->query_skill("force",1)<10)
	return notify_fail("你的基本内功火候还不够，无法领会混元一气功。\n");
       	if ( me->query("couple/have_couple") )
		return notify_fail("你已经破了色戒，无法再学习混元一气功！\n");

	if ( me->query("gender") != "男性" )
		return notify_fail("你非童男之体，不能练习混元一气功。\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("混元一气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"hunyuan-yiqi/" + func;
}
