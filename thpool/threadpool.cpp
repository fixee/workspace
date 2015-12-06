#include "threadpool.h"

threadpool::threadpool():min_worker(0),max_worker(0),running(false),list(NULL)
{
}

threadpool::~threadpool()
{
}

void threadpool::init( int _min_worker_cnt, int _max_worker_cnt, int _producer )
{
	min_worker = _min_worker_cnt;
	max_worker = _max_worker_cnt;

	list = new tasklist;
	list->init( min_worker, _producer );

	running = true;

	for( int i = 0; i < min_worker; i++ )
	{
		worker *w = new worker;
		w->init( this );
		vec.push_back(w);
	}
}
