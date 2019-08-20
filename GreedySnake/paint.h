#pragma once
#include <easyx.h>
#include "pch.h"
#include "position.h"
#include <string>
extern int foodscore;
const int BACKGROUND_COLOR = RGB(228, 241, 254);
const int BORDER_COLOR = RGB(0, 181, 204);
const int BORDER_HEIGHT = 600;
const int BORDER_WIDTH = 800;
const int SNAKE_COLOR = RGB(38, 194, 129);
const int FOOD_COLOR = RGB(232, 126, 4);

class Paint
{
public:
	Paint();
	~Paint();
	bool retangleInPosi(Position posi);
	bool printScore(int score = 0);
	bool printSnakeBody(Position posi);
	bool printFood(Position posi);
private:
	
};

bool Paint::printFood(Position posi) {
	if (posi.x < 0 + STEP || posi.x > BORDER_WIDTH - STEP * 2 ||
		posi.y < 0 + STEP || posi.y > BORDER_HEIGHT - STEP * 2) {
		std::cout << "invaild position on x: " << posi.x << " y: " << posi.y << std::endl;
		return false;
	}
	setfillcolor(FOOD_COLOR);
	solidcircle(posi.x + 10, posi.y + 10, STEP / 2 - 5);
	std::cout << "in Paint::printFood" << std::endl;
	std::cout << "posi = (" << posi.x << "," << posi.y << ")" << std::endl;
	std::cout << "out of Paint::printFood" << std::endl;
	return true;
}

bool Paint :: printSnakeBody(Position posi) {
	if (posi.x < 0 + STEP || posi.x > BORDER_WIDTH - STEP * 2 ||
		posi.y < 0 + STEP || posi.y > BORDER_HEIGHT - STEP * 2) {
		std::cout << "invaild position on x: " << posi.x << " y: " << posi.y << std::endl;
		return false;
	}
	int currcolor = getfillcolor();
	setfillcolor(SNAKE_COLOR);
	solidcircle(posi.x + 10, posi.y + 10, STEP/2 - 1);
	setfillcolor(currcolor);
	return true;
}

bool Paint::printScore(int score) {
	if (score < 0)	return false;
	settextcolor(RGB(30, 130, 76));
	std::string strScore = std::to_string(score);
	TCHAR *str = new TCHAR[strScore.size() + 1];
	#ifdef UNICODE
	_stprintf_s(str, strScore.size() + 1, _T("%S"), strScore.c_str());//%S���ַ�
	#else
	_stprintf_s(str, strScore.size() + 1, _T("%s"), strScore.c_str());//%s���ַ�
	#endif
	outtextxy(WINDOWS_WIDTH - strScore.size() * 10 - 15, 150, str);
	delete str;
	return true;
}

bool Paint::retangleInPosi(Position posi) {
	if (posi.x < 0 || posi.x > BORDER_WIDTH - STEP ||
		posi.y < 0 || posi.y > BORDER_HEIGHT - STEP)	
		return false;
	solidrectangle(posi.x + 2, posi.y + 20 - 2, posi.x + 20 - 2, posi.y + 2);
	return true;
}

Paint::Paint()
{
}

Paint::~Paint()
{
}

// ************************************************************

class WindowsPaint : public Paint
{
public:
	WindowsPaint();
	~WindowsPaint();
	void templatePaint() {
		printScore(foodscore);
		iniBorder();
		iniScoreBoard();
		FlushBatchDraw();
	}
private:
	void iniBorder();
	void iniScoreBoard();
	
};

WindowsPaint::WindowsPaint()
{
	// ��ʼ������
	initgraph(WINDOWS_WIDTH, WINDOWS_HEIGHT,SHOWCONSOLE);
	// ���Ͻ�Ϊ��0��0��
	/*setorigin(0,WINDOWS_HEIGHT);
	setaspectratio(1, -1);*/
	setbkcolor(BACKGROUND_COLOR);
	setbkmode(TRANSPARENT);
	cleardevice();
	iniBorder();
	iniScoreBoard();
	printScore();
	BeginBatchDraw();
	std::cout << "���ڳ�ʼ���ɹ�" << std::endl;
}

void WindowsPaint::iniBorder() {
	int currcolor = getfillcolor();
	setfillcolor(BORDER_COLOR);
	Position posi(0, 0);
	// ����һ��
	for (int i = 0; i <= BORDER_WIDTH - STEP; i += STEP) {
		posi.x = i;
		posi.y = 0;
		retangleInPosi(posi);
	}
	// ����һ��
	for (int i = 0; i <= BORDER_WIDTH - STEP; i += STEP) {
		posi.x = i;
		posi.y = BORDER_HEIGHT - 20;
		retangleInPosi(posi);
	}
	// ��������
	for (int i = 0; i <= BORDER_HEIGHT - STEP; i += STEP) {
		posi.x = 0;
		posi.y = i;
		retangleInPosi(posi);
		posi.x = BORDER_WIDTH - STEP;
		retangleInPosi(posi);
	}
	setfillcolor(currcolor);
	std::cout << "�߽�����" << std::endl;
}

void WindowsPaint::iniScoreBoard() {
	// ����������ʽ
	LOGFONT f;
	gettextstyle(&f);						
	f.lfHeight = 20;						
	_tccpy(f.lfFaceName, _T("����"));		
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	f.lfWeight = 700;
	settextstyle(&f);
	
	settextcolor(RGB(44, 130, 201));
	
	TCHAR name[] = _T("GreedySnake");
	outtextxy(890, 50, name);
	TCHAR s[] = _T("̰����");
	outtextxy(915, 75, s);
	TCHAR score[] = _T("SCORE:");
	outtextxy(810, 150, score);
}

WindowsPaint::~WindowsPaint()
{
}

