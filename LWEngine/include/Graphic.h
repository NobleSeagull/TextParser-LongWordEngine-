#ifndef _GRAPHIC_H
#define _GRAPHIC_H

#include "stdafx.h"

class Graphic
{
public:
	Graphic() {};
	Graphic(SDL_Texture * texture, SDL_Color color, int x, int y, int offsetX, int offsetY, int width, int height);
	~Graphic() {};

	SDL_Texture * Texture() { return m_texture; };
	void Texture(SDL_Texture * t) { m_texture = t; };

	int X() { return m_x; };
	void X(int x) { m_x = x; };

	int Y() { return m_y; };
	void Y(int x) { m_y = x; };

	int Width() { return m_width; };
	void Width(int x) { m_width = x; };

	int Height() { return m_height; };
	void Height(int x) { m_height = x; };

	int OffsetX() { return m_offsetX; };
	void OffsetX(int x) { m_offsetX = x; };

	int OffsetY() { return m_offsetY; };
	void OffsetY(int x) { m_offsetY = x; };

	SDL_Color Color() { return m_color; };
	void Color(SDL_Color c) { m_color = c; };

	void Update();

	void Render(SDL_Renderer & r);

private:

	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_offsetX;
	int m_offsetY;

	SDL_Color m_color;

	SDL_Texture * m_texture;
};
#endif

