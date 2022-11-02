//
//  main.cpp
//  xcode
//
//  Created by Apor Biro on 02.11.2022.
//

#include <iostream>
#include "../../include/creature.h"
#include "../../include/items.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Item item("Kapa");
    cout << item.getName() << endl;
    return 0;
}
