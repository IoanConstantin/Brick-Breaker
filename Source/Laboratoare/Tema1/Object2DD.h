#pragma once

#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>

namespace Object2DD
{
	// Create square with given bottom left corner, length and color
	Mesh* CreateSquare(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
	Mesh* CreateBrick(std::string name, glm::vec3 leftBottomCorner, float length, float width, glm::vec3 color, bool fill = false);
	Mesh* CreateBrickOriz(std::string name, glm::vec3 leftBottomCorner, float length, float width, glm::vec3 color, bool fill = false);
	Mesh* CreateCircle(std::string name, glm::vec3 leftBottomCorner, float raza, glm::vec3 color, bool fill = false);
}

