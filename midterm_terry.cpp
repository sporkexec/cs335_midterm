#include <iostream>
using namespace std;

struct Cell
{
    char val;	// V, H, or 0
    int row;
    int col;
    bool mark;
    bool check;
};

bool path_vert (Cell &cell, Cell** grid, int size);
bool path_horiz (Cell &cell, Cell** grid, int size);

int main()
{
    int size = 4;
    char winner = ' ';

    Cell **grid = new Cell*[size];
    for (int i = 0; i < size; i++)
    {
	grid[i] = new Cell[size];
    }

    for (int i = 0; i < size; i++)
    {
	for (int j = 0; j < size; j++)
	{
	    grid[i][j].val = '0';
	    grid[i][j].mark = false;
	    grid[i][j].check = false;
	    grid[i][j].row = i;
	    grid[i][j].col = j;
	}
    }

    grid [0][3].val = 'H';
    grid [1][1].val = 'H';
    grid [2][0].val = 'H';
//    grid [1][3].val = 'H';
    grid [2][3].val = 'H';
    grid [3][2].val = 'H';
    grid [2][2].val = 'H';
    grid [0][0].val = 'H';

    // Code for player V's turn goes here
    
    for (int i = 0; i < size; i++)
    {
	if (grid[0][i].val == 'V')
	{
	    if (path_vert (grid[0][i], grid, size))
	    {
		winner = 'V';
		break;
	    }
	}
    }

    // Code for player H's turn goes here
    
    for (int i = 0; i < size; i++)
    {
	if (grid[i][0].val == 'H')
	{
	    if (path_horiz(grid[i][0], grid, size))
	    {
		winner = 'H';
		break;
	    }
	}
    }

    if (winner != ' ')
    {
	for (int i = 0; i < size; i++)
	{
	    for (int j = 0; j < size; j++)
	    {
		if (grid[i][j].mark == true)
		{
		    grid[i][j].val = '*';
		}
	    }
	}
	cout << "\nWinner: " << winner << "\n\n";
    }
    else
	cout << "\nNo winner.\n\n";

    for (int i = 0; i < size; i++)
    {
	for (int j = 0; j< size; j++)
	{
	    cout << grid[i][j].val << " ";
	}
	cout << "\n";
    }
    cout << "\n";

    return 0;
}

bool path_vert (Cell &cell, Cell** grid, int size)
{
    cell.mark = true;
    if (cell.row == size - 1)
    {
	return true;
    }    

    int row_min = cell.row - 1;
    if (row_min < 0)
	row_min = 0;
    int row_max = cell.row + 1;
    if (row_max >=size)
	row_max = size - 1;
    int col_min = cell.col - 1;
    if (col_min < 0)
	col_min = 0;
    int col_max = cell.col + 1;
    if (col_max >= size)
	col_max = size - 1;

    for (int row = row_max; row >= row_min; row--)
    {
	for (int col = col_min; col <= col_max; col++)
	{
	    if (grid[row][col].val == 'V' && grid[row][col].check == false)
	    {
    		grid[row][col].check = true;
    		bool good = path_vert (grid[row][col], grid, size);

    		if (!good)
		{
    		    grid[row][col].mark = false;
		}
		if (grid[row][col].mark == true)
    		    return good;
	    }
	}
    }
    return false;
}

bool path_horiz (Cell &cell, Cell** grid, int size)
{ 
    cell.mark = true;
    if (cell.col == size - 1)
    {
	return true;
    }    

    int row_min = cell.row - 1;
    if (row_min < 0)
	row_min = 0;
    int row_max = cell.row + 1;
    if (row_max >=size)
	row_max = size - 1;
    int col_min = cell.col - 1;
    if (col_min < 0)
	col_min = 0;
    int col_max = cell.col + 1;
    if (col_max >= size)
	col_max = size - 1;

    for (int row = row_min; row <= row_max; row++)
    {
	for (int col = col_max; col >= col_min; col--)
	{
	    if (grid[row][col].val == 'H' && grid[row][col].check == false)
	    {
    		grid[row][col].check = true;
    		bool good = path_horiz (grid[row][col], grid, size);

    		if (!good)
		{
    		    grid[row][col].mark = false;
		}
		if (grid[row][col].mark == true)
    		    return good;
	    }
	}
    }
    return false;
}
