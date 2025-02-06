//
// Created by Jake Pappas on 2/4/2025.
//

#include "Ray.h"

Ray::Ray(vec3 initial_position, vec3 initial_direction, unsigned int MAX_COLLISIONS){
    this->initial_position = initial_position;
    this->initial_direction = initial_direction;
    this->MAX_COLLISIONS = MAX_COLLISIONS;
}

bool Ray::collides(string shape_type, vec3 shape_pos, float shape_size){
    if (shape_type == "SPHERE"){
        float radius = shape_size;


    }
}
