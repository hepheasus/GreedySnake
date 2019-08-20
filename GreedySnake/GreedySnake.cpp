// GreedySnake.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"
#include <iostream>
#include <easyx.h>
#include "paint.h"
#include "Snake.h"
#include <Windows.h>
#include <conio.h>
#include "Food.h"


using namespace std;
int main()
{
	int speed = 50;
	int flag = 0;
	int ret = 0;
	Snake snake;
	Food food;
	while (true) {
		cout << "new while" << endl;
		while (_kbhit()) {
			snake.dir = _getch();
		}
		if (snake.dir - flag != 3 && snake.dir - flag != 4 && flag - snake.dir != 3 && flag - snake.dir != 4) {
			flag = snake.dir;
		}
		else {
			snake.dir = flag;
		}
		cout << "flag = " << flag << endl;
		ret = snake.move(food.foodposi);
		if (ret == 2) {
			cout << " Game Over \n" << endl;
			break;
		}
		else if (!ret) {
			cout << " execute : food.printfood() " << endl;
			food.printfood();
			cout << " end execute-food.printfood() \n" << endl;
		}
		else {
			cout << " execute : food.iseaten = true " << endl;
			food.iseaten = true;
			food.swpan();
			food.printfood();
			cout << " end execute-iseaten \n" << endl;
			// lenth++;
		}
		Sleep(speed);
	}
}

