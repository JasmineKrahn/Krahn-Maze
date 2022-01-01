#include "Maze.h"

//-----------------------------------------------------------------
// Maze constructor
// Reads in the map.
// Sets valid to true if there are no invalid characters found and
// the size of the map is valid
//-----------------------------------------------------------------
Maze::Maze(Panel^ drawingPanel, ifstream& ifs)
{
	panel = drawingPanel;
	free = false;
	orig = nullptr;
	solved = nullptr;
	char curr;
	ifs >> width;
	ifs >> height;
	if (width <= MAXSIZE && height <= MAXSIZE)
	{
		orig = new char* [height];
		for (int i = 0; i < height; ++i)
			orig[i] = new char[width];

		solved = new char* [height];
		for (int j = 0; j < height; ++j)
			solved[j] = new char[width];
		
		for (int k = 0; k < height; k++)
		{
			for (int l = 0; l < width; l++)
			{
				ifs >> curr;
				if ((curr != OPEN) && (curr != DEADEND) && (curr != EXIT))
					valid = false;
				else if (orig != nullptr && solved != nullptr)
				{
					orig[k][l] = curr;
					solved[k][l] = curr;
				}
			}
		}
	}
}

// Maze destructor – clean up dynamically allocated 2D arrays!
Maze::~Maze()
{
	if (orig != nullptr)
	{
		for (int i = 0; i < height; ++i)
			delete[] orig[i];
		delete[] orig;
	}
	if (solved != nullptr)
	{
		for (int i = 0; i < height; ++i)
			delete[] solved[i];
		delete[] solved;
	}
}

//-----------------------------------------------------------------
// First checks if the mouse clicked a deadend or the exit and
// returns if either is true.
// Otherwise, it establishes the starting cell, colors it red,
// and calls RecSolve with the row and column of the clicked
// cell as parameters.
//-----------------------------------------------------------------
void Maze::Solve(int xPixel, int yPixel)
{
	if (valid)
	{
		free = false;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				solved[i][j] = orig[i][j];
			}
		}
		int startCol = xPixel / CELLSIZE;
		int startRow = yPixel / CELLSIZE;
		if (startCol < width && startCol >= 0 && startRow < height && startRow >= 0)
		{
			if (solved[startRow][startCol] == EXIT)
				free = true;
			else if (solved[startRow][startCol] == DEADEND)
				free = false;
			else
			{
				solved[startRow][startCol] = START;
				RecSolve(startRow, startCol);
			}
		}
		Show(solved);
	}
}

// Solves the maze recursively.
// First, as a base case, it checks if the current cell is the exit.
// If the cell is not the exit, it then checks if any adjacent cells
// are the exit if the exit is adjacent, RecSolve is called with
// the location of the exit as parameters.
// Otherwise, it checks for adjacent open cells and makes calls
// to RecSolve to move to said open cells.
//-----------------------------------------------------------------
void Maze::RecSolve(int row, int col)
{
	if (solved[row][col] == EXIT)
		free = true;
	else if (solved[row][col] != START)
		solved[row][col] = VISITED;
	if (col - 1 >= 0)
	{
		if (solved[row][col - 1] == OPEN || solved[row][col-1] == EXIT)
			RecSolve(row, col - 1);
	}
	if (col + 1 < width)
	{
		if (solved[row][col + 1] == OPEN || solved[row][col + 1] == EXIT)
			RecSolve(row, col + 1);
	}
	if (row + 1 < height)
	{
		if (solved[row + 1][col] == OPEN || solved[row + 1][col] == EXIT)
			RecSolve(row + 1, col);
	}
	if (row - 1 >= 0)
	{
		if (solved[row - 1][col] == OPEN || solved[row - 1][col] == EXIT)
			RecSolve(row - 1, col);
	}
}

//-----------------------------------------------------------------
// Displays the given data as a maze with deadends represented by
// black squares, open cells by white squares, and the exit by
// a green square.
//-----------------------------------------------------------------
void Maze::Show(char** cells)
{
	Graphics^ g = panel->CreateGraphics();

	g->Clear(Color::LightGray);

	SolidBrush^ blackBrush = gcnew SolidBrush(Color::Black);
	SolidBrush^ whiteBrush = gcnew SolidBrush(Color::White);
	SolidBrush^ blueBrush = gcnew SolidBrush(Color::Blue);
	SolidBrush^ greenBrush = gcnew SolidBrush(Color::Green);
	SolidBrush^ redBrush = gcnew SolidBrush(Color::Red);

	if (valid)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (cells[i][j] == DEADEND)
					g->FillRectangle(blackBrush, (CELLSIZE * j), (CELLSIZE * i), CELLSIZE, CELLSIZE);
				else if (cells[i][j] == OPEN)
					g->FillRectangle(whiteBrush, (CELLSIZE * j), (CELLSIZE * i), CELLSIZE, CELLSIZE);
				else if (cells[i][j] == EXIT)
					g->FillRectangle(greenBrush, (CELLSIZE * j), (CELLSIZE * i), CELLSIZE, CELLSIZE);
				else if (cells[i][j] == START)
					g->FillRectangle(redBrush, (CELLSIZE * j), (CELLSIZE * i), CELLSIZE, CELLSIZE);
				else if (cells[i][j] == VISITED)
					g->FillRectangle(blueBrush, (CELLSIZE * j), (CELLSIZE * i), CELLSIZE, CELLSIZE);
			}
		}
	}

}
