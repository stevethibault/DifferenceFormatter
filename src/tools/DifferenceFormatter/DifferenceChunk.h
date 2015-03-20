#ifndef DIFFERENCECHUNK_H
#define DIFFERENCECHUNK_H

#include "utilities.h"
#include "Line.h"
#include "CodeLine.h"
#include <string>
#include <vector>
#include <memory>

namespace Waters
{

	class DifferenceChunk
	{
		public:
			DifferenceChunk() {}
			DifferenceChunk(const std::string& line_range);
			~DifferenceChunk() {}

			int startLine() const;
			int lineCount() const;

			void addLine(const std::string& lineText, const Line::LineType lineType);
			const std::vector<Line> getLines() const;

		private:
			int start_line{};
			int line_count{};
			int current_line_number{};
			std::vector<Line> lines{};
	};

};

#endif // DIFFERENCECHUNK_H
