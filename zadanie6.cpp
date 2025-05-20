#include <iostream>
using namespace std;
#include <string.h> 
#include <string>
#include "list.h"

int main()
{
    cout << "\n Spisok \n";
    MyList<MARSH> list;
    for (MARSH x: gr)list.addEnd(x);
    cout << list << "\n";
}