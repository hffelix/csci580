#include "FileReader.h"


FileReader::FileReader(short int*** data)
{
	/*
	volumn_data = (short int***)malloc(X_MAX * sizeof(short int**));

	//
	for (int x = 0; x < X_MAX; x++)
	{
		volumn_data[x] = (short int**)malloc(Y_MAX * sizeof(short int**));
	}


	for (int x = 0; x < X_MAX; x++)
	{
		for (int y = 0; y < Y_MAX; y++)
		{
			volumn_data[x][y] = (short int*)malloc(Z_MAX * sizeof(short int*));
		}
	}*/

	volumn_data = data;
}


FileReader::~FileReader()
{
	//volumn_data = (short int***)malloc(X_MAX * sizeof(short int**));
	/*
	for (int x = 0; x < X_MAX; x++)
	{
		for (int y = 0; y < Y_MAX; y++)
		{
			//volumn_data[x][y] = (short int*)malloc(Z_MAX * sizeof(short int*));
			free(volumn_data[x][y]);
		}
	}

	for (int x = 0; x < X_MAX; x++)
	{
		free(volumn_data[x]);
		//volumn_data[x] = (short int**)malloc(Y_MAX * sizeof(short int**));
	}

	free(volumn_data);
	*/
}

bool FileReader::readFile(char* file_name)
{
	int current_c;
	errno_t err;
	FILE* fptr = NULL; //= fopen(file_name, "rb");

	err = fopen_s(&fptr, file_name, "rb");

	if (fptr == NULL)
	{


		fprintf(stderr, "File open failed\n");
		return false;
	}

	/*
	int counter = 0; //16777216 256*256*256
	//short int* volumn = (short int*)malloc(4000000 * sizeof(short int));
	while (counter <= 40000000)
	{
	current_c = fgetc(fptr);

	if (current_c == EOF)
	{
	int b = 0;
	break;
	}

	if (current_c != 0)
	{
	int a = 0;
	}

	setcolorRange(current_c);
	counter++;


	}*/


	for (int z = 0; z < Z_MAX; z++)
	{
		for (int y = 0; y < Y_MAX; y++)
		{
			for (int x = 0; x < X_MAX; x++)
			{
				current_c = fgetc(fptr);
				if (current_c == EOF)
				{
					fprintf(stderr, "Unexpected end of file\n");
					return false;
				}
				else
				{
					volumn_data[x][y][z] = current_c;

					if (current_c != 0)
					{
						int a = 0;
					}

					setcolorRange(current_c);
				}
			}
		}
	}
	fclose(fptr);
	return true;
}
