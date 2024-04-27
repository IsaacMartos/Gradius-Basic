#pragma once

class DrawEngine
{
	char *screenMatrix;


public:
	int boardSizeX;
	int boardSizeY;

	char corner_top_left = 201;
	char corner_top_right = 187;
	char corner_bot_left = 200;
	char corner_bot_right = 188;
	char row_lines = 205;
	char col_lines = 186;
	char connection_right = 204;
	char connection_left = 185;

	DrawEngine(int x, int y) : boardSizeX(x+1), boardSizeY(y)
	{
		screenMatrix = new char[((x+1)*y)+1]; 
		ResetMatrix(' ');
	}

	~DrawEngine() {}

	void DrawMatrix();
	void ResetMatrix(const char c);
	void ClearScreen();
	void DrawAtPos(const char c, int x, int y);
	void DrawAtPos(const char c, int index);
	void DrawAtPos(const char* string, int h, int w);
	void DrawRow(const char character, int h, int w);
	void DrawColumn(const char character, int h, int w);
	void DrawSpecificRow(const char character, int h, int startw, int endw);
	void DrawSpecificColumn(const char character, int starth, int endh, int w);

};





