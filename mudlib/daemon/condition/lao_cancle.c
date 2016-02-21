// snake_poison.c

#include <ansi.h>

int update_condition(object me)
{
	int how_long;
	switch(me->query("oldsix_flag/long"))	{
		case 1:		how_long=20*60;
				break;
		case 2:		how_long=10*60;
				break;
		case 3:		how_long=5*60;
				break;
			}
	if(me->query("mud_age")-me->query("oldsix_flag/time")>=how_long)			{
	me->set("oldsix_flag/lao",0);
	message("channel:rumor", YEL +"【谣言】某人："+me->query("name")+"被苏州官府释放了。\n"NOR,users());
		return 0;
	}
	me->apply_condition("lao_cancle");
	return 1;
}
