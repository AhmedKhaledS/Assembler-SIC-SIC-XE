#ifndef FILEREADER_H
#define FILEREADER_H
#include "FileHandler.h"
#include <vector>
#include <string>


class FileReader: public FileHandler
{
    private:
        std::string fileName;

    public:
        FileReader();
        void write(std::string path, std::string fileName);
        std::vector<std::string> read(std::string path);
        void throwError();
};
#endif
