#include "SliderElement.h"

SliderElement::SliderElement(EventListener * e, int noOfLines, int noOfLinesPerPage, Panel background, SDL_Texture * downArrow, SDL_Texture * upArrow)
{
	m_panel = background;
	m_upButton = ButtonElement(e, Panel(m_panel.X(), m_panel.Y(), m_panel.Width(), m_panel.Width(), m_panel.Margin(), m_panel.BodyColor(), m_panel.MarginColor()), Graphic(upArrow, m_panel.MarginColor(), m_panel.X(), m_panel.Y(), m_panel.Margin(), m_panel.Margin(), m_panel.Width() - (m_panel.Margin() * 2), m_panel.Width() -(m_panel.Margin() * 2)));
	m_downButton = ButtonElement(e, Panel(m_panel.X(), m_panel.Y() + (m_panel.Height() - m_panel.Width()), m_panel.Width(), m_panel.Width(), m_panel.Margin(), m_panel.BodyColor(), m_panel.MarginColor()), Graphic(downArrow, m_panel.MarginColor(), m_panel.X(), m_panel.Y() + (m_panel.Height() - m_panel.Width()), m_panel.Margin(), m_panel.Margin(), m_panel.Width() - (m_panel.Margin()*2), m_panel.Width() -(m_panel.Margin() * 2)));
	m_sliderButton = ButtonElement(e, Panel(m_panel.X(), m_panel.Y() + m_panel.Width(), m_panel.Width(), m_panel.Height() - (m_panel.Width() * 2), m_panel.Margin(), m_panel.BodyColor(), m_panel.MarginColor()));
	Uint8 rA = int(m_panel.BodyColor().r) - 15;
	if (rA < 0) { rA = 0; }
	Uint8 gA = int(m_panel.BodyColor().g) - 15;
	if (gA < 0) { gA = 0; }
	Uint8 bA = int(m_panel.BodyColor().b) - 15;
	if (bA < 0) { bA = 0; }
	m_panel.BodyColor(SDL_Color{ rA, gA, bA });
	m_numberOfLines = noOfLines;
	m_visibleLines = noOfLinesPerPage;
	m_currentTopLine = 0;
	m_buttonHeld = false;
	m_timer = 0;
}

SliderElement::~SliderElement()
{
}

void SliderElement::Update()
{
	m_downButton.Update();
	m_upButton.Update();
	m_sliderButton.Update();
	float holder = (m_panel.Height() - (m_downButton.GetPanel()->Height() + m_upButton.GetPanel()->Height())) / (float)m_numberOfLines;
	float holderY = holder * (float)m_currentTopLine;
	if (m_numberOfLines <= m_visibleLines)
	{
		m_sliderButton.GetPanel()->Height(holder * m_numberOfLines);
	}
	else
	{
		m_sliderButton.GetPanel()->Height(holder * m_visibleLines);
		if (m_sliderButton.Activated())
		{
			int x, y;
			SDL_GetMouseState(&x, &y);
			if (m_buttonHeld)
			{
				if (y != m_mousePositionY)
				{
					m_sliderButton.GetPanel()->Y(y - m_mouseDifference);
					float temp = (m_sliderButton.GetPanel()->Y() - (m_upButton.GetPanel()->Y() + m_upButton.GetPanel()->Height())) / holder;
					if (temp < 0)
					{
						m_sliderButton.GetPanel()->Y(m_upButton.GetPanel()->Y() + m_upButton.GetPanel()->Height());
						m_currentTopLine = 0;
					}
					else if (temp >= m_numberOfLines - m_visibleLines)
					{
						m_sliderButton.GetPanel()->Y(m_downButton.GetPanel()->Y() - m_sliderButton.GetPanel()->Height());
						m_currentTopLine = m_numberOfLines - m_visibleLines;
					}
					else
					{
						m_currentTopLine = temp;
					}
					m_mousePositionY = y;
					std::cout << "Current Line Shown is : " << m_currentTopLine << std::endl;
				}
			}
			else
			{
				m_buttonHeld = true;
				m_mouseDifference = y - m_sliderButton.GetPanel()->Y();
				m_mousePositionY = y;
			}
			m_timer = TIMER * 6;
		}
		else
		{
			m_buttonHeld = false;
		}

		if (m_upButton.Activated() && m_timer <= 0)
		{
			m_currentTopLine--;
			m_timer = TIMER;
			if (m_currentTopLine <= 0)
			{
				m_currentTopLine = 0;
				m_timer = 0;
			}
			m_sliderButton.GetPanel()->Y(holderY + (m_upButton.GetPanel()->Y() + m_upButton.GetPanel()->Height()));
			std::cout << "Current Line Shown is : " << m_currentTopLine << std::endl;
		}
		else if (m_downButton.Activated() && m_timer <= 0)
		{
			m_currentTopLine++;
			m_timer = TIMER;
			m_sliderButton.GetPanel()->Y(holderY + (m_upButton.GetPanel()->Y() + m_upButton.GetPanel()->Height()));
			if (m_currentTopLine >= m_numberOfLines - m_visibleLines)
			{
				m_sliderButton.GetPanel()->Y(m_downButton.GetPanel()->Y() - (m_sliderButton.GetPanel()->Height()));
				m_currentTopLine = m_numberOfLines - m_visibleLines;
				m_timer = 0;
			}
			std::cout << "Current Line Shown is : " << m_currentTopLine << std::endl;
		}
		else if (m_timer > 0)
		{
			m_timer--;
		}
	}

}

void SliderElement::Render(SDL_Renderer & r)
{
	m_panel.Render(r);
	m_upButton.Render(r);
	m_downButton.Render(r);
	m_sliderButton.Render(r);
}

void SliderElement::X(int x)
{
	m_panel.X(x);
	m_downButton.GetPanel()->X(x);
	m_upButton.GetPanel()->X(x);
	m_sliderButton.GetPanel()->X(x);
}
void SliderElement::Y(int x)
{
	m_panel.Y(x);
	m_downButton.GetPanel()->Y(m_panel.Y() + (m_panel.Height() - m_panel.Width()));
	m_upButton.GetPanel()->Y(x);
	m_sliderButton.GetPanel()->Y(m_panel.Y() + m_panel.Width());
	m_currentTopLine = 0;
}

void SliderElement::Width(int x)
{
	m_panel.Width(x);
	m_downButton.GetPanel()->Width(x);
	m_downButton.GetPanel()->Height(x);
	m_upButton.GetPanel()->Width(x);
	m_upButton.GetPanel()->Height(x);
	m_sliderButton.GetPanel()->Width(x);
}
void SliderElement::Height(int x)
{
	m_panel.Height(x);
	m_currentTopLine = 0;
}
void SliderElement::MarginWidth(int x)
{
	m_panel.Margin(x);
	m_downButton.GetPanel()->Margin(x);
	m_upButton.GetPanel()->Margin(x);
	m_sliderButton.GetPanel()->Margin(x);
}
void SliderElement::BodyColor(SDL_Color c)
{
	m_panel.BodyColor(c);
	m_downButton.GetPanel()->BodyColor(c);
	m_upButton.GetPanel()->BodyColor(c);
	m_sliderButton.GetPanel()->BodyColor(c);
	Uint8 rA = int(m_panel.BodyColor().r) - 15;
	if (rA < 0) { rA = 0; }
	Uint8 gA = int(m_panel.BodyColor().g) - 15;
	if (gA < 0) { gA = 0; }
	Uint8 bA = int(m_panel.BodyColor().b) - 15;
	if (bA < 0) { bA = 0; }
	m_panel.BodyColor(SDL_Color{ rA, gA, bA });
}
void SliderElement::MarginColor(SDL_Color c)
{
	m_panel.MarginColor(c);
	m_downButton.GetPanel()->MarginColor(c);
	m_upButton.GetPanel()->MarginColor(c);
	m_sliderButton.GetPanel()->MarginColor(c);
}