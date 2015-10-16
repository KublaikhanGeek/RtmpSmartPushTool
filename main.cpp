/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description: 
 *
 *        Version:  1.0
 *        Created:  2015/10/15 16时09分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "RtmpSmartPushTool.h"
int main(int argc, char** argv)
{
	RtmpSmartPushTool rtmptool;
	if(!rtmptool.ConnectServer("10.2.68.82"))
	{
			cout<<"rtmp connect server error"<<endl;
			return 0;
	}
	rtmptool.RtmpHandShake();
	return 0;
}
