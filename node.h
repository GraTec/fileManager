#include <string>
#include <vector>
#ifndef NODE_H
#define NODE_H


class Node
{
public:
    std::string name;
    bool dir;
    Node *parent;
    std::vector<Node> *child;
};

#endif // NODE_H
