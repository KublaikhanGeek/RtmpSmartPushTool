/*
 * =====================================================================================
 *
 *       Filename:  NetIO.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/10/15 13时46分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef NET_IO_H
#define NET_IO_H
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
using namespace std;
class NetIO
{
	public:
		NetIO();
		~NetIO();
		bool InitConnect(const char* ipAddress);
		bool SendData(char* data, int datasize);
		bool ReceiveData(char** data, int& datasize);
	private:
		int m_sockfd;
};

#endif
