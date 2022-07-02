#include <iostream>

#include <thread>

#include <chrono>

using namespace std;

void DoWork(int a, int b, string msg)
{
	cout << msg << endl;

	this_thread::sleep_for(chrono::milliseconds(3000));

	cout << "==========\t" << "DoWork STARTED\t==========" << endl;

	this_thread::sleep_for(chrono::milliseconds(5000));

	cout << " A + B = " << a + b << endl;

	this_thread::sleep_for(chrono::milliseconds(1000));

	cout << "==========\t" << "DoWork STOPPED\t==========" << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");

	thread th(DoWork, 2, 3, "our message");


	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID потока =" << this_thread::get_id() << "\tmain" << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	th.join(); // дожидаемся метода 

	return 0;
}

