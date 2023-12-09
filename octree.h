#ifndef OCTREE_H
#define OCTREE_H

#include <iostream>
#include "node.h"

class Octree {
private:
    Node*   root;

    void printLeavesRecursive(Node* current, glm::mat4 view, glm::mat4 projection);
public:
    Octree();
    glm::mat4 model = glm::mat4(1.0f);
    void insert(Point newPoint);
    void printLeaves(glm::mat4 view, glm::mat4 projection);
};

#endif // OCTREE_H