#include<iostream>
#include<pthread.h>
#include<stdio.h>
#include<string.h>

#include "tasklist.h"

using namespace std;

void hello(void)
{
    cout << "hello:" << pthread_self() <<endl;
}

void *consumer( void *data )
{
    tasklist *t = (tasklist *)data;
    ITask *task;

    while( 1 )
    {
        t->wait();

        task = t->get_task();

        if( NULL != task )
        {
            task->do_task();

            delete task;
            task = NULL;
        }
        
        sleep(1);
    }
}

void *producer( void *data )
{
    tasklist *t = (tasklist *)data;
    ITask *task = NULL;
    int i = 0; 

    while( i < 4096 )
    {
        if( task == NULL )
            task = make_task( hello );

        if( t->put_task(task) == 0 )
        {
            task = NULL;
            i++;
        }

        sleep(1);
    }
}

int main( int argc, char **argv )
{
    pthread_t pid1;
    pthread_t pid[10];


    tasklist t;
    t.init(10,1);

    pthread_create( &pid1, NULL, producer, &t );

    for( int i = 0; i < 10; i++ )
    {
        pthread_create( &pid[i], NULL, consumer, &t );
    }

    pthread_join( pid1, NULL );
    for( int i = 0; i < 10; i++ )
    {
        pthread_join( pid[i], NULL );
    }

}
