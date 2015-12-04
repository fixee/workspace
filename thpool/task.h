#ifndef _task_h_
#define _task_h_

class ITask
{
public:
    virtual void do_task() = 0;
};

template<typename F>
class Task : public ITask
{
public:
    Task( F _f ):f(_f){}
    void do_task()
    {
        f();
    }

private:
    F f;
};

template<typename F>
ITask *make_task( F _f )
{
    ITask * task = new Task<F>( _f );
    return task;
}


#endif//_task_h_

