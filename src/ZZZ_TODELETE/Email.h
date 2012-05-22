#ifndef __EMAIL_H__
#define __EMAIL_H__

#include <fstream>
#include <streambuf>
#include <string>

struct Email {
    int index;
    std::string filename;
    std::string text;

    Email(const int index, std::string& filename)
        : index(index), filename(filename)
    {}

    bool LoadFromFile()
    {
        std::ifstream t(filename.c_str());
        t.seekg(0, std::ios::end);
        text.reserve(t.tellg());
        t.seekg(0, std::ios::beg);

        text.assign((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
        return true;
    }
};
#endif
