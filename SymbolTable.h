#include <string>
#include <list>
#include "SymbolInfo.h"

#define SIZE 20

class SymbolTable
{
public:
    std::list<SymbolInfo*> table[SIZE];
    int insert(SymbolInfo *si);
    SymbolInfo* lookup(const std::string& symbol);
    void dump();
    int hash(const std::string& s);
};
