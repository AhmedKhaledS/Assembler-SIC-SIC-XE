#include "MemoryObjectCodeGenerator.h"
#include "D:\Collage\Assembler Project\Assembler-SIC-SIC-XE-\assembler\OperationCodeTable.h"
#include "D:\Collage\Assembler Project\Assembler-SIC-SIC-XE-\assembler\SymbolTable.h"

#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <map>

using namespace std;

MemoryObjectCodeGenerator::MemoryObjectCodeGenerator(string inst,string oper)
{
    instruction = inst;
    operand = oper;
}

string MemoryObjectCodeGenerator::parse(){

    // Grabbing object code in Binary...
    string binaryObjectCode;
    OperationCodeTable t;                           // Operation Code Table part TO BE MODIFIED
    t.load();
    binaryObjectCode = t.getCode(instruction);

    // Converting object code to Hexadecimal
    bitset<8> set(binaryObjectCode);
    stringstream hexaObjectCode;
    hexaObjectCode << hex << uppercase << set.to_ulong();

    string objectCode = hexaObjectCode.str();

    if(objectCode.size() != 2){
        objectCode = "0" + objectCode;
    }

    // Check Mode of addressing
    static int nPos = -1;
    if(operand.find(",X") != nPos){
        operand.replace(operand.find(",X"), 2, "");
        cout << "INDEXING" << endl;
        cout << operand << endl;
    }else{
        cout << "NO INDEXING" << endl;
        cout << operand << endl;
    }

    SymbolTable s;
    s.add("XXXX","7FFF");
    string labelCode = s.getAddress(operand);
    while(labelCode.size()!=4){
        labelCode = "0" + labelCode;
    }
    cout << labelCode << endl;

    unsigned int x;
    stringstream ss;
    ss << std::hex << "7fff";
    ss >> x;
    cout << "HELLO " << x << endl;
    x += 32768;

    stringstream stream;
    stream << hex  << uppercase << x;
    string output( stream.str() );
    cout << "output " << output << endl;



    return objectCode;
 }
