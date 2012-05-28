//------------------------------------------------------------------------------
#include <DiskFile.h>

//------------------------------------------------------------------------------

DiskFile::DiskFile(const char* path)
  : filename(path)
{}

//------------------------------------------------------------------------------

DiskFile::~DiskFile()
{
  if(file.is_open()) file.close();
}

//------------------------------------------------------------------------------

bool DiskFile::Open()
{
  file.open(filename.c_str());
  return file.is_open();
}

//------------------------------------------------------------------------------

bool DiskFile::ReadLine(string& line)
{
    return std::getline(file, line);
}
//------------------------------------------------------------------------------

bool DiskFile::eof()
{
    return file.eof();
}

//------------------------------------------------------------------------------

bool DiskFile::Close()
{
  file.close();
  return true;
}

//------------------------------------------------------------------------------
