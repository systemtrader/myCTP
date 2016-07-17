#include <string>
#include "myThostFtdcMdSpi.h"
#include "myThostFtdcTraderSpi.h"

int requestID = 0;
CThostFtdcReqUserLoginField req;

int main() {
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, "9999");
	strcpy_s(req.UserID, "054888");
	strcpy_s(req.Password, "538418");

	CThostFtdcMdApi *pMdApi = CThostFtdcMdApi::CreateFtdcMdApi(".\\mdflow\\");
	myThostFtdcMdSpi *pMdSpi = new myThostFtdcMdSpi(pMdApi);
	pMdApi->RegisterSpi(pMdSpi);
	pMdApi->RegisterFront("tcp://180.168.146.187:10031");
	pMdApi->Init();
	pMdApi->Join();

	/*CThostFtdcTraderApi *pTdApi = CThostFtdcTraderApi::CreateFtdcTraderApi(".\\tdflow\\");
	myThostFtdcTraderSpi *pTdSpi = new myThostFtdcTraderSpi(pTdApi);
	pTdApi->RegisterSpi(pTdSpi);
	pTdApi->RegisterFront("tcp://180.168.146.187:10030");
	pTdApi->SubscribePublicTopic(THOST_TERT_QUICK);
	pTdApi->SubscribePrivateTopic(THOST_TERT_QUICK);
	pTdApi->Init();
	pTdApi->Join();*/

	return 0;
}