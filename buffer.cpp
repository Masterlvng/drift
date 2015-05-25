/*
 * buffer.cpp
 *
 *  Created on: 2015年5月25日
 *      Author: zhangliangfu
 */

#include "buffer.h"

using namespace drift;

Buffer::Buffer(int total){
	size_ = 0;
	total_ = origin_total = total;
	buf = (char *)malloc(total);
	data_ = buf;
}

Buffer::~Buffer(){
	free(buf);
}

void Buffer::nice(){
	if(data_ - buf > total_/2){
		memcpy(buf, data_, size_);
		data_ = buf;
	}
}

int Buffer::grow(){
	int n;
	if(total_ < 8 * 1024){
		n = 8 * 1024;
	}else if(total_ < 512 * 1024){
		n = 8 * total_;
	}else{
		n = 2 * total_;
	}

	char *p = (char *)realloc(buf, n);
	if(p == NULL){
		return -1;
	}
	data_ = p + (data_ - buf);
	buf = p;
	total_ = n;
	return total_;
}

std::string Buffer::stats() const{
	char str[1024 * 32];
	str[0] = '\n';
	sprintf(str, "total: %d, data: %d, size: %d, slot: %d",
		total_, (int)(data_ - buf), size_, (int)(slot() - buf));
	return std::string(str);
}




