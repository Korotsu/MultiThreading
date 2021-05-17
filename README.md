# Multithreading
 
## How to run ?

To run the Program you need a compiler with Cmake. (Clion has been used in this case).

## In the program you can influence:

-the number of threads to use in the ThreaList array located in ThreadPool.hpp

-The number that the foo function should count before printing the text in main.cpp line 11; 

-Call the number of functions you want in main.cpp; 

-Influence the prioritization of multi-threaded tasks; 

-Influence the number displayed in the final results of the function Foo; 

-Display the different availability states of threads in ThreadPool.hpp;

-Change the thread selection mode from manual (Default) to automatic by uncommenting lines 14,53-59 and commenting lines 15,61-67 of theThreadPool.hpp, conversely to switch back to manual;

-Display the executions by order of priority by uncommenting line 49 of TaskSystem.hpp, the reverse to hide;

### And don't forget if
![speed.gif](speed.gif)
### Go Multithreaded !
