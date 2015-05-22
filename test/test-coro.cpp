/*
 * test-coro.cpp
 *
 *  Created on: 2015年5月22日
 *      Author: zhangliangfu
 */

#include "../coro.h"
#include <iostream>
#include <string>

using namespace drift;
using namespace std;

class HelloCoro: public Coro
{
public:
	HelloCoro(string name, coro_line_t *l, void* data): Coro(l, data)
	{
		this->name = name;
	}
	~HelloCoro()
	{}
	int proc()
	{
		cout << "hello i m " << name << endl;
		int flag = 1;
		cout << "ddd " << name << " have a phone call" << endl;
		yield(flag);
		cout << name << " back" << endl;
		return 1;
	}

private:
	string name;
};

int main()
{
	coro_line_t l;
	HelloCoro* lilei = new HelloCoro("lilei", &l, 0);
	lilei->resume();
//	HelloCoro* mary  = new HelloCoro("mary", &l, 0);
//	mary->resume();
//	HelloCoro* tom = new HelloCoro("tom", &l, 0);
//	tom->resume();
	return 0;
}



