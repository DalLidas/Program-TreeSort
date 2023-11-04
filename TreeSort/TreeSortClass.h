#pragma once


///////////////////////////////////////////////////
// Класс для работы с сортировкой деревом (двоичным деревом поиска)
///////////////////////////////////////////////////
class TreeSortClass {
private:

    //Структура узла дерева
    struct tnode
    {
        double field;           // поле данных
        struct tnode* left;  // левый потомок
        struct tnode* right; // правый потомок
    };

    tnode* root = nullptr;

public:

    // Сортировка деревом
    void TreeSort(std::vector<double>& data) {
        CreateTree(data);
        data.clear();
        //PrintTree(root);
        WriteTree(data, root);
        FreeMem(root);
    }

    // Создание дерева вершин из значений 
    void CreateTree(const std::vector<double>& data) {
        for (auto i = data.begin(); i != data.end(); ++i) {
            root = AddNode(*i, root);
        }
    }

    // Запись узлов дерева в струкктуру данных
    void WriteTree(std::vector<double>& data, tnode* tree){
        if (tree != NULL) {      //Пока не встретится пустой узел
            WriteTree(data, tree->left);  //Рекурсивная функция записи левого поддерева
            data.push_back(tree->field); //Запись корень дерева
            WriteTree(data, tree->right); //Рекурсивная функция записи правого поддерева
        }
    }

    // Вывод узлов дерева (обход в инфиксной форме)
    void PrintTree(tnode* tree)
    {
        if (tree != NULL) {      //Пока не встретится пустой узел
            PrintTree(tree->left);  //Рекурсивная функция вывода левого поддерева
            std::cout << tree->field << " "; //Отображаем корень дерева
            PrintTree(tree->right); //Рекурсивная функция вывода правого поддерева
        }
    }

    // Добавление узлов в дерево
    struct tnode* AddNode(int x, tnode* tree) {
        if (tree == NULL)     // Если дерева нет, то формируем корень
        {
            tree = new tnode; //память под узел
            tree->field = x;   //поле данных
            tree->left = NULL;
            tree->right = NULL; //ветви инициализируем пустотой
        }
        else     // иначе
            if (x < tree->field)   //Если элемент x меньше корневого, уходим влево
                tree->left = AddNode(x, tree->left); //Рекурсивно добавляем элемент
            else  //иначе уходим вправо
                tree->right = AddNode(x, tree->right); //Рекурсивно добавляем элемент
        return(tree);
    }

    //Освобождение памяти дерева
    void FreeMem(tnode* tree)
    {
        if (tree != NULL)    // если дерево не пустое
        {
            FreeMem(tree->left);   // рекурсивно удаляем левую ветку
            FreeMem(tree->right);  // рекурсивно удаляем правую ветку
            delete tree;           // удаляем корень
        }
    }
};
