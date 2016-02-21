inherit NPC;
void create()
{
   set_name("华筝公主",({"hua zheng"}));
   set("gender","女性");
   set("long","铁木真的小女儿,郭靖的未婚妻子!\n");
   set("mingwang",30000);
   set("combat_exp",600000);
   set("area_name","蒙古草原");
   
set("age",16);
   set("kee",900);
   set("max_kee",900);
set("food",250);
set("water",250);
   set("force",500);
   set("max_force",500);
   set("force_factor",10);

   set_skill("dodge",50);
   set_skill("force",50);
   set_skill("parry",50);
   set_skill("unarmed",50);
   set_skill("whip",50);

   setup();
   add_money("silver",10);
carry_object("/obj/cloth")->wear();
carry_object("/d/obj/weapon/whip/whip")->wield();
}
void init()
{
        object area;
        area=new("/obj/area");
	area->create(query("area_name"));
        set("banghui",(string)area->query("banghui"));
        destruct(area);
}