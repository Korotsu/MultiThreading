#if !defined(THREAD_HPP)
#define THREAD_HPP

#include <thread>
#include <future>
class Thread
{
public:
    std::thread* thread;
    std::future<void> future;
public:
    Thread(std::thread* _thread) : thread(_thread) {};
    ~Thread(){};
};


#endif // THREAD_HPP
