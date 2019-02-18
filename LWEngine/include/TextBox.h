#ifndef _TEXTBOX_H
#define _TEXTBOX_H

#include "stdafx.h"
#include "ResourceManager.h"
#include "TextElement.h"
#include "Panel.h"
#include "SliderElement.h"

class TextBox
{
public:
	TextBox(EventListener* e, FontPack * font, Panel panel, SDL_Texture* uptexture, SDL_Texture* downtexture);
	~TextBox() {};

	void Update();
	void Render(SDL_Renderer & r);

	SliderElement * Slider() { return &m_slider; };

	void SetFontPack(FontPack * f);
	void SetFontSize(int x);
	void SetString(std::string s);
	void SetTextColor(SDL_Color c);

	Panel * GetPanel() { return &m_panel; };

private:

	SliderElement m_slider;
	Panel m_panel;
	std::string m_text;
	SDL_Color m_color;
	std::vector<std::string> m_lines;
	std::vector<TextElement*> m_textElements;
	int m_maxNoOfLines, m_lineMargin;
	int m_currentLine;

	SDL_Point StringSize(TTF_Font * font, std::string text)
	{
		int width, height;
		TTF_SizeText(font, text.c_str(), &width, &height);
		return SDL_Point{ width, height };
	}

};
#endif