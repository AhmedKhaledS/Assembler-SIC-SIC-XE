#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <vector>
#include <string>

class FileHandler
{
    public:
        /** Default constructor */
        FileHandler();
        virtual std::vector<std::string> read(std::string path) = 0;
        virtual void write(std::string path, std::string fileName) = 0;
        virtual void throwError() = 0;
    protected:

    private:
};

#endif // FILEHANDLER_H
