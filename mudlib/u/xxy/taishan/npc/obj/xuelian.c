// music yangzhou's ѩ��
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("ѩ��", ({ "xuelian","lian","xue" }) );
        set("long", "һ������ҩ�ġ�\n");
        set("unit", "��");
        set("weight", 100);
        set("value", 5000);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("��Ҫ��ʲ�᣿\n");

        ob=this_player();
        ob->set("kee",(int)ob->query("max_kee"));
        ob->set("gin",(int)ob->query("max_gin"));
        ob->add("max_sen",1);
        ob->set("sen",(int)ob->query("max_sen"));
        ob->set("eff_kee",(int)ob->query("max_kee"));
        ob->set("eff_gin",(int)ob->query("max_gin"));
        ob->set("eff_sen",(int)ob->query("max_sen"));

        ob->set("atman", (int)ob->query("max_atman"));
        ob->add("max_force",10);
        ob->set("force", (int)ob->query("max_force"));
        ob->set("mana", (int)ob->query("max_mana"));

        ob->set("food",((int)ob->query("str")-10)*10+200);
        ob->set("water",((int)ob->query("str")-10)*10+200);

        write("[1;33m�����һ����ɽѩ�����о��ü��ˣ�\n[0;37m");

        message("vision", HIY + ob->name() + 
"����һ����ɽѩ�����о��ü��ˣ�\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}