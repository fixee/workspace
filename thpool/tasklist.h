#ifndef _tasklist_h_
#define _tasklist_h_

#include "task.h"
#include<pthread.h>

struct tasknode
{
	ITask *task;
	tasknode *next;
};

class tasklist
{
public:
    tasklist();
    ~tasklist();

    void init( size_t c_cnt, size_t p_cnt );

    void wait();
    void post( bool b_all = false );

    ITask *get_task();
    int put_task( ITask *t );

private:
    pthread_mutex_t mutex;
    pthread_cond_t cond;
private:
    pthread_mutex_t p_lock;
    pthread_mutex_t c_lock;

	tasknode *head;
	tasknode *tail;

    bool c_need_lock, p_need_lock;
};

#endif//_tasklist_h_
