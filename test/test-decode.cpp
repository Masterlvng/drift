/*
 * test-decode.cpp
 *
 *  Created on: 2015年5月25日
 *      Author: zhangliangfu
 */

#include "../message.h"
#include "../buffer.h"
#include <string>
#include <assert.h>
#include <stdio.h>

using namespace drift;
using namespace std;

int main()
{
	drift::Buffer b(128);
	string msg("oxffffeeee");
	int size = msg.size();
	b.append((char*)&size, 4);
	b.append((char*)msg.data(), size);
	drift::Decoder d(&b);
	string rst;
	int ret = d.read_32_data(&rst);
	assert(ret == size + 4);
	assert(rst == msg);
	printf("== decode passed\n");
	return 0;
}




