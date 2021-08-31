#ifndef OOP7_EDITOR_HPP
#define OOP7_EDITOR_HPP

#include "figure.hpp"
#include "document.hpp"
#include <stack>
#include "command.hpp"

struct editor {
private:
    std::shared_ptr<document> doc_;
    std::stack<std::shared_ptr<Acommand>> history_;
public:
    ~editor() = default;

    void PrintDocument();

    void CreateDocument(std::string& newName);

    bool DocumentExist();

    editor() : doc_(nullptr), history_()
    {
    }

    void InsertInDocument(std::shared_ptr<figure>& newFigure);

    void DeleteInDocument(uint32_t index);

    void SaveDocument();

    void LoadDocument(std::string& name);

    void Undo();

};

#endif