// Room: /d/jinding/pubuding
inherit ROOM;

void create()
{
  set ("short", "瀑布顶");
  set ("long", @LONG
此处居高临下,瀑布的水源从石地上的数十个口子中喷涌而出,你
站在这,能看到瀑布下面的一切,地面上溢水二尺,水色碧绿,在后面有
一个入口,隐隐露出光茫.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tianju",
  "down" : __DIR__"dongzhong2",
]));
  setup();
}
