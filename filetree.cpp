#include "filetree.h"
#include "node.h"
#include <string>

fileTree::fileTree()
{
    root=new Node("root", true);
    root->parent=NULL;
    currentDir=root;
    savedNode=NULL;
}

void fileTree::createFile(std::string name)
{
    Node *newFile=new Node(name,false);
    newFile->parent=currentDir;
    this->currentDir->child.push_back(newFile);
}

void fileTree::mkdir(std::string name)
{
    Node *newDir=new Node(name,true);
    newDir->parent=currentDir;
    this->currentDir->child.push_back(newDir);
}

void fileTree::cp(Node *from,Node *to) //"to" need to be a dir
{
    to->child.push_back(from);
    from->parent=to;
    std::list<Node*>::iterator it;
    for(it=currentDir->child.begin();it!=currentDir->child.end();it++){
        if ((*it)->name==from->name){
            (*it)
        }
    }
}
//void mv(Node *from,Node *to);
//void rm(Node *addr);


