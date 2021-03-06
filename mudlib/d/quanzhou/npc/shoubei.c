// wujiang.c 武将

inherit NPC;
void create()
{
        set_name("城门守备", ({ "shoubei", "bei", "jiang" }));
        set("gender", "男性");
        set("age", random(10) + 30);
        set("str", 25);
        set("long", "他威风凛凛，杀气腾腾，虽然只是个守城门的小官，当年也是打过大仗的。\n");
        set("combat_exp", 80000);
        set("attitude", "peaceful");

        set_skill("unarmed", 70);
        set_skill("force", 70);
        set_skill("sword", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
	set("max_kee", 700);
	set("max_sen", 600);
        set("force", 400); 
        set("max_force", 400);
        set("force_factor", 15);
        setup();
        carry_object("/d/quanzhou/obj/blade")->wield();
        carry_object("/d/quanzhou/obj/tiejia")->wear();
        add_money("gold",1);
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
int greeting(object ob)
{   object me,*inv;
    int count;
    ob=this_player();
   me=this_object();
 if (!living(ob)||environment(ob)!=environment()) return 0;
     if (random(5)==3)
  {
     message_vision("$N指着$n道:你过来,是良民吗,老爷怎么瞧着不像!
说着对$n一阵乱搜!\n",me,ob);
       	inv=all_inventory(ob);
	for(count=0;count<sizeof(inv);count++)
	    if(inv[count]->query("id")=="silver")
     {   if (random(3)==1)
                   {    inv[count]->move(me);
                        message_vision("$N从$n身上搜出一些银量,顺手揣入腰包!
随即踹了$n一脚:还不快滚开,想让老爷把你抓到牢里去么?\n",me,ob);
                        command("say 兄弟们,今晚大伙儿有得乐了!\n");
                        return 1;
                    }
                 else 
                    message_vision("$N搜了半天,什么都没找到,气愤地一脚把$n踢开!\n",me,ob);
                    if (random(2)==1)
                       {     tell_room("/d/quanzhou/estreet2",ob->query("name")+"被人一脚踢了过来,抱着屁股嗷嗷直叫!\n");
                             ob->move("/d/quanzhou/estreet2");
                              return 1;
                        }
                   else 
                           tell_room("/d/quanzhou/dalu1",ob->query("name")+"被人一脚踢了过来,抱着屁股嗷嗷直叫!\n");
                           ob->move("/d/quanzhou/dalu1");
                           return 1;
             }
    if (count==sizeof(inv))
         message_vision("$N搜了半天,一个大子儿没捞到,对$n破口大骂:
你这个穷光蛋,给老爷滚远一点!\n",me,ob);
      return 1;
  }
 return 1;
}                   