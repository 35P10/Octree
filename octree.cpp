#include "octree.h"

Octree::Octree() {
    root = nullptr;
}

void Octree::insert(Point newPoint) {
    Node* current = root;

    while (current != nullptr) {
        int octant = 0;
        
        if (newPoint.x > current->coordinate.x) octant += 1;
        if (newPoint.y > current->coordinate.y) octant += 2;
        if (newPoint.z > current->coordinate.z) octant += 4;

        if (current->child[octant] == nullptr) {
            current->child[octant] = new Node(newPoint.x, newPoint.y, newPoint.z);
            current->child[octant]->set_depth(current->depth + 1);
            current->child[octant]->GLCube = new GL_Cube(glm::vec3(0,0,0), glm::vec3(1,1,1));
            current->child[octant]->GLCube-> set_model(current -> GLCube-> get_model());
            current->child[octant]->GLCube->scale(glm::vec3(0.5f, 0.5f, 0.5f));
            current->child[octant]->GLCube->translate(current->GL_calcularCentroOctante(octant));
            
            return;
        }
        current = current->child[octant];
    }

    root = new Node(newPoint.x, newPoint.y, newPoint.z);
    root-> GLCube = new GL_Cube(glm::vec3(0,0,0), glm::vec3(1,1,1), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    
}

void Octree::printLeaves(glm::mat4 view, glm::mat4 projection) {
    view = view * model;
    printLeavesRecursive(root, view, projection);
}

void Octree::printLeavesRecursive(Node* current, glm::mat4 view, glm::mat4 projection) {
    if (current != nullptr) {
        if (current->child[0] == nullptr && current->child[1] == nullptr &&
            current->child[2] == nullptr && current->child[3] == nullptr &&
            current->child[4] == nullptr && current->child[5] == nullptr &&
            current->child[6] == nullptr && current->child[7] == nullptr) {
                current->render(view, projection);
        } else {
            for (int i = 0; i < 8; ++i) {
                printLeavesRecursive(current->child[i], view, projection);
            }
        }
    }
}