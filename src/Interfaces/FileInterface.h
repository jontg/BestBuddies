#ifndef __FILE_INTERFACE_H__
#define __FILE_INTERFACE_H__
#include <queue>
#include <string>

using namespace std;

class FileInterface {
  public:
    virtual bool Open() = 0;
    virtual bool ReadLine(string& line) = 0;
    virtual bool eof() = 0;
    virtual bool Close() = 0;
};

#endif
