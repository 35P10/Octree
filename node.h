#ifndef NODE_H
#define NODE_H

#include "GL_cube.h"
#include "point.h"

class Node {
private:

public:
    Point   coordinate;
    Node*   child[8];
    int     depth = 0;
    Point   GL_coordinate;

    Node();
    Node(int x, int y, int z);
    void set_depth(int newDepth);
    void set_GLcoordinate(Point newDepth);
    glm::vec3 GL_calcularCentroOctante(int octante);
    void config_cube();
    GL_Cube* GLCube;
    void render(glm::mat4 view, glm::mat4 projection);
};

#endif // NODE_H