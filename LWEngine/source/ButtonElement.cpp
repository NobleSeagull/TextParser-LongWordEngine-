#include "ButtonElement.h"

ButtonElement::ButtonElement(EventListener * e, Panel p)
{
	m_eventlistener = e;
	m_type = 0;
	m_panel = p;
	m_colorA = m_panel.BodyColor();
	m_colorB = m_panel.MarginColor();
}

ButtonElement::ButtonElement(EventListener * e, Panel p, Graphic g)
{
	m_eventlistener = e;
	m_type = 1;
	m_graphic = g;
	m_panel = p;
	m_graphic.X(m_panel.X());
	m_graphic.Y(m_panel.Y());
	m_colorA = m_panel.BodyColor();
	m_colorB = m_panel.MarginColor();
}

ButtonElement::ButtonElement(EventListener * e, Panel p, TextElement t, std::string text, int offsetX, int offsetY)
{
	m_text = text;
	m_eventlistener = e;
	m_type = 2;
	m_textElement = t;
	m_textElement.SetString(m_text);
	m_textOffsetX = offsetX;
	m_textOffsetY = offsetY;
	m_panel = p;
	m_textElement.X(m_panel.X() + m_textOffsetX);
	m_textElement.Y(m_panel.Y() + m_textOffsetY);
	m_colorA = m_panel.BodyColor();
	m_colorB = m_panel.MarginColor();
}

ButtonElement::~ButtonElement()
{

}

void ButtonElement::Update()
{
	m_graphic.OffsetX(m_panel.Margin());
	m_graphic.OffsetY(m_panel.Margin());
	m_graphic.Width(m_panel.Width() - (m_panel.Margin() * 2));
	m_graphic.Height(m_panel.Height() - (m_panel.Margin() * 2));
	m_selected = false;
	m_activated = false;
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Rect holderA{ m_panel.X(), m_panel.Y(), m_panel.Width(), m_panel.Height() };
	SDL_Rect holderB{ x, y, 1, 1 };
	if (SDL_HasIntersection(&holderA, &holderB))
	{
		m_selected = true;
		if (m_eventlistener->LeftClick)
		{
			m_activated = true;
		}
	}


	if (m_activated)
	{
		m_panel.MarginColor(m_colorA);
		m_panel.BodyColor(m_colorB);
		m_graphic.Color(m_colorA);
	}
	else if(m_selected)
	{
		//Adjusts border color if highlighted over. If it surpasses 255 it will be locked to 255, as having any of the colors beyond 255 will make it pure white. SDL is weird?
		Uint8 r = int(m_colorB.r) + 50;
		if (r > 255) { r = 255; }
		Uint8 g = int(m_colorB.g) + 50;
		if (g > 255) { g = 255; }
		Uint8 b = int(m_colorB.b) + 50;
		if (b > 255) { b = 255; }
		m_panel.BodyColor(m_colorA);
		m_panel.MarginColor(SDL_Color{ r, g, b, m_colorB.a });
		if (m_type == 1)
		{
			m_graphic.Color(SDL_Color{ r, g, b, m_colorB.a });
		}
	}
	else
	{
		m_graphic.Color(m_colorB);
		m_panel.MarginColor(m_colorB);
		m_panel.BodyColor(m_colorA);
		m_colorA = m_panel.BodyColor();
		m_colorB = m_panel.MarginColor();
	}

	if (m_type == 1)
	{
		m_graphic.X(m_panel.X());
		m_graphic.Y(m_panel.Y());
	}
	else if (m_type == 2)
	{
		m_textElement.X(m_panel.X() + m_textOffsetX);
		m_textElement.Y(m_panel.Y() + m_textOffsetY);
	}
}

void ButtonElement::Render(SDL_Renderer & r)
{
	m_panel.Render(r);
	if (m_type == 1)
	{
		m_graphic.Render(r);
	}
	else if (m_type == 2)
	{
		m_textElement.Render(r);
	}
}