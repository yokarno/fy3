inherit NPC;
inherit F_SAVE;

void create()
{
  set_name("花剑影",({"hua jianying"}));
  set("title","流星赶月");
  set("age",39);
  set("long","中等身材，白净脸皮，一副牙齿向外突了一寸，
一个鼻头低陷了半寸,他手中拿的是一副流星锤.\n");
	set("shen_type",-1);
  set("combat_exp",20000);
  set_skill("hammer",30);
  set_skill("parry",30);
  set_skill("dodge",30);
  set_skill("force",30);
  set_skill("unarmed",30);
  set("area","荒芜坟地");

  set("chat_chance",8);
  set("chat_msg",({
  "我看还是把[擅闯者死]改为[非请莫入]的好.\n",
  "为了打这对锤,把家里的锅都化了.\n",
  "舍不得孩子套不住狼，老大就是有文化.\n",
   }));
  set("inquiry",([
 "让路":"给钱,给钱就让你过去.给东西也成.",
  ]));
	setup();
 carry_object("/obj/armor/cloth")->wear();
 carry_object(__DIR__"obj/star_hammer")->wield();
}
void init()
{ 
	object ob,area;
	area=new("/obj/area");
	area->create(query("area"));
	set("banghui",(string)area->query("banghui"));
	destruct(area);

 if (interactive(ob=this_player())&&!is_fighting()) {
   remove_call_out("greeting");
   call_out("greeting",1,ob);
   }
}
void greeting(object ob)
{
  string str;
 if (!ob||environment(ob)!=environment()) return;
  str=this_object()->query("banghui");
 if (ob->query("banghui")!=str)    {
  command("say 你老可来了，我们都饿了三天了.\n");
  command("guard south");
  return;
            }
 command("say 原来是本帮弟兄,老大等你好久了.\n");
  return;
}
int accept_object(object me,object obj)
{
  if (obj->value()<20000)    {
  command("say 糊弄谁啊,二两金子,快,不然不给过.\n");
   return 0;        }
  command("guard cancel");
  message_vision("$N让开南面的路,让$n过去.\n",this_object(),me);
  return 1;
}

