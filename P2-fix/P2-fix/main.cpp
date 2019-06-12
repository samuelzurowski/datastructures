//
//  main.cpp
//  P2
//
//  Created by Samuel Zurowski on 4/6/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//
#include "controller/Runner.hpp"

int main(int argc, const char * argv[]) {
    Runner runner;
    runner.banner();
    runner.prompt();
    runner.startMatch();
    return 0;
}
