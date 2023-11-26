#include "stream.hpp"

FileSystem::FileSystem(const std::string &fname)
{
    srcFile.open(fname);
    std::string newFile = fname + ".replace";
    std::cout << fname << std::endl;
    destFile.open(newFile);
    if (!srcFile.is_open() || !destFile.is_open())
        std::cerr << "File cannot be opened" << std::endl;
}

FileSystem::~FileSystem()
{
    if (srcFile.is_open())
        srcFile.close();
    if (destFile.is_open())
        destFile.close();
}

std::ifstream &FileSystem::getSrc()
{
    return (srcFile);
}

std::ofstream &FileSystem::getDest()
{
    return (destFile);
}
