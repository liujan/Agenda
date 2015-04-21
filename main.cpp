//
//  main.cpp
//  Agenda
//
//  Created by 刘建安 on 4/20/15.
//  Copyright (c) 2015 刘建安. All rights reserved.
//

#include <iostream>
#include "AgendaController.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    AgendaController controller = AgendaController();
    controller.getOperation();
    return 0;
}
