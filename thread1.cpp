#include <iostream>
#include <conio.h>
#include <vector>
#include <ctime>
#include <thread>
#include <Windows.h>

using namespace std;

bool process_flag = false;

/*Эта подпрограмма симулирует работу первого тоннеля*/
void process_thread_1()
{	
	while (!process_flag)
	{
		//Задать паузу - длина состава
		Sleep(700);
		cout << "Passage of the train through the tunnel 1" << endl;
	}
}

/*Эта подпрограмма симулирует работу второго тоннеля*/
void process_thread_2()
{
	Sleep(500);
	while (!process_flag)
	{
		//Задать паузу - длина состава
		Sleep(1200);
		cout << "Passage of the train through the tunnel 2" << endl;
	}
}

/*Это главная подпрограмма*/
int main()
{
	//Объявить вектор потоков
	vector<thread> threads; 
	thread thr1(process_thread_1); 
	thread thr2(process_thread_2);
	//Выполнять поток 1
	threads.emplace_back(move(thr1));
	//Выполнять поток 2
	threads.emplace_back(move(thr2));
	//Задать время работы потоков
	threads.emplace_back([]() {Sleep(10000); process_flag = true;});
	_getch();
	return 0;
}
