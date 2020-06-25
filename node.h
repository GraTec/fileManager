#include <string>
#include <list>
#ifndef NODE_H
#define NODE_H


class Node
{
public:
    std::string name;
    bool dir;
    Node *parent;
    std::list<Node*> child;
    Node(std::string name, bool dir);

    void operator = (Node& n2);
};

#endif // NODE_H
