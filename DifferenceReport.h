#ifndef DIFFERENCEREPORT_H
#define DIFFERENCEPARSER_H

#include "stream.h"
#include "FileDifference.h"
#include <iostream>

namespace Waters
{

class DifferenceReport
{
    public:
        DifferenceReport(std::istream& diff_istream, std::ostream& output_stream);
        virtual ~DifferenceReport();

        void generate();

    protected:
        std::istream& diff_input_stream;
        std::ostream& report_output_stream;

    private:

};

};
#endif // DIFFERENCEREPORT_H
