#include <iostream>

const int MAX = 4; // Максимальный размер стека

// Структура для хранения координат
struct COORD {
    int x;
    int y;
};

// Базовый класс Stack1
class Stack1 {
protected:
    COORD stack[MAX]; // Массив для хранения координат
    int top; // Индекс верхнего элемента стека

public:
    Stack1() : top(-1) {} // Инициализация стека

    // Метод для добавления значения в стек
    void put(int value) {
        if (top >= MAX - 1) {
            std::cout << "Stack overflow\n"; // Сообщение о переполнении
            return;
        }
        stack[++top].x = value; // Сохраняем значение как координату X
    }

    // Метод для извлечения значения из стека
    int pop() {
        if (top < 0) {
            std::cout << "Stack is empty\n"; // Сообщение о пустом стеке
            return -1; // Возвращаем -1 как индикатор ошибки
        }
        return stack[top--].x; // Извлекаем значение как координату X
    }
};

// Производный класс Stack2
class Stack2 : public Stack1 {
public:
    // Метод для добавления координат в стек
    void put(const COORD& coord) {
        Stack1::put(coord.x); // Сохраняем X
        Stack1::put(coord.y); // Сохраняем Y
    }

    // Метод для извлечения координат из стека
    COORD pop() {
        int y = Stack1::pop(); // Извлекаем Y
        int x = Stack1::pop(); // Извлекаем X
        return { x, y }; // Возвращаем координаты как структуру COORD
    }
};

// Основная функция программы
int main() {
  

    Stack2 s1;

    COORD point1 = { 1, 2 };
    COORD point2 = { 3, 4 };

    // Помещение точек в стек
    s1.put(point1);
    s1.put(point2);

    // Извлечение точек из стека
    COORD retrievedPoint2 = s1.pop();
    COORD retrievedPoint1 = s1.pop();

    std::cout << "Popped point 2: (" << retrievedPoint2.x << ", " << retrievedPoint2.y << ")\n";
    std::cout << "Popped point 1: (" << retrievedPoint1.x << ", " << retrievedPoint1.y << ")\n";

    // Попробуем поместить три точки в стек
    s1.put(point1);
    s1.put(point2);
    s1.put(point1);

    // Извлечение всех трех точек из стека
    for (int i = 0; i < 3; ++i) {
        COORD point = s1.pop();
        if (point.x != -1 && point.y != -1) { // Проверяем, что извлечение прошло успешно
            std::cout << "Popped point: (" << point.x << ", " << point.y << ")\n";
        }
    }

    return 0;
}
