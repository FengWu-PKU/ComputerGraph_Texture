//
// Created by sakura on 2023/5/25.
//

#ifndef HAND_TBN_H
#define HAND_TBN_H
#include "glm/glm.hpp"
#include "GL/glew.h"

struct TBN_t {
    glm::vec3 tangent;
    glm::vec3 bitangent;
    glm::vec3 normal;
};

struct TBN_t calcTBN(glm::vec3 pos1,glm::vec3 pos2, glm::vec3 pos3, glm::vec2 uv1, glm::vec2 uv2, glm::vec2 uv3, glm::vec3 nm)
{
    struct TBN_t res;
    glm::vec3 tangent, bitangent, normal;
    glm::vec3 edge1=pos2-pos1;
    glm::vec3 edge2=pos3-pos1;
    glm::vec2 deltaUV1=uv2-uv1;
    glm::vec2 deltaUV2=uv3-uv1;

    GLfloat f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

    tangent.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
    tangent.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
    tangent.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
    tangent = glm::normalize(tangent);

    bitangent.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
    bitangent.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
    bitangent.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
    bitangent = glm::normalize(bitangent);

    normal=glm::normalize(nm);

    res.tangent= tangent;
    res.bitangent= bitangent;
    res.normal= normal;
    return res;
}
#endif //HAND_TBN_H
