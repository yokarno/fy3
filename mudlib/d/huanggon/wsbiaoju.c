// Room: /d/huanggon/wsbiaoju
inherit ROOM;

void create()
{
  set ("short", "武胜镖局");
  set ("long", @LONG
东城的武胜镖局,在京中是首曲一指的大镖局,不仅是因为其总镖头
金枪王武通的武艺,还靠的是在江湖上广阔的交游.镖局前竖了根高高的
旗杆,武胜的名号用红线绣在黑底的镖旗上.
LONG);

  set("outdoors", "/d/huanggon");
  setup();
  replace_program(ROOM);
}
