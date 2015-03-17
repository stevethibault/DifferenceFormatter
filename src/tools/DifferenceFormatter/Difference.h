#ifndef DIFFERENCE_H
#define DIFFERENCE_H

#include <string>

namespace Waters
{

	class Difference
	{
	public:
		Difference() {}
		Difference(std::string line) : line(line) {}
		virtual ~Difference();

	protected:
		std::string line;
	};

};

#endif //DIFFERENCE_H