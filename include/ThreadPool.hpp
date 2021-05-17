#if !defined(MACRO)
#define MACRO

#include "Thread.hpp"
#include <array>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>

class ThreadPool {
public:
    //std::vector<Thread*> threadList;
    std::array<Thread*, 8> threadList;

public:
    ThreadPool();
    ~ThreadPool();

    int CheckThreadsAvailability()
    {
        for (int i = 0; i < threadList.size(); i++) {
            if (!threadList[i]->thread) {
                //std::cout << "Le Thread numero : " << i << " est null !" << std::endl;
                return i;
            }

            else if (threadList[i]->future.valid()) {
                auto status = threadList[i]->future.wait_for(std::chrono::microseconds(1));

                if (status == std::future_status::ready) {
                    //std::cout << "Le Thread numero : " << i << " est disponible !" << std::endl;
                    threadList[i]->thread->join();
                    return i;
                }

                else {
                    //std::cout << "Le Thread numero : " << i << " est toujours en execution !" << std::endl;
                }
            }
        }

        return -1;
    }
};

/*ThreadPool::ThreadPool()
{
   for (int i = 0; i < std::thread::hardware_concurrency() ; ++i)
   {
        threadList.push_back(new Thread(nullptr,false));
   }
}*/

ThreadPool::ThreadPool()
{
    for (int i = 0; i < threadList.size(); ++i) {
        threadList[i] = new Thread(nullptr);
    }
}

ThreadPool::~ThreadPool()
{
}

#endif // MACRO
