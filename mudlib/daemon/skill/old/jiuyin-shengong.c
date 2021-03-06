inherit FORCE;

mapping *action = ({
        ([      "action":
"$N使出一招「天寒地冻」，一股至阴真气击向$n的$l",
                "force":                300,
        "dodge" : 0,
                "damage_type":  "内伤"
        ]),
        ([      "action":
"$N使出一招「幽谷游魂」，一股至阴真气击向$n的$l",
                "force":                500,
        "dodge" : -5,
                "damage_type":  "内伤"
        ]),
        ([      "action":
"$N使出一招「石破天惊」，双掌缓缓前推，一股强烈的至阴真气击向$n的$l",
                 "force":                700,
        "dodge" : -10,
        "damage_type" : "瘀伤"
        ]),
        ([      "action":
"$N使出一招「人鬼殊途」，左手遮面，右手朝天，化作强大的鬼气扑向$n的$l",
                "force":                1000,
        "dodge" : -15,
        "damage_type" : "瘀伤"
        ]),
});
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;
        int force;

        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
              if( random(4*(me->query_skill("jiuyin-shengong"))) > (damage_bonus ))
                 {
                        victim->receive_wound("kee", (damage_bonus + foo));
                        victim->receive_wound("gin", (damage_bonus + foo));
                        force = victim->query("force");
                        victim->set("force", 100);
                        me->add("neili",force-random(10)-1);
                        return
"$N的九阴神功摧毁了$n的真元！！！！\n";
                }
        }
        return foo;
}

int valid_enable(string usage) 
{ 
return
        usage=="unarmed" ||
        usage=="parry"||
        usage=="force";
}


int valid_learn(object me)
{
        int lvl = (int)me->query_skill("jiuyin-shengong", 1);
                            
        if ( me->query("gender") == "无性" )
                return notify_fail("以公公无根无性之身，练九阴神功容易走火入魔！\n");
       if ( me->query("gender") == "无性" && lvl > 49)
                 return notify_fail("你无根无性，阴阳不调，难以领会高深的九阴神功。\n");
        if ((int)me->query_skill("force", 1) < 30)
                return notify_fail("你的基本内功火候还不够，无法领会九阴神功。\n");
        if ( me->query_skill("taiji-shengong",1)
        || me->query_skill("xiuluo-force",1)
        || me->query_skill("suiyu-force",1)
        || me->query_skill("kunlun-xinfa",1)
        || me->query_skill("xiantian-force",1)
        || me->query_skill("xuantian-neigong",1)
        || me->query_skill("xiake-shengong",1)
        || me->query_skill("murong-xinfa",1)
        || me->query_skill("tianlong-xinfa",1)
        || me->query_skill("taiji-shengong",1)
        || me->query_skill("bahuang-gong",1))
             return notify_fail("九阴神功是最霸道的内功心法，你不先散了别派武功，怎能学九阴神功？！\n");
        return 1;

if ((int)me->query("max_force") < 500)
                return notify_fail("你的内力不够。\n");
     if ((int)me->query("combat_exp") < 100000)
                return notify_fail("你的能力还没达到学九阴神功的地步。 \n");
         if ((int)me->query_skill("daoxuexinde") < 120)
            return notify_fail("九阴神功是道家练气的无上秘诀，你的道学还不够。 \n");
        return 1;
}
int practice_skill(object me)
{
        return 
notify_fail("九阴神功只能用学的，或是从运用(exert)中增加熟练度。\\n");

}

int effective_level() { return 21; }

string *absorb_msg = ({
        "$n身体虚转，双手微划，无孔不入的九阴神功笼罩全身。\n",
        "$n施展出九阴神功，身体变得缥缈不定。\n",
        "$n身型微展，九阴神功有如铜墙铁壁。\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string *unarmed_parry_msg = ({
        "$n衣衫澎湃，内力汩汩，$N根本不可近身。\n",
        "$n长袖一甩，一股大力将$N送出丈外。\n",
        "$n施展出「日月无辉」，轻描淡写的化解了$N的攻势。\n",
});
string *parry_msg = ({
        "$n衣衫澎湃，内力汩汩，$N根本不可近身。\n",
        "$n长袖一甩，一股大力将$N送出丈外。\n",
        "$n施展出「九阴至尊」，轻描淡写的化解了$N的攻势。\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
string exert_function_file(string func)
{
        return __DIR__"jiuyin-shengong/" + func;

}
string perform_action_file(string action)
{
        return __DIR__"jiuyin-shengong/" + action;

}
int bounce_ratio()
{
        return 40;
}

int learn_bonus()
{
        return -100;
}
int practice_bonus()
{
        return -500;
}
int black_white_ness()
{
        return 200;
}
