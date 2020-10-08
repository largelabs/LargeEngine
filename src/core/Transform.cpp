#include "transform.hpp"

Transform::Transform()
{
   

}

Transform::~Transform()
{

}

void Transform::SetPosition(glm::vec3 i_position) 
{

}

void Transform::SetRotation(glm::quat i_rotation)
{
    
}

void Transform::SetScale(glm::vec3 i_scale)
{

}

glm::vec3 Transform::GetPosition()
{
    return glm::vec3(0.0f);
}

glm::quat Transform::GetRotation()
{
    return glm::quat(sqrt(1.0f / 2.0f), 0.0f, sqrt(1.0f / 2.0f), 0.0f);
}

glm::vec3 Transform::GetScale()
{
    return glm::vec3(1.0f);
}

glm::mat4x4 Transform::GetTRS()
{
    return glm::identity<glm::mat4>();
}
