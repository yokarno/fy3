#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("银针", ({"yin zhen"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一种细小的暗器,用纯银打就。\n");
                set("unit", "些");
                set("base_unit", "根");
                set("base_weight", 5);
                set("value", 50);
        }
        set_amount(20);
        init_throwing(20);
        setup();
}

