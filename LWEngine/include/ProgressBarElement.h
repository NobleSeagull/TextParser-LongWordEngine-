#ifndef _PROGRESSBARELEMENT_H
#define _PROGRESSBARELEMENT_H

#include "Panel.h"

enum Direction { UP, DOWN, LEFT, RIGHT };

class ProgressBarElement
{
public:
	ProgressBarElement(Panel background, int maximum, SDL_Color barcolor, Direction direction);
	~ProgressBarElement();

	int CurrentValue() { return m_currentValue; };
	void CurrentValue(int x) { m_currentValue = x; };

	int MaxValue() { return m_maxValue; };
	void MaxValue(int x) { m_maxValue = x; };

	int X() { return m_panel.X(); };
	void X(int x) { m_panel.X(x); };

	int Y() { return m_panel.Y(); };
	void Y(int x) { m_panel.Y(x); };

	int Width() { return m_panel.Width(); };
	void Width(int x) { m_panel.Width(x); };

	int Height() { return m_panel.Height(); };
	void Height(int x) { m_panel.Height(x); };

	int MarginWidth() { return m_panel.Margin(); };
	void MarginWidth(int x) { m_panel.Margin(x); };

	SDL_Color BodyColor() { return m_panel.BodyColor(); };
	void BodyColor(SDL_Color c) { m_panel.BodyColor(c); };

	SDL_Color MarginColor() { return m_panel.MarginColor(); };
	void MarginColor(SDL_Color c) { m_panel.MarginColor(c); };

	void Render(SDL_Renderer & r);

private:
	Panel m_panel;
	int m_maxValue;
	int m_currentValue;
	Direction m_direction;
	SDL_Color m_barColor;
};
#endif
