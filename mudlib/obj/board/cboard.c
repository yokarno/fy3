inherit BULLETIN_BOARD;

void create()
{
	set_name("小笔记本", ({ "board" }) );
        set("location", "/u/czgq/workroom");
        set("board_id", "cboard");
        set("long",
		"这是沧海用来记事的工作笔记本。\n" );
        setup();
        set("capacity", 50);
        replace_program(BULLETIN_BOARD);
}
