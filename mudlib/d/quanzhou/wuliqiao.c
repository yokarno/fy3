// Room: /d/quanzhou/wuliqiao.c

inherit ROOM;

void create()
{
	set("short", "安平桥");
	set("long", @LONG
这就是当代最长的海港大石桥'安平桥',全桥长2255米,宽3-3.8米
桥面上铺的都是大石板,长的有二十多米,重的达25吨,桥上有亭子五座.
中亭有历代重修碑记十三方,石雕武士两尊,亭柱上还有一幅对联(duilian).
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/hangzhou/npc/youke.c" : 1,
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "duilian" : "           世间有佛尊斯佛
               天下无桥长此桥.
",
]));
	set("outdoors", "/d/quanzhou");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"haigang",
  "northwest" : __DIR__"dalu3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
