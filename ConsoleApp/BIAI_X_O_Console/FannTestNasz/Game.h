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
	FieldValue player1;
	Board board;
	FieldValue winner = Empty;
	

public:
	Fann *fann;
	bool ended = false;
	bool versusAI = false;
	bool trainingOn = false;
	


	Game()
	{
		board = Board();
		actualPlayer = X;
		player1 = X;
	}

	bool init()
	{
		std::string choose;
		cout << "Play with AI? (y/n)" << endl;
		std::cin >> choose;
		if (choose == "y" || choose == "yes" || choose == "")
		{
			versusAI = true;
		}
		cout << "AI in training mode (y/n)?" << endl;
		std::cin >> choose;
		if (choose == "y" || choose == "yes" || choose == "")
		{
			trainingOn = true;
		}

		return versusAI || trainingOn;
	}
	void start()
	{
		while (!ended)
		{
			NextMove();
		}

		
		if (winner != Empty)
		{
			board.PrintBoard();
			cout << board.GetValueAsString(winner)<<" won!"<<endl;
			cout << "Game ended." << endl;
		}
		else {
			cout << "Game stopped" << endl;
		}

	}
	
	void NextMove()
	{
		board.PrintBoard();

		bool correctField = false;
		int x, y;

		while (!correctField)
		{
			printf("Now is playing %s, choose field...\n", board.GetValueAsString(actualPlayer));
			if (player1 == actualPlayer)
			{
				printf("x: ");
				std::cin >> x;
				printf("\ny: ");
				std::cin >> y;
				//TODO: Verify choose
				if (x == -1)
				{
					//board = Board();
					ended = true;
					break;
				}
				x--;
				y--;
			}
			
			if (fann != nullptr && fann->Loaded())
			{
				int fannX, fannY;
				GetFannMove(fannX, fannY);
				printf("\nFann would play: %d,%d", fannX + 1, fannY + 1);
				if (versusAI && actualPlayer != player1)
				{
					x = fannX;
					y = fannY;
				}
			}
			if (trainingOn)
			{
				TrainFann(x, y);
			}
			if (board.IsFieldEmpty(x, y))
			{
				
				if (!versusAI)
				{
					player1 = this->switchFieldValue(player1);
				}
				board.WriteField(x, y, actualPlayer);
				isEnd();
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
		bool correct_move = false;
			for (int y = 0; y < 5; y++)
			{
				for (int x = 0; x < 5; x++)
				{
					if (output[y * 5 + x] > max && board.IsFieldEmpty(x, y))
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

	void setFann(Fann *_fann)
	{
		this->fann = _fann;
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
	FieldValue switchFieldValue(FieldValue field)
	{
		if (field == X)
		{
			return O;
		}
		else if(field == O)
		{
			return X;
		}
		return field;
	}

	void isEnd()
	{
		FieldValue field = actualPlayer;
		int win = 5;
		int count = 0;
		int actx, acty;
		for (int i = 0; i < (board.x *board.y); i++)
		{
			actx = i / board.x;
			acty = i % board.y;
			if (board.fields[acty][actx] != Empty)
			{

				if (board.x - (actx) >= win)
				{
					for (int z = 0; z < win; z++)
					{
						if (field == board.fields[(acty )][actx + z])
						{
							count++;
							if (count == win)
							{
								ended = true;
								winner = actualPlayer;
								return;
							}
						}
						else
						{
							count = 0;
							break;
						}
					}
					
				}
				
				if (board.y - (acty) >= win)
				{
					for (int z = 0; z < win; z++)
					{
						if (field == board.fields[acty + z][actx])
						{
							count++;
							if (count == win)
							{
								ended = true;
								winner = actualPlayer;
								return;
							}
						}
						else {
							count = 0;
							break;
						}
					}
					
				}
				if (board.x - (actx) >= win && board.y - (acty) >= win)
				{
					for (int z = 0; z < win; z++)
					{
						if (field == board.fields[acty + z][actx + z])
						{
							count++;
							if (count == win)
							{
								ended = true;
								winner = actualPlayer;
								return;
							}
						}
						else
						{
							count = 0;
							break;
						}
					}
				}
				if (actx+1 >= win&&board.y - (acty) >= win)
				{
					for (int z = 0; z < win; z++)
					{
						if (field == board.fields[acty +z ][actx - z])
						{
							count++;
							if (count == win) {
								ended = true;
								winner = actualPlayer;
								return;
							}
							
						}
						else
						{
								count = 0;
								break;
						}
					}
				}

				
			}
			
		}
	}
};