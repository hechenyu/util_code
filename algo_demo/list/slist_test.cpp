#include <string>
#include <iostream>
#include "slist.h"

using namespace std;

int main(int argc, char *argv[])
{
    typedef Slist<string> List;
    typedef Slist_node<string> Node;

    List list;
    for (int i = 1; i < argc; i++) {
        list_insert_front(list, list_new_node(string(argv[i])));
    }

    if (list_empty(list)) {
        cout << "list is empty!" << endl;
    } else {
        cout << "list: [";
        list_for_each(list, [](Node *node) { cout << node->value << ", "; });
        cout << "]" << endl;
    }

    cout << "entry val for search: ";
    string val;
    cin >> val;
    if (list_search(list, val) != nullptr) {
        cout << "found it!" << endl;
    } else {
        cout << "not found!" << endl;
    }

    cout << "free list" << endl;
    while (!list_empty(list)) {
        list_free_node(list_remove_front(list));
    }

    cout << "after free list" << endl;
    if (list_empty(list)) {
        cout << "list is empty!" << endl;
    } else {
        cout << "list is not empty!" << endl;
    }

	return 0;
}
