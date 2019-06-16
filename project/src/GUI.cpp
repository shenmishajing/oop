
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "GUI.h"

namespace Graph_lib {

    //------------------------------------------------------------------------------

    void Button::attach(MyWindow &win) {
        own = &win;
        pw = new MyButton(loc.x, loc.y, width, height, do_it, own);
    }

    //------------------------------------------------------------------------------

    int In_box::get_int() {
        Fl_Input &pi = reference_to<Fl_Input>(pw);
        // return atoi(pi.value());
        const char *p = pi.value();
        if (!isdigit(p[0])) return -999999;
        return atoi(p);
    }

    //------------------------------------------------------------------------------

    void In_box::attach(MyWindow &win) {
        pw = new Fl_Input(loc.x, loc.y, width, height, label.c_str());
        own = &win;
    }

    //------------------------------------------------------------------------------

    void Out_box::put(const string &s) {
        reference_to<Fl_Output>(pw).value(s.c_str());
    }

    //------------------------------------------------------------------------------

    void Out_box::attach(MyWindow &win) {
        pw = new Fl_Output(loc.x, loc.y, width, height, label.c_str());
        own = &win;
    }

    //------------------------------------------------------------------------------

    void Menu_bar::attach(MyWindow &win) {
        Fl_Menu_Bar *o = new Fl_Menu_Bar(loc.x, loc.y, width, height, label.c_str());
        pw = o;
        o->menu(menu);
        pw->callback(reinterpret_cast<Fl_Callback *>(do_it), &win);
        own = &win;
    }

    //------------------------------------------------------------------------------

}; // of namespace Graph_lib