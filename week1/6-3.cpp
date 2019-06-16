#include <iostream>
#include <string>
using namespace std;
struct Dog
{
    string no;
    int    age;
    Dog *  next;
};
Dog *head = NULL;
void del(Dog *p)
{
    if (p != NULL)
    {
        del(p->next);
        delete p;
    }
}
void display(Dog *p)
{
    if (p != NULL)
    {
        cout << p->no << ' ' << p->age << endl;
        display(p->next);
    }
}

Dog *clear();
Dog *insert(string &no, int age);

int main()
{
    int    task, age;
    string no;
    cin >> task;
    while (task > 0)
    {
        switch (task)
        {
            case 1:
                cin >> no >> age;
                head = insert(no, age);
                display(head);
                break;
            case 2:
                head = clear();
                display(head);
                break;
        }
        cin >> task;
    }
    del(head);
    return 0;
}

/* 请在这里填写答案 */
Dog *insert(string &no, int age)    //加入一只狗的信息
{
    Dog *p  = new Dog;
    p->no   = no;
    p->age  = age;
    p->next = 0;
    if (!head)
    {
        return p;
    }

    if (p->age <= head->age)
    {
        p->next = head;
        return p;
    }
    Dog *l = head, *c = head->next;

    while (c && (p->age > c->age))
    {
        l = c;
        c = c->next;
    }

    l->next = p;
    p->next = c;
    return head;
}
Dog *clear()    //清理档案
{
    Dog *cur = head;
    while (cur)
    {
        Dog *c = head, *l = 0;
        while (c != cur)
        {
            if (c->no == cur->no)
            {
                if (l)
                {
                    l->next = c->next;
                    delete c;
                    c = l->next;
                }
                else
                {
                    c = c->next;
                    delete head;
                    head = c;
                }
            }
            else
            {
                l = c;
                c = c->next;
            }
        }

        cur = cur->next;
    }
    return head;
}
