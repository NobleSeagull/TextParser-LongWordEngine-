#define SDL_MAIN_HANDLED

#include "stdafx.h"
#include "ResourceManager.h"
#include "TextBox.h"
#include "SliderElement.h"
#include "InputBox.h"
#include "ProgressBarElement.h"


int main()
{

	bool running = true;

	SDL_Window* gameWindow = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	SDL_Renderer* gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Event *e = new SDL_Event();

	EventListener * eventListener = new EventListener();
	InputHandler inputHandler = InputHandler(e, eventListener);

	ResourceManager* resources = new ResourceManager(gameRenderer, "../Resources");
	resources->AddFontPack("SSP", "SSP_NORMAL", "SSP/SourceSansPro-Regular.ttf", "SSP_B", "SSP/SourceSansPro-Bold.ttf", "SSP_I", "SSP/SourceSansPro-Italic.ttf", "SSP_BI", "SSP/SourceSansPro-BoldItalic.ttf");
	resources->AddTexture("DownArrow", "arrow_down.png");
	resources->AddTexture("UpArrow", "arrow_up.png");

	TextBox t = TextBox(eventListener, resources->GetFontPack("SSP"), Panel(0, 0, 500, 450, 5, SDL_Color{ 75, 50 ,75 }, SDL_Color{ 50, 25 ,50 }), resources->GetTexture("DownArrow"), resources->GetTexture("UpArrow"));
	t.SetTextColor(SDL_Color{ 255,255,255,255 });

	InputBox b = InputBox(eventListener, Panel(0, 450, 400, 40, 5, SDL_Color{ 75, 50 ,75 }, SDL_Color{ 50, 25 ,50 }), resources->GetFontPack("SSP"), 5, 5);
	ButtonElement button = ButtonElement(eventListener, Panel(400, 450, 100, 40, 5, SDL_Color{ 75, 50 ,75 }, SDL_Color{ 50, 25 ,50 }), TextElement(resources->GetFontPack("SSP"), 18, true, 0, 0, 0, 0, SDL_Color{ 255,255,255,255 }),"[b]Add Line", 15, 8);
	b.Text("Input Text Here");

	//
	std::string stringHolder = "Normal[n][i]Italics[\\i][n][b]Bold[\\b][n][bi]Bold Italics![\\bi]";
	t.SetString(stringHolder);

	while (running)
	{
		t.Update();
		b.Update();
		button.Update();
		inputHandler.InputCheck();
		if (button.Activated())
		{
			if (b.Text().length() > 0)
			{
				stringHolder += "[n]" + b.Text();
				b.Text("");
				t.SetString(stringHolder);
			}
		}

		SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 0);
		SDL_RenderClear(gameRenderer);
		//Draw Code Here
		t.Render(*gameRenderer);
		b.Render(*gameRenderer);
		button.Render(*gameRenderer);
		//
		SDL_RenderPresent(gameRenderer);
	}
	return 0;
}