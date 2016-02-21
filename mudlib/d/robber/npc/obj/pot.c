inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("大茶缸", ({ "pot", "shuigang" , "big shuigang" }) );
	set_weight(1000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个装满了茶水的大水缸，如果你口渴，可以舀水来喝(drink)。\n");
		set("unit", "个");
		set("value", 20);
		set("max_liquid", 200);
	}
	set("liquid", ([
		"type": "water",
		"name": "茶水",
		"remaining": 200,
                "drink_msg":"$N喝了几口水缸中的茶水，觉得好多了.\n",
	]) );
}
