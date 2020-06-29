#ifndef FILETREE_H
#define FILETREE_H

#include "node.h"
#include <vector>
#include <QDebug>


class fileTree
{
private:
    Node *root;
    std::list<Node*>::iterator findChild(Node *addr);
public:
    fileTree();

    //Basic file operations
//    void createFile(std::string name,Node* addr);
    void createFile(QString name,Node* addr);

//    void mkdir(std::string name,Node* addr);
    void mkdir(QString name,Node* addr);

    void cp(Node *from,Node *to);
    void mv(Node *from,Node *to);
    void rm(Node *addr);

    bool check_is_child(Node *parent, Node *child);

    //Provide information that GUI needs.
    QString showAddr();

    Node *savedNode; //Used for cp/mv in GUI.

    Node *currentDir;

    //Used for test.
    void test();

};

#endif // FILETREE_H
