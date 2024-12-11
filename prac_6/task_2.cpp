#include"queue.h"

int main() {

    SetConsoleOutputCP(1251);

    LinkedList list;
    Queue queue;

    for (int i = 0; i <= 4; i++) {
        list.addItem(i);
        queue.addItem(i);
    }

    cout << "Содеожимое list:" << endl;
    list.display();

    cout << "\nСодеожимое queue:" << endl;
    queue.display();

    for (int i = 0; i < 3; ++i) {
        cout <<"Элемнет удален " << list.pop()<<endl;
    }

    for (int i = 0; i < 3; ++i) { 
  
        cout << "Элемнет удален " << queue.pop() << endl;
    }
    return 0;
}