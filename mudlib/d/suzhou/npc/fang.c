// huoji. 药铺伙计

inherit KZZNPC;
inherit F_VENDOR;
string query_save_file() { return DATA_DIR + "npc/方哲朴"; }


void create()
{
#include <kzznpc.h>

	set("area_name","苏州防具铺");
	set("area_file","/d/suzhou/liangongtang.c");
	set("long","老于世故的防具铺老板，正在整理着什么。\n");
	set("attitude", "friendly");
	set_temp("apply/defense",50);
	set_temp("apply/attack",40);
	set_temp("apply/armor",50);

	set("vendor_goods", ([
	"pikui":"/obj/std/armor/pikui",
	"tongkui":"/obj/std/armor/tongkui",
	"tiekui":"/obj/std/armor/tiekui",
	"pijia":"/obj/std/armor/pijia",
	"tongjia":"/obj/std/armor/tongjia",
	"tiejia":"/obj/std/armor/tiejia",
	"pist":"/obj/std/armor/pishoutao",
	"tongst":"/obj/std/armor/tongshoutao",
	"tiest":"/obj/std/armor/tieshoutao",
	"pixue":"/obj/std/armor/pixue",
	"tongxue":"/obj/std/armor/tongxue",
	"tiexue":"/obj/std/armor/tiexue",
	]));

	setup();
	carry_object(__DIR__"obj/hupi")->wear();
	carry_object("/obj/weapon/blade")->wield();
	add_money("gold",1);
}

void init()
{
        ::init();

        add_action("do_vendor_list", "list");
}


