#pragma once
#include <time.h>
#include<iostream>
class thestolb
{
public:
	int posX, posY, h, w;
	int speed;
	thestolb()
	{
		srand(time(0));
		posX = 1000;
		posY = 450;
		h = 400;
		w = 40;
		speed = 20;

	}
	void Move()
	{
		posX -= speed;
		if (posX < -100)
		{
			posX = rand() % 400 + 900;
			posY = 400 + rand() % 150;
			speed = 15 + rand() % 10;
		}
	}
};

