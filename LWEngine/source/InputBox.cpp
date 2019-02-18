#include "InputBox.h"



InputBox::InputBox(EventListener * e, Panel panel, FontPack * font, int offsetX, int offsetY)
{
	m_color = SDL_Color{ 255,255,255,255 };
	m_textElement = TextElement(font, 18, true, 0, 0, 0, 0, m_color);
	m_panel = panel;
	m_eventListener = e;
	m_textOffsetX = offsetX;
	m_textOffsetY = offsetY;
	m_colorA = m_panel.BodyColor();
	m_colorB = m_panel.MarginColor();
	m_timer = m_timerMax;
	m_lineAppear = false;
	m_text = "_";
	SDL_Point holder = StringSize(m_textElement.GetFontPack()->fonts.at(m_textElement.GetFontSize())->Normal, m_text);
	m_maxNumberOfLetters = ((m_panel.Width() - (m_panel.Margin() * 2)) / holder.x) - 1;
	m_text = "";
}

InputBox::~InputBox()
{
}

void InputBox::Update()
{
	m_selected = false;
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Rect holderA{ m_panel.X(), m_panel.Y(), m_panel.Width(), m_panel.Height() };
	SDL_Rect holderB{ x, y, 1, 1 };
	if (SDL_HasIntersection(&holderA, &holderB))
	{
		m_selected = true;
		if (m_eventListener->LeftClick)
		{
			m_activated = true;
		}
	}
	else if (m_eventListener->LeftClick)
	{
		m_activated = false;
	}

	if (m_selected)
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
	}
	else
	{
		m_panel.MarginColor(m_colorB);
		m_panel.BodyColor(m_colorA);
		m_colorA = m_panel.BodyColor();
		m_colorB = m_panel.MarginColor();
	}

	m_textElement.SetString(m_text);
	if (m_activated)
	{
		TextInputs();
		if (m_timer > 0)
		{
			m_timer--;
		}
		else
		{
			m_timer = m_timerMax;
			m_lineAppear = !m_lineAppear;
		}

		if (m_lineAppear)
		{
			m_textElement.SetString(m_text + "|");
		}
	}

	m_textElement.X(m_panel.X() + m_textOffsetX);
	m_textElement.Y(m_panel.Y() + m_textOffsetY);
}

void InputBox::Render(SDL_Renderer & r)
{
	m_panel.Render(r);
	m_textElement.Render(r);
}

void InputBox::TextInputs()
{
	int temp = m_text.size();
	if (m_inputTimer <= 0)
	{
		if (m_text.size() < m_maxNumberOfLetters)
		{
			if (m_eventListener->Shift)
			{
				if (m_eventListener->A) m_text += "A";
				else if (m_eventListener->B) m_text += "B";
				else if (m_eventListener->C) m_text += "C";
				else if (m_eventListener->D) m_text += "D";
				else if (m_eventListener->E) m_text += "E";
				else if (m_eventListener->F) m_text += "F";
				else if (m_eventListener->G) m_text += "G";
				else if (m_eventListener->H) m_text += "H";
				else if (m_eventListener->I) m_text += "I";
				else if (m_eventListener->J) m_text += "J";
				else if (m_eventListener->K) m_text += "K";
				else if (m_eventListener->L) m_text += "L";
				else if (m_eventListener->M) m_text += "M";
				else if (m_eventListener->N) m_text += "N";
				else if (m_eventListener->O) m_text += "O";
				else if (m_eventListener->P) m_text += "P";
				else if (m_eventListener->Q) m_text += "Q";
				else if (m_eventListener->R) m_text += "R";
				else if (m_eventListener->S) m_text += "S";
				else if (m_eventListener->T) m_text += "T";
				else if (m_eventListener->U) m_text += "U";
				else if (m_eventListener->V) m_text += "V";
				else if (m_eventListener->W) m_text += "W";
				else if (m_eventListener->X) m_text += "X";
				else if (m_eventListener->Y) m_text += "Y";
				else if (m_eventListener->Z) m_text += "Z";
				else if (m_eventListener->Zero) m_text += ")";
				else if (m_eventListener->One) m_text += "!";
				else if (m_eventListener->Two) m_text += '"';
				else if (m_eventListener->Three) m_text += "£";
				else if (m_eventListener->Four) m_text += "$";
				else if (m_eventListener->Five) m_text += "%";
				else if (m_eventListener->Six) m_text += "^";
				else if (m_eventListener->Seven) m_text += "&";
				else if (m_eventListener->Eight) m_text += "*";
				else if (m_eventListener->Nine) m_text += "(";
				else if (m_eventListener->Minus) m_text += "_";
				else if (m_eventListener->Equals) m_text += "+";
			}
			else
			{
				if (m_eventListener->A) m_text += "a";
				else if (m_eventListener->B) m_text += "b";
				else if (m_eventListener->C) m_text += "c";
				else if (m_eventListener->D) m_text += "d";
				else if (m_eventListener->E) m_text += "e";
				else if (m_eventListener->F) m_text += "f";
				else if (m_eventListener->G) m_text += "g";
				else if (m_eventListener->H) m_text += "h";
				else if (m_eventListener->I) m_text += "i";
				else if (m_eventListener->J) m_text += "j";
				else if (m_eventListener->K) m_text += "k";
				else if (m_eventListener->L) m_text += "l";
				else if (m_eventListener->M) m_text += "m";
				else if (m_eventListener->N) m_text += "n";
				else if (m_eventListener->O) m_text += "o";
				else if (m_eventListener->P) m_text += "p";
				else if (m_eventListener->Q) m_text += "q";
				else if (m_eventListener->R) m_text += "r";
				else if (m_eventListener->S) m_text += "s";
				else if (m_eventListener->T) m_text += "t";
				else if (m_eventListener->U) m_text += "u";
				else if (m_eventListener->V) m_text += "v";
				else if (m_eventListener->W) m_text += "w";
				else if (m_eventListener->X) m_text += "x";
				else if (m_eventListener->Y) m_text += "y";
				else if (m_eventListener->Z) m_text += "z";
				else if (m_eventListener->Zero) m_text += "0";
				else if (m_eventListener->One) m_text += "1";
				else if (m_eventListener->Two) m_text += "2";
				else if (m_eventListener->Three) m_text += "3";
				else if (m_eventListener->Four) m_text += "4";
				else if (m_eventListener->Five) m_text += "5";
				else if (m_eventListener->Six) m_text += "6";
				else if (m_eventListener->Seven) m_text += "7";
				else if (m_eventListener->Eight) m_text += "8";
				else if (m_eventListener->Nine) m_text += "9";
				else if (m_eventListener->Minus) m_text += "-";
				else if (m_eventListener->Equals) m_text += "=";
			}
		}
		if (m_eventListener->Backspace && m_text.size() > 0)
		{
			m_text.pop_back();
		}
		else if(m_eventListener->Space)
		{
			m_text += " ";
		}

		if (temp != m_text.size())
		{
			m_inputTimer = m_inputTimerMax;
		}
	}
	else
	{
		m_inputTimer--;
	}
}