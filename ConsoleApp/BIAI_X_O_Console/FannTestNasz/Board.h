#pragma once

#include "floatfann.h"
#include "fann_cpp.h"
#include <ios>
#include <iostream>
#include <iomanip>
using std::cout;
using std::cerr;
using std::endl;
using std::setw;
using std::left;
using std::right;
using std::showpos;
using std::noshowpos;


enum FieldValue
{
	Empty,
	X,
	O
};

class Board
{
public:
	FieldValue fields[5][5];

	Board()
	{
		for (int i = 0; i < 25; i++)
		{
			fields[i / 5][i % 5] = Empty;
		}
	}

	bool IsFieldEmpty(int x, int y)
	{
		if (x >= 0 && x < 5 && y >= 0 && y < 5)
		{
			return fields[y][x] == Empty;
		}
		else
		{
			return false;
		}
	}

	void WriteField(int x, int y, FieldValue value)
	{
		fields[y][x] = value;
	}

	void PrintBoard()
	{
		printf("\n\n\n\n\t");
		for (int i = 1; i <= 5; i++)
		{
			printf("%d\t", i);
		}

		for (int y = 0; y < 5; y++)
		{
			printf("\n\n%d\t", y + 1);

			for (int x = 0; x < 5; x++)
			{
				printf("%s\t", GetValueAsString(fields[y][x]));
			}
		}

		printf("\n\n\n\n\t");
	}

	char* GetValueAsString(FieldValue value)
	{
		switch (value)
		{
		case Empty:
			return "-";
		case X:
			return "X";
		case O:
			return "O";
		default:
			break;
		}
	}

	void GetBoardAsInt_X(int * result)
	{
		result[25];

		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
					result[y *5 + x] = fields[y][x] == X ? 1 : 0;
			}
		}
	}

	void GetBoardAsInt_O(int * result)
	{
		result[25];

		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				result[y * 5 + x] = fields[y][x] == O ? 1 : 0;
			}
		}
	}

	/*FieldValue GetStringAsValue(char value)
	{
	switch (value)
	{
	case 'X':
	return X;
	case'O':
	return O;
	default:
	break;
	}
	}*/
};
