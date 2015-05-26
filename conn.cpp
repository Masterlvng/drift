/*
 * conn.cpp
 *
 *  Created on: 2015年5月25日
 *      Author: zhangliangfu
 */

#include "conn.h"

using namespace drift;

Conn::Conn(int fd, Coro* c, Decoder* d): fd_(fd), coro_(c), d_(d)
{
	input_  = new Buffer(16 * 1024); //16K
	output_ = new Buffer(16 * 1024); //16K
}

Conn::~Conn()
{
	delete input_;
	delete output_;
}

int Conn::read()
{
	return 0;
}

int Conn::write()
{
	return 0;
}

int Conn::parse(std::string* ret)
{
	return 0;
}

int Conn::connect(char* ip, int port)
{
	return 0;
}


