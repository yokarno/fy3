inherit ITEM;
inherit F_CLEAN_UP;
int top_cmd();

void create()
{
        set_name("xxxx", ({"book"}));
        set_weight(1000);
                set("unit", "本");
     set("value", 100);
   set("long",
"一本薄薄的小册子．．．．\n");
        set("material", "paper");
        }


void init()
{
    add_action("top_cmd","top");
} 

int top_cmd(object me, string arg)
{
        string str,*astr;
        int i;
        seteuid(geteuid(me));
        if (!arg||arg=="")
                return notify_fail("指令格式 : topten <类型>\n");
        str=TOP_D->topten_query(arg);
        write(str+"\n");
        return 1;
}
