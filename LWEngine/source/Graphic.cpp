#include "Graphic.h"

Graphic::Graphic(SDL_Texture * texture, SDL_Color color, int x, int y, int offsetX, int offsetY, int width, int height)
{
	m_texture = texture;
	m_x = x;
	m_y = y;
	m_offsetX = offsetX;
	m_offsetY = offsetY;
	m_width = width;
	m_height = height;
	m_color = color;
}

void Graphic::Update()
{

}

void Graphic::Render(SDL_Renderer & r)
{
	SDL_Rect tempRect{ m_x + m_offsetX, m_y + m_offsetY, m_width, m_height };
	SDL_SetTextureColorMod(m_texture, m_color.r, m_color.g, m_color.b);
	SDL_RenderCopy(&r, m_texture, NULL, &tempRect);
}