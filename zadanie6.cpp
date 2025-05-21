#include <iostream>
using namespace std;
#include <string.h> 
#include <string>
#include "list.h"

int main() {
    // Создаем список маршрутов
    MyList<MARSH> list;

    cout << "\nСписок маршрутов:\n";
    
    // Добавляем несколько маршрутов
    list.addEnd(MARSH("Москва", "Санкт-Петербург", 1));
    list.addEnd(MARSH("Казань", "Нижний Новгород", 3));
    list.addBegin(MARSH("Новосибирск", "Красноярск", 2));

    // Выводим список
    cout << list << "\n";

    // Проверяем методы
    cout << "Проверка методов:\n";
    cout << "Список пуст? " << (list.IsEmpty() ? "Да" : "Нет") << "\n";

    // Удаление элемента
    MARSH toDelete("Казань", "Нижний Новгород", 3);
    list.deleteEl(toDelete);
    cout << "\nПосле удаления маршрута №3:\n" << list << "\n";

    // Очистка списка
    list.deleteList();
    cout << "После очистки списка:\n";
    cout << "Список пуст? " << (list.IsEmpty() ? "Да" : "Нет") << "\n";

    return 0;
}
