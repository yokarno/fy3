// music   yangzhou's 店小二

inherit NPC;
void create()
{
	set_name("小和尚",({"xiao heshang","xiao","heshang"}));
	set("gender", "男性" );
	set("age",15);
	set("long",
	"头上光光的修行小和尚。\n");
	set("mingwang",1);
	set("combat_exp",1000);
	set_skill("dodge",20);
	set_skill("unarmed",20);
	set("attitude", "friendly");
	setup();
	carry_object(__DIR__"obj/qingbusengyi")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
//	remove_call_out("greeting");
//	call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
	say("小沙弥拿起扫帚打扫着地上的落叶。\n");
			break;
		case 1:
	say("小沙弥放下扫帚，擦了擦光头上的汗。\n");
			break;
                           }
}
