#include <string>
#include "myThostFtdcMdSpi.h"
#include "myFunc.h"

extern int requestID;
extern CThostFtdcReqUserLoginField req;

void myThostFtdcMdSpi::OnFrontConnected()
{
	printf_s("mdOnFrontConnected\n");
	printf_s("mdReqUserLogin£¬");
	retPrint(pMdApi->ReqUserLogin(&req, ++requestID));
}

void myThostFtdcMdSpi::OnFrontDisconnected(int nReason)
{
	printf_s("mdOnFrontDisconnected:%d\n", nReason);
}

void myThostFtdcMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField * pRspUserLogin, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
	printf_s("mdOnRspUserLogin\n");
	if (pRspInfo->ErrorID == 0) {
		//printf("SessionID£º%d£¬FrontID£º%d£¬MaxOrderRef£º%s\n",pRspUserLogin->SessionID,pRspUserLogin->FrontID,pRspUserLogin->MaxOrderRef);
		char *InstrumentID[] = { "IH1607" };
		printf_s("mdSubscribeMarketData£¬");
		retPrint(pMdApi->SubscribeMarketData(InstrumentID, 1));
	}
	else {
		printf_s("ErrorID:%d£¬ErrorMsg:%s", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
	}
}

void myThostFtdcMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField * pSpecificInstrument, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
	printf_s("mdOnRspSubMarketData\n");
	if (pRspInfo->ErrorID != 0) {
		printf_s("ErrorID:%d£¬ErrorMsg : %s\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
	}
}

void myThostFtdcMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField * pDepthMarketData)
{
	printf_s("%f,%s,%d\n", pDepthMarketData->LastPrice,pDepthMarketData->UpdateTime,pDepthMarketData->UpdateMillisec);

}
