#include "TextBox.h"



TextBox::TextBox(EventListener * e, FontPack * font, Panel panel, SDL_Texture* uptexture, SDL_Texture* downtexture)
{
	m_panel = panel;
	m_color = SDL_Color{ 255,255,255,255 }; 
	m_textElements.push_back(new TextElement(font, 18, true, 0, 0, 0, 0, m_color));
	m_slider = SliderElement(e, 1, 1, Panel(m_panel.X() + (panel.Width() * 0.9), 0, panel.Width() / 10, panel.Height(), panel.Margin(), m_panel.BodyColor(), m_panel.MarginColor()), uptexture, downtexture);
}

void TextBox::Update()
{
	for (int i = 0; i < m_lines.size() && i < m_textElements.size(); i++)
	{
		m_textElements.at(i)->Update();
	}
	m_slider.Update();
	if (m_currentLine != m_slider.CurrentLine())
	{
		m_currentLine = m_slider.CurrentLine();
		for (int i = 0; i < m_textElements.size(); i++)
		{
			m_textElements.at(i)->SetString(m_lines.at(i + m_currentLine));
		}
	}
}
void TextBox::Render(SDL_Renderer & r)
{
	m_panel.Render(r);
	m_slider.Render(r);
	for (int i = 0; i < m_lines.size() && i < m_textElements.size(); i++)
	{
		m_textElements.at(i)->Render(r);
	}
}

void TextBox::SetFontPack(FontPack * f)
{
	for (int i = 0; i < m_textElements.size(); i++)
	{
		m_textElements.at(i)->SetFontPack(f);
	}
}

void TextBox::SetFontSize(int x)
{
	for (int i = 0; i < m_textElements.size(); i++)
	{
		m_textElements.at(i)->SetFontSize(x);
	}
}

void TextBox::SetString(std::string s)
{
	m_currentLine = 0;
	m_text = s;
	std::string textHolder = s;
	std::vector<std::string> paragraphs;
	int noOfOccurences = std::count(m_text.begin(), m_text.end(), '[n]');
	bool paraComplete = false;
	while(!paraComplete)
	{
		if (textHolder.size() > 0)
		{
			if (textHolder.at(0) == ' ')
			{
				textHolder.erase(textHolder.begin());
			}
			int x = textHolder.find("[n]");
			if (x != -1)
			{
				paragraphs.push_back(textHolder);
				paragraphs.back().erase(x, paragraphs.back().length());
				textHolder.erase(0, x + 3);
			}
			else
			{
				paraComplete = true;
			}
		}
		else
		{
			paraComplete = true;
		}
	}
	if (textHolder.size() > 0)
	{
		if (textHolder.at(0) == ' ')
		{
			textHolder.erase(textHolder.begin());
		}
	}

	paragraphs.push_back(textHolder);

	SDL_Point holder = StringSize(m_textElements.front()->GetFontPack()->fonts.at(m_textElements.front()->GetFontSize())->Normal, m_text);
	int maxWidth = m_panel.Width() - ((m_panel.Margin() * 4) + (m_panel.Width()/10));
	int meanCharWidth = holder.x / m_text.length();
	int maxNoChar = (maxWidth / meanCharWidth)-3;//Max Chars per line
	m_lineMargin = holder.y / 4;

	m_lines.clear();
	for (int i = 0; i < paragraphs.size(); i++)
	{
		textHolder = paragraphs.at(i);
		while (textHolder.length() > 0)
		{
			bool finished = false;
			std::string line = textHolder.substr(0, maxNoChar);
			int eraseHolder = 0;
			if (line.size() <= maxNoChar - 1)
			{
				finished = true;
				line = textHolder.substr(0, maxNoChar);
				eraseHolder = line.length();
				if (m_lines.size() > 0)
				{
					int b = m_lines.back().rfind("[b]");
					int it = m_lines.back().rfind("[i]");
					int bi = m_lines.back().rfind("[bi]");
					int bend = m_lines.back().rfind("[\\b]");
					int itend = m_lines.back().rfind("[\\i]");
					int biend = m_lines.back().rfind("[\\bi]");
					if (b == -1) { b = -inf; }; if (it == -1) { it = -inf; }; if (bi == -1) { bi = -inf; };
					if (bend == -1) { bend = -inf; }; if (itend == -1) { itend = -inf; }; if (biend == -1) { biend = -inf; };
					if (bend < b) { line = "[b]" + line; } if (itend < it) { line = "[i]" + line; } if (biend < bi) { line = "[bi]" + line; }
				}
			}
			while (!finished)
			{
				if (line.size() <= 0)
				{
					finished = true;
					line = textHolder.substr(0, maxNoChar);
					eraseHolder = line.length();
					line += "-";
					if (m_lines.size() > 0)
					{
						int b = m_lines.back().rfind("[b]");
						int it = m_lines.back().rfind("[i]");
						int bi = m_lines.back().rfind("[bi]");
						int bend = m_lines.back().rfind("[\\b]");
						int itend = m_lines.back().rfind("[\\i]");
						int biend = m_lines.back().rfind("[\\bi]");
						if (b == -1) { b = -inf; }; if (it == -1) { it = -inf; }; if (bi == -1) { bi = -inf; };
						if (bend == -1) { bend = -inf; }; if (itend == -1) { itend = -inf; }; if (biend == -1) { biend = -inf; };
						if (bend < b) { line = "[b]" + line; } if (itend < it) { line = "[i]" + line; } if (biend < bi) { line = "[bi]" + line; }
					}
				}
				if (!finished)
				{
					if (line.at(line.length() - 1) == ' ' && StringSize(m_textElements.front()->GetFontPack()->fonts.at(m_textElements.front()->GetFontSize())->Normal, line).x < maxWidth
						|| line.at(line.length() - 1) == '.' && StringSize(m_textElements.front()->GetFontPack()->fonts.at(m_textElements.front()->GetFontSize())->Normal, line).x < maxWidth
						|| line.at(line.length() - 1) == '!' && StringSize(m_textElements.front()->GetFontPack()->fonts.at(m_textElements.front()->GetFontSize())->Normal, line).x < maxWidth
						|| line.at(line.length() - 1) == '?' && StringSize(m_textElements.front()->GetFontPack()->fonts.at(m_textElements.front()->GetFontSize())->Normal, line).x < maxWidth)
					{
						eraseHolder = line.length();
						if (m_lines.size() > 0)
						{
							int b = m_lines.back().rfind("[b]");
							int it = m_lines.back().rfind("[i]");
							int bi = m_lines.back().rfind("[bi]");
							int bend = m_lines.back().rfind("[\\b]");
							int itend = m_lines.back().rfind("[\\i]");
							int biend = m_lines.back().rfind("[\\bi]");
							if (b == -1) { b = -inf; }; if (it == -1) { it = -inf; }; if (bi == -1) { bi = -inf; };
							if (bend == -1) { bend = -inf; }; if (itend == -1) { itend = -inf; }; if (biend == -1) { biend = -inf; };
							if (bend < b) { line = "[b]" + line; } if (itend < it) { line = "[i]" + line; } if (biend < bi) { line = "[bi]" + line; }
						}
						finished = true;
					}
					else
					{
						line.erase(line.length() - 1);
					}
				}
			}
			m_lines.push_back(line);

			textHolder.erase(0, eraseHolder);

			if (textHolder.length() > 0  && textHolder.at(0) == ' ')
			{
				textHolder.erase(textHolder.begin());
			}
		}
		m_lines.push_back(" ");
	}
	int numberOfTextElements = 0;
	float tempSizeHolder = 0;
	while (tempSizeHolder < (m_panel.Height() * 0.9))
	{
		tempSizeHolder = (numberOfTextElements * (holder.y + m_lineMargin) + m_panel.Margin());
		numberOfTextElements++;
	}
	if (m_textElements.size() > numberOfTextElements)
	{
		int difference = m_textElements.size() - numberOfTextElements;
		for (int i = 0; i < difference; i++)
		{
			delete m_textElements.back();
			m_textElements.pop_back();
			m_textElements.shrink_to_fit();
		}
	}
	else if (m_textElements.size() < numberOfTextElements)
	{
		int difference = numberOfTextElements - m_textElements.size();
		for (int i = 0; i < difference; i++)
		{
			m_textElements.push_back(new TextElement(*m_textElements.front()));
		}
	}
	for (int i = 0; i < m_textElements.size() && i < m_lines.size(); i++)
	{
		m_textElements.at(i)->X((m_panel.X() + m_panel.Margin()) + m_lineMargin);
		m_textElements.at(i)->Y((i * (holder.y + m_lineMargin) + m_panel.Margin()));
		m_textElements.at(i)->SetString(m_lines.at(i));
	}
	m_slider.NumberOfLines(m_lines.size());
	m_slider.NumberOfVisibleLines(m_textElements.size());
}

void TextBox::SetTextColor(SDL_Color c)
{
	for (int i = 0; i < m_textElements.size(); i++)
	{
		m_textElements.at(i)->SetColor(c);
	}
}