// MultiThread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <chrono>         // chrono::seconds
#include <thread>
#include <iostream>
#include <vector>
using namespace std;

void pause_thread(int n)
{
	//this_thread::sleep_for(chrono::seconds(n));
	cout << "pause of " << n << " seconds ended\n";
}

void multiThreadTestOne() {
	cout << "Spawning 3 threads...\n";
	thread t1(pause_thread, 1);
	thread t2(pause_thread, 2);
	thread t3(pause_thread, 3);
	//thread t1(pause_thread, 1);
	//thread t2(pause_thread, 1);
	//thread t3(pause_thread, 1);
	cout << "Done spawning threads. Now waiting for them to join:\n";
	t1.join();
	t2.join();
	t3.join();
	cout << "All threads joined!\n";
}

void multiThreadTestTwo() {
	vector<thread> threads;
	for (int i = 0; i < 5; ++i) {
		threads.push_back(thread([]() {
			cout << "Hello from thread " << this_thread::get_id() << endl;
		}));
	}
	for (auto& thread : threads) {
		thread.join();
	}
}

int main()
{
	cout << "yo" << endl;
	this_thread::sleep_for(chrono::seconds(5));
	cout << "s'up" << endl;
	multiThreadTestOne();
	multiThreadTestTwo();

	return 0;
}

//Join will block main thread until all the sub threads inside main have been finished, 
//so the last cout in the main func can be guaranteed to be printed in the end,
//but second cout will not be guarateed, it might be in front of, between or after the threads' print out
