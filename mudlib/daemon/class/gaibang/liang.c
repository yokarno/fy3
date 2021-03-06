inherit NPC;
inherit F_MASTER;
string do_yaoqing();
void create()
{
  set_name("梁长老",({"liang zhanglao","liang"}));
  set("gender","男性");
  set("age",65);
  set("mingwang",-3000);
  set("combat_exp",700000);
  set("force",1200);
  set("max_force",1200);
  set("title","丐帮九代长老");
  set("max_kee",1200);
  set("force_factor",30);
  set("food",250);
  set("banghui","丐帮");
  set("water",250);

  set_skill("unarmed",120);
  set_skill("dodge",120);
  set_skill("parry",120);
  set_skill("staff",120);
  set_skill("force",120);
  set_skill("huntian-qigong",120);
  set_skill("xianglong-zhang",120);
  set_skill("dagou-bang",120);
  set_skill("xiaoyaoyou",120);
  map_skill("dodge","xiaoyaoyou");
  map_skill("force","huntian-qigong");
  map_skill("staff","dagou-bang");
  map_skill("unarmed","xianglong-zhang");
  map_skill("parry","xianglong-zhang");

  set("inquiry",([
    "丐帮":"我丐帮分舵遍布天下,你可是想加入丐帮吗?",
    "加入丐帮":(:do_yaoqing:),
    "入帮":(:do_yaoqing:),
      ]));
  setup();
  carry_object("/obj/weapon/blade")->wield();
  carry_object("/obj/cloth")->wear();
 add_money("silver",30);
 }
void init()
{
  object ob;
  ::init();
 if (interactive(ob=this_player())&&!is_fighting()) {
     remove_call_out("greeting");
      call_out("greeting",1,ob);
  }
}
void greeting(object ob)
{
  string banghui;
 banghui=ob->query("banghui");
 if(banghui=="丐帮")  {
  if (!ob->query_temp("gaibang/peng"))  {
   command("give 2 silver to "+ob->query("id"));
   command("say 去买些吃的,喝的,也不能老讨饭哪.\n");
   ob->set_temp("gaibang/peng",1); 
  return;
  } 
command("heng "+ob->query("id"));
return;
 }
command("say 有钱的大爷,可怜可怜老叫话,施舍几文吧.\n"); 
return;
 }
string do_yaoqing()
{
  object ob;
 string banghui;
 ob=this_player();
 banghui=ob->query("banghui");
 if (ob->query("balance")>500000)
  return "你老这么有钱,要加入丐帮,先把钱给散咯.\n";
 if (!banghui)  {
   ob->set_temp("oldsix/target",this_object());
  return "好,我丐帮就要你这样的人才,加入吧(jiaru liang).\n";
    }
 if (banghui!="丐帮")
 return "你是"+banghui+"的吧,想来卧底怎么着?\n";
 else return "再开这种玩笑,我把你关禁闭.\n";
}
int accept_object(object who,object ob)
{
  if (ob->query("money_id"))  {
 command("say 多谢你老,多谢你老,多... ...\n");
 return 1;
   }
 command("say 什么玩意儿,我呸.\n");
 return 0;
}
int recognize_apprentice(object ob)
{
  string banghui;
  banghui=ob->query("banghui");
  if (!banghui||banghui!="丐帮")  
   return notify_fail("梁长老摇头道:你并非我丐帮弟子,老化子不能传武功给你.\n");
	if(ob->query("score")<2000)
   return notify_fail("梁长老皱眉道:你如能为本帮再作些事情,老化子再考虑吧.\n");
  return 1;
}
