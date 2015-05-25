/*
 * buffer.h
 *
 *  Created on: 2015年5月25日
 *      Author: zhangliangfu
 */

#ifndef BUFFER_H_
#define BUFFER_H_

#include <string>

namespace drift
{
class Buffer{
	public:
		Buffer(int total);
		~Buffer();

		int total() const {
			return total_;
		}

		bool empty() const {
			return size_ == 0;
		}

		char* data() const {
			return data_;
		}

		int size() const {
			return size_;
		}

		char* slot() const {
			return data_ + size_;
		}

		int space() const {
			return total_ - (int)(data_ - buf) - size_;
		}

		void incr(int num) {
			size_ += num;
		}

		void decr(int num) {
			size_ -= num;
			data_ += num;
		}

		int append(char *buf, int size);

		void nice();
		int grow();

		std::string stats() const;

	private:
		char *buf;
		char *data_;
		int size_;
		int total_;
		int origin_total;
};
};


#endif /* BUFFER_H_ */
