#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include<glm/gtc/quaternion.hpp>

class Transform
{

private:
	//glm::mat4x4 matTRS, matPos, matRot, matSc;

protected:

public:

	/// <summary>
	/// CTOR
	/// </summary>
	Transform();

	/// <summary>
	/// DTOR
	/// </summary>
	virtual ~Transform();

	void SetPosition(glm::vec3 i_position);

	void SetRotation(glm::quat i_rotation);

	void SetScale(glm::vec3 i_scale);

	glm::vec3 GetPosition();

	glm::quat GetRotation();

	glm::vec3 GetScale();

	glm::mat4x4 GetTRS();
};
