#pragma once
#include <ThostFtdcMdApi.h>

class myThostFtdcMdSpi :
	public CThostFtdcMdSpi
{
public:
	myThostFtdcMdSpi() {};
	myThostFtdcMdSpi(CThostFtdcMdApi *p) :pMdApi(p) {};
	~myThostFtdcMdSpi() {};

	virtual void OnFrontConnected();
	virtual void OnFrontDisconnected(int nReason);
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);

private:
	CThostFtdcMdApi *pMdApi;
};

