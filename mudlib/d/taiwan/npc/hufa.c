#include <ansi.h>
inherit NPC;
void do_kneel();
string *words=({
	"全能的湿婆神啊... ...\n",
	"我愿意把我全部的生命献给湿婆,献给幽冥一派.\n",
	"全能的湿婆神啊,我是您忠实的信徒...\n",
	"请湿婆神保佑我们,保佑幽冥一派.\n",
     });
void create()
{
    set_name("护法",({"hufa"}));
    set("gender","男性");
	set("shen_type",-1);
    set("age",46);
    set("title",RED"幽冥山庄"NOR);
    set("combat_exp",200000);
    set("kee",500);
    set("max_kee",500);
    set("force",500);
    set("max_force",500);
    set("force_factor",15);
    set("food",200);
    set("water",200);
    
    set("inquiry",([
    "幽冥山庄":"你现在呆的地方就是了。\n",
    "道心种魔大法":"我门中无上大法，可惜早几代就失传了.\n",
    ]));
    
    set("chat_chance",3);
    set("chat_msg",({
    (:do_kneel:),
    }));
    
    set_skill("dodge",40);
    set_skill("parry",40);
    set_skill("unarmed",40);
    set_skill("force",40);
    set_skill("literate",20);
    set_skill("guiyingmizong",40);
    set_skill("jiuyou-xinfa",40);
    set_skill("youming-zhang",40);
    
    map_skill("dodge","guiyingmizong");
    map_skill("unarmed","youming-zhang");
    map_skill("parry","youming-zhang");
    map_skill("force","jiuyou-xinfa");
  
    setup();
    add_money("silver",10);
 }
void do_kneel()
{
  int i;
  object *ob,env;
  string word;
   env=environment(this_object());
   ob=all_inventory(env);
   if (env->query("short")!="巨大山洞") return;
   word=words[random(sizeof(words))];
   command("say "+word);
   for (i=0;i<sizeof(ob);i++)   {
   	if (ob[i]->query("id")=="mentu")
	call_other(ob[i],"say_some",word);
  }
return;
}
   
