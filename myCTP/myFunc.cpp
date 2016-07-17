#include <string>
#include "myFunc.h"

void retPrint(int ret)
{
	switch (ret)
	{
	case 0:printf_s("发送成功\n"); break;
	case -1:printf_s("因网络原因发送失败\n"); break;
	case -2:printf_s("未处理请求队列总数量超限\n"); break;
	case -3:printf_s("每秒发送请求数量超限\n"); break;
	}
}
