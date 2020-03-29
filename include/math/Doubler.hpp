#ifndef DOUBLER_HPP
#define DOUBLER_HPP

class Doubler {
	private:
		int num;

	public:
		Doubler(const int);
		~Doubler();

		int doubled();
};

#endif