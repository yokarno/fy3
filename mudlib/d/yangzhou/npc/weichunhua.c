// by Mr.music 韦春花

#include <ansi.h>

inherit KZZNPC;

string ask_me(object who);
string query_save_file() { return DATA_DIR + "npc/韦春花"; }

void create()
{
#include <kzznpc.h>
	set_name("韦春花", ({"weichunhua","wei","chun hua", "hua" }) );
	set("title", "赌场老板");
	set("gender", "女性" );
	set("mingwang", -1);
	set("age", 30);
	set("str", 45);
	set("cor", 15);
	set("cps", 45);
	set("int", 15);
	set("max_kee",800);
        set("area_name","赌场");
      	set("area_file","/d/yangzhou/duchang.c");
	set("long",
		"你眼睛一花，竟象中了邪,不知所措。\n" );

	set("combat_exp", 150000);
//        set("attitude", "aggressive");
	set("attitude", "heroism");

        set("chat_chance", 8);
        set("chat_msg", ({
                "春花说道：大爷真帅，很有钱吧～ \n",
                "春花似笑非笑地看了你一眼。 \n",
                "春花笑骂道：本姑娘是你能看的吗？\n",
//                (: random_move :) 
        }) );

	set("chat_chance_combat", 4);
	set("chat_msg_combat", ({
		"春花说道: 真忍心杀我呀! \n",
		"春花说道: 算啦 ! 算我输了还不行 ?....\n",
                "春花说道: 别这样，都依你成不 ? \n",
//                (: random_move :)
	}) );

	set("inquiry", ([
		"韦小宝" : "不知这小鬼死哪去了。。。。" ,
                "weixiaobao" : "不知这小鬼死哪去了。。。。" ,
                "apple" : "她是我妹妹，很调皮的... ",
	]) );

	setup();
	
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/weapon/sword")->wear();
}

#include <die.h>
