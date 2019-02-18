#include "Panel.h"

Panel::Panel(int x, int y, int width, int height, int margin, SDL_Color bodyColor, SDL_Color marginColor)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_margin = margin;
	m_bodyColor = bodyColor;
	m_marginColor = marginColor;
}

void Panel::Render(SDL_Renderer & r)
{
	SDL_Rect holder;

	if (m_margin > 0)
	{
		//Exterior Rectangle
		holder = SDL_Rect({ m_x, m_y, m_width, m_height });
		SDL_SetRenderDrawColor(&r, m_marginColor.r, m_marginColor.g, m_marginColor.b, m_marginColor.a);
		SDL_RenderFillRect(&r, &holder);
		//Interior Rectangle
		holder = SDL_Rect({ m_x + m_margin, m_y + m_margin, m_width - m_margin * 2, m_height - m_margin * 2 });
		SDL_SetRenderDrawColor(&r, m_bodyColor.r, m_bodyColor.g, m_bodyColor.b, m_bodyColor.a);
		SDL_RenderFillRect(&r, &holder);
	}
	else
	{
		holder = SDL_Rect({ m_x, m_y, m_width, m_height });
		SDL_SetRenderDrawColor(&r, m_bodyColor.r, m_bodyColor.g, m_bodyColor.b, m_bodyColor.a);
		SDL_RenderFillRect(&r, &holder);
	}
}