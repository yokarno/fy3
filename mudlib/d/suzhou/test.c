// Room: /d/suzhou/qianzhuang.c

inherit ROOM;

void create()
{
	object ob;
	set("short", "钱庄");
	set("long", @LONG
钱庄内静悄悄的，各人都在小心警慎的干着自己的事。虽然苏州的治安良好，
但你还是紧紧的拽住自己的钱袋，生怕它会飞走似的。钱老板正聚精会神的打着
算盘，并没有注意到你走进来。
LONG
	);
	set("flag",0);
	set("exits", ([ /* sizeof() == 1 */
]));
	set("no_clean",1);
	set("objects",([
		__DIR__"npc/mouth":1,
]));
	setup();
	if(query("flag")==0)	{
		ob=load_object(__DIR__"npc/obj/zhujian");
		ob->move(this_object());
		set("flag",1);
	}
}
