#include "cpp-common/helper_functions.h"

#include <fstream>

bool readFile(const char* filename, char* data, size_t& size, bool binary)
{
	std::ifstream fin(filename, binary ? std::ios::binary : 1);
    if (!fin.is_open())
        return false;

    bool retVal;
    if (data) {
        retVal = (bool)fin.read(data, size);
    }
    else {
        fin.ignore(std::numeric_limits<std::streamsize>::max());
        retVal = true;
    }

    size = fin.gcount();
    fin.close();
    return true;
}
