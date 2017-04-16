#ifndef FILEREADER_H
#define FILEREADER_H
#include <vector>
#include <string>


class FileReader
{
    private:
        std::string fileName;

    public:
        FileReader(std::string);
        std::vector<std::string> readInst();

};
#endif
