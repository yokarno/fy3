// Room: /d/hangzhou/leifeng.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "雷峰夕照");
	set("long", @LONG
这座以木石为内心，外建木构楼廊的高塔就是雷峰塔了.塔高五 
层,内壁嵌有刻着《华严经》条石，塔下供奉金铜十六罗汉像。夕阳 
西照，塔影横空，亭台金碧，故得“雷峰夕照”之名 
LONG
	);
	set("outdoors", "/d/hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"shilu.c",
  "in" : __DIR__"tanei.c",
]));

	setup();
	replace_program(ROOM);
}
