// xiaoyaoyou.c ��ң��
// modified by Venus Oct.1997
// written by Xiang

inherit SKILL;

string *dodge_msg = ({
    "$nһ�������ѵ�ˮ���������$N��һ�С�\n",
    "$n�������һ�ݣ�ʹ��һ�С�ϸ���ɷ��ơ����ܹ���$N�Ĺ�����\n",
    "$nʹ�����黳���ȡ���ǡ�ö����$N�Ĺ��ơ�\n"
//    "����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
//    "$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
//    "����$n����һ�ã�$N��һ�����˸��ա�\n",
//    "ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
//    "$n����΢�Σ��о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage)
{
	return (usage == "dodge");
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if((int)me->query("kee")<40)
   return notify_fail("�������̫���ˣ���������ң�Ρ�\n");
	me->receive_damage("kee",30);
    return 1;
}

int power_point()	{	return 1.25;	}