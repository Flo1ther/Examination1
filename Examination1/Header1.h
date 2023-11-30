#pragma once
#include "Header.h";
using namespace std;
struct warehouse {
    Product products[WarehouseMaxProducts];
    int count;
    void addProduct(warehouse warehouse) {
        if (warehouse.count < WarehouseMaxProducts) {
            Product newProduct;
            cout << "������ ����� ��������: ";
            cin >> newProduct.name;
            cout << "������ ���������: ";
            cin >> newProduct.manufacturer;
            cout << "������ ��������: ";
            cin >> newProduct.category;
            cout << "������ ����: ";
            cin >> newProduct.price;
            cout << "������ ���� ��������: ";
            cin >> newProduct.arrivalDate;
            cout << "������ ���� ��������� ������ ����������: ";
            cin >> newProduct.expirationDate;

            warehouse.products[warehouse.count++] = newProduct;
            cout << "������� ������ �� �����." << endl;
        }
        else {
            cout << "����� ����������. ��������� ������ ����� ��������." << endl;
        }
    }

    void removeProduct(warehouse warehouse, const char* name) {
        int removedCount = 0;
        for (int i = 0; i < warehouse.count; ++i) {
            if (strcmp(warehouse.products[i].name, name) == 0) {
                for (int j = i; j < warehouse.count - 1; ++j) {
                    warehouse.products[j] = warehouse.products[j + 1];
                }
                --warehouse.count;
                ++removedCount;
                --i;
            }
        }
    }

    void displayProduct(const Product product) {
        using namespace std;
        cout << "�����: " << product.name << endl;
        cout << "��������: " << product.manufacturer << endl;
        cout << "��������: " << product.category << endl;
        cout << "ֳ��: " << product.price << endl;
        cout << "���� ��������: " << product.arrivalDate << endl;
        cout << "����� ����������: " << product.expirationDate << endl;
        cout << "-----------------------" << endl;
    }

    void displayProductsByCriterion(const warehouse warehouse, const char* criterion, const char* value) {
        cout << "��������, �� ���������� ������� " << criterion << " � ��������� " << value << ": " << endl;
        for (int i = 0; i < warehouse.count; ++i) {
            const Product& product = warehouse.products[i];
            if (strcmp(criterion, "name") == 0 && strcmp(product.name, value) == 0) {
                displayProduct(product);
            }
            else if (strcmp(criterion, "manufacturer") == 0 && strcmp(product.manufacturer, value) == 0) {
                displayProduct(product);
            }
            else if (strcmp(criterion, "category") == 0 && strcmp(product.category, value) == 0) {
                displayProduct(product);
            }
            else if (strcmp(criterion, "price") == 0 && to_string(product.price) == value) {
                displayProduct(product);
            }
            else if (strcmp(criterion, "arrivalDate") == 0 && strcmp(product.arrivalDate, value) == 0) {
                displayProduct(product);
            }
            else if (strcmp(criterion, "expirationDate") == 0 && strcmp(product.expirationDate, value) == 0) {
                displayProduct(product);
            }
        }
    }

    void SortByPrice(warehouse warehouse) {
        for (int i = 0; i < warehouse.count; i++) {
            for (int j = 0; j < warehouse.count - i - 1; j++) {
                if (warehouse.products[j].price > warehouse.products[j + 1].price) {
                    Product tmp = warehouse.products[j];
                    warehouse.products[j] = warehouse.products[j + 1];
                    warehouse.products[j + 1] = tmp;
                }
            }
        }
    }

    void SortByCategory(warehouse warehouse) {
        for (int i = 0; i < warehouse.count; i++) {
            for (int j = 0; j < warehouse.count - i - 1; j++) {
                if (strcmp(warehouse.products[j].category, warehouse.products[j + 1].category) > 0) {
                    Product tmp = warehouse.products[j];
                    warehouse.products[j] = warehouse.products[j + 1];
                    warehouse.products[j + 1] = tmp;
                }
            }
        }
    }

    void replaceProductByName(warehouse warehouse, const char* name) {
        for (int i = 0; i < warehouse.count; ++i) {
            if (strcmp(warehouse.products[i].name, name) == 0) {
                Product newProduct;
                cout << "������ ���� ����� ��������: ";
                cin >> newProduct.name;
                cout << "������ ������ ���������: ";
                cin >> newProduct.manufacturer;
                cout << "������ ���� ��������: ";
                cin >> newProduct.category;
                cout << "������ ���� ����: ";
                cin >> newProduct.price;
                cout << "������ ���� ���� ��������: ";
                cin >> newProduct.arrivalDate;
                cout << "������ ���� ���� ��������� ������ ����������: ";
                cin >> newProduct.expirationDate;

                warehouse.products[i] = newProduct;
                std::cout << "������� ������ �������.\n";
                return;
            }
        }

        cout << "������� �� ������ \"" << name << "\" �� �������� �� �����.\n";
    }

    void searchProduct(warehouse warehouse, const char* criterion, const char* value) {
        using namespace std;
        cout << "��������, �� ���������� ������� " << criterion << " � ��������� " << value << ":";
        for (int i = 0; i < warehouse.count; ++i) {
            const Product& product = warehouse.products[i];
            if (strcmp(criterion, "name") == 0 && strcmp(product.name, value) == 0) {
                displayProduct(product);
            }
            else if (strcmp(criterion, "manufacturer") == 0 && strcmp(product.manufacturer, value) == 0) {
                displayProduct(product);
            }
            else if (strcmp(criterion, "category") == 0 && strcmp(product.category, value) == 0) {
                displayProduct(product);
            }
            else if (strcmp(criterion, "price") == 0 && to_string(product.price) == value) {
                displayProduct(product);
            }
            else if (strcmp(criterion, "arrivalDate") == 0 && strcmp(product.arrivalDate, value) == 0) {
                displayProduct(product);
            }
            else if (strcmp(criterion, "expirationDate") == 0 && strcmp(product.expirationDate, value) == 0) {
                displayProduct(product);
            }
        }
    }
};