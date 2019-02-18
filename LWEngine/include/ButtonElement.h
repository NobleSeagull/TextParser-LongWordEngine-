#ifndef _BUTTONELEMENT_H
#define _BUTTONELEMENT_H

#include "Panel.h"
#include "TextElement.h"
#include "Graphic.h"

class ButtonElement
{
public:
	ButtonElement() {};
	ButtonElement(EventListener * e, Panel p);
	ButtonElement(EventListener * e, Panel p, Graphic g);
	ButtonElement(EventListener * e, Panel p, TextElement t, std::string text, int offsetX, int offsetY);
	~ButtonElement();

	void SetGraphic(Graphic g) { m_graphic = g; };
	Graphic * GetGraphic() { return &m_graphic; };

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

	void Update();
	void Render(SDL_Renderer & r);


private:

	EventListener * m_eventlistener;

	Panel m_panel;
	TextElement m_textElement;
	int m_textOffsetX;
	int m_textOffsetY;
	Graphic m_graphic;

	SDL_Color m_colorA;
	SDL_Color m_colorB;

	std::string m_text;

	int m_type;

	bool m_activated;
	bool m_selected;

	int m_timer;

};
#endif
