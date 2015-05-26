/*
 * coro.h
 *
 *  Created on: 2015年5月22日
 *      Author: zhangliangfu
 */

#ifndef CORO_H_
#define CORO_H_

#include <ucontext.h>

namespace drift
{
	typedef ucontext_t coro_context_t;

	struct coro_line_t
	{
	    coro_context_t caller;
	    coro_context_t callee;
	};

    #define PTHREAD_STACK_MIN 8192
    #define CORO_STACK_MIN   ((3 * (PTHREAD_STACK_MIN)) / 2)

	class Coro
	{
	public:
		enum {
		    CORO_ABORT = -1,
		    CORO_MAY_RESUME = 0,
		    CORO_FINISHED = 1
		};
		Coro(coro_line_t *l, void* data);
		virtual ~Coro();
		int resume();
		int resume(int value);
		int yield(int value);
		void* get_data();
		bool done();
		void setdone(bool done);
		virtual int proc() = 0;
		static void entry_point(Coro* coro);

	protected:
		struct coro_t
		{
			coro_line_t *line;
			coro_context_t context;
			int yield_value;
			void *data;
			bool isdone;
		};
		coro_t* coro;
	};

	class DriftCoro : public Coro
	{
	public:
		DriftCoro(coro_line_t *l, void* data);
		virtual ~DriftCoro();
		virtual int proc();
		virtual void handle() = 0;
	};
};



#endif /* CORO_H_ */
