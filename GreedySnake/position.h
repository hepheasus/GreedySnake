#pragma once
#include "pch.h"
#include <random>
#include <time.h>
class Position
{
public:
	Position();
	Position(int x, int y);
	int x;
	int y;
	Position randomPosi();
private:
	
};
Position::Position() {
	srand(GetTickCount());
}

Position::Position(int x, int y):x(x),y(y){

}
Position Position::randomPosi() {
	int randomY = (rand() % 28 + 1) * 20;
	int randomX = (rand() % 38 + 1) * 20;
	std::cout << "random position on x : " << randomX << " y: " << randomY << std::endl;
	return Position(randomX, randomY);
}
