#ifndef DIFFERENCESET_H
#define DIFFERENCESET_H

#include "Difference.h"
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

		Difference& leftDifference();
        Difference& rigthDifference();

        void addDifference(const std::string& line);

    private:
        Difference left_difference{};
        Difference right_difference{};
        int left_lines{};
        int right_lines{};

		void BalanceWithBlankLines(Difference &difference, int imballance);
};

};

#endif // DIFFERENCESET_H
