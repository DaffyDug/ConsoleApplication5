#include <SFML/Graphics.hpp>
#include "kolobok.h"
#include "thestolb.h"
using namespace sf;
RenderWindow window(VideoMode(800, 800), L"да", Style::Default);
kolobok Kolobok;
thestolb shalala;
CircleShape getCircle(int x, int y, int r, Color c)
{
	CircleShape shape(r, 100);
	shape.setPosition(x, y);
	shape.setFillColor(c);
	return shape;
}
RectangleShape getRectangle(int x, int y, int w, int h, Color c)
{
	RectangleShape rect(Vector2f(1, 1));
	rect.setFillColor(c);
	rect.setPosition(x, y);
	rect.setSize(Vector2f(w, h));
	return rect;
}
void DrawBackground()
{
	window.draw(getRectangle(1, 1, 800, 500, Color(127, 255, 212)));
	window.draw(getRectangle(1, 500, 800, 500, Color(34, 139, 34)));
	window.draw(getCircle(680, 50, 50, Color(255, 215, 0)));
}
void drawcolobok(int x, int y)
{
	window.draw(getCircle(x, y, 120, Color(255, 165, 0)));
	window.draw(getCircle(x + 50, y + 30, 40, Color::White));
	window.draw(getCircle(x + 130, y + 30, 40, Color::White));
	window.draw(getCircle(x + 90, y + 50, 20, Color::Black));
	window.draw(getCircle(x + 130, y + 50, 20, Color::Black));
	CircleShape m = getCircle(x + 100, y + 150, 10, Color::Red);
	m.scale(3, 1);
	window.draw(m);
}

bool check()
{
	return Kolobok.posX + 200 > shalala.posX && Kolobok.posX < shalala.posX + shalala.w && Kolobok.posY + 200 > shalala.posY && Kolobok.posY < shalala.posY + shalala.h;
}

int main()
{
	window.setVerticalSyncEnabled(true);

	CircleShape shape(100.f, 3);
	shape.setPosition(100, 100);
	shape.setFillColor(Color::Magenta);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == (Event::KeyPressed))
			{
				Kolobok.Jump();
			}
		}

		window.clear(Color::Black);
		if (!check()) {
			shalala.Move();

			Kolobok.Gravity();
			DrawBackground();
			window.draw(getRectangle(shalala.posX, shalala.posY, shalala.w, shalala.h, Color(100, 100, 100)));
			drawcolobok(Kolobok.posX, Kolobok.posY);
			window.display();

		}
	}
	return 0;
}