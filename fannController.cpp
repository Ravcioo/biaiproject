/*
*
*  Fast Artificial Neural Network (fann) C++ Wrapper Sample
*
*  C++ wrapper XOR sample with functionality similar to xor_train.c
*
*  Copyright (C) 2004-2006 created by freegoldbar (at) yahoo dot com
*
*  This wrapper is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*
*  This wrapper is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public
*  License along with this library; if not, write to the Free Software
*  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*/

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

struct fann *ann;

void CreateNewFANN()
{
	const unsigned int num_input = 2;
	const unsigned int num_output = 1;
	const unsigned int num_layers = 3;
	const unsigned int num_neurons_hidden = 3;

	ann = fann_create_standard(num_layers, num_input,
		num_neurons_hidden, num_output);

	fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
	fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);
}

void SaveFANN()
{
	fann_save(ann, "xor_float.net");
}

void LoadFANN()
{
	ann = fann_create_from_file("xor_float.net");
}

void DestroyFANN()
{
	fann_destroy(ann);
}

void TrainFANN(char* filePath)
{
	const float desired_error = (const float) 0.001;
	const unsigned int max_epochs = 500000;
	const unsigned int epochs_between_reports = 1000;

	fann_train_on_file(ann, filePath, max_epochs,
		epochs_between_reports, desired_error);
}

float RunFANN(int input_1,int input_2)
{
	fann_type *calc_out;
	fann_type input[2];

	input[0] = input_1;
	input[1] = input_2;
	calc_out = fann_run(ann, input);

	return calc_out[0];
}


int main(int argc, char **argv)
{
	try
	{
		std::ios::sync_with_stdio(); // Syncronize cout and printf output
		CreateNewFANN();
		//LoadFANN();
		TrainFANN("xor.data");

		float result = RunFANN(1, 1);

		printf("Result: %f", result);

		SaveFANN();
		DestroyFANN();
	}
	catch (...)
	{
		cerr << endl << "Abnormal exception." << endl;
	}


	char a;

	std::cin >> a;

	return 0;
}

/******************************************************************************/
