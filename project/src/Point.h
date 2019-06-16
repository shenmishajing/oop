
#ifndef POINT_GUARD
#define POINT_GUARD

//typedef void (*Callback)(void*,void*);

namespace Graph_lib {

    class Point {
    public:
        int x, y;

        Point(int xx, int yy) : x(xx), y(yy) {}

        Point() : x(0), y(0) {}

        bool in_region(int min_x, int min_y, int max_x, int max_y) {
            return x >= min_x && x <= max_x && y >= min_y && y <= max_y;
        }

        void set(int xx, int yy) {
            x = xx;
            y = yy;
        }

        Point operator+(Point d) {
            d.x += x;
            d.y += y;
            return d;
        }

        Point operator-(Point d) {
            d.x = -d.x;
            d.y = -d.y;
            d.x += x;
            d.y += y;
            return d;
        }

        Point &operator+=(Point d) {
            x += d.x;
            y += d.y;
            return *this;
        }

        Point &operator-=(Point d) {
            x -= d.x;
            y -= d.y;
            return *this;
        }

        Point &operator=(Point d) {
            x = d.x;
            y = d.y;
            return *this;
        }
    };

    inline bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }

    inline bool operator!=(Point a, Point b) { return !(a == b); }


}
#endif