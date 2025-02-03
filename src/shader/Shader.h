#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
using std::string, std::ifstream, std::stringstream, std::cout, std::endl;

/// @brief General purpose shader object.
/// @details Compiles from file, generates compile/link-time error messages and
/// hosts several utility functions for easy management.
class Shader {
public:
    /// @brief The shader program ID
    unsigned int ID;

    /// @brief Construct a new Shader object
    Shader() {}

    /// @brief Inform OpenGL to use this shader
    /// @return A pointer to this shader object (for method chaining)
    Shader &use();

    /// @brief Compile the shader from given source code
    /// @details Creates, compiles and links the shader
    /// @note geometry source code is optional
    /// @param vertexSource the source code for the vertex shader
    /// @param fragmentSource the source code for the fragment shader
    /// @param geometrySource the source code for the geometry shader (optional)
    void compile(const char *vertexSource, const char *fragmentSource,
                 const char *geometrySource =
                 nullptr); // note: geometry source code is optional

    // ------------------------------------------------------------------------
    // utility functions
    // ------------------------------------------------------------------------

    /// @brief set a uniform float in the shader
    /// @param name name of the uniform
    /// @param value float value to set
    /// @param useShader boolean to indicate whether to use this shader
    void setFloat(const char *name, float value) const;

    /// @brief set a uniform integer in the shader
    /// @param name name of the uniform
    /// @param value integer value to set
    /// @param useShader boolean to indicate whether to use this shader
    void setInteger(const char *name, int value) const;

    /// @brief set a uniform vector of two floats in the shader
    /// @param name name of the uniform
    /// @param value x and y values to set as a glm::vec2
    /// @param useShader boolean to indicate whether to use this shader
    void setVector2f(const char *name, float x, float y) const;

    /// @brief set a uniform vector of two floats in the shader
    /// @param name name of the uniform
    /// @param value glm::vec2 values to set
    /// @param useShader boolean to indicate whether to use this shader
    void setVector2f(const char *name, const glm::vec2 &value) const;

    /// @brief set a uniform vector of three floats in the shader
    /// @param name name of the uniform
    /// @param value x, y and z values to set as a glm::vec3
    /// @param useShader boolean to indicate whether to use this shader
    void setVector3f(const char *name, float x, float y, float z) const;

    /// @brief set a uniform vector of three floats in the shader
    /// @param name name of the uniform
    /// @param value glm::vec3 values to set
    /// @param useShader boolean to indicate whether to use this shader
    void setVector3f(const char *name, const glm::vec3 &value) const;

    /// @brief set a uniform vector of four floats in the shader
    /// @param name name of the uniform
    /// @param value x, y, z and w values to set as a glm::vec4
    /// @param useShader boolean to indicate whether to use this shader
    void setVector4f(const char *name, float x, float y, float z,
                     float w) const;

    /// @brief set a uniform vector of four floats in the shader
    /// @param name name of the uniform
    /// @param value glm::vec4 values to set
    /// @param useShader boolean to indicate whether to use this shader
    void setVector4f(const char *name, const glm::vec4 &value) const;

    /// @brief set a uniform matrix of four floats in the shader
    /// @param name name of the uniform
    /// @param matrix glm::mat4 values to set
    /// @param useShader boolean to indicate whether to use this shader
    void setMatrix4(const char *name, const glm::mat4 &matrix) const;

private:
    /// @brief Checks if compilation or linking failed and if so, print the
    /// error logs
    /// @param object the shader object to check
    /// @param type the type of shader object (vertex, fragment, geometry)
    void checkCompileErrors(unsigned int object, std::string type);
};

#endif
