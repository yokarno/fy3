  //   Wangzc kunlun's 玩家留言板
inherit BULLETIN_BOARD;

void create()
{
	set_name("莫邪和皮皮鲁的情书",({"book"}));
	set("location","/u/wangzc/workroom");
		set("board_id","wzc&ppl");
        set("long",
		"私人情书，不许偷看！！！(help board)。\n");
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
