#include <Novice.h>
#include "Functions.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "Move.h"

enum MAPTYPE {
	NONE, BLOCK, COLLISION
};

const char kWindowTitle[] = "LC1A_17_セキ_ショウマ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//ウィンドウサイズ
	const int WindowWidth = 640;
	const int WindowHeight = 500;

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, WindowWidth, WindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	srand(unsigned int(time(nullptr)));

	Player player;
	player.vertex.center.x = 32;
	player.vertex.center.y = 32;
	player.vertex.width = 16;
	player.vertex.height = 16;
	player.velocity.x = 2;
	player.velocity.y = 2;

	const int MapSizeWidth = 20;
	const int MapSizeHeight = 10;
	const int MapChipSize = 32;
	int mapchip[MapSizeHeight][MapSizeWidth] = {
		{0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,1,0,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0},
		{0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,0},
		{0,0,1,1,1,1,0,1,0,1,0,0,1,0,0,1,0,0,0,0},
		{0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
		{0,0,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
		{0,0,1,0,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
	};

	//画像のロード
	int NoneTex = Novice::LoadTexture("./None.png");
	int BlockTex = Novice::LoadTexture("./Block.png");
	int mapCollisionTex = Novice::LoadTexture("./mapCollision.png");

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		CalculateVertex(player.vertex);
		//プレイヤー移動
		CalculatePlayerVertex(player);
		CalculateQuadMapMapNumber(player, MapChipSize);
		Move(player, 640, 320);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		for (int row = 0; row < MapSizeWidth; row++) {
			for (int column = 0; column < MapSizeHeight; column++) {
				if (mapchip[column][row] == BLOCK) {
					Novice::DrawSprite(row * MapChipSize, column * MapChipSize, BlockTex, 1, 1, 0.0f, 0xFFFFFFFF);
				}
				if (mapchip[column][row] == NONE) {
					Novice::DrawSprite(row * MapChipSize, column * MapChipSize, NoneTex, 1, 1, 0.0f, 0xFFFFFFFF);
				}
			}
		}
		Novice::DrawEllipse(int(player.vertex.center.x), int(player.vertex.center.y), 16, 16, 0.0f, WHITE, kFillModeSolid);
		VertexScreenPrintf(player, 50, 400);
		mapCollisionTex;
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
