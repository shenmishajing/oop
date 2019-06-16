//
// Created by *** on 2019-06-06.
//

#ifndef PROJECT_BOARD_WINDOW_H
#define PROJECT_BOARD_WINDOW_H

#include <iostream>
#include <fstream>
#include <array>
#include <list>
#include "Graph.h"         // get access to our graphics library facilities
#include "GUI.h"
#include "MyWindow.h"

namespace Graph_lib {

//------------------------------------------------------------------------------

    class board_window : public MyWindow {
    public:
        board_window(Point xy, int w, int h, const string &title);

        pair<bool, pair<Point, Point>> check_win(Point point);

        pair<bool, pair<Point, Point>> check_win(int x, int y);

        friend Point find_position(int x, int y);

        friend Point find_position(Point board_location);

        friend Point find_location(int x, int y);

        friend Point find_location(Point board_position);

        Point next_position(Point board_position);

        // actions invoked by callbacks:
        void undo();

        void restart();

        void quit();

        void open();

        void save();

        void open_file(string);

        void save_file(string);

        int img_handle(int);

    private:

        const static int board_min_x = 40, board_min_y = 60, board_step = 40;

        const static std::array<Point, 4> directions;

        const static string black_win_str, white_win_str;

        enum states {
            init, black, white, compute_black, compute_white, win
        } state;

        enum piece {
            e, b, w
        };

        Menu_bar menu_bar;

        Fl_File_Chooser open_file_chooser, save_file_chooser;

        Image init_img, board_img;

        Button button;

        list<Circle *> pieces;

        std::array<std::array<enum piece, 19>, 19> board;

        Fl_Menu_Item menu[6];

        void clear_shapes();

        // callback functions:
        static void cb_undo(Address, Address);

        static void cb_restart(Address, Address);

        static void cb_quit(Address, Address);

        static void cb_open(Address, Address);

        static void cb_save(Address, Address);

        static void cb_open_file(Fl_File_Chooser *, Address);

        static void cb_save_file(Fl_File_Chooser *, Address);

        static void cb_img_handle(Address, Address);
    };

//------------------------------------------------------------------------------

}


#endif //PROJECT_BOARD_WINDOW_H
