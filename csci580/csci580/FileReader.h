#pragma once
#ifndef _FILE_READER_
#define _FILE_READER_


#include <string.h>
#include <stdlib.h>
#include "stdio.h"
#include "math.h"

#define INPUT_FILE "foot.raw"

#define X_MAX 256
#define Y_MAX 256
#define Z_MAX 256


class FileReader
{

	inline void setcolorRange(int current_value)
	{
		if (current_value > color_max)
		{
			color_max = current_value;
		}

		if (current_value < color_min)
		{
			color_min = current_value;
		}
	}

public:
	FileReader(short int*** data);
	~FileReader();

	short int*** volumn_data;
	short int color_max = 0;
	short int color_min = 255;

	bool readFile(char* file_name = INPUT_FILE);
};


#endif // !_FILE_READER_