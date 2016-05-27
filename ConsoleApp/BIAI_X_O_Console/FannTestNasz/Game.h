#pragma once

#include <ios>
#include <iostream>
#include <iomanip>
#include "Board.h"
#include "Fann.h"
using std::cout;
using std::cerr;
using std::endl;
using std::setw;
using std::left;
using std::right;
using std::showpos;
using std::noshowpos;

class Game
{
private:
	FieldValue actualPlayer;
	Board board;
	bool trainingOn = false;

public:
	Fann *fann;
	bool ended = false;


	Game()
	{
		board = Board();
		actualPlayer = X;
	}

	void NextMove()
	{
		board.PrintBoard();

		bool correctField = false;
		int x, y;

		while (!correctField)
		{
			printf("Now is playing %s, choose field...\n", board.GetValueAsString(actualPlayer));
			printf("x: ");
			std::cin >> x;
			printf("\ny: ");
			std::cin >> y;

			x--;
			y--;

			if (x == -1)
			{
				board = Board();
				//ended = true;
				break;
			}

			if (board.IsFieldEmpty(x, y))
			{
				if (fann->Loaded())
				{
					int fannX, fannY;
					GetFannMove(fannX, fannY);
					printf("\nFann would play: %d,%d", fannX+1, fannY+1);
				}

				if (trainingOn)
				{
					TrainFann(x, y);
				}

				board.WriteField(x, y, actualPlayer);
				ChangeActualPlayer();
				correctField = true;
			}
			else
			{
				printf("\nThis field is busy! \n");
			}
		}

	}

	void GetFannMove(int &result_x, int &result_y)
	{
		int *input;
		input = GetFannInput();

		float* output = (float*)fann->Run((fann_type*)input);

		float max = -999999999999999;

		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				if (output[y * 5 + x] > max)
				{
					result_x = x;
					result_y = y;
					max = output[y * 5 + x];
				}
			}
		}

		//DEBUG

		printf("\n\n Fann Output: \n");

		for (int i = 0; i < 25; i++)
		{
			printf("%f ", output[i]);
		}

		printf("\n\n");
	}

	int* GetFannInput()
	{
		int input[50];
		int me[25];
		int opponent[25];

		if (actualPlayer == X)
		{
			board.GetBoardAsInt_X(me);
			board.GetBoardAsInt_O(opponent);
		}
		else
		{
			board.GetBoardAsInt_X(opponent);
			board.GetBoardAsInt_O(me);
		}


		for (int i = 0; i < 25; i++)
		{
			input[i] = me[i];
			input[i + 25] = opponent[i];
		}


		//DEBUG

		printf("\n\n Fann Input\n");

		for (int i = 0; i < 25; i++)
		{
			printf("%d ", input[i]);
		}

		printf("\n\n");

		for (int i = 0; i < 25; i++)
		{
			printf("%d ", input[i+25]);
		}

		return input;
	}

	void TrainFann(int expectedX, int expectedY)
	{
		int *input;
		int output[25];

		input = GetFannInput();

		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				if (x == expectedX && y == expectedY)
				{
					output[y * 5 + x] = 1;
				}
				else
				{
					output[y * 5 + x] = 0;
				}
			}
		}

		fann->Train((fann_type*)input, (fann_type*)output);
	}

	void TurnOnTrainingFann(Fann *_fann)
	{
		trainingOn = true;
		fann = _fann;
	}

	void TurnOffTrainingFann()
	{
		trainingOn = false;
	}

private:

	void TrainFann()
	{

	}

	void ChangeActualPlayer()
	{
		if (actualPlayer == X)
		{
			actualPlayer = O;
		}
		else
		{
			actualPlayer = X;
		}
	}
};