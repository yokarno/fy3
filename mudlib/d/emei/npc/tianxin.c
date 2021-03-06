inherit NPC;
inherit F_MASTER;

void create()
{
    set_name("天心",({"tian xin","laoren"}));
    set("gender","男性");
    set("shen_type",1);
    set("age",96);
    set("combat_exp",1500000);
    set("long","峨嵋派长老,遁世隐修!\n");
    
set_skill("dodge",200);
set_skill("unarmed",200);
set_skill("parry",200);
set_skill("force",200);
set_skill("literate",200);
set_skill("sixiang-zhang",200);
 set_skill("emei-xinfa",200);
set_skill("anying-fuxiang",200);
set_skill("huifeng-jian",200);

    map_skill("dodge","anying-fuxiang");
    map_skill("unarmed","sixiang-zhang");
    map_skill("parry","sixiang-zhang");
    map_skill("sword","huifeng-jian");

    create_family("峨嵋派",4,"长老");
    set("inquiry",([
       "name":"老和尚天心.\n",
       "here":"此处乃峨嵋隐府\n",
     ]));
   setup();
   }
void attempt_apprentice(object me)
{
    if (me->query("family/family_name")=="峨嵋派")
 {
     command("say 善哉,善哉,你我已是同门,何来拜师之说!\n");
      return;
 }
  if (me->query("gender")=="女性")
{
    command("say 阿弥佗佛,罪过,罪过,女施主不要说笑!\n");
    return;
}
  command("say 即入我门,四大皆空,汝须紧记.\n");
  command("recruit "+me->query("id"));
return;
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
			ob->set("class","xiake");
}
