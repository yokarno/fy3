// thd:music_hole.c
// 97.7.14 bu Aug

inherit ROOM;

void create()
{
      set("short", "清音洞");
	set("long", @LONG
这里是清音洞。只是个很小的山洞，它深藏在山腹之中。只是个溶洞
，到处是石笋、石柱。这里的回声极强，只要有一点声响就会有千百声回
声。在这里你不能大声说话，否则那回声会使你很不舒服，使你不得不运
功向抗，不过这样对增进你的内功倒是有好处。在地上你还能看到一根玉
箫(xiao)。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

	set("detail", ([ /* sizeof() == 1 */
		"xiao" : "这是根晶莹剔透的玉箫。\n",
      ]));

      set("exits", ([ /* sizeof() == 1 */
          "west" : __DIR__"songshu",
	]));
      
	setup();
}

void init()
{
	add_action("do_sing", "sing");
}

int do_sing(string arg)
{
	int gin_cost;
	object me;

	me=this_player();

	if(me->query_skill("force")>150)
	{
		write("你的内功这么好，抵御萧声已经不成问题了，再吹萧也没用了。/n");
		return 1;
	}

	gin_cost = 60 / (int)me->query_attr("int") *4;

	if( (int)me->query("gin") < gin_cost ) 
	{
		write("你太累了，没有办法吹出乐曲了。\n");
		return 1;
	}

	me->consume_stat("gin", gin_cost);

	if( (string)me->query("class")!="taohua")
	{
		write(
"你拿起地上的那根玉箫开始吹奏。
你发出的乐音经过洞壁的放大，又反射到你的耳边。
令你感到很不舒服，不得不运功相抗。

你的内功进步了。\n");

		me->improve_skill("force", me->query_skill("force")/10+1);
	}
	else
	{
		write(
"你拿起地上的那根玉箫开始吹奏“碧海潮生曲”。
你发出的乐音经过洞壁的放大，又反射到你的耳边。
令你感到很不舒服，不得不运功相抗。

你的内功根基进步了。
你的碎玉神功进步了。\n");

		me->improve_skill("force", me->query_skill("force")/10+1);
		me->improve_skill("suiyu-force", me->query_skill("force")/12+1);
	}

	return 1;
}


