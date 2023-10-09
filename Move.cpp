#include <Novice.h>
#include <math.h>
#include "Functions.h"
#include "Move.h"

void Move(Player& player, int ScreenSizeX, int ScreenSizeY) {

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	static float dirY = 0;
	static float dirX = 0;
	/*float velocityTmpX = int(player.velocity.x);
	float velocityTmpY = int(player.velocity.y);*/

	if (keys[DIK_A] || keys[DIK_LEFT]) {
		dirX--;
	}
	if (keys[DIK_D] || keys[DIK_RIGHT]) {
		dirX++;
	}
	if (keys[DIK_W] || keys[DIK_UP]) {
		dirY--;
	}
	if (keys[DIK_S] || keys[DIK_DOWN]) {
		dirY++;
	}

	player.vertex.center.x += dirX * player.velocity.x;
	player.vertex.center.y += dirY * player.velocity.y;

	if (player.vertex.center.x <= player.vertex.width) {
		player.vertex.center.x = player.vertex.width;
	}
	if (player.vertex.center.x >= ScreenSizeX - player.vertex.width) {
		player.vertex.center.x = ScreenSizeX - player.vertex.width;
	}

	if (player.vertex.center.y <= player.vertex.height) {
		player.vertex.center.y = player.vertex.height;
	}
	if (player.vertex.center.y >= ScreenSizeY - player.vertex.height) {
		player.vertex.center.y = ScreenSizeY - player.vertex.height;
	}

	dirX = 0;
	dirY = 0;
}