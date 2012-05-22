#include <cassert>
#include <Mock_Implementations/MockFile.h>

//------------------------------------------------------------------------------

bool MockFile::Open()
{
    assert(!Open_response_queue.empty());
    bool response=Open_response_queue.front();
    Open_response_queue.pop();
    return response;
}

//------------------------------------------------------------------------------

bool MockFile::ReadLine(string& line)
{
    assert(!Read_response_queue.empty());
    pair<string,bool> response(Read_response_queue.front());
    Read_response_queue.pop();
    line=response.first;
    return response.second;
}

//------------------------------------------------------------------------------

bool MockFile::eof()
{
    return Read_response_queue.empty();
}
//------------------------------------------------------------------------------

bool MockFile::Close()
{
    assert(!Close_response_queue.empty());
    bool response=Close_response_queue.front();
    Close_response_queue.pop();
    return response;
}

//------------------------------------------------------------------------------

void MockFile::AssignOpenResponse(bool response)
{
    Open_response_queue.push(response);
}

//------------------------------------------------------------------------------

void MockFile::AssignReadLineResponse(bool response, const string& response_line)
{
    Read_response_queue.push(pair<string,bool>(response_line, response));
}

//------------------------------------------------------------------------------

void MockFile::AssignCloseResponse(bool response)
{
    Close_response_queue.push(response);
}

//------------------------------------------------------------------------------
