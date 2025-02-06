//
// Created by Jake Pappas on 2/4/2025.
//

#ifndef INC_3D_TEMPLATE_RAY_H
#define INC_3D_TEMPLATE_RAY_H

#include <glm/glm.hpp>
#include <iostream>

using std::cout, std::endl, glm::vec3, std::string;

class Ray {
    vec3 initial_position;
    vec3 initial_direction;
    vec3 current_direction;
    unsigned int collisions;
    unsigned int MAX_COLLISIONS;

    Ray(vec3 initial_position, vec3 initial_direction, unsigned int MAX_COLLISIONS);

    bool collides(string shape_type, vec3 shape_pos, float shape_size); //generalized for future development

};




#endif //INC_3D_TEMPLATE_RAY_H
