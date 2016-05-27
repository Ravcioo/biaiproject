#include "floatfann.h"
#include "fann_cpp.h"
#include "Game.h"
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

int main(int argc, char **argv)
{
	Game game = Game();
	Fann fann = Fann();

	game.TurnOnTrainingFann(&fann);

	try
	{
		std::ios::sync_with_stdio();

		fann.CreateNew();
		fann.TrainWithFile("game_float.data");
		//fann.Load();

		while (!game.ended)
		{
			game.NextMove();
		}

		fann.Save();
		fann.Destroy();
	}
	catch (...)
	{
		cerr << endl << "Abnormal exception." << endl;
	}

	return 0;
}

/******************************************************************************/
