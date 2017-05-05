#ifndef OBJECTCODECONTAINER_H
#define OBJECTCODECONTAINER_H
#include <vector>
#include <string>

class ObjectCodeContainer
{
    public:
        static std::vector<std::string> objectCodes;
        static void addObjectCode(std::string objectCode);
        static std::string getObjectCodeAt(int index);
        static int getObjectCodeContainerSize();
};

#endif // OBJECTCODECONTAINER_H
