#ifndef SCENE_HPP
#define SCENE_HPP

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>
#include "../shader/Shader.h"

using std::vector;

class Scene {
  private:
	unsigned int VBO;
	unsigned int VAO;
    unsigned int EBO;
	vector<unsigned int> indices;
	vector<float> vertices;


  public:
    void setShader(Shader &shader);
    Shader shader;
	Scene();
	void initVBO();
    unsigned int initVAO();
//    void initEBO();
	void draw();
    void setUniforms(const glm::mat4 &model, const glm::mat4 &view,
                     const glm::mat4 &projection) const;
};

#endif // SCENE_HPP

