/*
 * conn.h
 *
 *  Created on: 2015年5月25日
 *      Author: zhangliangfu
 */

#ifndef CONN_H_
#define CONN_H_

#include "coro.h"
#include "buffer.h"
#include "message.h"

#include <string>

namespace drift
{
	class Conn
	{
	public:
		Conn(int fd, Coro* c, Decoder* d);
		~Conn();
		int read();
		int write();
		int parse(std::string* ret); //parse input buffer. try to get complete message
		int connect(char* ip, int port);

	private:
		int fd_;
		Coro* coro_;
		Buffer* input_;
		Buffer* output_;
		Decoder* d_;
	};
};



#endif /* CONN_H_ */
