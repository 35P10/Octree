#include "node.h"

Node::Node() {
    for (int i = 0; i < 8; ++i) {
        child[i] = nullptr;
    }
}

Node::Node(int x, int y, int z) {
    coordinate.x = x;
    coordinate.y = y;
    coordinate.z = z;

    for (int i = 0; i < 8; ++i) {
        child[i] = nullptr;
    }
}

void Node::set_depth(int newDepth) {
    depth = newDepth;
}

void Node::set_GLcoordinate(Point newGLcoordinate) {
    GL_coordinate = newGLcoordinate;
}

glm::vec3 Node::GL_calcularCentroOctante(int octante) {

    float offsetX = (octante & 1) ? 0.5f : -0.5f;
    float offsetY = (octante & 2) ? 0.5f : -0.5f;
    float offsetZ = (octante & 4) ? 0.5f : -0.5f;


    return glm::vec3(offsetX, offsetY, offsetZ);
}

void Node::render(glm::mat4 view, glm::mat4 projection) {
    GLCube->render(view, projection);
}