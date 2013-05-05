#include <iostream>
#include <string>
#include "SymbolTable.h"
using namespace std;

int prompt();

int main()
{
    string name, type;
    SymbolTable st;
    SymbolInfo *si;

    int p;
    while ((p = prompt()) != 4)
    {
        switch(p)
        {
            case 1:
                cin >> name >> type;
                name.resize(name.size() - 1); // ignore the comma(,)
                si = new SymbolInfo(name, type);
                if (!st.insert(si))
                    cout << "Symbol already exists.\n";
                break;
            case 2:
                cin >> name;
                si= st.lookup(name);
                if (si == 0)
                    cout << "Symbol not found.\n";
                else
                    cout << "Symbol Name: " << si->symbol_name << ", Symbol type: "
                        << si->symbol_type << endl;
                cout << endl;
                break;
            case 3:
                cout << "\nSymbol Table:\n";
                st.dump();
                cout << endl;
                break;
            default:
                cout << "Please enter a valid option\n";
                break;
        }
    }
    return 0;
}

int prompt()
{
    int p;
    
    cout << "\nSelect an option:\n";
    cout << "1. Insert\n";
    cout << "2. Lookup\n";
    cout << "3. Dump\n";
    cout << "4. Quit\n";

    cin >> p;
    return p;
}
