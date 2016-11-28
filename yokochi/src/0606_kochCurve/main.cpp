#include <iostream>
#include <math.h>
#include <stdlib.h>

struct Coodinate {
    double x;
    double y;
    Coodinate* next;
};
Coodinate* initCoodinate()
{
    Coodinate* c = (Coodinate*)malloc(sizeof(Coodinate));
    c->x = -1;
    c->y = -1;
    c->next = c;
    return c;
}

void kochCurve(Coodinate* start, Coodinate* end, int n)
{
    if (n == 0) {
	return;
    }
    Coodinate* s = initCoodinate();
    Coodinate* t = initCoodinate();
    Coodinate* u = initCoodinate();
    start->next = s;
    s->x = (2.0 * start->x + 1.0 * end->x) / 3;
    s->y = (2.0 * start->y + 1.0 * end->y) / 3;
    s->next = t;
    u->x = (1.0 * start->x + 2.0 * end->x) / 3;
    u->y = (1.0 * start->y + 2.0 * end->y) / 3;
    u->next = end;
    double th = M_PI * 60.0 / 180.0;
    t->x = (u->x - s->x) * cos(th) - (u->y - s->y) * sin(th) + s->x;
    t->y = (u->x - s->x) * sin(th) + (u->y - s->y) * cos(th) + s->y;
    t->next = u;
    n--;
    kochCurve(start, s, n);
    kochCurve(s, t, n);
    kochCurve(t, u, n);
    kochCurve(u, end, n);
}
int main()
{
    int n = 0;
    std::cin >> n;
    Coodinate* start = (Coodinate*)malloc(sizeof(Coodinate));
    Coodinate* end = (Coodinate*)malloc(sizeof(Coodinate));
    Coodinate* nil = initCoodinate();

    start->x = 0;
    start->y = 0;
    start->next = end;
    end->x = 100;
    end->y = 0;
    end->next = nil;

    kochCurve(start, end, n);
    Coodinate* i = start;
    while (i->next != i) {
	std::cout << i->x << " " << i->y << std::endl;
	i = i->next;
    }
    return 0;
}
