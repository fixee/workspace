#include "tasklist.h"
#include <string.h>

void tasklist::wait()
{
    pthread_mutex_lock( &mutex );
    while( head == tail )
    {
        pthread_cond_wait( &cond, &mutex );
    }
    pthread_mutex_unlock( &mutex );
}

void tasklist::post( bool b_all )
{
    pthread_mutex_lock( &mutex );
    if( !b_all )
        pthread_cond_signal( &cond );
    else
        pthread_cond_broadcast( &cond );
    pthread_mutex_unlock( &mutex );
}

tasklist::tasklist():head(NULL),tail(NULL),c_need_lock(false),p_need_lock(false)
{
	tail = new tasknode;
	head = tail;
}

tasklist::~tasklist()
{
    pthread_mutex_destroy( &mutex );
    pthread_cond_destroy( &cond );

    pthread_mutex_destroy( &p_lock );
    pthread_mutex_destroy( &c_lock );
}

void tasklist::init( size_t c_cnt, size_t p_cnt )
{
    pthread_mutex_init( &mutex, NULL );
    pthread_cond_init( &cond, NULL );

    pthread_mutex_init( &p_lock, NULL );
    pthread_mutex_init( &c_lock, NULL );

    if( c_cnt > 1 )
        c_need_lock = true;

    if( p_cnt > 1 )
        p_need_lock = true;
}

ITask *tasklist::get_task()
{
    ITask *t = NULL;
	tasknode *node;
    if( c_need_lock )
        pthread_mutex_lock( &c_lock );

    if( tail != head )
    {
        t = head->task;
		node = head;
		head = head->next;
		delete node;
    }

    if( c_need_lock )
        pthread_mutex_unlock( &c_lock );

    return t;
}

int tasklist::put_task( ITask *t )
{
    if( p_need_lock )
        pthread_mutex_lock( &p_lock );

	tasknode *node = new tasknode;
	tail->task = t;
	tail->next = node;
	tail = node;
    post();

    if( p_need_lock )
        pthread_mutex_unlock( &p_lock );

    return 0;
}
