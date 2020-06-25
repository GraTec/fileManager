#ifndef FILETREE_H
#define FILETREE_H

#include "node.h"

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

    Node *savedNode; //Used for cp/mv in GUI.

    Node *currentDir;
};

#endif // FILETREE_H
