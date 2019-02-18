#ifndef _PANEL_H
#define _PANEL_H

#include "stdafx.h"

class Panel
{
public:
	Panel(int x, int y, int width, int height, int margin, SDL_Color bodyColor, SDL_Color marginColor);
	Panel() {};
	~Panel() {};

	int X() { return m_x; };
	void X(int x) { m_x = x; };

	int Y() { return m_y; };
	void Y(int x) { m_y = x; };

	int Width() { return m_width; };
	void Width(int x) { m_width = x; };

	int Height() { return m_height; };
	void Height(int x) { m_height = x; };

	int Margin() { return m_margin; };
	void Margin(int x) { m_margin = x; };

	SDL_Color BodyColor() { return m_bodyColor; };
	void BodyColor(SDL_Color x) { m_bodyColor = x; };

	SDL_Color MarginColor() { return m_marginColor; };
	void MarginColor(SDL_Color x) { m_marginColor = x; };

	void Update() {};

	void Render(SDL_Renderer & r);

private:

	SDL_Color m_bodyColor;
	SDL_Color m_marginColor;

	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_margin;
};
#endif