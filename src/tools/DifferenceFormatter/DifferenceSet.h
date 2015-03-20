#ifndef DIFFERENCESET_H
#define DIFFERENCESET_H

#include "DifferenceChunk.h"
#include "utilities.h"
#include <string>

namespace Waters
{

class DifferenceSet
{
    public:
        DifferenceSet() {}
        DifferenceSet(const std::string& line_numbers);
		DifferenceSet(DifferenceSet &&diffSet) : left_difference(std::move(diffSet.left_difference)), right_difference(std::move(diffSet.right_difference)) {}


		DifferenceSet& operator=(DifferenceSet&& diffSet)
		{
			left_difference = std::move(diffSet.left_difference);
			right_difference = std::move(diffSet.right_difference);
			return *this;
		}

		const DifferenceChunk& leftDifference() const;
		const DifferenceChunk& rightDifference() const;
		const std::string& lineNumbers() const;
        void addDifference(const std::string& line);

    private:
		DifferenceChunk left_difference{};
		DifferenceChunk right_difference{};
        int left_lines{};
        int right_lines{};
		std::string line_numbers{};

		void BalanceWithBlankLines(DifferenceChunk &difference, int imballance);
};

};

#endif // DIFFERENCESET_H
