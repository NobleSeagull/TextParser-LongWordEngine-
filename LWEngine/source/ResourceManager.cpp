#include "ResourceManager.h"

//Texture Stuff
void ResourceManager::AddTexture(std::string id, std::string location)
{
	std::string temp = m_directory + "/Texture/" + location;
	SDL_Surface * holder;
	const char * tempLocation = temp.c_str();
	if (!(holder = IMG_Load(tempLocation)))
	{
		std::cout << "Could not load " << id << "! Loading Placeholder!" << std::endl;
		temp = m_directory + "/Texture/placeholder.otf";
		tempLocation = temp.c_str();
		holder = IMG_Load(tempLocation);
		m_surfaces.push_back(holder);
		SDL_Texture * tempTexture = SDL_CreateTextureFromSurface(m_renderer, m_surfaces.back());
		m_textures.push_back(tempTexture);
		m_textureKey.push_back(id);
	}
	else
	{
		std::cout << "Loaded " << id << "!" << std::endl;
		m_surfaces.push_back(holder);
		SDL_Texture * tempTexture = SDL_CreateTextureFromSurface(m_renderer, m_surfaces.back());
		m_textures.push_back(tempTexture);
		m_textureKey.push_back(id);
	}
}
void ResourceManager::RemoveTexture(std::string id)
{
	int holder = -1;
	for (int i = 0; i < m_textureKey.size(); i++)
	{
		if (m_textureKey.at(i) == id)
		{
			holder = i;
			break;
		}
	}
	if (holder != -1)
	{
		m_textureKey.erase(m_textureKey.begin() + holder);
		m_textureKey.shrink_to_fit();

		SDL_DestroyTexture(m_textures.at(holder));
		m_textures.erase(m_textures.begin() + holder);
		m_textures.shrink_to_fit();

		SDL_FreeSurface(m_surfaces.at(holder));
		m_surfaces.erase(m_surfaces.begin() + holder);
		m_surfaces.shrink_to_fit();
	}
	else
	{
		std::cout << "Could not find " << id << "!" << std::endl;
	}
}

SDL_Texture * ResourceManager::GetTexture(std::string id)
{
	for (int i = 0; i < m_textureKey.size(); i++)
	{
		if (m_textureKey.at(i) == id)
		{
			return m_textures.at(i);
		}
	}
	std::cout << "Could not find " << id << "!" << std::endl;
	return 0;
}
//

//Font Stuff
void ResourceManager::AddFont(std::string id, std::string location, int size)
{
	std::string temp = m_directory + "/Font/" + location;
	const char * tempLocation = temp.c_str();
	TTF_Font * holder;
	if (!(holder = TTF_OpenFont(tempLocation, size)))
	{
		std::cout << "Could not load " << id << "! Loading Placeholder!" << std::endl;
		temp = m_directory + "/Font/placeholder.ttf";
		tempLocation = temp.c_str();
		holder = TTF_OpenFont(tempLocation, size);
		m_fonts.push_back(holder);
		m_fontKey.push_back(id);
	}
	else
	{
		std::cout << "Loaded " << id << "!" << std::endl;
		m_fonts.push_back(holder);
		m_fontKey.push_back(id);
	}
}
void ResourceManager::RemoveFont(std::string id)
{
	int holder = -1;
	for (int i = 0; i < m_fontKey.size(); i++)
	{
		if (m_fontKey.at(i) == id)
		{
			holder = i;
			break;
		}
	}
	if (holder != -1)
	{
		m_fontKey.erase(m_fontKey.begin() + holder);
		m_fontKey.shrink_to_fit();

		TTF_CloseFont(m_fonts.at(holder));
		m_fonts.erase(m_fonts.begin() + holder);
		m_fonts.shrink_to_fit();
	}
	else
	{
		std::cout << "Could not find " << id << "!" << std::endl;
	}
}

TTF_Font * ResourceManager::GetFont(std::string id)
{
	for (int i = 0; i < m_fontKey.size(); i++)
	{
		if (m_fontKey.at(i) == id)
		{
			return m_fonts.at(i);
		}
	}
	std::cout << "Could not find " << id << "!" << std::endl;
	return 0;
}
//

void ResourceManager::AddFontPack(std::string id, std::string normal, std::string normal_loc, std::string bold, std::string bold_loc, std::string italics, std::string italics_loc, std::string bolditalics, std::string bolditalics_loc)
{
	std::vector<Font*> holder;
	for (int i = 0; i < 36; i++)
	{
		AddFont(normal + "_" + std::to_string(i), normal_loc, i);
		AddFont(bold + "_" + std::to_string(i), bold_loc, i);
		AddFont(italics + "_" + std::to_string(i), italics_loc, i);
		AddFont(bolditalics + "_" + std::to_string(i), bolditalics_loc, i);
		holder.push_back(new Font(id + "_" + std::to_string(i), i, GetFont(normal + "_" + std::to_string(i)), GetFont(bold + "_" + std::to_string(i)), GetFont(italics + "_" + std::to_string(i)), GetFont(bolditalics + "_" + std::to_string(i))));
	}
	m_fontPacks.push_back(new FontPack(id, holder));
}
void ResourceManager::RemoveFontPack(std::string id)
{
	bool notFound = true;
	for (int i = 0; i < m_fontPacks.size(); i++)
	{
		if (m_fontPacks.at(i)->ID == id)
		{
			delete m_fontPacks.at(i);
			m_fontPacks.erase(m_fontPacks.begin() + i);
			m_fontPacks.shrink_to_fit();
			notFound = false;
			break;
		}
	}
	if (notFound)
	{
		std::cout << "Could not find " << id << "!" << std::endl;
	}
}
FontPack * ResourceManager::GetFontPack(std::string id)
{
	bool notFound = true;
	for (int i = 0; i < m_fontPacks.size(); i++)
	{
		if (m_fontPacks.at(i)->ID == id)
		{
			return m_fontPacks.at(i);
		}
	}
	std::cout << "Could not find " << id << "!" << std::endl;
	return 0;
}