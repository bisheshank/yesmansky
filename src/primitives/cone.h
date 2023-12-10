#ifndef CONE_H
#define CONE_H

#include "primitive.h"

class Cone : public Primitive
{
public:
    // Constructors
    Cone(const glm::mat4 &pctm, const ScenePrimitive &pprimitive);
    Cone();

    // Generates mesh for this primitive and binds VAOs and VBOs to it
    void generate_mesh(const int shape_param_1, const int shape_param_2) override;

    // (Fake?) destructor
    ~Cone();

    // Function to draw Cone (don't draw if certain shape params set)
    void draw(GLuint shader);

    // Function to delete buffers
    void delete_buffers() override;

    // Function to retrieve VAO for this primitive class
    GLuint get_vao() override;

    // Function to retrieve VBO for this primitive class
    GLuint get_vbo() override;

private:

    // Helper functions for generating the mesh
    void make_cap_tile(std::vector<GLfloat> &data, glm::vec3 top_left, glm::vec3 top_right, glm::vec3 bottom_left, glm::vec3 bottom_right);
    void make_side_tile(std::vector<GLfloat> &data, glm::vec3 top_left, glm::vec3 top_right, glm::vec3 bottom_left, glm::vec3 bottom_right);
    void make_wedge(std::vector<GLfloat> &data, float curr_theta, float next_theta);
    glm::vec3 compute_normal(glm::vec3 point);

    // Function to retrieve number of triangles for this class
    int get_triangles() override;

    // Fields unique to the Cones class

    // VAO shared across all instances of Coness
    static GLuint m_vao;
    // VBO shared across all instances of Coness
    static GLuint m_vbo;
    // Number of triangles shared across all instances of Coness
    static int num_triangles;

    // Static ints that control parameters for shape generation
    static int shape_parameter_1;
    static int shape_parameter_2;
};


#endif // CONE_H