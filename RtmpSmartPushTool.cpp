/*
 * =====================================================================================
 *
 *       Filename:  RtmpSmartPushTool.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/10/15 13时36分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "RtmpSmartPushTool.h"
#include <time.h>
#include <string.h>
static const int C0C1SIZE = 1537;
static const int S0S1SIZE = 1537;
RtmpSmartPushTool::RtmpSmartPushTool()
{

}

RtmpSmartPushTool::~RtmpSmartPushTool()
{
		
}

bool RtmpSmartPushTool::ConnectServer(const char* ipaddress)
{
	if(!m_netio.InitConnect(ipaddress))
	{
		return false;	
	}
	return true;
}
	
bool RtmpSmartPushTool::RtmpHandShake()
{
	if(!CreateAndSendC0C1())
	{
			return false;
	}
	
	return true;
}

bool RtmpSmartPushTool::CreateAndSendC0C1()
{
	char *C0C1 = new char[C0C1SIZE];
	memset(C0C1,0,C0C1SIZE);
	int num = 0;
	*(C0C1+num) = 0x03;   //C0
	num++;
	time_t date = time(0);
	int netorderdate = htonl((int)date);
	memcpy(C0C1+num,&netorderdate,4);
	num+=4;
	Srs_random_generate(C0C1+num,C0C1SIZE-num);
	//after create begin send
	m_netio.SendData(C0C1,C0C1SIZE);
}




void RtmpSmartPushTool::Srs_random_generate(char* bytes,int size)
{
	static bool random_initialized = false;
	if(!random_initialized)
	{
			srand(0);
			random_initialized = true;
	}
	for(int i=0;i<size;i++)
	{
			bytes[i] = 0x0f + (rand() % (256 - 0x0f - 0x0f));
	}
}

bool RtmpSmartPushTool::CreateAndReceiveS0S1()
{
	char* S0S1 = new char[S0S1SIZE];
	memset(S0S1,0,S0S1SIZE);
	int num = 0;
	m_netio.ReceiveData(S0S1+num,1);
	num+=1;
	m_netio.ReceiveData(S0S1+num,S0S1SIZE-1);	
}
