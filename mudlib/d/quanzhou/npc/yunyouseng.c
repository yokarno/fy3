inherit NPC;

void create()
{
  set_name("云游僧", ({"seng","heshang"}));
  set("gender", "男性");
  set("long","遇山过山,遇佛拜佛,入世修行的僧人.\n");
  set("combat_exp",5000+random(50000) );
  set("age", 30+random(50));
  set("per", 32);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 50+random(20));
  set_skill("parry",40+random(30));
    set_skill("dodge",40+random(20));
  
  setup();
  carry_object("/d/quanzhou/obj/jiasha")->wear();
  carry_object("/d/quanzhou/obj/muyu")->wield();
  add_money("silver",10);
}

