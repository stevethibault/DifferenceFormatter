#ifndef DIRECTORYDIFFERENCE_H
#define DIRECTORYDIFFERENCE_H

#include "Difference.h"

namespace Waters
{
	class DirectoryDifference : public Difference
	{
	public:
		DirectoryDifference() {}
		DirectoryDifference(std::string input_line) : line(input_line) {}
	
		std::string difference() const { return line; }
	protected:
		std::string line{};
	};

};

#endif