#ifndef _TEXTELEMENT_H
#define _TEXTELEMENT_H

#include <map>
#include "stdafx.h"
#include "ResourceManager.h"

const int inf = 99999999;

class TextElement
{
public:
	TextElement() {};
	TextElement(FontPack * f, int size, bool autoSize, int x, int y, int width, int height, SDL_Color c);
	~TextElement() {};

	void SetString(std::string s);
	std::string GetString() { return m_string; };

	void SetFontPack(FontPack * f);
	FontPack * GetFontPack() { return m_fontpack; }

	int X() { return m_x; };
	void X(int x) { m_x = x; };

	int Y() { return m_y; };
	void Y(int x) { m_y = x; };

	int Width() { return m_width; };
	void Width(int x) { m_width = x; };

	int Height() { return m_height; };
	void Height(int x) { m_height = x; };

	void SetColor(SDL_Color c);
	void SetFontSize(int x);
	int GetFontSize() { return m_fontSize; };
	int GetX() { return m_x; }; int GetY() { return m_y; }; int GetWidth() { return m_width; }; int GetHeight() { return m_height; };

	void Update();
	void Render(SDL_Renderer & r);

private:
	FontPack * m_fontpack;
	SDL_Color m_color;
	std::string m_string;
	bool m_autoSize;
	int m_stringLength;
	int m_x, m_y;
	int m_width, m_height;
	int m_fontSize;

	SDL_Point StringSize(TTF_Font * font, std::string text)
	{
		int width, height;
		TTF_SizeText(font, text.c_str(), &width, &height);
		return SDL_Point{ width, height };
	}
};
#endif
