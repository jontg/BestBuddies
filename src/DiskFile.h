#ifndef __DISK_FILE_H__
#define __DISK_FILE_H__

#include <Interfaces/FileInterface.h>

using namespace std;

class DiskFile : public FileInterface {
  public:
    DiskFile(const char* path, const char* mode);
    virtual ~DiskFile();

    bool Open();
    bool ReadLine(string& line);
    bool eof();
    bool Close();
};

#endif
