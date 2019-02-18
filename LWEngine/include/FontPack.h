#ifndef _FONTPACK_H
#define _FONTPACK_H

#include "stdafx.h"
#include "ResourceManager.h"

class Font
{
public:

	Font(std::string id, int size, TTF_Font * normal, TTF_Font * bold, TTF_Font * italics, TTF_Font * bolditalics)
	{
		ID = id;
		Size = size;
		Normal = normal;
		Bold = bold;
		Italics = italics;
		Bold_Italics = bolditalics;
	}

	int Size;
	std::string ID;
	TTF_Font * Normal;
	TTF_Font * Bold;
	TTF_Font * Italics;
	TTF_Font * Bold_Italics;
};

class FontPack
{
public:
	FontPack(std::string id, std::vector<Font*> f)
	{
		ID = id;
		fonts = f;
	}
	std::vector<Font*> fonts;
	std::string ID;
};

#endif