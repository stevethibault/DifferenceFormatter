#include "DifferenceReport.h"

DifferenceReport::DifferenceReport(std::istream& diff_istream, std::ostream& report_stream) :
                                        diff_input_stream{diff_istream},
                                        report_output_stream{report_stream}
{
    //ctor
}

DifferenceReport::~DifferenceReport()
{
    //dtor
}


void DifferenceReport::generate()
{

}
