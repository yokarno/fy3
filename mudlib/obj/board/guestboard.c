inherit BULLETIN_BOARD;

void create()
{
        set_name("访客留言板", ({ "board" }) );
        set("location", "/d/wiz/wizroom");
        set("board_id", "guestboard");
        set("long",
                "这是专供热心玩家给巫师们提意见和建议的留言板。\n
因本板不允许删除以前留言，故请想好后再动笔(post).\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
