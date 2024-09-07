// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

void Init();
void Update();
void Draw();

int main()
{
	
	int arr[20][10];
	int rows = sizeof(arr) / sizeof arr[0];
	int cols = sizeof(arr[0]) / sizeof(int);

	for (int i = 0; i < rows ; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = 0;
		}
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << arr[i][j];
		}
		std::cout << "\n";
	}
}



