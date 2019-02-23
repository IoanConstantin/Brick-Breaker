#pragma once

#include <Component/SimpleScene.h>
#include <string>
#include <Core/Engine.h>

class Tema1 : public SimpleScene
{
public:
	Tema1();
	~Tema1();

	void Init() override;

private:
	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;

	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;

protected:
	glm::mat3 modelMatrix;
	float translateX, translateY;
	float scaleX, scaleY;
	float angularStep;
	float flag1 = 0, flag2 = 0;
	float centruX;
	float centruY;
	float grosimePereteVertical = 20;
	float lungimePereteVertical = 650;
	float grosimePereteOrizontal = 20;
	float lungimePereteOrizontal = 1260;
	float grosimePlatforma = 10;
	float grosimeCaramida = 25;
	float lungimeCaramida = 50;
	float laturaPowerup = 20;
	float translatePerete1X = 0;
	float translatePerete1Y = 100;
	float translatePerete2X = 1260;
	float translatePerete2Y = 100;
	float translatePereteOrizontalX = 0;
	float translatePereteOrizontalY = 720 - grosimePereteOrizontal;
	float translateplatformaX = 535;
	float translateplatformaY = 30;
	float translatePlatformaInitialX = 535;
	float translatePlatformaInitialY = 30;
	float translateCaramidaInitialY = 600;
	float flagPlecareBila = 0;
	float flagIntoarcereBila = 0;
	float flagLovirePerete1 = 0;
	float flagLovirePerete2 = 0;
	float flagPierdereViata = 0;
	float pozitieBila = 0;
	float flagAtingerePlatforma = 0;
	float unghiBila = 90;
	float distantaAtingerePlatforma = 0;
};
