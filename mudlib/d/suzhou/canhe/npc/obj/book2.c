// jinchuang.c 金创药

#include <ansi.h>
inherit ITEM;



void create()
{
	set_name("斗转星移要诀",({"douzhuan","shu","book"}));
	set("unit","本");
	set("long","一本记载着「以彼之道还施彼身」的秘籍。\n");
	set("no_give",1);
	setup();
}
void init()
{
	add_action("do_study","study");
	add_action("do_study","du");
}
int do_study(string arg)
{
	int k;
	object me;
	me=this_player();
	if (!id(arg))
	return 0;
	if(me->query_skill("murongquanfa",1)<80||!me->query_skill("murongquanfa",1))
	{
	tell_object(me,"你的「慕容拳法」功力不够，还没有领悟「斗转星移」呢。\n");
	return 1;
	}
	k=me->query("oldsix_flag/douzhuan");
	if(!k||k==0)	k=3;
	if(k==10)	
	{
	tell_object(me,"你的「斗转星移」已达到最高境界，再研究它也没用啦。\n");
		return 1;
	}
	message_vision("$N正仔细专研「斗转星移」神功。\n",me);
	if(me->query_int()<24+(k-2)*3)
	{
	tell_object(me,"以你当前的领悟力还难以理解更深的「斗转星移」神功。\n");
		return 1;
	}
	if(random(me->query_kar())<25)
	{
	tell_object(me,"你好象对「斗转星移」神功有所理解，但又不敢肯定。\n");
		return 1;
	}
	tell_object(me,CYN"你的「斗转星移」神功进步了！\n"NOR);
	k=k+1;
	me->set("oldsix_flag/douzhuan",k);
	return 1;
}
