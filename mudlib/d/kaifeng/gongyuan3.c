// Room: /d/yangzhou/gongyuan.c

inherit ROOM;
#include <localtime.h>
int now_time();
void create()
{
	set("short", "开封贡院");
	set("long", @LONG
过了州桥，街道边一处高深的大院，威武的石狮守卫两边，门楣上[贡院]两字作
深红色，每月上旬，此处将进行举人的开考，门边墙上贴了张告示(gaoshi).
LONG
	);
	set("no_magic", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhukao3.c" : 1,
]));
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "gaoshi" : "本处限考举人
1.凡已考中举人或以上功名者，不得入考。
2.读书写字未满60级者，不得入考。
3.非秀才者不得入考,开考仅限于每月上旬，即1-10日。
4.使用[exam]请主考官出题，用[answer .....]回答问题。
5.回答问题限时3分钟.
6.若回答不对，请明天再来。
7.答题时间离开考场，作弃权论。
注意 回答的最后请勿加任何标点符号。
",
]));
	set("light_up", 1);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road2",
]));
	set("no_fight", 1);
        set("no_steal",1);
        set("no_sleep",1);

	setup();
}
int valid_leave(object me, string dir)
{
  if (dir=="east"&&me->query_temp("xxy/answer")){
  tell_room(this_object(),me->query("name")+"摇摇头长叹一声：看来我还得多读两年!\n");
  me->delete_temp("xxy");
  me->set("xxy/last_check",now_time());
   }
        return ::valid_leave(me, dir);
}
int now_time()
{int i;
 object ob=this_player();
 mixed *local;
 local = localtime(time()*60);
 i=local[LT_MDAY] + (local[LT_HOUR]>23? 1 : 0);
 return i;
}
