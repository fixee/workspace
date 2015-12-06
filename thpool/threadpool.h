#ifndef _threadpool_h_
#define _threadpool_h_

#include <vector>

#include "tasklist.h"
#include "worker.h"

class threadpool
{
public:
	threadpool();
	~threadpool();

public:
    void init( int _min_worker_cnt, int _max_worker_cnt, int _producer );

	template<typename F>
	int put_task( F f )
	{
		ITask *task = new Task<F>(f);
		return list->put_task( task );
	}

	template<typename F, typename T1>
	int put_task( F f, T1 t1)
	{
		ITask *task = new Task1<F,T1>(f,t1);
		return list->put_task( task );
	}

	template<typename F, typename T1, typename T2>
	int put_task( F f, T1 t1, T2 t2)
	{
		ITask *task = new Task2<F,T1,T2>(f,t1,t2);
		return list->put_task( task );
	}

	template<typename F, typename T1, typename T2, typename T3>
	int put_task( F f, T1 t1, T2 t2, T3 t3)
	{
		ITask *task = new Task3<F,T1,T2,T3>(f,t1,t2,t3);
		return list->put_task( task );
	}

	template<typename F, typename T1, typename T2, typename T3, typename T4>
	int put_task( F f, T1 t1, T2 t2, T3 t3, T4 t4)
	{
		ITask *task = new Task4<F,T1,T2,T3,T4>(f,t1,t2,t3,t4);
		return list->put_task( task );
	}

	template<typename F, typename T1, typename T2, typename T3, typename T4, typename T5>
	int put_task( F f, T1 t1, T2 t2, T3 t3, T4 t4, T5 t5)
	{
		ITask *task = new Task5<F,T1,T2,T3,T4,T5>(f,t1,t2,t3,t4,t5);
		return list->put_task( task );
	}

	template<typename F, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	int put_task( F f, T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6)
	{
		ITask *task = new Task6<F,T1,T2,T3,T4,T5,T6>(f,t1,t2,t3,t4,t5,t6);
		return list->put_task( task );
	}

	template<typename F, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
	int put_task( F f, T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6, T7 t7)
	{
		ITask *task = new Task7<F,T1,T2,T3,T4,T5,T6,T7>(f,t1,t2,t3,t4,t5,t6,t7);
		return list->put_task( task );
	}

	template<typename F, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
	int put_task( F f, T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6, T7 t7, T8 t8)
	{
		ITask *task = new Task8<F,T1,T2,T3,T4,T5,T6,T7,T8>(f,t1,t2,t3,t4,t5,t6,t7,t8);
		return list->put_task( task );
	}

	template<typename F, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
	int put_task( F f, T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6, T7 t7, T8 t8, T9 t9)
	{
		ITask *task = new Task9<F,T1,T2,T3,T4,T5,T6,T7,T8,T9>(f,t1,t2,t3,t4,t5,t6,t7,t8,t9);
		return list->put_task( task );
	}

public:
	tasklist *list;
	bool running;

private:
	int min_worker;
	int max_worker;
	std::vector<worker *> vec;
};


#endif//_threadpool_h_
