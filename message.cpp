/*
 * message.cpp
 *
 *  Created on: 2015年5月25日
 *      Author: zhangliangfu
 */

#include "message.h"

using namespace drift;

int32_t Decoder::read_8_data(std::string *ret) //length prefix datagram
{
	if(b_->size() < 1)
	{
		return -1;
	}
	int32_t len = (uint8_t)b_->data()[0];
	b_->decr(1);
	if(b_->size() < len)
	{
		return -1;
	}
	if(ret)
	{
		ret->assign(b_->data(), b_->size());
	}
	b_->decr(len);
	return 1 + len;
}

int32_t Decoder::read_32_data(std::string *ret) //length prefix datagram
{
	if(b_->size() < 1)
	{
		return -1;
	}
	int32_t len = 0;
	read_int32(&len);
	if(b_->size() < len)
	{
		return -1;
	}
	if(ret)
	{
		ret->assign(b_->data(), b_->size());
	}
	b_->decr(len);
	return sizeof(uint32_t) + len;
}

int32_t Decoder::read_data(std::string *ret) //need user define
{
	int32_t n = b_->size();
	if(ret)
	{
		ret->assign(b_->data(), b_->size());
	}
	b_->decr(n);
	return n;
}




