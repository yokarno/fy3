// Ǭ����Ų��
#include <ansi.h>
inherit SKILL;


int valid_enable(string usage) { return usage=="parry"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("��������ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}
int parry_action(object me,object target,object target_weapon,int attack_type,mapping action,string limb)
{
	object *enemy,vic;
	string msg;
	int pp,ap,i;
	if(target_weapon)	ap=target->query_skill(target_weapon->query("skill_type"));
	else	ap=target->query_skill("unarmed");
	pp=me->query_skill("qiankun-nuoyi",1);
	if(random(pp)<ap/2)	return 0;
	msg="\n"+action["action"]+"\n";
	if(target_weapon)       msg=replace_string(msg,"$w",target_weapon->query("name"));
	msg=replace_string(msg,"$l",limb);
	enemy=me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;
	i=sizeof(enemy);
	if(i==1)	{
		msg+=HIW"$n�����һ��ʩչ��Ǭ����Ų�ơ��񼼣�$N������������գ�\n"NOR;
		message_combat(msg,target,me);
		return 1;
	}
	else	{

	if(member_array(target,enemy)!=-1)	enemy-=({target});
	vic=enemy[random(sizeof(enemy))];
		msg+=HIW"$n�����һ��ʩչ��Ǭ����Ų�ơ��񼼣���$N��������������"+vic->query("name")+"��"NOR;
		message_combat(msg,target,me);
		COMBAT_D->do_attack_now(target,vic,target_weapon,2,action,limb);
		return 1;
	}
}
int power_point()
{
	return 1.5;
}
int hard_point()
{
	return 2;
}

