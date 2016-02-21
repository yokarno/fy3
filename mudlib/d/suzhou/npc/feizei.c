// woodcutter.c
#include <ansi.h>
inherit KZZNPC;

string do_give();

string query_save_file() { return DATA_DIR + "npc/胡桂南"; }


void create()
{
#include <kzznpc.h>

	set("inquiry", ([
		"劫富济贫": (: do_give :),
	]));
	set("have_give",0);
	set("thief",0);
	set("long","一个瘦小精干的汉子，"+
	HIY"劫富济贫"NOR"的好汉。\n");
	set_temp("apply/defense",50);
		set("chat_chance",20);
        set("chat_msg", ({
		"胡桂南呵呵的笑了起来，像似想起什么事情来。\n",
		"胡桂南道：想当年。。。哎，不提也罢。\n",
		(: random_move :),
}));
	 set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
		"胡桂南叹道：非要逼我出手不可？\n",
		"胡桂南叫道：风紧，扯呼！\n",
		"胡桂南喝道：是谁派你来杀俺的？\n",
}));
	set("env/wimpy",60);
	set_temp("apply/dodge",100);
	set_temp("apply/armor",40);
	setup();
	carry_object("/obj/cloth")->wear();
}
void init()
{
	object ob;
	::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
		call_out("greeting",1,ob);
        }
}

void greeting(object ob)
{
	string banghui;

	banghui=(string)ob->query("banghui");
        if( !ob || environment(ob) != environment() ) return;
	if(! banghui || banghui!=(string)query("banghui"))	{
		if((int)ob->query("mingwang")<0)	{
		write("胡桂南拍了拍你的肩膀，干笑了两声。\n");
		command("steal all from "+ob->query("id"));
		return;
		}
	}
	
}
string do_give()
{
	object me=this_player();
	object *ob,thing;
	int i;
	string banghui;

	if((int)query("have_give"))
		return "别这么猴急，总得让我歇会儿吧。";
	banghui=(string)me->query("banghui");
	if(! banghui || banghui!=(string)query("banghui"))
		return "你我素昧平生，这个忙我可帮不了。";
	ob=all_inventory(this_object());
	if(! sizeof(ob))	return "不好意思，我还没有得手呢。";
	for(i=0;i<sizeof(ob);i++)	{
		if(ob[i]->query("equipped"))
		ob-=({ ob[i] });
	}
	if(! sizeof(ob))	return "不好意思，我还没有得手呢。";
	thing=ob[random(sizeof(ob))];
	set("have_give",1);
	thing->move(me);
	call_out("reset_flag",600);
	return "这"+thing->query("unit")+thing->query("name")+"拿去吧。";
}

void reset_flag()
{
	set("have_give",0);
}

