/*
 * main.cpp
 *
 * NAME: Raina Galbiati
 * DATE: 7/8/2016
 * Purpose: Finds the maximum sum from the top of a triangle to the bottom.
 *
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "triangle.h"


void read_file(char * argv[], Triangle &t);

int main(int argc, char * argv[])
{
	if (argc != 2) {
		std::cerr << "usage: program file1" << std::endl;
		exit(1);
	}

	Triangle t;
	read_file(argv, t);

	int sum = t.dynamic_sum();
	std::cout << sum << std::endl;

	return 0;
}

/*
 * Purpose: reads file and inputs values into vector
 * Args: input file, reference to 2D vector that holds triangle
 * 	(part of Triangle class)
 */
void read_file(char * argv[], Triangle &t)
{
	std::ifstream file (argv[1]);
	int input;
	int row = 0;
	int row_length = 1;
	int index = 0;

	//push 1st row into vector
	std::vector <int> newRow;
	t.nums.push_back(newRow);

	while  (file >> input) {
		//if at end of row
		if (index == row_length) {
			std::vector <int> newRow;
			t.nums.push_back(newRow);
			row++;
			row_length++;
			index = 0;
		}
		t.nums.at(row).push_back(input);
		index++;
	}
	file.close();
}

