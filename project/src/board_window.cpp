//
// Created by *** on 2019-06-06.
//

#include "board_window.h"

namespace Graph_lib {

//------------------------------------------------------------------------------

    const std::array<Point, 4> board_window::directions = {Point(0, -1),
                                                           Point(1, -1),
                                                           Point(1, 0),
                                                           Point(1, 1)
    };

    const string board_window::black_win_str = "black win!";

    const string board_window::white_win_str = "white win!";

//------------------------------------------------------------------------------

    Point find_position(int x, int y) {
        const int max = 19 * 40;
        x += board_window::board_step / 2 - board_window::board_min_x;
        y += board_window::board_step / 2 - board_window::board_min_y;

        Point res(x, y);

        if (!res.in_region(0, 0, max, max)) {
            res.x = -1;
            res.y = -1;
        } else {
            res.set(x / board_window::board_step, y / board_window::board_step);
        }

        return res;
    }

//------------------------------------------------------------------------------

    Point find_position(Point board_location) {
        return find_position(board_location.x, board_location.y);
    }

//------------------------------------------------------------------------------

    Point find_location(Point board_position) {
        Point res(-1, -1);
        if (board_position.in_region(0, 0, 18, 18)) {
            res.x = board_window::board_min_x + board_window::board_step * board_position.x;
            res.y = board_window::board_min_y + board_window::board_step * board_position.y;
        }
        return res;
    }

//------------------------------------------------------------------------------

    Point find_location(int x, int y) {
        return find_location(Point(x, y));
    }

//------------------------------------------------------------------------------

    pair<bool, pair<Point, Point>> board_window::check_win(Point point) {
        Point current, next, first_point, second_point;
        for (size_t i = 0; i < 4; i++) {
            first_point = second_point = current = point;
            int count = 1;

            next = current + directions[i];
            while (count < 5 && next.in_region(0, 0, 18, 18)
                   && board[next.x][next.y] == board[current.x][current.y]) {
                first_point = next;
                next += directions[i];
                count++;
            }

            next = current - directions[i];
            while (count < 5 && next.in_region(0, 0, 18, 18)
                   && board[next.x][next.y] == board[current.x][current.y]) {
                second_point = next;
                next -= directions[i];
                count++;
            }
            if (count >= 5)
                return pair<bool, pair<Point, Point>>(true, pair<Point, Point>(first_point, second_point));
        }
        return pair<bool, pair<Point, Point>>(false, pair<Point, Point>(Point(-1, -1), Point(-1, -1)));
    }

//------------------------------------------------------------------------------

    pair<bool, pair<Point, Point>> board_window::check_win(int x, int y) {
        return check_win(Point(x, y));
    }

//------------------------------------------------------------------------------

    Point board_window::next_position(Point board_position = Point(0, 0)) {
        int max = 0, count, flag;
        Point tmp, current, first, second;
        for (size_t i = 0; i < 4; i++) {
            current = board_position;
            first = current + directions[i];
            second = current - directions[i];
            count = 1;
            flag = 0;
            while (first.in_region(0, 0, 18, 18) && board[first.x][first.y] == board[current.x][current.y]) {
                first += directions[i];
                count++;
            }
            if (first.in_region(0, 0, 18, 18) && board[first.x][first.y] == e) {
                flag = 1;
            }
            while (second.in_region(0, 0, 18, 18) && board[second.x][second.y] == board[current.x][current.y]) {
                second += directions[i];
                count++;
            }
            if (second.in_region(0, 0, 18, 18) && board[second.x][second.y] == e) {
                flag = 2;
            }
            if (flag && count > max) {
                max = count;
                tmp = flag == 1 ? first : second;
            }
        }
        return tmp;
    }

//------------------------------------------------------------------------------

    board_window::board_window(Point xy, int w, int h, const string &title)
            : MyWindow(xy, w, h, title),
              init_img(Point(0, 20), "../img/init.jpg", Suffix::jpg),
              board_img(Point(0, 20), "../img/board.jpg", Suffix::jpg),
              menu_bar(Point(0, 0), 800, 20, menu),
              open_file_chooser("../data", "TXT Files (*.txt)", Fl_File_Chooser::SINGLE, "打开棋盘文件"),
              save_file_chooser("../data", "TXT Files (*.txt)", Fl_File_Chooser::CREATE, "保存棋盘文件"),
              button(Point(0, 20), 800, 800, "", cb_img_handle),
              state(init) {
        menu[0] = {"打开(&o)", FL_CTRL + 'o', (Fl_Callback *) cb_open, this, 0};
        menu[1] = {"保存(&s)", FL_CTRL + 's', (Fl_Callback *) cb_save, this, 0};
        menu[2] = {"悔棋(&u)", FL_CTRL + 'u', (Fl_Callback *) cb_undo, this, 0};
        menu[3] = {"重开(&r)", FL_CTRL + 'r', (Fl_Callback *) cb_restart, this, 0};
        menu[4] = {"退出(&q)", FL_CTRL + 'q', (Fl_Callback *) cb_quit, this, 0};
        menu[5] = {0, 0, 0, 0, 0};
        open_file_chooser.callback(cb_open_file, this);
        save_file_chooser.callback(cb_save_file, this);
        clear_shapes();
        attach(menu_bar);
        attach(init_img);
        attach(button);
    }

//------------------------------------------------------------------------------

    void board_window::clear_shapes() {
        for (int i = 0; i < shapes.size(); ++i) {
            if (shapes[i] != &init_img && shapes[i] != &board_img) {
                delete shapes[i];
            }
        }
        MyWindow::clear_shapes();
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                board[i][j] = e;
            }
        }
        pieces.clear();
    }

//------------------------------------------------------------------------------

    void board_window::cb_undo(Address, Address pw) {
        reference_to<board_window>(pw).undo();
    }

//------------------------------------------------------------------------------

    void board_window::undo() {
        if ((state == black || state == white) && shapes[shapes.size() - 1] != &init_img &&
            shapes[shapes.size() - 1] != &board_img) {
            Circle *board_position = (Circle *) shapes[shapes.size() - 1];
            Point location = board_position->center();
            Point position = find_position(location);
            if (board[position.x][position.y] == b) {
                state = black;
            } else {
                state = white;
            }
            board[position.x][position.y] = e;
            detach(*shapes[shapes.size() - 1]);
            delete board_position;
            pieces.pop_back();
            redraw();
        }
    }

//------------------------------------------------------------------------------

    void board_window::cb_restart(Address, Address pw) {
        reference_to<board_window>(pw).restart();
    }

//------------------------------------------------------------------------------

    void board_window::restart() {
        clear_shapes();
        attach(init_img);
        state = init;
        redraw();
    }

//------------------------------------------------------------------------------

    void board_window::cb_quit(Address, Address pw) {
        reference_to<board_window>(pw).quit();
    }

//------------------------------------------------------------------------------

    void board_window::quit() {
        exit(0);
    }

//------------------------------------------------------------------------------

    void board_window::cb_open(Address, Address pw) {
        reference_to<board_window>(pw).open();
    }

//------------------------------------------------------------------------------

    void board_window::open() {
        open_file_chooser.show();
    }

//------------------------------------------------------------------------------

    void board_window::cb_save(Address, Address pw) {
        reference_to<board_window>(pw).save();
    }

//------------------------------------------------------------------------------

    void board_window::save() {
        save_file_chooser.show();
    }

//------------------------------------------------------------------------------

    void board_window::open_file(string str) {
        clear_shapes();
        attach(board_img);
        ifstream file(str);
        int temp_state, count, x, y;
        Color col = Color::black;
        piece pie = b;
        file >> temp_state >> count;
        state = (enum states) temp_state;
        for (int i = 0; i < count; ++i) {
            file >> x >> y;
            Point position(x, y);
            Point location = find_location(position);
            Circle *pcir = new Circle(location, 10);
            board[position.x][position.y] = pie;
            pcir->set_color(col);
            pcir->set_fill_color(col);
            attach(*pcir);
            if (pie == b) {
                col = Color::white;
                pie = w;
            } else {
                col = Color::black;
                pie = b;
            }
        }
        file.close();
        redraw();
    }

//------------------------------------------------------------------------------

    void board_window::save_file(string str) {
        if (state == black || state == white) {
            ofstream file(str);
            file << state << endl;
            int count = 0;
            for (int i = 0; i < shapes.size(); ++i) {
                if (shapes[i] != &init_img && shapes[i] != &board_img) {
                    count++;
                }
            }
            file << count << endl;
            for (int i = 0; i < shapes.size(); ++i) {
                if (shapes[i] != &init_img && shapes[i] != &board_img) {
                    Circle *board_position = (Circle *) shapes[i];
                    Point location = board_position->center();
                    Point position = find_position(location);
                    file << position.x << " " << position.y << endl;
                }
            }
            file.close();
        }
    }

//------------------------------------------------------------------------------

    void board_window::cb_open_file(Fl_File_Chooser *pw, Address win) {
        string str(pw->value());
        if (str[str.size() - 1] == 't' && str[str.size() - 2] == 'x' && str[str.size() - 3] == 't' &&
            str[str.size() - 4] == '.') {
            pw->hide();
            reference_to<board_window>(win).open_file(str);
        }
    }

//------------------------------------------------------------------------------

    void board_window::cb_save_file(Fl_File_Chooser *pw, Address win) {
        string str(pw->value());
        if (str[str.size() - 1] == 't' && str[str.size() - 2] == 'x' && str[str.size() - 3] == 't' &&
            str[str.size() - 4] == '.') {
            pw->hide();
            reference_to<board_window>(win).save_file(str);
        }
    }

//------------------------------------------------------------------------------

    void board_window::cb_img_handle(Address event, Address win) {
        *(int *) event = reference_to<board_window>(win).img_handle(*(int *) event);
    }

//------------------------------------------------------------------------------

    int board_window::img_handle(int event) {
        int button, x, y, retval = 0;
        button = Fl::event_button();

        Color col = Color::black;
        piece pie = b;
        string str = black_win_str;
        states next_state = white;

        pair<bool, pair<Point, Point>> res;

        Point mouse_location, board_location, board_position;

        switch (button) {
            case 1: // left button
                switch (event) {
                    case FL_PUSH:
                        x = Fl::event_x();
                        y = Fl::event_y();
                        mouse_location.set(x, y);
                        switch (state) {
                            case init:
                                if (mouse_location.in_region(200, 420, 600, 520) ||
                                    mouse_location.in_region(200, 570, 600, 670)) {
                                    clear_shapes();
                                    attach(board_img);
                                    redraw();
                                    if (mouse_location.in_region(200, 420, 600, 520)) { // compute
                                        state = compute_black;
                                    } else { // player
                                        state = black;
                                    }
                                    retval = 1;
                                }
                                break;
                            case black:
                            case white:
                            case compute_black:
                                board_position = find_position(x, y);
                                if (board_position != Point(-1, -1) && board[board_position.x][board_position.y] == e) {
                                    board_location = find_location(board_position);
                                    Circle *pcir = new Circle(board_location, 10);
                                    if (state == white) {
                                        col = Color::white;
                                        pie = w;
                                        str = white_win_str;
                                        next_state = black;
                                    }
                                    board[board_position.x][board_position.y] = pie;
                                    pcir->set_color(col);
                                    pcir->set_fill_color(col);
                                    attach(*pcir);
                                    res = check_win(board_position);
                                    if (res.first) {
                                        Text *ptext = new Text(Point(200, 200), str);
                                        ptext->set_color(col);
                                        ptext->set_font_size(100);
                                        Line *pline = new Line(find_location(res.second.first),
                                                               find_location(res.second.second));
                                        pline->set_color(Color::red);
                                        attach(*pline);
                                        attach(*ptext);
                                        state = win;
                                    } else {
                                        if (state == compute_black) {
                                            board_position = next_position(board_position);
                                            board_location = find_location(board_position);
                                            Circle *pcir = new Circle(board_location, 10);
                                            board[board_position.x][board_position.y] = w;
                                            pcir->set_color(Color::white);
                                            pcir->set_fill_color(Color::white);
                                            attach(*pcir);
                                            res = check_win(board_position);
                                            if (res.first) {
                                                Text *ptext = new Text(Point(200, 200), white_win_str);
                                                ptext->set_color(Color::white);
                                                ptext->set_font_size(100);
                                                Line *pline = new Line(find_location(res.second.first),
                                                                       find_location(res.second.second));
                                                pline->set_color(Color::red);
                                                attach(*pline);
                                                attach(*ptext);
                                                state = win;
                                            }
                                        } else {
                                            state = next_state;
                                        }
                                        pieces.push_back(pcir);
                                    }
                                    redraw();
                                    retval = 1;
                                }
                                break;
                            case win:
                                if (mouse_location.in_region(0, 20, 800, 820)) {
                                    restart();
                                    retval = 1;
                                }
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 2: // middle button
            case 3: // right button
            default:
                break;
        }
        return retval;
    }

//------------------------------------------------------------------------------

}