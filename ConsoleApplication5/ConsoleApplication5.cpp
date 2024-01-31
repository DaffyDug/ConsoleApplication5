#include <SFML/Graphics.hpp>
using namespace sf;
RenderWindow window(VideoMode(800, 800), "IgorBest", Style::Default);

void DrawLine(float x, float y, float angle, int len)
{
	RectangleShape line(Vector2f(3, len));
	line.setPosition(x, y);
	line.rotate(angle);
	line.setFillColor(Color(255, 0, 255));
	window.draw(line);

}


void DrawTree(float x, float y, float angle, int len)
{
	float x1 = cos(3.1415 / 180.0 * (angle - 270)) * len + x;
	float y1 = sin(3.1415 / 180.0 * (angle - 270)) * len + y;
	DrawLine(x, y, angle, len);

	if (len > 20)
	{
		DrawTree(x1, y1, angle - 15, len - 10);
		DrawTree(x1, y1, angle + 15, len - 10);
	}


}


int main()
{
	window.setVerticalSyncEnabled(true);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			window.clear(Color::Black);
			DrawTree(400, 800, 180, 120);
			window.display();
		}
	}
}