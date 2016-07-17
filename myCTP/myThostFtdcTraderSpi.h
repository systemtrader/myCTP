#pragma once
#include <ThostFtdcTraderApi.h>

class myThostFtdcTraderSpi :
	public CThostFtdcTraderSpi
{
public:
	myThostFtdcTraderSpi() {};
	myThostFtdcTraderSpi(CThostFtdcTraderApi *p) :pTdApi(p) {};
	~myThostFtdcTraderSpi() {};

	virtual void OnFrontConnected();
	virtual void OnFrontDisconnected(int nReason);
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

private:
	CThostFtdcTraderApi *pTdApi;
};

