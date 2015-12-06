#ifndef _task_h_
#define _task_h_

class ITask
{
public:
    virtual void do_task() = 0;
};

template<typename F>
class Task: public ITask
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

template<typename F, typename T1>
class Task1: public ITask
{
public:
	Task1( F _f, T1 _t1 ):f(_f),t1(_t1){}
    void do_task()
    {
        f( t1 );
    }
private:
	F f;
	T1 t1;
};

template<typename F, typename T1, typename T2>
class Task2: public ITask
{
public:
	Task2( F _f, T1 _t1, T2 _t2 ):f(_f),t1(_t1),t2(_t2){}
    void do_task()
    {
        f( t1, t2 );
    }
private:
	F f;
	T1 t1;
	T2 t2;
};

template<typename F, typename T1, typename T2, typename T3>
class Task3: public ITask
{
public:
	Task3( F _f, T1 _t1, T2 _t2, T3 _t3 ):f(_f),t1(_t1),t2(_t2),t3(_t3){}
    void do_task()
    {
        f( t1, t2, t3 );
    }
private:
	F f;
	T1 t1;
	T2 t2;
	T3 t3;
};

template<typename F, typename T1, typename T2, typename T3, typename T4>
class Task4: public ITask
{
public:
	Task4( F _f, T1 _t1, T2 _t2, T3 _t3, T4 _t4 ):f(_f),t1(_t1),t2(_t2),t3(_t3),t4(_t4){}
    void do_task()
    {
        f( t1, t2, t3, t4 );
    }
private:
	F f;
	T1 t1;
	T2 t2;
	T3 t3;
	T4 t4;
};

template<typename F, typename T1, typename T2, typename T3, typename T4, typename T5>
class Task5: public ITask
{
public:
	Task5( F _f, T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5 ):f(_f),t1(_t1),t2(_t2),t3(_t3),t4(_t4),t5(_t5){}
    void do_task()
    {
        f( t1, t2, t3, t4, t5 );
    }
private:
	F f;
	T1 t1;
	T2 t2;
	T3 t3;
	T4 t4;
	T5 t5;
};

template<typename F, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Task6: public ITask
{
public:
	Task6( F _f, T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6 ):f(_f),t1(_t1),t2(_t2),t3(_t3),t4(_t4),t5(_t5),t6(_t6){}
    void do_task()
    {
        f( t1, t2, t3, t4, t5, t6 );
    }
private:
	F f;
	T1 t1;
	T2 t2;
	T3 t3;
	T4 t4;
	T5 t5;
	T6 t6;
};

template<typename F, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
class Task7: public ITask
{
public:
	Task7( F _f, T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6, T7 _t7 ):f(_f),t1(_t1),t2(_t2),t3(_t3),t4(_t4),t5(_t5),t6(_t6),t7(_t7){}
    void do_task()
    {
        f( t1, t2, t3, t4, t5, t6, t7 );
    }
private:
	F f;
	T1 t1;
	T2 t2;
	T3 t3;
	T4 t4;
	T5 t5;
	T6 t6;
	T7 t7;
};

template<typename F, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
class Task8: public ITask
{
public:
	Task8( F _f, T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6, T7 _t7, T8 _t8 ):f(_f),t1(_t1),t2(_t2),t3(_t3),t4(_t4),t5(_t5),t6(_t6),t7(_t7),t8(_t8){}
    void do_task()
    {
        f( t1, t2, t3, t4, t5, t6, t7, t8 );
    }
private:
	F f;
	T1 t1;
	T2 t2;
	T3 t3;
	T4 t4;
	T5 t5;
	T6 t6;
	T7 t7;
	T8 t8;
};

template<typename F, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
class Task9: public ITask
{
public:
	Task9( F _f, T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6, T7 _t7, T8 _t8, T9 _t9 ):f(_f),t1(_t1),t2(_t2),t3(_t3),t4(_t4),t5(_t5),t6(_t6),t7(_t7),t8(_t8),t9(_t9){}
    void do_task()
    {
        f( t1, t2, t3, t4, t5, t6, t7, t8, t9 );
    }
private:
	F f;
	T1 t1;
	T2 t2;
	T3 t3;
	T4 t4;
	T5 t5;
	T6 t6;
	T7 t7;
	T8 t8;
	T9 t9;
};


#endif//_task_h_

