//华山派留言板 by xxy 6/14/99
inherit BULLETIN_BOARD;

void create()
{
set_name("华山君子录",({"board"}));
set("location","/d/huashan/qunxianguan");
set("board_id","huashan_board");
        set("long",
"华山掌门岳不群的标准语录都写在上面,以备门人弟子随时\n
温习,不过已经被涂改得不像样了.(help board)\n");
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
