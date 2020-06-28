#ifndef NODE_H
#define NODE_H

#include <string>
#include <list>
#include <QString>

class Node
{
public:
    QString name;
    bool dir;
    Node *parent;
    std::list<Node*> child;

    Node(std::string name, bool dir);
    Node(QString name, bool dir);

    void operator = (Node& n2);
};

#endif // NODE_H
