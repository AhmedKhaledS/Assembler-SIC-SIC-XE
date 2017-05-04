#include "TablesLoader.h"
#include "../tables/InstructionTypeTable.h"
#include "../tables/OperationCodeTable.h"

void TablesLoader::loadTables() {
    InstructionTypeTable::load();
    OperationCodeTable::load();
}
