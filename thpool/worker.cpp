#include "worker.h"
#include "threadpool.h"
#include "tasklist.h"

worker::worker()
{
}

worker::~worker()
{
}

void worker::init( threadpool *_pool )
{
	pool = _pool;

	pthread_create( &tid, NULL, worker::work, pool );
	pthread_detach( tid );
}

void *worker::work( void *data )
{
	threadpool *pool = (threadpool *)data;
    tasklist *t = (tasklist *)pool->list;
    ITask *task;

    while( pool->running )
    {
        t->wait();

        task = t->get_task();

        if( NULL != task )
        {
            task->do_task();

            delete task;
            task = NULL;
        }
    }
}
