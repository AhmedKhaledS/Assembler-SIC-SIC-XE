#ifndef FILEREADER_H
#define FILEREADER_H
#include <vector>
#include <string>


class FileReader
{
    private:
        std::string fileName;

    public:
        FileReader();
        std::vector<std::string> readInst(std::string);

};
#endif
