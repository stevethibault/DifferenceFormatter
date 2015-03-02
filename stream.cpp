#include "stream.h"

namespace diff
{

    std::string getline(std::istream& istm)
    {
        std::string line{};
        auto buffer = std::make_unique<char[]>(512);

        while (!istm.eof() && !istm.bad())
        {
            istm.getline(buffer.get(), 512);
            line.append(buffer.get());
        }

        return line;
    }



}
