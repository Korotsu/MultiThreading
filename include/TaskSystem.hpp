#if !defined(TASKSYSTEM_HPP)
#define TASKSYSTEM_HPP

#include <iostream>
#include <vector>
#include <future>
#include "Task.hpp"
#include "ThreadPool.hpp"

void UpdateTaskSystem(class TaskSystem* taskManager);

class TaskSystem
{
public:
    bool alreadyInit = false;
    std::vector<Task> taskList;
    ThreadPool        threadPool;  
public:

    TaskSystem() = default;
    ~TaskSystem() = default;

    template<typename FUNCTION, typename ... ARGS>
    void Add(PriorityEnum _priority, FUNCTION &&function, ARGS &&... args)
    {
        taskList.emplace_back(Task(_priority,function,args...));
    }

    void Add(Task t1)
    {
        taskList.emplace_back(t1);
    }

    void RunMono(int index)
    {
        if (taskList.size() >= index)
        {
            //(taskList[index])();
        }
    }

    void Run(int taskNumber, int threadNumber)
    {
        //std::cout << "Task of priority : " << taskList[taskNumber].priority << " Started ! And index is : " << taskNumber << " !" << std::endl; /* Print the priority in the console log */
        std::packaged_task<void()> task(taskList[taskNumber]);
        threadPool.threadList[threadNumber]->future = task.get_future();
        threadPool.threadList[threadNumber]->thread = new std::thread(std::move(task));
        taskList.erase(taskList.cbegin() + taskNumber);
    }

    void Init()
    {
        if (!alreadyInit)
        {
            std::thread t1(UpdateTaskSystem,this);
            t1.detach();
        }
        
    }

    int CheckTaskPriority()
    {
        int taskIndex = 0;
        for (int i = 0; i < taskList.size() ; i++)
        {
            if (taskList[taskIndex].priority < taskList[i].priority)
            {
                taskIndex = i;
                if (taskList[taskIndex].priority == PriorityEnum::Max)
                {
                    return taskIndex;
                }
            }
        }

        return taskIndex;
    }
};

void UpdateTaskSystem(TaskSystem* taskManager)
{
    if (taskManager->taskList.size() > 0)
    {
        //std::cout << "Start Task Checking" << std::endl;
        int taskNumber   = taskManager->CheckTaskPriority();
        int threadNumber = taskManager->threadPool.CheckThreadsAvailability();

        if (threadNumber >= 0)
        {
            taskManager->Run(taskNumber,threadNumber);
        }

        //std::cout << "End Task Checking" << std::endl;
    }
    UpdateTaskSystem(taskManager);
}

#endif // TASKSYSTEM_HPP
