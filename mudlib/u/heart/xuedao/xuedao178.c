//This xuedao178 room file by mapmaker

inherit ROOM;

void create()
{
  set("short", "骷髅涧");
  set("long",@LONG
这里尸骨累累，是血刀门练内功所杀之人。
此地是本门任务 --- 清除石牢内尸体的终点处。
LONG
  );
  set("exits", ([ /* sizeof() == 1 */ 
      "westup" : __DIR__"xuedao177",
      ]));
  set("no_clean_up", 0);
  set("outdoors","xuedaomen/1");
  setup();
  replace_program(ROOM);//如果没有init函数请不要删除这句话

}
