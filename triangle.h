/*
 * triangle.h
 *
 *  Created on: Jul 12, 2016
 *      Author: raina.galbiati
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>
#include <vector>

class Triangle {
public:
	std::vector<std::vector<int> >nums;
	void print_tri();
	int greedy_sum();
	void brute_sum();
	int brute_sum(int sum, int row, int index, int max);
	int dynamic_sum();
};

#endif /* TRIANGLE_H_ */
