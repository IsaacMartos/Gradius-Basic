#include "DrawEngine.h"
#include <iostream>


void DrawEngine::DrawAtPos(const char c, int x, int y)
{
	screenMatrix[boardSizeX*y+x] = c;
}

void DrawEngine::DrawAtPos(const char c, int index)
{
	screenMatrix[index] = c;
}

void DrawEngine::DrawAtPos(const char* string, int h, int w)
{
	int i = 0;
	while (string[i] != '\0' && i < 999)
	{
		char* puntero = &(screenMatrix[h * boardSizeX + w + i]);
		*puntero = string[i];
		i++;
	}
}

void DrawEngine::DrawRow(const char character, int h, int w)
{
	for (size_t r = 1; r < w - 1; ++r)
	{
		screenMatrix[h * boardSizeX + r] = character;
	}
}

void DrawEngine::DrawColumn(const char character, int h, int w)
{
	for (size_t r = 1; r < h - 1; ++r)
	{
		screenMatrix[r * boardSizeX + w] = character;
	}
}

void DrawEngine::DrawSpecificRow(const char character, int h, int startw, int endw)
{
	for (size_t r = startw; r < endw; ++r)
	{
		screenMatrix[h * boardSizeX + r] = character;
	}
}

void DrawEngine::DrawSpecificColumn(const char character, int starth, int endh, int w)
{
	for (size_t c = starth; c < endh; ++c)
	{
		screenMatrix[c * boardSizeX + w] = character;
	}
}

void DrawEngine::ResetMatrix(const char c)
{
	for (size_t i = 0; i < boardSizeX*boardSizeY; i++)
	{
		if (i % boardSizeX == boardSizeX - 1)
			screenMatrix[i] = '\n';
		else
			screenMatrix[i] = c;
	}
	screenMatrix[boardSizeX*boardSizeY] = '\0';
}

void DrawEngine::ClearScreen()
{
	system("cls");
}

void DrawEngine::DrawMatrix()
{
	std::cout << screenMatrix;
}
