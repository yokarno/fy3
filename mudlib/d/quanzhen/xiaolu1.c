// xiaolu1.c ��ɽС·


inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
	�����Ǻ�ɽ�ϵ�С·������С·�������˹������޳����ģ�
Ҳ��ֻ����ǰ�Ĳ�ҩ�˲ȶ��ˣ��ֳ�����һ��С·����
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"xiaolu2",
		"southwest" : __DIR__"houshan",
	]));

	setup();
set("outdoors","/d/quanzhen");
	replace_program(ROOM);
}
