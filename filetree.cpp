#include "filetree.h"
#include "node.h"

fileTree::fileTree()
{
    root=new Node("root", true);
    root->parent=NULL;
    currentDir=root;
    savedNode=NULL;
}

std::list<Node*>::iterator fileTree::findChild(Node *addr)
{
    std::list<Node*>::iterator it;
    for(it=addr->parent->child.begin();it!=addr->parent->child.end();it++){
        if((*it)->name==addr->name&& (*it)->dir==addr->dir){
            return it;
        }
    }
    return it;
}

void fileTree::createFile(std::string name, Node* addr)
{
    Node *newFile=new Node(name,false);
    newFile->parent=addr;
    addr->child.push_back(newFile);
}

void fileTree::mkdir(std::string name, Node* addr)
{
    Node *newDir=new Node(name,true);
    newDir->parent=addr;
    addr->child.push_back(newDir);
    //For some reasons, mkdir&createFile are treated differently.
    //They could be merged if you want.
}

void fileTree::rm(Node *addr){
    if(addr->dir){ //addr is related to a dir. Need to delete everything inside it.
        std::list<Node*>::iterator it;
        for(it=addr->child.begin();it!=addr->child.end();it++){
            this->rm(*it);
        }
        it=this->findChild(addr);
        addr->parent->child.erase(it);
        delete (*it);
    }
    else{ //addr is related to a file
        std::list<Node*>::iterator it=this->findChild(addr);
        addr->parent->child.erase(it);
        delete (*it);
    }
    //For easier debugging, dir&file are treated differently.
    //They could be merged if you want.
}

void fileTree::cp(Node *from,Node *to) //"to" need to be a dir
{
    if(from->dir){ //Same to "rm".
        //Create a new dir in "to"
        Node *newDir=from;
        to->child.push_back(newDir);
        //Copy everything in "from" to new dir in "to";
        std::list<Node*>::iterator it;
        for(it=from->child.begin();it!=from->child.end();it++){
            this->cp((*it),newDir);
        }
    }
    else{
        Node *newFile=from;
        to->child.push_back(newFile);
        newFile->parent=to;
    }
}

void fileTree::mv(Node *from,Node *to)
{
    this->cp(from,to);
    this->rm(from);
}



