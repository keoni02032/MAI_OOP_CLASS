#include <iostream>
#include "factory.hpp"
#include "editor.hpp"

void help() {
    std::cout << "1 - help\n"
                 "2 - создать\n"
                 "3 - загрузить\n"
                 "4 - сохранить\n"
                 "5 - добавить фигуру\n"
                 "6 - удалить\n"
                 "7 - печать\n"
                 "8 - назад\n"
                 "0 - выход\n";
}

void create(editor& edit) {
    std::string tmp;
    std::cout << "Введите название нового документа\n";
    std::cin >> tmp;
    edit.CreateDocument(tmp);
    std::cout << "Документ создан\n";
}

void load(editor& edit) {
    std::string tmp;
    std::cout << "Введите название файла\n";
    std::cin >> tmp;
    try {
        edit.LoadDocument(tmp);
        std::cout << "Документ загружен\n";

    } catch (std::runtime_error& e) {
        std::cout << e.what();
    }
}

void save(editor& edit) {
    std::string tmp;
    try {
        edit.SaveDocument();
        std::cout << "Документ сохранен\n";
    } catch (std::runtime_error& e) {
        std::cout << e.what();
    }
}

void add(editor& edit) {
    factory fac;
    try {
        std::shared_ptr<figure> newElem = fac.FigureCreate(std::cin);
        edit.InsertInDocument(newElem);
    } catch (std::logic_error& e) {
        std::cout << e.what() << '\n';
    }
    std::cout << "Ok\n";
}

void remove(editor& edit) {
    uint32_t index;
    std::cout << "Введите индекс фигуры которую хотите удалить\n";
    std::cin >> index;
    try {
        edit.DeleteInDocument(index);
        std::cout << "Ok\n";
    } catch (std::logic_error& err) {
        std::cout << err.what() << "\n";
    }
}

int main() {
    editor edit;
    int command;
    std::cout << "1 - help" << "\n"
              << "2 - создать файл" << "\n"
              << "3 - загрузить" << "\n"
              << "4 - сохранить" << "\n"
              << "5 - добавить фигуру" << "\n"
              << "6 - удалить фигуру из файла" << "\n"
              << "7 - печать" << "\n"
              << "8 - назад" << "\n"
              << "0 - выход" << "\n";
    while (true) {
        std::cin >> command;
        if (command == 1) {
            help();
        } else if (command == 2) {
            create(edit);
        } else if (command == 3) {
            load(edit);
        } else if (command == 4) {
            save(edit);
        } else if (command == 0) {
            break;
        } else if (command == 5) {
            add(edit);
        } else if (command == 6) {
            remove(edit);
        } else if (command == 7) {
            edit.PrintDocument();
        } else if (command == 8) {
            try {
                edit.Undo();
            } catch (std::logic_error& e) {
                std::cout << e.what();
            }
        } else {
            std::cout << "ERROR\n";
        }
    }
    return 0;
}