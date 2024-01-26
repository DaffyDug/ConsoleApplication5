#pragma once
class kolobok
{
public:
	int posX, posY;
	int jumpForce;
	int gravity;
	int dvijenie;
	bool onGround = false;

	kolobok()
	{
		posX = 100;
		posY = 100;
		jumpForce = 20;
		gravity = 0;
		dvijenie = 0;
	}
	void Gravity()
	{
		if (posY > 300)
			onGround = true;

		if (gravity < 10)
		{
			gravity++;
		}

		if (!onGround)
			posY += gravity;


	}
	void Jump()
	{
		if (onGround)
		{
			onGround = false;
			posY -= jumpForce;
			gravity = -jumpForce;

		}
	}
};

