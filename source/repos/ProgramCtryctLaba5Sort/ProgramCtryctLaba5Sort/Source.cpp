#include <iostream>
#include <cstdlib>
#include <malloc.h>
using namespace std;

struct node {
    node* next;
    int    val;
};

class slist {
private:
    node* lst;
    size_t cnt;
public:
    slist(void);
    ~slist();

    bool add(int val);
    void clear(void);
    void isort(void);
    void bsort(void);
    void ssort(void);

    size_t size(void)  const { 
        return cnt; 
    }
    bool empty(void) const { 
        return (lst == NULL); 
    }
    node* begin(void) const { 
        return lst; 
    }
    node* begin(void) { 
        return lst; 
    }
};
void slist_print(std::ostream& _out, const slist& lst);


void menu(slist&l1, slist& l2, slist& l3) {
    printf("Какую сортировку вы хотите выбрать?\n");
    printf("1.Пузырьком\n");
    printf("2.Выбором\n");
    printf("3.Вставками\n");
    int a;
    scanf_s("%d", &a);

    while (true)
    {
        if (a == 1) {
            l1.bsort();
            slist_print(std::cout, l1);
            menu(l1, l2, l3);
        }
        else if (a == 2) {
            l2.ssort();
            slist_print(std::cout, l2);
            menu(l1, l2, l3);
        }
        else if (a == 3) {
            l3.isort();
            slist_print(std::cout, l3);
            menu(l1, l2, l3);
        }
        else {
            printf("Ввели неверную цифру:\n");
            scanf_s("%d", &a);
        }
    }
}

int main(void) {
    int   n;
    slist l1, l2, l3;
    for (int i = 0; i < 6; ++i) {
        n = rand() % 10;
        l1.add(n);
        l2.add(n);
        l3.add(n);
    }
    slist_print(std::cout, l1);

    

    setlocale(LC_ALL, "rus");
    menu(l1, l2, l3);
    return 0;
}


slist::slist(void) :lst(NULL), cnt(0) {}
slist::~slist() {
    clear();
}

//Сортировка вставками
void slist::isort(void) {
    node* a, * b, * p, * h = NULL;

    for (node* i = lst; i != NULL; ) {
        a = i;
        i = i->next;//второй элемент
        b = h;
        for (p = NULL; (b != NULL) && (a->val > b->val); ) {
            p = b;
            b = b->next;
        }

        if (p == NULL) {
            a->next = h;
            h = a;
        }
        else {
            a->next = b;
            p->next = a;
        }
    }
    if (h != NULL)
        lst = h;
}

//Пузырьковая сортировка//все робит
void slist::bsort(void) {
    node* t, * m, * a, * b;
    if (lst == NULL)
        return;

    for (bool go = true; go; ) {
        go = false;
        a = t = lst;//первый элемент
        b = lst->next;//второй
        int count = 1;
        while (b != NULL) {
            if (a->val > b->val) {
                if (t == a) {
                    lst = b;
                }
                else {//в левый запишем правый
                    t->next = b;

                }

                a->next = b->next;

                b->next = a;

                m = a, a = b, b = m;
                go = true;

            }
            t = a;
            cout << t->val<< ' ';
            a = a->next;
            b = b->next;
            if (count % 5 == 0) {
                cout << a->val<<' ';
                cout << '\n';
            }
            count++;
        }
    }
}
//Сортировка выбором
void slist::ssort(void) {
    node* a, * b;
    node* p1, * p2, * r1, * r2;

    for (p1 = r1 = lst; p1 != NULL; p1 = p1->next) {
        a = p2 = r2 = p1;
        for (b = p1->next; b != NULL; b = b->next) {
            if (p2->val >b->val ) {//p2 левый //b правый,min
                r2 = a;//будет хранить все кроме 1 элемента,чтобы потом закидывать его из p2 в r2
                p2 = b;//min
            }
            a = b;
        }
        int count = 1;
        if (p1 != p2) {
            if (p1 == lst)
                lst = p2;//закидываем первое значение
            else
                r1->next = p2;

            b = p2->next;
            if (p1 == r2) {
                p2->next = p1;
                p1->next = b;
            }
            else {
                a = p1->next;
                r1->next = p2;
                r2->next = p1;
                p1->next = b;
                p2->next = a;
            }
            p1 = p2;
            for (int i = 0; i < 5; i++) {
                if (i % 5 != 0) {
                    cout << p1->val << ' ';
                    p1 = p1->next;

                    if (i == 4) {
                        cout << '\n';
                    }
                }
                else {
                    cout << p1->val << ' ';
                    p1 = p1->next;
                }
            }
            p1 = p2;
            //for (int i = count; i < 6; i++) {
            //    cout << p1->val << ' ';
            //    p1 = p1->next;
            //    if (i == 5) {
            //        cout << '\n';
            //    }
            //}
            //cout << p1->val;
            //p1 = p2;

        }

        r1 = p1;

    }
}

//добавление
bool slist::add(int val) {
    node* p = new (std::nothrow) node();
    p = (struct node*)malloc(sizeof(struct node));
    if (p != NULL) {
        p->val = val;
        p->next = lst;
        lst = p;
        ++cnt;
    }
    return (p != NULL);
}

//удаление всех
void slist::clear(void) {
    node* t;
    while (lst != NULL) {
        t = lst;
        lst = lst->next;
        delete t;
        free(t);
    }
    cnt = 0;
}

//печать
void slist_print(std::ostream& _out, const slist& lst) {
    for (const node* p = lst.begin(); p != NULL; p = p->next)
        cout << p->val << ' ';
    cout << std::endl;
}


