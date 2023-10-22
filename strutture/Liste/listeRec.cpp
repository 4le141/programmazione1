#include <iostream>
 
using namespace std;

struct node;
typedef node* list; 
struct node
{
    int value;
    list next;
};
 
list newList() {
    list l = NULL;
    return l;
}
 
list newRandomList(int length, int min, int max) {
    srand(time(NULL));
    list l = newList();
    for(int i = 0; i < length; ++i) {
        add(l, rand()%(max-min)+min);
    }
    return l;
}
 
bool isEmpty(list & l) {
    return l == NULL; 
}
 
void add(list & l, int n) {
    if(isEmpty(l)) {
        l = new node;
        l->value = n;
        l->next = NULL;
    }
    else {
        add(l->next, n);
    }
}
 
void remove(list & l, int index) {
    if(index == 1) {
        if(isEmpty(l->next))
            return;
        list t = l->next;
        l->next = l->next->next;
        delete t;
    }
    else 
        remove(l->next, index-1);
}
 
 
list elementAt(list & l, int index, bool cloneElement = false) {
    if(isEmpty(l))
        return NULL;
    //cout << "Index: " << index << " value: " << l->value << endl;
    if(index == 0) {
        if(cloneElement) {
            list n = new node;
            n->value = l->value;
 
            return n;
        }
        return l;
    }
    else 
        return elementAt(l->next, index-1, cloneElement);
}
 
int inedxOf(list & l, int n) {
    for(int i = 0; !isEmpty(l); ++i) {
        if(l->value == n)
            return i;
        l = l->next;
    }
    return -1; 
}
 
void printList(list & l) {
    if(!isEmpty(l)) {
        cout << l->value << " ";
        printList(l->next);
    }
}
 
void printInvertedList(list & l) {
    if(!isEmpty(l)) {
        printInvertedList(l->next);
        cout << l->value << " ";
    }
}
 
void removeAll(list & l, int value) {
    if(isEmpty(l))
        return;
    if(l->value == value) {
        list t = l;
        l = l->next;
        delete t;
        removeAll(l, value);
    }
    else    
        removeAll(l->next, value);
}
 
void removeDuplicates(list & l) {
    if(isEmpty(l))
        return;
    removeAll(l->next, l->value);
    removeDuplicates(l->next);
}
 
bool replaceNode(list & l, list node, int index) {
    if(isEmpty(l))
        return false;
    if(index == 0) {
        node->next = l->next;
        l = node;
        return true; 
    }
    if(index == 1) {
        if(isEmpty(l->next)) {
            return false;
        }
        else {
            list t = l->next->next;
            node->next = t;
            l->next = node;
        } 
        return true;
    }
    else 
        return replaceNode(l->next, node, index-1);
 
}
 
bool switchNodes(list & l, int index1, int index2) {
    if(index1 == index2)
        return true;
    list n1 = elementAt(l, index1, true);
    if(n1 == NULL) {
        cerr << "Index1 was out of bounds on the list!" << endl;
        return false;
    }
    list n2 = elementAt(l, index2, true);
    if(n2 == NULL) {
        cerr << "Index2 was out of bounds on the list!" << endl;
        deinit(n1);
        return false;
    }
 
    if(!replaceNode(l, n1, index2))
        return false;
    printList(l);
    if(!replaceNode(l, n2, index1))
        return false;
    return true;
}
 
void deinit(list & l) {
    if(!isEmpty(l)) 
        deinit(l->next);
    delete l;
}