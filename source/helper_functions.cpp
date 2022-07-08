/*
 * Copyright (C) 2022 Konstanty Misiak
 *
 * SPDX-License-Identifier: MIT
 */

#include "ccl/helper_functions.h"

#include <fstream>

namespace ccl {

    bool readFile(const char* filename, char* data, size_t& size, bool binary)
    {
        std::ifstream fin(filename, binary ? std::ios::binary : std::ios::in);
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

    bool writeFile(const char* filename, const char* data, size_t size, bool binary)
    {
        std::ofstream fout(filename, binary ? std::ios::binary : std::ios::out);
        if (!fout.is_open())
            return false;

        bool retVal = (bool)fout.write(data, size);

        fout.close();
        return retVal;
    }

    std::string wstringToString(const std::wstring& wideString)
    {
        std::string temp(wideString.length(), ' ');
        std::copy(wideString.begin(), wideString.end(), temp.begin());
        return temp;
    }

    std::wstring stringToWstring(const std::string& string)
    {
        std::wstring temp(string.length(), L' ');
        std::copy(string.begin(), string.end(), temp.begin());
        return temp;
    }

} // namespace ccl
