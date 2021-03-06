#include <ansi.h>

inherit SSERVER;

mapping *msg = ({
        (["action": "$N使出随缘三剑中第一招「剑扫长虹」，$w幽灵般陡然刺向$n$l",
        "damage": 270,
        "force": 200,
        "damage_type": "刺伤",
        ]),
        (["action": "$N使出随缘三剑中第二招「剑转乾坤」，$w幻出一道紫光刺向$n$l",
        "damage": 290,
        "force": 260,
        "damage_type": "刺伤",
        ]),
        (["action": "$N使出随缘三剑中第三招「剑霸天下」，人影和着剑光风一般击向$n",
        "damage": 330,
        "force": 300,
        "damage_type": "刺伤",
        ]),
});

int perform(object me, object target)
{
        object weapon;
        int i, damage, lvl;

        if(!living(me)) return 0;
        if(me->is_busy())
                return notify_fail("你正忙着呢，无法运用剑法。\n");
        if(! weapon = me->query_temp("weapon")) 
                return notify_fail("只有使用剑的时候才能用特殊剑法。\n");
        if(weapon->query("skill_type") != "sword")
                return notify_fail("只有使用剑的时候才能用特殊剑法。\n");

        if((lvl = me->query_skill("songshan-jianfa", 1)) < 50)
                return notify_fail("你的嵩山剑法还不够高，无法使用「随缘三剑」。\n");

        if(!target) target = offensive_target(me);

        if(!target
        || !target->is_character()
        || !me->is_fighting(target))
                return notify_fail("「随缘三剑」只能对战斗中的对手使用。\n");

        if(target->is_busy())
                return notify_fail(target->name() 
                                + "目前正自顾不暇，放胆攻击吧！\n");
//      weapon = me->query_temp("weapon");

        me->start_busy(1);

        damage = lvl / 2;
        me->add_temp("apply/attack", lvl);
        me->add_temp("apply/damage", damage);
        for(i=0;i<3;i++)
        {
                me->set("actions", msg[i]);
                COMBAT_D->do_attack(me, target, weapon);
        }
        me->reset_action();
        me->receive_damage("kee", damage / 2);
        me->add_temp("apply/attack", -lvl);
        me->add_temp("apply/damage", -damage);

        return 1;
}
