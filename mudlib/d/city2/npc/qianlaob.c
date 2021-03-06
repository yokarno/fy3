// qianlaob.c
#include <ansi.h>

inherit NPC;
void create()
{
	set_name("钱老本", ({"qian laoben", "qian", "laoben"}));
	set("banghui","天地会");
	set("gender", "男性");
	set("age", 34);

	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);

	set("kee", 800); 
	set("max_kee", 800);
	set("gin", 100);
	set("max_gin", 100);
	set("mingwang",500);
	set("max_force",800);
	set("force",800);
	set("force_factor",80);

	set("combat_exp", 100000);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 5);
	set("chat_msg", ({
	"钱老本说道：我叫钱老本，就是因为做生意连老本也赔了。\n",
	"钱老本笑着说道：在本店存钱利息至少百分之一，客官您只管存吧。\n",
	"钱老本说：只有对本派弟子我才这么客气，对别的人啊，哼哼......\n",
	"钱老本突然说道: 江湖名望很重要，名望值高大有好处啊。\n",
        "钱老本突然说：五人分开一首诗，身上洪英无人知。\n",
	}));
        set("inquiry", ([
		"利息" :  "\n想要利息先入会！\n",
		"陈近南" :  "\n想见总舵主可没那么容易。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会(join tiandihui)。\n",
   ]));
	set_skill("unarmed", 80);
	set_skill("yunlong-shou",80);
	set_skill("force",80);
	set_skill("yunlong-xinfa",80);
	set_skill("dodge", 80);
	set_skill("yunlong-shenfa",80);
	set_skill("parry",80);

	map_skill("unarmed","yunlong-shou");
	map_skill("parry","yunlong-shou");
	map_skill("dodge","yunlong-shenfa");
	map_skill("force","yunlong-xinfa");
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);

	setup();
	carry_object("/obj/cloth")->wear();
	add_money("gold", 3);
}
void init()
{
	object ob;
	::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_check", "check");
	add_action("do_check", "wen");
	add_action("do_convert", "convert");
	add_action("do_convert", "duihuan");
        add_action("do_convert", "huan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
}

void greeting(object ob)
{
	string banghui;
	int money;
	object lp;
	if(! (banghui=ob->query("banghui")))	{
		command("nod");
		return;
	}
	lp=new("/obj/lingpai");
	lp->create(banghui);
	if(lp->query("no_use"))	{
		destruct(lp);
		message_vision("$N冲着$n道：“这位"+
		RANK_D->query_respect(ob)+"的帮会文件有问题，快点与巫师联系吧。”\n",this_object(),ob);
		return;
	}
	if(lp->query("bangzhu_id")=="???")	{
		destruct(lp);
		message_vision("$N提醒$n道：“贵帮帮主已失踪多日，快去找黄飞鸿大侠商量商量吧。\n",this_object(),ob);
		return;
	}
	if( lp->query("bangzhu_id")!=ob->query("id"))	{
		destruct(lp);
		message_vision("$N笑咪咪的对着$n道：“帮主何时来此处转帐啊？”\n",this_object(),ob);
		return;
	}
	if(! (int)(money=lp->query("money")))	{
		destruct(lp);
		message_vision("$N对$n陪笑道：“目前无帐可转。”\n",
		this_object(),ob);
		return;
	}
	lp->set("money",0);
	lp->save();
	destruct(lp);
	ob->add("balance",money);
	ob->save();
	message_vision("$N将"+banghui+"最近的收帐"+MONEY_D->money_str(money)+"转到了$n的帐下。\n",this_object(),ob);

}

void enough_rest()
{
	delete_temp("busy");
}

int do_check()
{
	// here we use 3 units to display bank infos
	int total = (int)this_player()->query("balance");
        
	
	if (!total || total < 0) {
		this_player()->set("balance", 0);
		return notify_fail("您在敝商号没有存钱。\n");
	}
	write("你核对了帐本，在庄里共存有" + 
		MONEY_D->money_str(total) + "\n");
	return 1;
}

int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;
	object me;
	
	if (query_temp("busy"))
		return notify_fail("这就去拿帐本，请稍候。\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
	{
		return notify_fail("命令格式：huan <数量> <货币> to <新货币单位>\n");
	}

	from_ob = present(from + "_money", me);
	to_ob = present(to + "_money", me);

	if (!to_ob && file_size("/obj/money/" + to + ".c") < 0)
	{
		return notify_fail("你想换成什么？\n");
	}
	if (!from_ob)
	{
		return notify_fail("你身上没有带这种钱。\n");
	}
	if (amount < 1)
	{
		return notify_fail("你想白赚啊？\n");
	}
	if ((int)from_ob->query_amount() < amount)
	{
		return notify_fail("你带的" + from_ob->query("name") + "不够。\n");
	}
	
	bv1 = from_ob->query("base_value");
	if (!bv1)
	{
		return notify_fail("这样东西不值钱。\n");
	}

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/obj/money/" + to, 
"query", "base_value" );
	
	if (bv1 < bv2)
		amount -= amount % (bv2 / bv1);	

	if (amount == 0)
	{
		return notify_fail("这些" + from_ob->query("name") + "不够换。\n");
	}

	// allowed to convert now
	set_temp("busy", 1);	

	from_ob->add_amount(-amount);

	if (!to_ob) {
		to_ob = new("/obj/money/" + to);
		to_ob->set_amount(amount * bv1 / bv2);
		to_ob->move(me);
	}
	else
		to_ob->add_amount(amount * bv1 / bv2);
	
	message_vision(sprintf("$N从身上取出%s%s%s，换成了%s%s%s。\n",
	chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
	chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), 
	to_ob->query("name")), me);

//	from_ob->add_amount(-amount);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);

	return 1;
}

int do_deposit(string arg)
{
	string what;
	int amount;
	object what_ob, me;

	if (query_temp("busy"))
		return notify_fail("您请坐，这就去取帐本。\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	{
		return notify_fail("命令格式: cun <数量> <货币>\n");
	}

	what_ob = present(what + "_money", me);
	if (!what_ob)
	{
		return notify_fail("你身上没有带这种钱。\n");
	}
	if (amount < 1)
	{
		return notify_fail("你想存多少" + what_ob->query("name") + "？\n");
	}
	if ((int)what_ob->query_amount() < amount)
	{
		return notify_fail("你带的" + what_ob->query("name") + "不够。\n");
	}

	// deposit it
	set_temp("busy", 1);	

	me->add("balance", what_ob->query("base_value") * amount);
	what_ob->add_amount(-amount);
	message_vision(sprintf("$N拿出%s%s%s，存进了钱庄。\n", 
	chinese_number(amount), what_ob->query("base_unit"), 
	what_ob->query("name")), me);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);
	return 1;
}

int do_withdraw(string arg)
{
	int amount, v,lixi;
	string what,banghui;
	object me;

	if (query_temp("busy"))
		return notify_fail("您请稍候.....。\n");

	me = this_player();
	
	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	{
		return notify_fail("命令格式：qu <数量> <货币单位>\n");
	}
	if (amount < 1)
	{
		return notify_fail("你想取出多少钱？\n");
	}
	if (file_size("/obj/money/" + what + ".c") < 0)
	{
		return notify_fail("你想取出什么钱？\n");
	}
	what = "/obj/money/" + what;

//	if ((v = amount * what->query("base_value")) > me->query("balance"))
//	{
//		return notify_fail("你存的钱不够。\n");
//	}



      if ( amount  > 
              ( me->query("balance") / (what->query("base_value")) ) )
      {
              return notify_fail("你存的钱不够。\n");
      }

     v = (amount) * what->query("base_value");


	if((int)me->query_encumbrance() + 
		amount* what->query("base_weight")
		> me->query_max_encumbrance() )
		return notify_fail("你取得钱太沉了，装不下。\n");

	set_temp("busy",1);
	me->add("balance",  -v);

	banghui=(string)me->query("banghui");
	if(! banghui || banghui!=(string)query("banghui"))	{
        v=what->query("base_value") * amount * 8 /10 ;
/*
	钱庄利息转入帮会收入，同帮会不收利息
	由于本NPC是非征招NPC，所以不用进行利息转入帮会
	收入的处理。
	 lixi=what->query("base_value") * amount/10;
	 if(lixi>0)	"/cmds/adm/ctom.c"->save_money(this_object(),lixi);
*/
	}
	else
	 v=what->query("base_value") * amount;

	MONEY_D->pay_player(me, v );
	
	message_vision(sprintf("$N从钱庄里取出%s。\n", MONEY_D->money_str(v)),
		me);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);
	return 1;
}

void recognize_apprentice(object ob)
{
        string banghui;
        if(! stringp(banghui=ob->query("banghui")) ||
                banghui!=query("banghui"))
        return notify_fail(query("name")+"摇头道：非我天地会兄弟不教。\n");
        if(ob->query("score")<50)
                return notify_fail(query("name")+"道：你要多为天地会出力啊。\n")
;
        return 1;
}
