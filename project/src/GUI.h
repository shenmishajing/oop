
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef GUI_GUARD
#define GUI_GUARD

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_File_Chooser.H>
#include <iostream>

#include "MyWindow.h"
#include "Graph.h"

namespace Graph_lib {

//------------------------------------------------------------------------------

    typedef void *Address;    // Address is a synonym for void*
    typedef void(*Callback)(Address, Address);    // FLTK's required function type for all callbacks

//------------------------------------------------------------------------------

    template<class W>
    W &reference_to(Address pw)
    // treat an address as a reference to a W
    {
        return *static_cast<W *>(pw);
    }

//------------------------------------------------------------------------------

    class MyButton : public Fl_Button {
        Callback cb;
        Address own;
    public:
        MyButton(int x, int y, int w, int h, Callback cb, Address own)
                : Fl_Button(x, y, w, h, 0), cb(cb), own(own) {}

        int handle(int e) {
            cb(&e, own);
            return e;
        }

    };

//------------------------------------------------------------------------------

    class Widget {
        // Widget is a handle to an Fl_widget - it is *not* an Fl_widget
        // We try to keep our interface classes at arm's length from FLTK
    public:
        Widget(Point xy, int w, int h, const string &s, Callback cb)
                : loc(xy), width(w), height(h), label(s), do_it(cb) {}

        virtual void move(int dx, int dy) {
            hide();
            pw->position(loc.x += dx, loc.y += dy);
            show();
        }

        virtual void hide() { pw->hide(); }

        virtual void show() { pw->show(); }

        virtual void attach(MyWindow &) = 0;

        Point loc;
        int width;
        int height;
        string label;
        Callback do_it;

        virtual ~Widget() {}

        //protected:
        MyWindow *own;    // every Widget belongs to a MyWindow
        Fl_Widget *pw;  // connection to the FLTK Widget
    private:
        Widget &operator=(const Widget &); // don't copy Widgets
        Widget(const Widget &);
    };

//------------------------------------------------------------------------------

    struct Button : Widget {
        Button(Point xy, int w, int h, const string &label, Callback cb)
                : Widget(xy, w, h, label, cb) {}

        void attach(MyWindow &);
    };

//------------------------------------------------------------------------------

    struct In_box : Widget {
        In_box(Point xy, int w, int h, const string &s)
                : Widget(xy, w, h, s, 0) {}

        int get_int();

        string get_string();

        void attach(MyWindow &win);
    };

//------------------------------------------------------------------------------

    struct Out_box : Widget {
        Out_box(Point xy, int w, int h, const string &s)
                : Widget(xy, w, h, s, 0) {}

        void put(int);

        void put(const string &);

        void attach(MyWindow &win);
    };

//------------------------------------------------------------------------------

    class Menu_bar : public Widget {  // a empty pane use to get mouse event
        Fl_Menu_Item *menu;
    public:
        Menu_bar(Point xy, int w, int h, Fl_Menu_Item *menu)
                : Widget(xy, w, h, "", 0), menu(menu) {}

        void attach(MyWindow &);
    };

//------------------------------------------------------------------------------

} // of namespace Graph_lib

#endif // GUI_GUARD
