#ifndef _worker_h_
#define _worker_h_

#include "pthread.h"

class threadpool;

class worker
{
public:
	worker();
	~worker();
	void init( threadpool *_pool );

public:
	static void *work( void *data );

private:
	threadpool *pool;
	pthread_t tid;
};

#endif//_worker_h_
