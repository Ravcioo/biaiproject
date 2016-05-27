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

class Fann
{

	struct fann *ann;
	const char* path = "game_float.net";

public:

	void CreateNew()
	{
		const unsigned int num_input = 50;
		const unsigned int num_output = 25;
		const unsigned int num_layers = 3;
		const unsigned int num_neurons_hidden = 100;

		ann = fann_create_standard(num_layers, num_input,
			num_neurons_hidden, num_output);

		fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
		fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);
	}

	bool Loaded()
	{
		return ann != NULL;
	}

	void Save()
	{
		fann_save(ann, "game_float.net");
	}

	void Load()
	{
		ann = fann_create_from_file("game_float.net");
	}

	void Destroy()
	{
		fann_destroy(ann);
	}

	void TrainWithFile(char* filePath)
	{
		const float desired_error = (const float) 0.0001;
		const unsigned int max_epochs = 500000;
		const unsigned int epochs_between_reports = 1000;

		fann_train_on_file(ann, filePath, max_epochs,
			epochs_between_reports, desired_error);
	}

	void Train(fann_type *input, fann_type *desiredOutput)
	{
		fann_train(ann, input, desiredOutput);
	}

	fann_type* Run(fann_type *input)
	{
		fann_type *output;

		output = fann_run(ann, input);

		return output;
	}

};



