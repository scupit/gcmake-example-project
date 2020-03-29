#ifndef DOUBLER_HPP
#define DOUBLER_HPP

#include "matrices/Matrix.hpp"

class Doubler {
	private:
		int num;

	public:
		Doubler(const int);
		~Doubler();

		int doubled();
		Matrix<int> asMatrix(const size_t, const size_t);
};

#endif