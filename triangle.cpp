/*
 * triangle.cpp
 *
 *  Created on: Jul 12, 2016
 *      Author: Raina Galbiati
 */

#include <iostream>
#include <vector>

#include "triangle.h"

/*
 * prints inputed triangle
 */
void Triangle::print_tri()
{
	for (int i = 0; i < (int)nums.size(); i++) {
		for (int j = 0; j < (int)nums.at(i).size(); j++) {
			std::cout << nums[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

/*
 * finds the greatest sum using a greedy algorithm.  Does not necessarily
 * 	find the largest possible sum but generally gets close.
 */
int Triangle::greedy_sum()
{
	int sum = nums[0][0];
	int a, b, j;
	j = 0;

	for (int i = 1; i < (int)nums.size(); i++) {
		a = nums[i][j];
		b = nums[i][j+1];

		if (a < b) {
			sum += b;
			j++;
		}
		else
			sum += a;
	}
	std::cout << "The greatest sum by greedy sum = " << sum << std::endl;
	return sum;
}

/*
 * Uses brute force to find the greatest possible sum.  Works for small data
 * 	sets but not for larger ones as the total possibilities is 2^n
 */
void Triangle::brute_sum()
{
	int max = 0;
	int sum = 0;

	max = brute_sum(sum, 0, 0, max);

	std::cout << "The greatest sum by brute sum = " << max << std::endl;
}


int Triangle::brute_sum(int sum, int row, int i, int max)
{
	sum += nums[row][i];

	//if not on last row, call recursively for next row
	if (row != (int)nums.size()-1) {
		max = brute_sum(sum, row+1, i, max);
		max = brute_sum(sum, row+1, i+1, max);
	}
	if (max < sum) {
		max = sum;
	}
	return max;
}

/*
 * Uses dynamic programming to find greatest possible sum
 */
int Triangle::dynamic_sum()
{
	int sums[nums.size()];

	/*copy last row into sums array */
	for (int i = 0; i < (int)nums.size(); i++) {
		sums[i] = nums[nums.size()-1][i];
	}

	/* work from bottom up, find max at each level*/
	for (int i = nums.size()-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			sums[j] = std::max(sums[j],sums[j+1]) + nums[i-1][j];
		}
		sums[i] = 0;
	}
	return sums[0];
}
