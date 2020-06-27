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
    qDebug()<<QString::fromStdString(addr->name);
    if(addr->dir){ //addr is related to a dir. Need to delete everything inside it.
        std::list<Node*>::iterator it;
        while(!addr->child.empty()){
            this->rm(addr->child.back());
        }
        it=this->findChild(addr);
        addr->parent->child.erase(it);
        delete (*it);
    }
    else{ //addr is related to a file
//        qDebug()<<"Trying to delete"+QString::fromStdString(addr->name);
        std::list<Node*>::iterator it=this->findChild(addr);
        addr->parent->child.erase(it);
        delete (*it);
//        qDebug()<<"Finished";
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

std::string fileTree::showAddr()
{
    std::vector<std::string> addr;
    Node *searchNode = currentDir;
    addr.push_back(searchNode->name);
    while(searchNode->parent!=NULL){
        searchNode=searchNode->parent;
        addr.push_back(searchNode->name);
    }
    std::string address="";
    for(int i=addr.size()-1;i>=0;i--){
        address+=("/"+addr[i]);
    }
    return address;
}

void fileTree::test()
{
    this->mkdir("testDir",this->currentDir);
    this->createFile("testFile",this->currentDir);
}


