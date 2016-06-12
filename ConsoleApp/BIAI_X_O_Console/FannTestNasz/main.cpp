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
	
	Fann fann = Fann();
	Game game = Game();

	try
	{
		std::ios::sync_with_stdio();

		fann.CreateNew();
		fann.TrainWithFile("game_float.data");
		//fann.Load();
		if (game.init())
		{
			game.setFann(&fann);
		}
		game.start();
		fann.Save();
		fann.Destroy();
		system("pause");
	}
	catch (...)
	{
		cerr << endl << "Abnormal exception." << endl;
	}

	return 0;
}

/******************************************************************************/
