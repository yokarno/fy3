// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit ITEM;

void create()
{
        set_name("千手观音神像", ({ "xiang" }) );
        set_weight(500000);
        set_max_encumbrance(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "座");
                set("long", "从身上伸出一千只手,每只手掌上都有一只眼睛.\n");
                set("value", 50);
        }
}


