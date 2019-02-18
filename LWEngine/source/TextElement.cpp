#include "TextElement.h"

TextElement::TextElement(FontPack * f, int size, bool autoSize, int x, int y, int width, int height, SDL_Color c)
{
	m_fontpack = f;
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_autoSize = autoSize;
	m_color = c;
	m_fontSize = size;
}

void TextElement::SetString(std::string s)
{
	m_string = s;
}

void TextElement::SetFontPack(FontPack * f)
{
	m_fontpack = f;
}

void TextElement::SetColor(SDL_Color c)
{
	m_color = c;
}

void TextElement::SetFontSize(int x)
{
	m_fontSize = x;
	if (m_fontSize > 34)
	{
		m_fontSize = 34;
	}
}

void TextElement::Update()
{

}

void TextElement::Render(SDL_Renderer & r)
{
	std::string holder = m_string;
	std::vector<std::string> strings;
	std::vector<std::string> stringKey;
	while (holder.length() > 0)
	{	
		int b = holder.find("[b]");
		int it = holder.find("[i]");
		int bi = holder.find("[bi]");
		if (b == -1) { b = inf; }; if (it == -1) { it = inf; }; if (bi == -1) { bi = inf; };

		if (holder.at(0) != '[')
		{
			strings.push_back(holder);
			if (b < it && b < bi && b != inf)
			{
				strings.back().erase(b, strings.back().length());
				holder.erase(0, b);
			}
			else if (it < b && it < bi && it != inf)
			{
				strings.back().erase(it, strings.back().length());
				holder.erase(0, it);
			}
			else if (bi < b && bi < it && bi != inf)
			{
				strings.back().erase(bi, strings.back().length());
				holder.erase(0, bi);
			}
			else
			{
				holder.erase(0, strings.back().length());
			}
			stringKey.push_back("normal");
		}
		else if (b < it && b < bi && b != inf)
		{
			holder.erase(0, 3);
			strings.push_back(holder);
			int end = holder.find("[\\b]");
			switch (end)
			{
			case -1:
			{
				holder.erase(0, holder.length());
				break;
			}
			default:
			{
				strings.back().erase(end, strings.back().length());
				holder.erase(0, end + 4);
				break;
			}
			}
			stringKey.push_back("bold");
			
		}
		else if (it < b && it < bi && it != inf)
		{
			holder.erase(0, 3);
			strings.push_back(holder);
			int end = holder.find("[\\i]");
			switch (end)
			{
			case -1:
			{
				holder.erase(0, holder.length());
				break;
			}
			default:
			{
				strings.back().erase(end, strings.back().length());
				holder.erase(0, end + 4);
				break;
			}
			}
			stringKey.push_back("italic");
		}
		else if (bi < b && bi < it && bi != inf)
		{
			holder.erase(0, 4);
			strings.push_back(holder);
			int end = holder.find("[\\bi]");
			switch (end)
			{
			case -1:
			{
				holder.erase(0, holder.length());
				break;
			}
			default:
			{
				strings.back().erase(end, strings.back().length());
				holder.erase(0, end + 5);
				break;
			}
			}
			stringKey.push_back("bolditalic");
		}
	}
	int x = m_x;
	for (int i = 0; i < strings.size(); i++)
	{
		if (strings.at(i).size() > 0)
		{
			SDL_Surface *surfaceMessage;
			SDL_Point p;
			if (stringKey.at(i) == "bold")
			{
				surfaceMessage = TTF_RenderText_Blended(m_fontpack->fonts.at(m_fontSize)->Bold, strings.at(i).c_str(), m_color);
				p = StringSize(m_fontpack->fonts.at(m_fontSize)->Bold, strings.at(i));
			}
			else if (stringKey.at(i) == "italic")
			{
				surfaceMessage = TTF_RenderText_Blended(m_fontpack->fonts.at(m_fontSize)->Italics, strings.at(i).c_str(), m_color);
				p = StringSize(m_fontpack->fonts.at(m_fontSize)->Italics, strings.at(i));
			}
			else if (stringKey.at(i) == "bolditalic")
			{
				surfaceMessage = TTF_RenderText_Blended(m_fontpack->fonts.at(m_fontSize)->Bold_Italics, strings.at(i).c_str(), m_color);
				p = StringSize(m_fontpack->fonts.at(m_fontSize)->Bold_Italics, strings.at(i));
			}
			else
			{
				surfaceMessage = TTF_RenderText_Blended(m_fontpack->fonts.at(m_fontSize)->Normal, strings.at(i).c_str(), m_color);
				p = StringSize(m_fontpack->fonts.at(m_fontSize)->Normal, strings.at(i));
			}
			SDL_Texture *message = SDL_CreateTextureFromSurface(&r, surfaceMessage);
			SDL_Rect temp;
			if (m_autoSize)
			{
				temp = { x, m_y, surfaceMessage->w, surfaceMessage->h };
			}
			else
			{
				temp = { x, m_y, m_width, m_height };
			}

			SDL_RenderCopy(&r, message, NULL, &temp);

			SDL_DestroyTexture(message);
			SDL_FreeSurface(surfaceMessage);

			x += p.x;
		}
	}
}