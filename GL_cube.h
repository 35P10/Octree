#ifndef GLCUBE_H
#define GLCUBE_H

#include <vector>
#include "GL_plane.h"

class GL_Cube {
private:
    glm::mat4 transform = glm::mat4(1.0f);
    glm::vec4  color = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
    GL_Plane* lados = new GL_Plane[6];

public:
    GL_Cube() { ; } 
    GL_Cube(glm::vec3 translacion, glm::vec3 escalar, glm::vec4 newColor = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), bool drawWired = false) {
        color = newColor;
        transform = glm::scale(transform, escalar);
        transform = glm::translate(transform, translacion);

        float vertices1[] = {
            // positions          // texture coords
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
             0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
             0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
        };
        float vertices2[] = {
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
             0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
             0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        };
        float vertices3[] = {
            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f
        };
        float vertices4[] = {
             0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
             0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
             0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
             0.5f, -0.5f,  0.5f,  0.0f, 0.0f
        };
        float vertices5[] = {
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
             0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
             0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f
        };
        float vertices6[] = {
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
             0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
             0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 0.0f
        };
        unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
        };

        lados[0].setColor(color); lados[0].setVertices(vertices1, indices, drawWired);
        lados[1].setColor(color); lados[1].setVertices(vertices2, indices, drawWired);
        lados[2].setColor(color); lados[2].setVertices(vertices3, indices, drawWired);
        lados[3].setColor(color); lados[3].setVertices(vertices4, indices, drawWired);
        lados[4].setColor(color); lados[4].setVertices(vertices5, indices, drawWired);
        lados[5].setColor(color); lados[5].setVertices(vertices6, indices, drawWired);

    }

    void setColor(glm::vec4 newColor)
    {
        for (int i = 0; i < 6; i++)
            lados[i].setColor(newColor);
    }

    glm::mat4 get_model() {
        return transform;
    }

    void set_model(glm::mat4 newModel) {
        transform = newModel;
    }

    void translate(glm::vec3 translacion) {
        transform = glm::translate(transform, translacion);
    }

    void scale(glm::vec3 escalar) {
        transform = glm::scale(transform, escalar);
    }

    void render(glm::mat4 view, glm::mat4 projection) {
        for (int i = 0; i < 6; i++)
            lados[i].render(transform, view, projection);
    }
};

#endif // GLCUBE_H