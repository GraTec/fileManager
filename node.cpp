#include "node.h"

Node::Node(std::string name, bool dir)
{
    Node(QString(name.c_str()), dir);
}

Node::Node(QString name, bool dir)
{
    this->name=name;
    this->dir=dir;
}

void Node::operator=(Node& n2)
{
    this->name=n2.name;
    this->dir=n2.dir;
    this->parent=n2.parent;

    std::list<Node*>::iterator it;
    if(!this->child.empty()){
        this->child.clear();
    }
    for(it=n2.child.begin();it!=n2.child.end();it++){
        this->child.push_back(*it);
    }
}
