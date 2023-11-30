#include <iostream>
#include <string>
#include <Windows.h>
#include "Header1.h"

using namespace std;
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    warehouse warehouse;
    warehouse.count = 0;

    while (true) {
        cout << "\nСистема менеджменту складу\n";
        cout << "1. Додати продукт\n";
        cout << "2. Видалити продукт за назвою\n";
        cout << "3. Показати продукти за критерієм\n";
        cout << "4. Сортувати продукти за ціною\n";
        cout << "5. Сортувати продукти за категорією\n";
        cout << "6. Замінити продукт за назвою\n";
        cout << "7. Пошук продукту за критерієм\n";
        cout << "8. Вихід\n";
        cout << "Оберіть опцію: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            warehouse.addProduct(warehouse);
            break;
        case 2: {
            char name[50];
            cout << "Введіть назву продукту для видалення: ";
            cin >> name;
            warehouse.removeProduct(warehouse, name);
            break;
        }
        case 3: {
            char criterion[20], value[50];
            cout << "Введіть критерій (назва, виробник, категорія, ціна, дата прибуття, дата закінчення): ";
            cin >> criterion;
            cout << "Введіть значення для критерію: ";
            cin >> value;
            warehouse.displayProductsByCriterion(warehouse, criterion, value);
            break;
        }
        case 4:
            warehouse.SortByPrice(warehouse);
            break;
        case 5:
            warehouse.SortByCategory(warehouse);
            break;
        case 6: {
            char name[50];
            cout << "Введіть назву продукту для заміни: ";
            cin >> name;
            warehouse.replaceProductByName(warehouse, name);
            break;
        }
        case 7: {
            char criterion[20], value[50];
            cout << "Введіть критерій (назва, виробник, категорія, ціна, дата прибуття, дата закінчення): ";
            cin >> criterion;
            cout << "Введіть значення для критерію: ";
            cin >> value;
            warehouse.searchProduct(warehouse, criterion, value);
            break;
        }
        case 8:
            cout << "Вихід з програми.\n";
            return 0;
        default:
            cout << "Невірний вибір. Будь ласка, введіть правильну опцію.\n";
        }
    }

}
