#pragma once
#include "position.h"
#include "paint.h"
using namespace std;
int foodscore = 0;
class Food {
private:
public:
	Paint paint;
	Position foodposi;
	Food();
	bool iseaten = false;
	void printfood();
	void swpan();
	
};

void Food::swpan() {
	foodscore++;
	foodposi = foodposi.randomPosi();
	cout << "in Food swpan () : foodposi = " << "( " << foodposi.x << " £¬" << foodposi.y << " )" << endl;
	iseaten = false;
}

Food::Food() {
	cout << "---execute: Food() constructor  " << endl;
	cout << "-execute: foodposi.randomPosi() " << endl;
	foodposi = foodposi.randomPosi();
	cout << "-end execute: foodposi.randomPosi() " << endl;
	paint.printFood(foodposi);
	FlushBatchDraw();
	cout << "---end excute: Food-constructor \n" << endl;
}
void Food::printfood() {
	cout << "in Food::printfood" << endl;
	paint.printFood(foodposi);
	FlushBatchDraw();
	cout << "out of Food::printfood" << endl;
}
