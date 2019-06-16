#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string name;
    int    start;
    int    end;
    Node * next;
};
Node *add(Node *, Node *);
void  display(Node *);
bool  check(Node *head)
{
    if (head == NULL || head->next == NULL) return true;
    Node *p = head->next;
    if (head->start > p->start) return false;
    return check(p);
}
int main()
{
    Node *head = NULL, *p;
    int   i, repeat;
    cin >> repeat;
    for (i = 0; i < repeat; i++)
    {
        p = new Node;
        cin >> p->name >> p->start >> p->end;
        p->next = NULL;
        head    = add(head, p);
    }
    if (!check(head)) cout << "ERROR" << endl;
    display(head);
    return 0;
}

/* 请在这里填写答案 */
Node *add(Node *head, Node *p)
{
    if (!head)
    {
        return p;
    }

    if (p->start < head->start)
    {
        p->next = head;
        return p;
    }

    if (!head->next)
    {
        head->next = p;
        return head;
    }

    Node *l = head, *c = head->next;

    while (c && (p->start > c->start))
    {
        l = c;
        c = c->next;
    }

    l->next = p;
    p->next = c;
    return head;
}

void display(Node *head)
{
    int   cur = 0;
    Node *p   = head;
    while (p)
    {
        if (cur > p->start || (p->next && p->end > p->next->start))
        {
            cout << "*";
        }
        cout << p->name << " " << p->start << " " << p->end << endl;
        cur = cur > p->end ? cur : p->end;
        p   = p->next;
    }
}
