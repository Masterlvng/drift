/*
 * conn.h
 *
 *  Created on: 2015年5月25日
 *      Author: zhangliangfu
 */

#ifndef CONN_H_
#define CONN_H_

#include "coro.h"

namespace drift
{
	class Conn
	{
	public:
		int read();
		int write();

	private:
		int fd;
		Coro* coro;

	};
};



#endif /* CONN_H_ */
