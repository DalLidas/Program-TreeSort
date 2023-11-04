#pragma once


///////////////////////////////////////////////////
// ����� ��� ������ � ����������� ������� (�������� ������� ������)
///////////////////////////////////////////////////
class TreeSortClass {
private:

    //��������� ���� ������
    struct tnode
    {
        double field;           // ���� ������
        struct tnode* left;  // ����� �������
        struct tnode* right; // ������ �������
    };

    tnode* root = nullptr;

public:

    // ���������� �������
    void TreeSort(std::vector<double>& data) {
        CreateTree(data);
        data.clear();
        //PrintTree(root);
        WriteTree(data, root);
        FreeMem(root);
    }

    // �������� ������ ������ �� �������� 
    void CreateTree(const std::vector<double>& data) {
        for (auto i = data.begin(); i != data.end(); ++i) {
            root = AddNode(*i, root);
        }
    }

    // ������ ����� ������ � ���������� ������
    void WriteTree(std::vector<double>& data, tnode* tree){
        if (tree != NULL) {      //���� �� ���������� ������ ����
            WriteTree(data, tree->left);  //����������� ������� ������ ������ ���������
            data.push_back(tree->field); //������ ������ ������
            WriteTree(data, tree->right); //����������� ������� ������ ������� ���������
        }
    }

    // ����� ����� ������ (����� � ��������� �����)
    void PrintTree(tnode* tree)
    {
        if (tree != NULL) {      //���� �� ���������� ������ ����
            PrintTree(tree->left);  //����������� ������� ������ ������ ���������
            std::cout << tree->field << " "; //���������� ������ ������
            PrintTree(tree->right); //����������� ������� ������ ������� ���������
        }
    }

    // ���������� ����� � ������
    struct tnode* AddNode(int x, tnode* tree) {
        if (tree == NULL)     // ���� ������ ���, �� ��������� ������
        {
            tree = new tnode; //������ ��� ����
            tree->field = x;   //���� ������
            tree->left = NULL;
            tree->right = NULL; //����� �������������� ��������
        }
        else     // �����
            if (x < tree->field)   //���� ������� x ������ ���������, ������ �����
                tree->left = AddNode(x, tree->left); //���������� ��������� �������
            else  //����� ������ ������
                tree->right = AddNode(x, tree->right); //���������� ��������� �������
        return(tree);
    }

    //������������ ������ ������
    void FreeMem(tnode* tree)
    {
        if (tree != NULL)    // ���� ������ �� ������
        {
            FreeMem(tree->left);   // ���������� ������� ����� �����
            FreeMem(tree->right);  // ���������� ������� ������ �����
            delete tree;           // ������� ������
        }
    }
};
