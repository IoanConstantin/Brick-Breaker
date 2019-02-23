#include "Object2DD.h"

#include <Core/Engine.h>

Mesh* Object2DD::CreateSquare(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(length, 0, 0), color),
		VertexFormat(corner + glm::vec3(length, length, 0), color),
		VertexFormat(corner + glm::vec3(0, length, 0), color)
	};

	Mesh* square = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3 };
	
	if (!fill) {
		square->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	square->InitFromData(vertices, indices);
	return square;
}

Mesh* Object2DD::CreateBrick(std::string name, glm::vec3 leftBottomCorner, float length, float width, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices1 =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(length, 0, 0), color),
		VertexFormat(corner + glm::vec3(length, width, 0), color),
		VertexFormat(corner + glm::vec3(0, width, 0), color)
	};

	Mesh* brick = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3 };

	if (!fill) {
		brick->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	brick->InitFromData(vertices1, indices);
	return brick;
}

Mesh* Object2DD::CreateBrickOriz(std::string name, glm::vec3 leftBottomCorner, float length, float width, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices1 =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(width, 0, 0), color),
		VertexFormat(corner + glm::vec3(width, length, 0), color),
		VertexFormat(corner + glm::vec3(0, length, 0), color)
	};

	Mesh* brick = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3 };

	if (!fill) {
		brick->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	brick->InitFromData(vertices1, indices);
	return brick;
}

Mesh* Object2DD::CreateCircle(std::string name, glm::vec3 leftBottomCorner, float raza, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices2 ={};

	for(float i=0;i<360;i=i+0.01)
		vertices2.push_back(VertexFormat(corner+glm::vec3(raza + raza * cos(i*M_PI/180), raza + raza * sin(i*M_PI/180), 0), color));

	Mesh* circle = new Mesh(name);
	std::vector<unsigned short> indices = {};
	for (float i = 0; i < 360*100; i++)
		indices.push_back(i);

	circle->SetDrawMode(GL_TRIANGLE_FAN);

	circle->InitFromData(vertices2, indices);
	return circle;
}