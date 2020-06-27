#ifndef FILETREE_H
#define FILETREE_H

#include "node.h"
#include <vector>

class fileTree
{
private:
    Node *root;
    std::list<Node*>::iterator findChild(Node *addr);
public:
    fileTree();

    //Basic file operations
    void createFile(std::string name,Node* addr);
    void mkdir(std::string name,Node* addr);
    void cp(Node *from,Node *to);
    void mv(Node *from,Node *to);
    void rm(Node *addr);

    //Provide information that GUI needs.
    std::string showAddr();

    Node *savedNode; //Used for cp/mv in GUI.

    Node *currentDir;

    //Used for test.
    void test();

};

#endif // FILETREE_H
