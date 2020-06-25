#ifndef FILETREE_H
#define FILETREE_H

#include "node.h"
#include <string>

class fileTree
{
private:
    Node *root;
public:
    fileTree();

    //Basic file operations
    void createFile(std::string name);
    void mkdir(std::string name);
    void cp(Node *from,Node *to);
    void mv(Node *from,Node *to);
    void rm(Node *addr);

    Node *savedNode; //Used for cp/mv in GUI.

    Node *currentDir;
};

#endif // FILETREE_H
