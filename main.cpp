#include<iostream>
#include<pthread.h>
#include<stdio.h>
#include<string.h>

#include "thpool/tasklist.h"
#include "thpool/threadpool.h"

using namespace std;

void hello(void)
{
    cout << "hello:" << pthread_self() <<endl;
}

void hello1( int a )
{
	cout << "hello" << a << endl;
}

int main( int argc, char **argv )
{
	threadpool *pool = new threadpool;
	pool->init(10, 20, 2 );

    ITask *task = NULL;
    int i = 0; 

    while( i < 100 )
    {
        if( pool->put_task( hello1, i ) == 0 )
        {
            task = NULL;
            i++;
        }

		sleep(1);
    }

	sleep(1);
}
