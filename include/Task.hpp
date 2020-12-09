#if !defined(TASK_HPP)
#define TASK_HPP

#include <thread>
#include <stdarg.h>
#include <vector>
#include <functional>
#include <memory>
#include <utility>
#include <any>

enum PriorityEnum
{
  Bonus     = 0,
  Small     = 10,
  Medium    = 20,
  Huge      = 30,
  Important = 40,
  Critical  = 50,
  Max       = 100,
};

class AbstractTaskData
{
public:
  virtual void operator()(){};
  virtual ~AbstractTaskData() = default;
};

template<typename ...ARGS>
class TaskData : public AbstractTaskData
{
  std::function<void(ARGS...)> _function;
  std::tuple<ARGS...> _args;

public:
  TaskData(std::function<void(ARGS...)> function, ARGS... args) : _function(function), _args(args...) {}

  virtual void operator()() override
  {
      std::apply(_function,_args);
  }
};

class Task
{
public:
  AbstractTaskData* taskData = nullptr;
  PriorityEnum      priority;
public:
  template<typename FUNCTION, typename ... ARGS>
  Task(PriorityEnum _priority, FUNCTION &&function, ARGS &&... args) : priority(_priority), taskData(new TaskData<ARGS ...>(function,args...)){}

  void operator()() { (*taskData)(); }
};

#endif // TASK_HPP
