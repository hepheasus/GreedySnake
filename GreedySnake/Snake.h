#pragma once
#include "pch.h"
#include "position.h"
#include "paint.h"
#include <queue>
#include <vector>
using namespace std;
class Snake
{
private:
	int length;
	queue<Position> body;
	Position SnakeBody;
	WindowsPaint paint;
	void printBody();
	int speed = 200;
public:
	int dir;
	Snake();
	void Eat();
	void move();
};

Snake::Snake() {
	int dire[4] = { 65,68,83,87 };
	SnakeBody = SnakeBody.randomPosi();
	body.push(SnakeBody);
	length = 1;
	printBody();
	
	srand((unsigned)time(NULL));																																//what's this???
	dir = dire[rand() % 4];																																			//oh, amazing
}
void Snake::Eat() {
	length++;
	
}
void Snake::printBody() {
	queue<Position> body1 = body;
	for (int i = 0; i < length; i++) {
		Position top = body1.front();
		paint.printSnakeBody(top);
		body1.pop();
	}
	FlushBatchDraw();
}
void Snake::move() {
	// 判断撞墙和吃东西和吃到自己
	Position top = body.front();
	switch (dir) {
	case 97:	//A--left
		body.pop();
		top.x -= STEP;
		body.push(top);
		cleardevice();
		printBody();
		paint.templatePaint();
		break;
	case 100:	//D--right
		cleardevice();

		body.pop();
		top.x += STEP;
		body.push(top);
		printBody();
		Sleep(speed);
		paint.templatePaint();
		break;
	case 115:	//S--down
		body.pop();
		top.y += STEP;
		body.push(top);
		printBody();
		Sleep(speed);
		paint.templatePaint();
		break;
	case 119:	//W--up
		body.pop();
		top.y -= STEP;
		body.push(top);
		printBody();
		Sleep(speed);
		paint.templatePaint();
		break;
	}


}
 