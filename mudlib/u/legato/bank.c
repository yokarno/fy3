#include <room.h>
inherit ROOM;

void create()
{
      set("short","����԰");
      set("long",@LONG
������ɽׯ���е�һ����԰��ֻ��������ݺ�������ݱ̻�Ũ�����ⰻȻ��
�����һ�����������濪���˺ɻ����������ĵļ�ɽ�������֣���֪������
���п�����Ȫ���٣����齦�񣬷������£���ǻ��㣬���ֿ�����   ˮ��
���ѣ���Ӱ���档�ұ���һƬ��������Ȼ�����ǿ�����ʱ�ڣ�������Щ��
�������Ĳ�������������е�������ˬ���ݴ�����ЩС�����������௵�
�е�������
LONG);
           set("exits",([ /* sizeof() == 1 */
          "east"  : __DIR__"liangongfang",
          "west"  : __DIR__"path2",
          "north" : __DIR__"path1",
          "south" : __DIR__"path",
      ]));
      setup();
}

