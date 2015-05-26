/*
 * coro.cpp
 *
 *  Created on: 2015年5月22日
 *      Author: zhangliangfu
 */

#include "coro.h"
#include "conn.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

using namespace drift;

Coro::Coro(coro_line_t *l, void* data)
{
	this->coro =  (coro_t*)malloc(sizeof(coro_t) + CORO_STACK_MIN);
	assert(this->coro);
	this->coro->line     = l;
	this->coro->data     = data;
	this->coro->isdone   = false;
	this->coro->yield_value = 0;

	unsigned char *stack = (unsigned char *)(this->coro + 1);
	getcontext(&coro->context);

	coro->context.uc_stack.ss_sp = stack;
	coro->context.uc_stack.ss_size = CORO_STACK_MIN;
	coro->context.uc_stack.ss_flags = 0;
	coro->context.uc_link = NULL;

	makecontext(&coro->context, (void (*)())&Coro::entry_point, 1, this);
}

Coro::~Coro()
{
	free(this->coro);
}

int Coro::resume()
{
	assert(coro);
	assert(coro->isdone == false);

	swapcontext(&coro->line->caller, &coro->context);
	if (!coro->isdone)
	   memcpy(&coro->context, &coro->line->callee, sizeof(coro->context));
	return coro->yield_value;
}

int Coro::resume(int value)
{
    assert(coro);
    assert(coro->isdone == false);

    coro->yield_value = value;
    return resume();
}

int Coro::yield(int value)
{
    assert(coro);
    coro->yield_value = value;
    swapcontext(&coro->line->callee, &coro->line->caller);
    return coro->yield_value;
}

void* Coro::get_data()
{
	return this->coro->data;
}

bool Coro::done()
{
	return this->coro->isdone;
}

void Coro::setdone(bool done)
{
	this->coro->isdone = done;
}

void Coro::entry_point(Coro* coro)
{
    int return_value = coro->proc();
    coro->setdone(true);
    coro->yield(return_value);
}

DriftCoro::DriftCoro(coro_line_t *l, void* data):Coro(l, data)
{

}

DriftCoro::~DriftCoro()
{

}

int DriftCoro::proc()
{
	Conn *conn = (Conn*)get_data();
	while(true)
	{
		//prepare message

		//handle message
	}
	return CORO_FINISHED;
}

