#include <ansi.h>

inherit NPC;
void use_poison();
void backattack();
void create()
{
        set_name("响尾蛇", ({ "snake" }) );
        set("race", "野兽");
        set("age", 4);
        set("yes_carry", 1);
        set("long", "一条剧毒的响尾蛇。\n");
        set("limbs", ({ "头部", "身体", "尾巴", "七寸" }) );
        set("verbs", ({ "bite" }) );
        set("cor", 50);
        set("bellicosity", 100 );
        set_skill("dodge", 50);
        set("combat_exp", random(3)*10000+20000);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        setup();
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        if( is_fighting() && (int) this_object()->query("kee") <= 100)
        backattack();
        return ::heal_up() + 1;
}

void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        tell_object(ob,
"你觉得脸上剧痛，伸手一摸发现两个毒牙印痕。\n");
        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                ob->apply_condition("snake_poison", 
                (int)this_player()->query_condition("snake_poison")
                + random(3)+3);
}

void leave()
{
        object owner;
        message("vision",
                 name() + "吐了吐鲜红的蛇信，缓缓盘起了身体。\n\n"
                + name() + "舒展开长长的身体，悠闲地游走了。\n" , environment(),
                this_object() );
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("max_guard",-1);
        destruct(this_object());
}

void invocation(object who, int level)
{
        int i;
        object *enemy;
        message("vision",
                 name() + "呲地一声蹿了出来！\n" NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        set_leader(who);
        set("possessed",who);
}
void backattack()
{
        int i;
        object owner, *enemy;
        if(objectp(owner=this_object()->query("possessed")))
        {
                enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        }

        }

}

void die()
{
        object owner;
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("max_guard",-1);
        ::die();
}

