// Copyright 2021 Bulychev Vladislav

#include "include/tree_app.h"
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <limits>
#include <stdlib.h>
#include "include/btree.h"

std::string TreeApp::help(const std::string& filename) const {
    return "This is application for tree class\n"
        "Actions:\n"
        "add <value> - add value to the tree\n"
        "find <value> - find the value in the tree\n";
}

std::string TreeApp::operator()(int argc, const char** argv) {
    if (argc == 1) {
        return help(*argv);
    }
    try {
        if (argc == 2) {
            throw std::runtime_error("ERROR: invalid argument\n\n");
        }
        else {
            int size = argc - 1;
            std::vector<std::string> str;
            for (int i = 0; i < size; i++) {
                std::stringstream convert(argv[i + 1]);
                std::string num;
                if (!(convert >> num)) {
                    throw std::runtime_error("ERROR: " +
                        std::string(argv[i + 1]) + " is invalid argument\n\n");
                }
                str.push_back(num);
            }
            std::ostringstream stream;
            if (str[0] == "add") {
                tnode* t_;
                t_ = nullptr;
                int n = atoi(str[1].c_str());
                t_ = addtree(t_, n);
            }
            else if (str[0] == "find") {
            }
            else {
                throw std::runtime_error("ERROR: " +
                    str[0] + " is invalid argument\n\n");
            }
            return stream.str();
        }

    }
    catch (std::exception& e) {
        return e.what() + help(argv[0]);
    }
}
