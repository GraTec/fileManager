#include "new_node.h"

Node::Node(QString name, Node* parent, bool is_dir): name(name),  parent(parent), is_dir(is_dir), children(QList<Node*>())
{
    parent->children.append(this);
}

//void Node::operator=(Node& n2)
//{
//    this->name=n2.name;
//    this->dir=n2.dir;
//    this->parent=n2.parent;

//    std::list<Node*>::iterator it;
//    if(!this->child.empty()){
//        this->child.clear();
//    }
//    for(it=n2.child.begin();it!=n2.child.end();it++){
//        this->child.push_back(*it);
//    }
//}
