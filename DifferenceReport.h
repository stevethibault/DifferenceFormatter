#ifndef DIFFERENCEREPORT_H
#define DIFFERENCEPARSER_H

#include "stream.h"
#include <iostream>

class DifferenceReport
{
    public:
        DifferenceReport(istream diff_istream);
        virtual ~DifferenceReport();

    protected:
        istream input_stream{};

    private:

};

#endif // DIFFERENCEREPORT_H
