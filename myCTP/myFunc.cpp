#include <string>
#include "myFunc.h"

void retPrint(int ret)
{
	switch (ret)
	{
	case 0:printf_s("���ͳɹ�\n"); break;
	case -1:printf_s("������ԭ����ʧ��\n"); break;
	case -2:printf_s("δ���������������������\n"); break;
	case -3:printf_s("ÿ�뷢��������������\n"); break;
	}
}
