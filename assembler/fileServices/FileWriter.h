#ifndef FILEWRITER_H
#define FILEWRITER_H
#include "FileHandler.h"

class FileWriter: public FileHandler
{
    public:
        /** Default constructor */
        FileWriter();
        void write(std::string path, std::string fileName);
        std::vector<std::string> read(std::string path);
        void throwError();
    protected:

    private:
};

#endif // FILEWRITER_H
