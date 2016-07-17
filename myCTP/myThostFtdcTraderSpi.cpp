#include <string>
#include "myThostFtdcTraderSpi.h"
#include "myFunc.h"

extern int requestID;
extern CThostFtdcReqUserLoginField req;

void myThostFtdcTraderSpi::OnFrontConnected()
{
	printf_s("tdOnFrontConnected\n");
	printf_s("tdReqUserLogin£¬");
	retPrint(pTdApi->ReqUserLogin(&req, ++requestID));
}

void myThostFtdcTraderSpi::OnFrontDisconnected(int nReason)
{
	printf_s("tdOnFrontDisconnected:%d\n", nReason);
}

void myThostFtdcTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField * pRspUserLogin, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
	printf_s("tdOnRspUserLogin\n");
	if (pRspInfo->ErrorID == 0) {
		printf("SessionID£º%d£¬FrontID£º%d£¬MaxOrderRef£º%s\n", pRspUserLogin->SessionID, pRspUserLogin->FrontID, pRspUserLogin->MaxOrderRef);
		CThostFtdcSettlementInfoConfirmField settlementInfoConfirm;
		memset(&req, 0, sizeof(settlementInfoConfirm));
		strcpy_s(settlementInfoConfirm.BrokerID, "9999");
		strcpy_s(settlementInfoConfirm.InvestorID, "054888");
		printf("ReqSettlementInfoConfirm£¬");
		retPrint(pTdApi->ReqSettlementInfoConfirm(&settlementInfoConfirm, ++requestID));
	}
	else {
		printf_s("ErrorID:%d£¬ErrorMsg:%s", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
	}
}

void myThostFtdcTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField * pSettlementInfoConfirm, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
	printf_s("OnRspSettlementInfoConfirm\n");
}
