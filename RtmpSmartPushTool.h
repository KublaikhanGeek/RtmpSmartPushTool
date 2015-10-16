/*
 * =====================================================================================
 *
 *       Filename:  RtmpSmartPushTool.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/10/15 13时36分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef RTMP_SMART_PUSH_TOOL_H
#define RTMP_SMART_PUSH_TOOL_H
#include "NetIO.h"
class RtmpSmartPushTool
{
	public:
		RtmpSmartPushTool();
		~RtmpSmartPushTool();
		bool ConnectServer(const char* ipaddress);
		bool RtmpHandShake();
	private:
		bool CreateAndSendC0C1();
		bool CreateAndReceiveS0S1();
		void Srs_random_generate(char* bytes,int size);
	private:
		NetIO m_netio;
};

#endif
