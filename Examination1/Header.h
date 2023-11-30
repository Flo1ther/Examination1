#pragma once
const int WarehouseMaxProducts = 100;
struct Product {
    char name[50];
    char manufacturer[50];
    char category[50];
    double price;
    char arrivalDate[20];
    char expirationDate[20];
};