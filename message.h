/*
 * message.h
 *
 *  Created on: 2015年5月25日
 *      Author: duowan-PC
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>
#include <stdint.h>
#include "buffer.h"
class Message;

namespace drift
{
class Decoder{
	public:
		Decoder(Buffer *b)
		{
			this->b_ = b;
		}

		virtual ~Decoder()
		{

		}

		int skip(int n)
		{
			if(b_->size() < n){
				return -1;
			}
			b_->decr(n);
			return n;
		}

		int read_int64(int64_t *ret)
		{
			if(size_t(b_->size()) < sizeof(int64_t))
			{
				return -1;
			}
			if(ret)
			{
				*ret = *(int64_t *)b_->data();
			}
			b_->decr(sizeof(int64_t));
			return sizeof(int64_t);
		}

		int read_uint64(uint64_t *ret)
		{
			if(size_t(b_->size()) < sizeof(uint64_t))
			{
				return -1;
			}
			if(ret)
			{
				*ret = *(uint64_t *)b_->data();
			}
			b_->decr(sizeof(uint64_t));
			return sizeof(uint64_t);
		}

		int read_int32(int32_t *ret)
		{
			if(size_t(b_->size()) < sizeof(int32_t))
			{
				return -1;
			}
			if(ret)
			{
				*ret = *(int32_t *)b_->data();
			}
			b_->decr(sizeof(int32_t));
			return sizeof(int32_t);
		}

		int read_uint32(uint32_t *ret)
		{
			if(size_t(b_->size()) < sizeof(uint32_t))
			{
				return -1;
			}
			if(ret)
			{
				*ret = *(uint32_t *)b_->data();
			}
			b_->decr(sizeof(uint32_t));
			return sizeof(uint32_t);
		}

		int32_t read_8_data(std::string *ret=NULL); //length prefix datagram

		int32_t read_32_data(std::string *ret=NULL); //length prefix datagram

		virtual int32_t read_data(std::string *ret); //need user define



	protected:
		Buffer *b_;
	};

}



#endif /* MESSAGE_H_ */
