#pragma once
#include "pch.h"
#include "position.h"
#include "paint.h"
#include <queue>
#include <vector>
using namespace std;
class Snake{
private:
	int length;
	queue<Position> body;
	Position SnakeBody;
	WindowsPaint paint;
	void printBody();
	int speed = 200;
	int flag = 0;

public:
	int dir;
	Snake();
	int move(Position foodposi);
	bool isInQueue(Position po);
};
bool Snake::isInQueue(Position po) {
	cout << " execute:isInQueue" << endl;
	queue<Position> body2 = body;
	cout << "po = (" << po.x << "," << po.y << ")" << endl;
	for (int i = 0;i < length - 1; ++i) {
		cout << "in 'for' isInQueue: body2.front() = (" << body2.front().x << "," << body2.front().y << ")" << endl;
		cout << "i = " << i << endl;
		if (body2.front() == po) {
			cout << "end-execute:isInQueue-return true\n" << endl;
			return true;
		}			
		body2.pop();
	}
	cout << "out 'for'" << endl;
	cout << "end-execute:isInQueue-return false\n" << endl;
	return false;
}
Snake::Snake() {
	cout << "---execute: Snake() constructor  " << endl;
	int dire[4] = { 97, 100, 115, 119 };
	cout << "-execute: SnakeBody.randomPosi() " << endl;
	SnakeBody = SnakeBody.randomPosi();
	cout << "-end execute: SnakeBody.randomPosi() " << endl;
	body.push(SnakeBody);
	length = 1;
	printBody();
	srand((unsigned)time(NULL));																																//what's this???
	dir = dire[rand() % 4];																												//oh, amazing
	cout << "---end excute: Snake-constructor \n" << endl;
}
void Snake::printBody() {
	queue<Position> body1 = body;
	for (int i = 0; i < length; i++) {
		Position top = body1.front();
		cout << "<--- paint ---> body1.front().x = " << top.x << "	body1.front().y = " << top.y << endl;
		paint.printSnakeBody(top);
		body1.pop();
	}
	FlushBatchDraw();
}
int Snake::move(Position foodposi) {
	int re = 0;
	cout << "---execute:Snake::move()" << endl;
	Position top = body.back();																															//这老鼠真是厉害
	if (top.y == 0 || top.y == BORDER_HEIGHT - STEP || top.x == 0 || top.x == BORDER_WIDTH - STEP) {
		return 2;
	}
	switch (dir) {
	case 97:	//A--left		
		top.x -= STEP;
		if (foodposi == top) {
			re = 1;
			body.push(top);
			length++;
		}
		else {
			if (isInQueue(top))	return 2;
			body.pop();
			body.push(top);
		}
		cleardevice();
		printBody();			
		paint.templatePaint();
		printf("A	body.front().x = %d, body.front().y = %d\n", body.front().x, body.front().y);
		printf("body.back().x = %d, body.back().y = %d\n", body.back().x, body.back().y);
		return re;		
	case 100:	//D--right	
		top.x += STEP;			
		if (foodposi == top) {
			re = 1;
			length++;
		}
		else {
			if (isInQueue(top))	return 2;
			body.pop();
		}
		body.push(top);
		cleardevice();
		printBody();
		paint.templatePaint();
		printf("D	body.front().x = %d, body.front().y = %d\n", body.front().x, body.front().y);
		printf("body.back().x = %d, body.back().y = %d\n", body.back().x, body.back().y);
		return re;		
	case 115:	//S--down
		top.y += STEP;
		if (foodposi == top) {
			re = 1;
			length++;
		}
		else {
			if (isInQueue(top))	return 2;
			body.pop();
		}
		body.push(top);
		cleardevice();
		printBody();
		paint.templatePaint();
		printf("S	body.front().x = %d, body.front().y = %d\n", body.front().x, body.front().y);
		printf("body.back().x = %d, body.back().y = %d\n", body.back().x, body.back().y);
		return re;
	case 119:	//W--up	
		top.y -= STEP;
		if (foodposi == top) {
			re = 1;
			length++;
		}
		else {
			if (isInQueue(top))	return 2;
			body.pop();
		}
		body.push(top);
		cleardevice();
		printBody();
		paint.templatePaint();
		printf("W	body.front().x = %d, body.front().y = %d\n", body.front().x, body.front().y);
		printf("body.back().x = %d, body.back().y = %d\n", body.back().x, body.back().y);
		return re;
	default://按下其他键的时候
		return 2;
	}
	cout << "---end execute:Snake::move() \n" << endl;

}
 