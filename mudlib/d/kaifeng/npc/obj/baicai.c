// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
if (random(2)==1) set_name("大白菜",({"bai cai"}));
else set_name("卷心菜",({"juan xincai"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
set("unit","棵");
    set("value", 90);
    set("food_remaining", 10);
    set("food_supply", 25);
  }
}
