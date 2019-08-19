// GreedySnake.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"
#include <iostream>
#include <easyx.h>
#include "paint.h"
#include "Snake.h"
#include <Windows.h>
#include <conio.h>
using namespace std;
int main()
{
	Snake snake;
	while (true) {
		while (_kbhit()) {
			snake.dir = _getch();
		}
		snake.move();
	}
}

