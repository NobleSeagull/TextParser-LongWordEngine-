#pragma once

#include "stdafx.h"
#include "FontPack.h"

class ResourceManager
{
public:
	ResourceManager(SDL_Renderer* r, std::string directory)
	{
		m_renderer = r;
		m_directory = directory;
		TTF_Init();
	};
	~ResourceManager() {};

	//Texture Stuff
	void AddTexture(std::string id, std::string location);
	void RemoveTexture(std::string id);
	SDL_Texture * GetTexture(std::string id);

	//Font Stuff
	void AddFont(std::string id, std::string location, int size);
	void RemoveFont(std::string id);
	TTF_Font * GetFont(std::string id);

	//Font Large Stuff
	void AddFontPack(std::string id, std::string normal, std::string normal_loc, std::string bold, std::string bold_loc, std::string italics, std::string italics_loc, std::string bolditalics, std::string bolditalics_loc);
	void RemoveFontPack(std::string id);
	FontPack * GetFontPack(std::string id);

private:

	SDL_Renderer * m_renderer;
	std::string m_directory;

	//Textures
	std::vector<SDL_Surface*> m_surfaces;
	std::vector<SDL_Texture*> m_textures;
	std::vector<std::string> m_textureKey;

	//Font
	std::vector<TTF_Font*> m_fonts;
	std::vector<std::string> m_fontKey;

	//FontPack
	std::vector<FontPack*> m_fontPacks;

};
