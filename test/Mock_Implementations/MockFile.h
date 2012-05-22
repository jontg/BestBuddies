#ifndef __FILE_IO_H__
#define __FILE_IO_H__
#include <queue>
#include <string>

#include <Interfaces/FileInterface.h>

using namespace std;

class MockFile : public FileInterface {
    queue<bool> Open_response_queue;
    queue<pair<string, bool> > Read_response_queue;
    queue<bool> Close_response_queue;
  public:
    MockFile() {}
    ~MockFile() {}

    bool Open();
    bool ReadLine(string& line);
    bool eof();
    bool Close();

    void AssignOpenResponse(bool);
    void AssignReadLineResponse(bool, const string&);
    void AssignCloseResponse(bool);
};

#endif
