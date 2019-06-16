//
// Created by *** on 2019-05-24.
//

#include <iostream>
#include "board_window.h"

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------

int main() {
    try {
        board_window win(Point(100, 100), 800, 820, "五子棋");
        return gui_main();
    }
    catch (exception &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        cerr << "Some exception\n";
        return 2;
    }
}

//------------------------------------------------------------------------------