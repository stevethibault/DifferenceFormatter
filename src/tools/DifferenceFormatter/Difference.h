#ifndef DIFFERENCE_H
#define DIFFERENCE_H

#include "utilities.h"
#include "Line.h"
#include "CodeLine.h"
#include <string>
#include <vector>
#include <memory>

namespace Waters
{

	class Difference
	{
		public:
			Difference(){}
			Difference(const std::string& line_range);
			~Difference(){}

			void addLine(const std::string& lineText, const Line::LineType lineType);

		private:
			int start_line{};
			int line_count{};
			int current_line_number{};
			std::vector<Line> lines{};
	};

};

#endif // DIFFERENCE_H
