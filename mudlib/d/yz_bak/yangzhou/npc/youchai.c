//Mr.music yangzhou 邮差

inherit NPC;

string send_mail();
string receive_mail();

void create()
{
	set_name("邮差", ({"youchai", "postofficer", }) );
	set("title", "飞马驿站的");
	set("gender", "男性" );
	set("age", 33);
	set("long",
               "飞马驿站的邮差");
        set("mingwang",1);
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("inquiry", ([
                "mail" : "不知您是想寄信还是看信? \n" ,
		"寄信" : (: send_mail :),
                "send" : (: send_mail :),
                "jixin" : (: send_mail :),
		"看信" : (: receive_mail :),
                "receive" : (: receive_mail :),
                "kanxin" : (: receive_mail :),
	]) );
	set_skill("literate", 20);
	set_skill("dodge", 50);
	set_skill("unarmed", 40);
	setup();
	add_money("coin", 20);
}

string send_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "看看信箱上的使用说明吧。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "真是抱歉，请您等一下到驿站来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
        say("邮差递给"+this_player()->query("name")+"一个信箱。\n");
	return "寄信吗？这是信箱，寄信的方法信箱上有说明。\n";
}

string receive_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "看看信箱？你所有的信都在里面。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "真是抱歉，请您等一下到驿站来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
        say("邮差递给"+this_player()->query("name")+"一个信箱。\n");
	return "你的信箱在这，坐下来慢慢看吧。\n";
}
