#include "SymbolTable.h"
#include <iostream>
using namespace std;

int SymbolTable::hash(const string& s)
{
    int len = s.size();
    int h = 0;
    
    for (int i = 0; i < len; ++i)
    {
        h += s[i] * (i + 1);
    }
    
    h = h % SIZE;
    return h;
}
        
int SymbolTable::insert(SymbolInfo *si)
{
    if (this->lookup(si->symbol_name) != 0)
        return 0;

    int h = hash(si->symbol_name);
    table[h].push_back(si);
    return 1;
}

SymbolInfo* SymbolTable::lookup(const string& symbol)
{
    int h = hash(symbol);
    list<SymbolInfo*>::iterator it;
    for (it = table[h].begin(); it != table[h].end(); it++)
    {
        if ((*it)->symbol_name == symbol)
            return *it;
    }
    return 0;
}

void SymbolTable::dump()
{
    list<SymbolInfo*>::iterator it;

    for (int i = 0; i < SIZE; ++i)
    {
        cout << i << ": ";
        for (it = table[i].begin(); it != table[i].end(); ++it)
        {
           cout << (*it)->symbol_name << ", " << (*it)->symbol_type << '\t';
        }
        cout << endl;
    }
}
