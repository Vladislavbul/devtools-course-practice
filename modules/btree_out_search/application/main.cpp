// Copyright 2021 Bulychev Vladislav

#include <iostream>
#include <string>
#include "include/tree_app.h"

int main(int argc, const char* argv[]) {
    TreeApp app;
    std::cout << app(argc, argv) << std::endl;
    return 0;
}
