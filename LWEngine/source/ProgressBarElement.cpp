#include "ProgressBarElement.h"



ProgressBarElement::ProgressBarElement(Panel background, int maximum, SDL_Color barcolor, Direction direction)
{
	m_panel = background;
	m_maxValue = maximum;
	m_barColor = barcolor;
	m_direction = direction;
}

ProgressBarElement::~ProgressBarElement()
{
}

void ProgressBarElement::Render(SDL_Renderer & r)
{
	SDL_Rect holder;
	float size = 0;
	switch (m_direction)
	{
	case UP:
		m_panel.Render(r);
		size = ((m_panel.Height() - (m_panel.Margin() * 2)) / (float)m_maxValue)*m_currentValue;
		holder = SDL_Rect({ m_panel.X() + m_panel.Margin() , (m_panel.Y() + (m_panel.Height() - m_panel.Margin())) - (int)size, m_panel.Width() - (m_panel.Margin() * 2), (int)size });
		SDL_SetRenderDrawColor(&r, m_barColor.r, m_barColor.g, m_barColor.b, m_barColor.a);
		SDL_RenderFillRect(&r, &holder);
		break;
	case DOWN:
		m_panel.Render(r);
		size = ((m_panel.Height() - (m_panel.Margin() * 2)) / (float)m_maxValue)*m_currentValue;
		holder = SDL_Rect({ m_panel.X() + m_panel.Margin() , m_panel.Y() + m_panel.Margin(), m_panel.Width() - (m_panel.Margin() * 2), (int)size });
		SDL_SetRenderDrawColor(&r, m_barColor.r, m_barColor.g, m_barColor.b, m_barColor.a);
		SDL_RenderFillRect(&r, &holder);
		break;
	case LEFT:
		m_panel.Render(r);
		size = ((m_panel.Height() - (m_panel.Margin() * 2)) / (float)m_maxValue)*m_currentValue;
		holder = SDL_Rect({ (m_panel.X() + (m_panel.Width() - m_panel.Margin())) - (int)size, m_panel.Y() + m_panel.Margin(), int(size), m_panel.Height() - (m_panel.Margin()*2) });
		SDL_SetRenderDrawColor(&r, m_barColor.r, m_barColor.g, m_barColor.b, m_barColor.a);
		SDL_RenderFillRect(&r, &holder);
		break;
	default:
		m_panel.Render(r);
		size = ((m_panel.Height() - (m_panel.Margin() * 2)) / (float)m_maxValue)*m_currentValue;
		holder = SDL_Rect({ m_panel.X() + m_panel.Margin(), m_panel.Y() + m_panel.Margin() , (int)size, m_panel.Height() - (m_panel.Margin() * 2) });
		SDL_SetRenderDrawColor(&r, m_barColor.r, m_barColor.g, m_barColor.b, m_barColor.a);
		SDL_RenderFillRect(&r, &holder);
		break;
	}
}