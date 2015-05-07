// MultiThread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

void pause_thread(int n)
{
	//std::this_thread::sleep_for(std::chrono::seconds(n));
	std::cout << "pause of " << n << " seconds ended\n";
}

int main()
{
	std::cout << "Spawning 3 threads...\n";
	std::thread t1(pause_thread, 1);
	std::thread t2(pause_thread, 2);
	std::thread t3(pause_thread, 3);
	/*std::thread t1(pause_thread, 1);
	std::thread t2(pause_thread, 1);
	std::thread t3(pause_thread, 1);*/
	std::cout << "Done spawning threads. Now waiting for them to join:\n";
	t1.join();
	t2.join();
	t3.join();
	std::cout << "All threads joined!\n";

	return 0;
}

//Join will block main thread until all the sub threads inside main have been finished, 
//so the last cout in the main func can be guaranteed to be printed in the end,
//but second cout will not be guarateed, it might be in front of, between or after the threads' print out
