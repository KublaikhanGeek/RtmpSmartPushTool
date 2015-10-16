/*
 * =====================================================================================
 *
 *       Filename:  NetIO.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/10/15 13时46分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "NetIO.h"

NetIO::NetIO()
{

}

NetIO::~NetIO()
{

}

bool NetIO::InitConnect(const char* ipAddress)
{
		m_sockfd = socket(AF_INET,SOCK_STREAM,0);
		if(m_sockfd < 0)
		{
			cout<<"create connect socket error"<<std::endl;
			return 	false;	
		}
		struct sockaddr_in dest;
		memset(&dest,0,sizeof(struct sockaddr_in));
		dest.sin_family = AF_INET;
		dest.sin_addr.s_addr = inet_addr(ipAddress);
		dest.sin_port = htons(1935);
		int ret = 0;
		ret = connect(m_sockfd,(struct sockaddr*)(&dest),sizeof(dest));
		if(ret == -1)
		{
				cout<<"connect socket error"<<endl;
				return false;
		}
		return true;
}

bool NetIO::SendData(char* data, int datasize)
{
	int size = 0;
	char* tmpdata = data;
	while(datasize)
	{
		size = send(m_sockfd,tmpdata,datasize,0);
		if(size == -1)
		{
				cout<<"socket send data error"<<endl;
				return false;
		}
		tmpdata += size;
		datasize -= size;
	}
	return true;
}

bool NetIO::ReceiveData(char* data, int datasize)
{
	int readdata = datasize;
	int ret = 0;
	while(readdata)
	{
		ret = recv(m_sockfd,data+ret,readdata,0);
		if(ret == -1)
		{
				cout<<"recv data error"<<endl;
				return false;
		}
		else if(ret == 0)
		{
				cout<<"server has shutdown"<<endl;
				return false;
		}
		readdata -= ret;
	}
	return true;
}

