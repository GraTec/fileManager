#ifndef NEW_NODE_H
#define NEW_NODE_H

#include <QString>
#include <QList>

class Node
{
public:
    QString name;
    Node *parent;
    bool is_dir;

    QList<Node*> children;

    Node(QString name, Node *parent, bool is_dir);

//    void operator = (Node& n2);
};


#endif // NEW_NODE_H
