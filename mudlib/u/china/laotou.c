inherit NPC;
#include <ansi.h>;
int ask_con();
int ask_kar();
int ask_spi();
int ask_int();
void create()
{
        set_name("��������", ({ "laotou"}) );
        set("gender", "����" );
        set("title",MAG"������"NOR);
        set("age", 62);
        set("long",
"��������ͷ������һ�ۿ�������츳.\n");
        set("inquiry",  ([
                "����" : (: ask_int :),
                "��Ե" : (: ask_kar :),
                "����" : (: ask_con :),
"����" : "Ҫ����������ѽ!��֪����������?��Ե?����?����?",
                "����" : (: ask_spi :),
        ]) );
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("chat_msg", ({
                "��ͷ��������ӡ�����\n",
        }) );
        setup();
        carry_object("/obj/cloth")->wear();
}

int accept_object(object me,object obj)
{
       if(this_object()->is_busy())
       {
       command("say ���Ժ�,����æ����!");
       return 0;
       }
       if(query(me->query("id")))
       {
       command("say �Ѿ��չ����Ǯ��,��Ҫ�� ���� ��Ե ���� ���� �е���һ��?");
       return 0;
       }
       if(!(string)obj->query("money_id")||(string)obj->query("money_id")!="gold")
       {
       command("say ������ý���֧��!");
       return 0;
       }
       if((int)obj->value() < 20000 )
       {
      say(CYN+name()+"ƤЦ�ⲻЦ��˵��: ������Ҳ̫С���˰�!\n"NOR);
       return 0;
       }
       command("nod "+me->query("id"));
       command("say ��,�����������,��Ҫ����һ�?");
       set(me->query("id"),1);
       return 1;
}

int ask_int()
{
        object me;
        me = this_player();
       if(this_object()->is_busy())
       {
       command("say ���Ժ�,����æ����!");
       return 1;
       }
      if(!query(me->query("id")))
        {
        command("say �Ϻ���ҲҪ���Һ��ڰ�,�ǲ����ȸ��������!");
        return 1;
        }
        delete(me->query("id"));
       this_object()->start_busy(2);
        if (me->query("int") >= 30)
        {
        command("say ������Ժܸ��");
        return 1;
        }
        if (me->query("int") >= 20 && me->query("int") < 30)
        {
        command("say ������Ի�������");
        return 1;
        }
        if (me->query("int") > 10 && me->query("int") < 20)
        {
        command("say �������һ�㡣");
        return 1;
        }
        if (me->query("int") <= 10 )
        {
        command("say ��û��������ô�����ˣ�");
        return 1;
        }
        return 1;
}
int ask_kar()
{
        object me;
        me = this_player();
       if(this_object()->is_busy())
       {
       command("say ���Ժ�,����æ����!");
       return 1;
       }
      if(!query(me->query("id")))
        {
        command("say �Ϻ���ҲҪ���Һ��ڰ�,�ǲ����ȸ��������!");
        return 1;
        }
        delete(me->query("id"));
       this_object()->start_busy(2);
        if (me->query("kar") >= 30)
        {
        command("say ��ĸ�Ե�ܸ��");
        return 1;
        }
        if (me->query("kar") >= 20 && me->query("kar") < 30)
        {
        command("say ��ĸ�Ե��������");
        return 1;
        }
        if (me->query("kar") > 10 && me->query("kar") < 20)
        {
        command("say ��ĸ�Եһ�㡣");
        return 1;
        }
        if (me->query("kar") <= 10 )
        {
          command("say ���������������");
        return 1;
        }
        return 1;
}
int ask_spi()
{
        object me;
        me = this_player();
       if(this_object()->is_busy())
       {
       command("say ���Ժ�,����æ����!");
       return 1;
       }
      if(!query(me->query("id")))
        {
        command("say �Ϻ���ҲҪ���Һ��ڰ�,�ǲ����ȸ��������!");
        return 1;
        }
        delete(me->query("id"));
       this_object()->start_busy(2);
        if (me->query("spi") >= 30)
        {
        command("say ������Ժܸ��");
        return 1;
        }
        if (me->query("spi") >= 20 && me->query("spi") < 30)
        {
        command("say ������Ի�������");
        return 1;
        }
        if (me->query("spi") > 10 && me->query("spi") < 20)
        {
        command("say �������һ�㡣");
        return 1;
        }
        if (me->query("spi") <= 10 )
        {
        command("say ��Ҫ�Ǹ�����1+1=2������֪��1+2=?��");
        return 1;
        }
        return 1;
}
int ask_con()
{
        object me;
        me = this_player();
       if(this_object()->is_busy())
       {
       command("say ���Ժ�,����æ����!");
       return 1;
       }
      if(!query(me->query("id")))
        {
        command("say �Ϻ���ҲҪ���Һ��ڰ�,�ǲ����ȸ��������!");
        return 1;
        }
        delete(me->query("id"));
       this_object()->start_busy(2);
        if (me->query("con") >= 30)
        {
        command("say ��ĸ��Ǻܸ��");
        return 1;
        }
        if (me->query("con") >= 20 && me->query("spi") < 30)
        {
        command("say ��ĸ��ǻ�������");
        return 1;
        }
        if (me->query("con") > 10 && me->query("spi") < 20)
        {
        command("say ��ĸ���һ�㡣");
        return 1;
        }
        if (me->query("con") <= 10 )
        {
        command("say �������ಡ���ҿ������ˡ���");
        return 1;
        }
        return 1;
}

int accept_fight(object me)
{
        command("say ��ʲô�˰���һ����������ͷ��Ҳ�۸�����");
        return 0;
}
