#ifndef _INPUTBOX_H
#define _INPUTBOX_H

#include "TextElement.h"
#include "EventListener.h"
#include "Panel.h"
class InputBox
{
public:
	InputBox(EventListener * e, Panel panel, FontPack * font, int offsetX, int offsetY);
	~InputBox();

	void SetPanel(Panel p) { m_panel = p; };
	Panel * GetPanel() { return &m_panel; };

	void SetTextElement(TextElement t) { m_textElement = t; };
	TextElement * GetTextElement() { return &m_textElement; };

	void Text(std::string t) { m_text = t; m_textElement.SetString(t); };
	std::string Text() { return m_text; };

	void TextOffsetX(int x) { m_textOffsetX = x; };
	int TextOffsetX() { return m_textOffsetX; };

	void TextOffsetY(int y) { m_textOffsetY = y; };
	int TextOffsetY() { return m_textOffsetY; };

	bool Activated() { return m_activated; };

	void TextInputs();

	void Update();
	void Render(SDL_Renderer & r);

private:
	std::string m_text;
	EventListener * m_eventListener;
	Panel m_panel;
	TextElement m_textElement;
	SDL_Color m_color;
	bool m_selected, m_activated;
	int m_textOffsetX, m_textOffsetY;
	SDL_Color m_colorA;
	SDL_Color m_colorB;
	int m_timer;
	int m_timerMax = 20;
	int m_inputTimer;
	int m_inputTimerMax = 10;
	int m_maxNumberOfLetters;
	bool m_lineAppear;

	SDL_Point StringSize(TTF_Font * font, std::string text)
	{
		int width, height;
		TTF_SizeText(font, text.c_str(), &width, &height);
		return SDL_Point{ width, height };
	}
};
#endif
