#include <iostream>
//#include <utility>
#include <thread>
#include <chrono>
#include <algorithm>
#include <array>
#include "TaskSystem.hpp"

void foo(int a)
{
    for (long long i = 0; i < 100000000; i++)
    {}
    
    //while (true);
    std::cout << a << std::endl;
}

int main()
{
    std::cout << "START PROGRAM !" << std::endl;

    std::cout << "Le nombre de thread pouvant être utiliser par votre ordinateur est : " << std::thread::hardware_concurrency() << " !" << std::endl;
    std::cout << "Monothread : " << std::endl;

    auto start = std::chrono::system_clock::now();

    foo(25);
    foo(25);
    foo(25);
    foo(25);
    foo(25);
    foo(25);
    foo(25);
    foo(25);
    foo(25);
    foo(25);
    foo(75);
    foo(25);
    foo(25);
    foo(25);
    foo(25);
    foo(25);
    foo(25);
    foo(25);
    foo(20);
    foo(20);
    foo(20);
    foo(20);
    foo(20);
    foo(20);

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << elapsed.count() << std::endl;

    std::cout << "Multithread : " << std::endl;

    start = std::chrono::system_clock::now();

    auto taskManager = TaskSystem();
    taskManager.Init();
    taskManager.Add(PriorityEnum::Bonus,foo,25);
    taskManager.Add(PriorityEnum::Bonus,foo,25);
    taskManager.Add(PriorityEnum::Small,foo,2);
    taskManager.Add(PriorityEnum::Medium,foo,55);
    taskManager.Add(PriorityEnum::Bonus,foo,25);
    taskManager.Add(PriorityEnum::Bonus,foo,25);
    taskManager.Add(PriorityEnum::Bonus,foo,25);
    taskManager.Add(PriorityEnum::Critical,foo,37);
    taskManager.Add(PriorityEnum::Bonus,foo,25);
    taskManager.Add(PriorityEnum::Bonus,foo,25);
    taskManager.Add(PriorityEnum::Max,foo,75);
    taskManager.Add(PriorityEnum::Bonus,foo,25);
    taskManager.Add(PriorityEnum::Bonus,foo,25);
    taskManager.Add(PriorityEnum::Bonus,foo,25);
    taskManager.Add(PriorityEnum::Huge,foo,68);
    taskManager.Add(PriorityEnum::Bonus,foo,25);
    taskManager.Add(PriorityEnum::Bonus,foo,25);
    taskManager.Add(PriorityEnum::Bonus,foo,25);
    taskManager.Add(PriorityEnum::Important,foo,20);
    taskManager.Add(PriorityEnum::Important,foo,20);
    taskManager.Add(PriorityEnum::Important,foo,20);
    taskManager.Add(PriorityEnum::Important,foo,20);
    taskManager.Add(PriorityEnum::Important,foo,20);
    taskManager.Add(PriorityEnum::Important,foo,20);

    while (taskManager.taskList.size() > 0){ /*std::cout << "Loading ..." << std::endl;*/};

    end = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << elapsed.count() << std::endl;
    std::cout << "END PROGRAM !" << std::endl;

    return 0;
}