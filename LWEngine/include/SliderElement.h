#ifndef _SLIDERELEMENT_H
#define _SLIDERELEMENT_H
#include "ButtonElement.h"

class SliderElement
{
public:
	SliderElement() {};
	SliderElement(EventListener * e, int noOfLines, int noOfLinesPerPage, Panel background, SDL_Texture * downArrow, SDL_Texture * upArrow);
	~SliderElement();

	int X() { return m_panel.X(); };
	void X(int x);

	int Y() { return m_panel.Y(); };
	void Y(int x);

	int Width() { return m_panel.Width(); };
	void Width(int x);

	int Height() { return m_panel.Height(); };
	void Height(int x);

	int MarginWidth() { return m_panel.Margin(); };
	void MarginWidth(int x);

	SDL_Color BodyColor() { return m_panel.BodyColor(); };
	void BodyColor(SDL_Color c);

	SDL_Color MarginColor() { return m_panel.MarginColor(); };
	void MarginColor(SDL_Color c);

	int NumberOfLines() { return m_numberOfLines; };
	void NumberOfLines(int x) { m_numberOfLines = x; };

	int NumberOfVisibleLines() { return m_visibleLines; };
	void NumberOfVisibleLines(int x) { m_visibleLines = x; };

	int CurrentLine() { return m_currentTopLine; };
	void CurrentLine(int x) { m_currentTopLine = x; };

	void Update();
	void Render(SDL_Renderer & r);

private:

	Panel m_panel;
	ButtonElement m_upButton, m_downButton, m_sliderButton;
	int m_numberOfLines, m_visibleLines, m_currentTopLine;
	bool m_buttonHeld;
	int m_mousePositionY, m_mouseDifference;
	int m_timer;
	int TIMER = 5;
};
#endif

