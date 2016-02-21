// Room: /open/xiaoyao/mimi/default.c
inherit ROOM;

void create()
{
  set ("short", "小猫的家");
  set ("long", @LONG
    这是小猫家的客厅，小猫一生爱武从这里可以看出。当中墙
上挂着一幅大大的（武）字是小猫花重金请京城的老夫子所书，
案上两旁插着两只红烛中间供着八把飞刀。左面墙上挂着一件夜
行衣，右面墙脚有一个小木柜里面关着一只金毛老鼠。
    这里明显的出口是 out。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/xiaoyao");
  set("no_clean_up", 1);
  setup();
}
