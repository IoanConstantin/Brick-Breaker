#include "Tema1.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>
#include "Transform2DD.h"
#include "Object2DD.h"

using namespace std;

Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}

float contorTime1;
float contorTime2;
float contorTime3;
float contorTime4;
float scaleBilaInitial;
float scalePlatformaInitial;
float razaBilaInitial;
float lungimePlatformaInitial;
float vitezaBilaInitial;
float grosimePlatformaInitial;
float contorP1[12][12];
float contorP2[12][12];
float contorP3[12][12];
float contorP4[12][12];
float scaleBila;
float scalePlatforma;
float flagVietiConsumate;
float translateXPatrat[12][12];
float translateYPatrat[12][12];
float UnghiRotatie[12][12];
float razaBila;
float lungimePlatforma;
float vitezaBila;
float translateBilaX;
float translateBilaY;
float translateBilaInitialX;
float translateBilaInitialY;
float flagAtingerePowerup1[12][12];
float flagAtingerePowerup2[12][12];
float flagAtingerePowerup3[12][12];
float flagAtingerePowerup4[12][12];
float flagActivarePowerup1[12][12];
float flagActivarePowerup2[12][12];
float flagActivarePowerup3[12][12];
float flagActivarePowerup4[12][12];
float flagAtingereMacarOCaramida = 0;
float contorAtingereCaramida[12][12];
float flagAtingereCaramida[12][12];
float flagNuScalaDinNou[12][12];
float scaleCaramidaX[12][12];
float scaleCaramidaY[12][12];
float flagDisparitieCaramida[12][12];
float contorPrimaAtingerePlatforma = 0;
float contorPrimaAtingereTavan = 0;
float contorPrimaAtingerePerete1 = 0;
float contorPrimaAtingerePerete2 = 0;

void Tema1::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	glm::vec3 corner = glm::vec3(0, 0, 0);

	scaleBila = 1;
	scalePlatforma = 1;
	scaleBilaInitial = 1;
	scalePlatformaInitial = 1;

	razaBilaInitial = 10;
	lungimePlatformaInitial = 200;
	vitezaBilaInitial = 200;
	grosimePlatformaInitial = 10;
	razaBila = 10;
	lungimePlatforma = 200;
	vitezaBila = 200;

	translateBilaX = translatePlatformaInitialX + lungimePlatforma / 2 - razaBila;
	translateBilaY = translatePlatformaInitialY + grosimePlatforma + 10; 
	translateBilaInitialX = translatePlatformaInitialX + lungimePlatforma / 2 - razaBila;
	translateBilaInitialY = translatePlatformaInitialY + grosimePlatforma + 10;

	Mesh* brick4 = Object2DD::CreateBrickOriz("brick4", corner, grosimePlatforma, lungimePlatforma, glm::vec3(0, 1, 0), true);
	AddMeshToList(brick4);

	Mesh* circle = Object2DD::CreateCircle("circle", corner, razaBila, glm::vec3(1, 1, 1), true);
	AddMeshToList(circle);

	Mesh* square1 = Object2DD::CreateSquare("square1", corner, laturaPowerup, glm::vec3(0, 1, 1), true);
	AddMeshToList(square1);

	Mesh* square2 = Object2DD::CreateSquare("square2", corner, laturaPowerup, glm::vec3(1, 0, 1), true);
	AddMeshToList(square2);

	Mesh* square3 = Object2DD::CreateSquare("square3", corner, laturaPowerup, glm::vec3(1, 1, 0), true);
	AddMeshToList(square3);

	Mesh* square4 = Object2DD::CreateSquare("square4", corner, laturaPowerup, glm::vec3(0, 0, 1), true);
	AddMeshToList(square4);

	Mesh* brick1 = Object2DD::CreateBrick("brick1", corner, grosimePereteVertical, lungimePereteVertical, glm::vec3(0, 0, 1), true);
	AddMeshToList(brick1);

	Mesh* brick2 = Object2DD::CreateBrick("brick2", corner, grosimePereteVertical, lungimePereteVertical, glm::vec3(0, 0, 1), true);
	AddMeshToList(brick2);

	Mesh* brick3 = Object2DD::CreateBrickOriz("brick3", corner, grosimePereteOrizontal, lungimePereteOrizontal, glm::vec3(0, 0, 1), true);
	AddMeshToList(brick3);

	for (float i = 0; i < 99; i++)
	{
		Mesh* brick5 = Object2DD::CreateBrickOriz("brick5", corner, grosimeCaramida, lungimeCaramida, glm::vec3(1, 0, 0), true);
		AddMeshToList(brick5);
	}

	Mesh* circle2 = Object2DD::CreateCircle("circle2", corner, razaBila, glm::vec3(1, 1, 0), true);
	AddMeshToList(circle2);

	Mesh* circle3 = Object2DD::CreateCircle("circle3", corner, razaBila, glm::vec3(1, 1, 0), true);
	AddMeshToList(circle3);

	Mesh* circle4 = Object2DD::CreateCircle("circle4", corner, razaBila, glm::vec3(1, 1, 0), true);
	AddMeshToList(circle4);

	float translateXPatratInitial = 250, translateYPatratInitial = 600;
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scaleCaramidaX[i][j] = 1;
			scaleCaramidaY[i][j] = 1;
			contorAtingereCaramida[i][j] = 0;
			flagAtingereCaramida[i][j] = 0;
			flagAtingerePowerup1[i][j] = 0;
			flagAtingerePowerup2[i][j] = 0;
			flagAtingerePowerup3[i][j] = 0;
			flagAtingerePowerup4[i][j] = 0;
			contorP1[i][j] = 0;
			contorP2[i][j] = 0;
			contorP3[i][j] = 0;
			contorP4[i][j] = 0;
			translateXPatrat[i][j] = translateXPatratInitial;
			translateYPatrat[i][j] = translateYPatratInitial;

			UnghiRotatie[i][j] = 0;
			translateYPatratInitial = translateYPatratInitial - grosimeCaramida - 10;
			if (j == 8) translateYPatratInitial = translateCaramidaInitialY;
		}
		translateXPatratInitial = translateXPatratInitial + lungimeCaramida + 25;
	}
}

void Tema1::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema1::Update(float deltaTimeSeconds)
{
	/* Reflexia din peretele orizontal*/
	if (translateBilaY >= (translatePereteOrizontalY - 2 * razaBila) || flagIntoarcereBila == 1)
	{
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				flagAtingereCaramida[i][j] = 0;
				contorAtingereCaramida[i][j] = 0;
			}
		}
		flagAtingereMacarOCaramida = 0;
		flagAtingerePlatforma = 0;
		contorPrimaAtingerePlatforma = 0;
		flagLovirePerete1 = 0;
		flagLovirePerete2 = 0;
		contorPrimaAtingerePerete1 = 0;
		contorPrimaAtingerePerete2 = 0;
		contorPrimaAtingereTavan++;
		if (contorPrimaAtingereTavan == 1)
			unghiBila = -unghiBila;
		flagIntoarcereBila = 1;

		translateBilaX = translateBilaX + deltaTimeSeconds * vitezaBila * cos(unghiBila*M_PI / 180);
		translateBilaY = translateBilaY + deltaTimeSeconds * vitezaBila * sin(unghiBila*M_PI / 180);
	}

	/*Reflexia din platforma*/
	if ((translateBilaY <= (translateplatformaY + grosimePlatforma) && translateBilaX > (translateplatformaX - razaBila) && translateBilaX < (translateplatformaX + lungimePlatforma - razaBila)) || flagAtingerePlatforma == 1)
	{
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				flagAtingereCaramida[i][j] = 0;
				contorAtingereCaramida[i][j] = 0;
			}
		}
		flagAtingereMacarOCaramida = 0;
		flagIntoarcereBila = 0;
		contorPrimaAtingereTavan = 0;
		flagLovirePerete1 = 0;
		flagLovirePerete2 = 0;
		contorPrimaAtingerePerete1 = 0;
		contorPrimaAtingerePerete2 = 0;
		contorPrimaAtingerePlatforma++;
		if (contorPrimaAtingerePlatforma == 1)
		{
			distantaAtingerePlatforma = translateBilaX - (translateplatformaX - razaBila);
			distantaAtingerePlatforma = distantaAtingerePlatforma / (lungimePlatforma + 2 * razaBila);
			distantaAtingerePlatforma = distantaAtingerePlatforma * 2;
			distantaAtingerePlatforma = distantaAtingerePlatforma - 1;
			unghiBila = acos(distantaAtingerePlatforma) * 180 / M_PI;
		}
		flagAtingerePlatforma = 1;

		translateBilaX = translateBilaX + deltaTimeSeconds * vitezaBila * cos(unghiBila*M_PI / 180);
		translateBilaY = translateBilaY + deltaTimeSeconds * vitezaBila * sin(unghiBila*M_PI / 180);
	}

	/*Reflexia din peretele vertical din partea stanga*/
	if ((translateBilaX <= (translatePerete1X + grosimePereteVertical)) || flagLovirePerete1 == 1)
	{
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				flagAtingereCaramida[i][j] = 0;
				contorAtingereCaramida[i][j] = 0;
			}
		}
		flagAtingereMacarOCaramida = 0;
		flagAtingerePlatforma = 0;
		contorPrimaAtingerePlatforma = 0;
		flagLovirePerete2 = 0;
		contorPrimaAtingerePerete2 = 0;
		contorPrimaAtingerePerete1++;
		if (contorPrimaAtingerePerete1 == 1)
		{
			unghiBila = 180 - unghiBila;
		}
		flagLovirePerete1 = 1;

		translateBilaX = translateBilaX + deltaTimeSeconds * vitezaBila * cos(unghiBila*M_PI / 180);
		translateBilaY = translateBilaY + deltaTimeSeconds * vitezaBila * sin(unghiBila*M_PI / 180);
	}

	/*Reflexia din peretele vertical din partea dreapta*/
	if ((translateBilaX >= (translatePerete2X - 2 * razaBila)) || flagLovirePerete2 == 1)
	{
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				flagAtingereCaramida[i][j] = 0;
				contorAtingereCaramida[i][j] = 0;
			}
		}
		flagAtingereMacarOCaramida = 0;
		flagAtingerePlatforma = 0;
		contorPrimaAtingerePlatforma = 0;
		flagLovirePerete1 = 0;
		contorPrimaAtingerePerete1 = 0;
		contorPrimaAtingerePerete2++;
		if (contorPrimaAtingerePerete2 == 1)
		{
			unghiBila = 180 - unghiBila;
		}
		flagLovirePerete2 = 1;

		translateBilaX = translateBilaX + deltaTimeSeconds * vitezaBila * cos(unghiBila*M_PI / 180);
		translateBilaY = translateBilaY + deltaTimeSeconds * vitezaBila * sin(unghiBila*M_PI / 180);
	}

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (flagAtingereCaramida[i][j] == 1)
			{
				flagAtingereMacarOCaramida = 1;
			}
		}
	}

	/*Aruncarea bilei sub unghi drept*/
	if (flagAtingereMacarOCaramida == 0 && flagPlecareBila == 1 && flagIntoarcereBila == 0 && flagAtingerePlatforma == 0 && flagLovirePerete1 == 0 && flagLovirePerete2 == 0)
	{
		unghiBila = 90;
		translateBilaX = translateBilaX + deltaTimeSeconds * vitezaBila * cos(unghiBila*M_PI / 180);
		translateBilaY = translateBilaY + deltaTimeSeconds * vitezaBila * sin(unghiBila*M_PI / 180);
	}

	/*Repozitionarea bilei deasupra platformei la pierderea unei vieti*/
	if (translateBilaY <= 0 && flagVietiConsumate != 3)
	{
		if (flagVietiConsumate != 2)
		{
			for (int i = 0; i < 11; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					flagAtingereCaramida[i][j] = 0;
					contorAtingereCaramida[i][j] = 0;
				}
			}
			flagAtingereMacarOCaramida = 0;
			contorPrimaAtingerePlatforma = 0;
			flagAtingerePlatforma = 0;
			contorTime1 = 0;
			contorTime2 = 0;
			contorTime3 = 0;
			contorTime4 = 0;
			contorPrimaAtingereTavan = 0;
			flagIntoarcereBila = 0;
			contorPrimaAtingerePerete1 = 0;
			flagLovirePerete1 = 0;
			contorPrimaAtingerePerete2 = 0;
			flagLovirePerete2 = 0;
			flagPlecareBila = 0;
			flagPierdereViata = 1;
			scaleBila = scaleBilaInitial;
			scalePlatforma = scalePlatformaInitial;
			razaBila = razaBilaInitial;
			lungimePlatforma = lungimePlatformaInitial;
			vitezaBila = vitezaBilaInitial;
			grosimePlatforma = grosimePlatformaInitial;
		
			translateBilaX = translateplatformaX + lungimePlatforma / 2 - razaBila;
			translateBilaY = translateBilaInitialY;
		}
		if(flagVietiConsumate < 3)
			flagVietiConsumate++;
	}

	/*Desenare pereti si platforma*/
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2DD::Translate(translatePerete1X, translatePerete1Y);
	RenderMesh2D(meshes["brick1"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2DD::Translate(translatePerete2X, translatePerete2Y);
	RenderMesh2D(meshes["brick2"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2DD::Translate(translatePereteOrizontalX, translatePereteOrizontalY);
	RenderMesh2D(meshes["brick3"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2DD::Translate(translateplatformaX, translateplatformaY);
	modelMatrix *= Transform2DD::Scale(scalePlatforma, scalePlatforma);
	RenderMesh2D(meshes["brick4"], shaders["VertexColor"], modelMatrix);

	/*Desenare caramizi si powerups*/
	float translateCaramidaX = 250, translateCaramidaY = 600;
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (flagNuScalaDinNou[i][j] == 0 && translateBilaX >= (translateCaramidaX - 2 * razaBila) && translateBilaX <= (translateCaramidaX + lungimeCaramida) && translateBilaY >= (translateCaramidaY - 2 * razaBila) && translateBilaY <= (translateCaramidaY + grosimeCaramida))
			{
				flagDisparitieCaramida[i][j] = 1;

				if (scaleCaramidaX[i][j] > 0)
				{
					if (scaleCaramidaX[i][j] == 1)
						contorAtingereCaramida[i][j] = -2; 

					/*Momentul coliziunii cu caramida*/
					if (contorAtingereCaramida[i][j] == -2)
					{
						for (int a = 0; a < 11; a++)
						{
							for (int b = 0; b < 9; b++)
							{
								if (a != i || b != j)
								{
									flagAtingereCaramida[a][b] = 0;
									contorAtingereCaramida[a][b] = 0;
								}
							}
						}

						if (((translateBilaY - (translateCaramidaY - 2 * razaBila)) < vitezaBila / 50) || (((translateCaramidaY + grosimeCaramida) - translateBilaY) < vitezaBila / 50))
							unghiBila = 360 - unghiBila;

						if (((translateBilaX - (translateCaramidaX - 2 * razaBila)) < vitezaBila / 50) || (((translateCaramidaX + lungimeCaramida) - translateBilaX) < vitezaBila / 50))
							unghiBila = 180 - unghiBila;

						/*Cazuri de caramizi sub care se afla powerups*/
						if (i % 4 == 0 && j % 4 == 0)
							flagAtingerePowerup1[i][j] = 1;

						if (i % 4 != 0 && j % 4 != 0 && i % 2 == 0 && j % 2 == 0)
							flagAtingerePowerup4[i][j] = 1;

						if (i % 4 == 0 && j % 4 != 0 && j % 2 == 0)
							flagAtingerePowerup2[i][j] = 1;

						if (j % 4 == 0 && i % 4 != 0 && i % 2 == 0)
							flagAtingerePowerup3[i][j] = 1;
					}
					contorAtingereCaramida[i][j]++;

					scaleCaramidaX[i][j] = scaleCaramidaX[i][j] - deltaTimeSeconds;
				}

				if (scaleCaramidaY[i][j] > 0)
					scaleCaramidaY[i][j] = scaleCaramidaY[i][j] - deltaTimeSeconds;
			}

			/*Ultima coliziune a fost efectuata cu o caramida*/
			if (contorAtingereCaramida[i][j] == -1 || flagAtingereCaramida[i][j] == 1)
			{
				flagIntoarcereBila = 0;
				contorPrimaAtingereTavan = 0;
				flagLovirePerete1 = 0;
				flagLovirePerete2 = 0;
				contorPrimaAtingerePerete1 = 0;
				contorPrimaAtingerePerete2 = 0;
				flagAtingerePlatforma = 0;
				contorPrimaAtingerePlatforma = 0;
				flagAtingereCaramida[i][j] = 1;
				translateBilaX = translateBilaX + deltaTimeSeconds * vitezaBila * cos(unghiBila*M_PI / 180);
				translateBilaY = translateBilaY + deltaTimeSeconds * vitezaBila * sin(unghiBila*M_PI / 180);
			}

			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2DD::Translate(translateCaramidaX, translateCaramidaY);

			modelMatrix *= Transform2DD::Scale(scaleCaramidaX[i][j], scaleCaramidaY[i][j]);

			RenderMesh2D(meshes["brick5"], shaders["VertexColor"], modelMatrix);

			/*Rotire si cadere powerups*/
			if (i % 4 == 0 && j % 4 == 0)
			{
				modelMatrix = glm::mat3(1);
				modelMatrix *= Transform2DD::Translate(translateXPatrat[i][j], translateYPatrat[i][j]);
				modelMatrix *= Transform2DD::Rotate(UnghiRotatie[i][j]);
				RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);
			}

			if (i % 4 != 0 && j % 4 != 0 && i % 2 == 0 && j % 2 == 0)
			{
				modelMatrix = glm::mat3(1);
				modelMatrix *= Transform2DD::Translate(translateXPatrat[i][j], translateYPatrat[i][j]);
				modelMatrix *= Transform2DD::Rotate(UnghiRotatie[i][j]);
				RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);
			}

			if (i % 4 == 0 && j % 4 != 0 && j % 2 == 0)
			{
				modelMatrix = glm::mat3(1);
				modelMatrix *= Transform2DD::Translate(translateXPatrat[i][j], translateYPatrat[i][j]);
				modelMatrix *= Transform2DD::Rotate(UnghiRotatie[i][j]);
				RenderMesh2D(meshes["square3"], shaders["VertexColor"], modelMatrix);
			}

			if (j % 4 == 0 && i % 4 != 0 && i % 2 == 0)
			{
				modelMatrix = glm::mat3(1);
				modelMatrix *= Transform2DD::Translate(translateXPatrat[i][j], translateYPatrat[i][j]);
				modelMatrix *= Transform2DD::Rotate(UnghiRotatie[i][j]);
				RenderMesh2D(meshes["square4"], shaders["VertexColor"], modelMatrix);
			}

			/*Efectele propriu-zise ale powerups-urilor*/
			if (flagAtingerePowerup1[i][j] == 1)
			{
				translateYPatrat[i][j] = translateYPatrat[i][j] - deltaTimeSeconds * vitezaBila;
				UnghiRotatie[i][j] = UnghiRotatie[i][j] + deltaTimeSeconds;
				if (translateYPatrat[i][j] <= (translateplatformaY + grosimePlatforma) && translateXPatrat[i][j] > (translateplatformaX - laturaPowerup) && translateXPatrat[i][j] < (translateplatformaX + lungimePlatforma - laturaPowerup))
					contorP1[i][j]++;
				if (contorP1[i][j] == 1)
				{
					lungimePlatforma = lungimePlatforma * 1.5;
					grosimePlatforma = grosimePlatforma * 1.5;
					scalePlatforma = scalePlatforma * 1.5;
					contorTime1 = 1;
				}
			}

			if (flagAtingerePowerup2[i][j] == 1)
			{
				translateYPatrat[i][j] = translateYPatrat[i][j] - deltaTimeSeconds * vitezaBila;
				UnghiRotatie[i][j] = UnghiRotatie[i][j] + deltaTimeSeconds;
				if (translateYPatrat[i][j] <= (translateplatformaY + grosimePlatforma) && translateXPatrat[i][j] > (translateplatformaX - laturaPowerup) && translateXPatrat[i][j] < (translateplatformaX + lungimePlatforma - laturaPowerup))
					contorP2[i][j]++;
				if (contorP2[i][j] == 1)
				{
					vitezaBila = vitezaBila + 200;
					contorTime2 = 1;
				}
			}

			if (flagAtingerePowerup3[i][j] == 1)
			{
				translateYPatrat[i][j] = translateYPatrat[i][j] - deltaTimeSeconds * vitezaBila;
				UnghiRotatie[i][j] = UnghiRotatie[i][j] + deltaTimeSeconds;
				if (translateYPatrat[i][j] <= (translateplatformaY + grosimePlatforma) && translateXPatrat[i][j] > (translateplatformaX - laturaPowerup) && translateXPatrat[i][j] < (translateplatformaX + lungimePlatforma - laturaPowerup))
					contorP3[i][j]++;
				if (contorP3[i][j] == 1)
				{
					razaBila = razaBila * 1.5;
					scaleBila = scaleBila * 1.5;
					contorTime3 = 1;
				}
					
			}

			if (flagAtingerePowerup4[i][j] == 1)
			{
				translateYPatrat[i][j] = translateYPatrat[i][j] - deltaTimeSeconds * vitezaBila;
				UnghiRotatie[i][j] = UnghiRotatie[i][j] + deltaTimeSeconds;
				if (translateYPatrat[i][j] <= (translateplatformaY + grosimePlatforma) && translateXPatrat[i][j] > (translateplatformaX - laturaPowerup) && translateXPatrat[i][j] < (translateplatformaX + lungimePlatforma - laturaPowerup))
					contorP4[i][j]++;
				if (contorP4[i][j] == 1)
				{
					if (vitezaBila >= 60)
						vitezaBila = vitezaBila - 50;
					contorTime4 = 1;
				}
			}

			/*Revenire la dimensiunea normala dupa efectuarea powerup-ului*/
			if (contorTime1 >= 1 && contorTime1 < 3000)
				contorTime1 += deltaTimeSeconds;

			if (contorTime2 >= 1 && contorTime2 < 3000)
				contorTime2 += deltaTimeSeconds;

			if (contorTime3 >= 1 && contorTime3 < 3000)
				contorTime3 += deltaTimeSeconds;

			if (contorTime4 >= 1 && contorTime4 < 3000)
				contorTime4 += deltaTimeSeconds;

			if (contorTime1 >= 3000)
			{
				contorTime1 = 0;
				lungimePlatforma = lungimePlatformaInitial;
				grosimePlatforma = grosimePlatformaInitial;
				scalePlatforma = scalePlatformaInitial;
			}

			if (contorTime2 >= 3000)
			{
				contorTime2 = 0;
				vitezaBila = vitezaBilaInitial;
			}

			if (contorTime3 >= 3000)
			{
				contorTime3 = 0;
				razaBila = razaBilaInitial;
				scaleBila = scaleBilaInitial;
			}

			if (contorTime4 >= 3000)
			{
				contorTime4 = 0;
				vitezaBila = vitezaBilaInitial;
			}
				
			/*Animatie disparitie caramida*/
			if (flagNuScalaDinNou[i][j] == 0 && flagDisparitieCaramida[i][j] == 1)
			{
				if (scaleCaramidaX[i][j] > 0)
					scaleCaramidaX[i][j] = scaleCaramidaX[i][j] - deltaTimeSeconds;

				if (scaleCaramidaY[i][j] > 0)
					scaleCaramidaY[i][j] = scaleCaramidaY[i][j] - deltaTimeSeconds;

				if (scaleCaramidaX[i][j] <= 0 && scaleCaramidaY[i][j] <= 0)
					flagNuScalaDinNou[i][j] = 1;
			}

			translateCaramidaY = translateCaramidaY - grosimeCaramida - 10;
			if (j == 8) translateCaramidaY = translateCaramidaInitialY;
		}
		translateCaramidaX = translateCaramidaX + lungimeCaramida + 25;
	}

	/*Desenarea bilei si a vietilor*/
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2DD::Translate(translateBilaX, translateBilaY);
	modelMatrix *= Transform2DD::Scale(scaleBila, scaleBila);
	RenderMesh2D(meshes["circle"], shaders["VertexColor"], modelMatrix);

	float translateViataX = 10, translateViataY = 10;

	if (flagVietiConsumate <= 2)
	{
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2DD::Translate(translateViataX, translateViataY);
		RenderMesh2D(meshes["circle2"], shaders["VertexColor"], modelMatrix);
	}

	if (flagVietiConsumate <= 1)
	{
		translateViataX += 25;
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2DD::Translate(translateViataX, translateViataY);
		RenderMesh2D(meshes["circle3"], shaders["VertexColor"], modelMatrix);
	}

	if (flagVietiConsumate == 0)
	{
		translateViataX += 25;
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2DD::Translate(translateViataX, translateViataY);
		RenderMesh2D(meshes["circle4"], shaders["VertexColor"], modelMatrix);
	}
}

void Tema1::FrameEnd()
{

}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{

}

void Tema1::OnKeyPress(int key, int mods)
{
	// add key press event
}

void Tema1::OnKeyRelease(int key, int mods)
{
	// add key release event
}

/*Mutarea platformei si a bilei (in cazul in care nu a fost aruncata) dupa miscarea mouse-ului*/
void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	translateplatformaX = mouseX - lungimePlatforma / 2;
	if (flagPlecareBila == 0)
		translateBilaX = mouseX - razaBila;
}

/*Aruncarea bilei*/
void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT))
	{
		flagPlecareBila = 1;
	}
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}
