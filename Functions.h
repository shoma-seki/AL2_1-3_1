#pragma once

struct Vector2 {
	float x;
	float y;
};

struct intPos {
	int x;
	int y;
};

struct MapChip {
	intPos LeftTop;
	intPos LeftBottom;
	intPos RightTop;
	intPos RightBottom;
};

struct Vertex {
	Vector2 LeftTop;
	Vector2 LeftBottom;
	Vector2 RightTop;
	Vector2 RightBottom;
	Vector2 center;
	MapChip mapnum;
	float width;
	float height;
};

struct Player {
	Vertex vertex;
	Vector2 velocity;
};

float DotProduct(float AstartX, float AstartY, float AendX, float AendY, float BstartX, float BstartY, float BendX, float BendY);
float CrossProduct(float AstartX, float AstartY, float AendX, float AendY, float BstartX, float BstartY, float BendX, float BendY);
float MAX(float x, float y);
float pNorm(float x, float y, float p);
float GetRadian(float AstartX, float AstartY, float AendX, float AendY, float BstartX, float BstartY, float BendX, float BendY);
float GetDegree(float radian);
float GetDis(float x1, float y1, float x2, float y2);
float Normalize(float startX, float startY, float endX, float endY, int n);
float Clamp(float n, float min, float max);
float isBoxCollisionBeta(float leftTopX1, float leftTopY1, float rightBottomX1, float rightBottomY1, float leftTopX2, float leftTopY2, float rightBottomX2, float rightBottomY2);
float isCircleCollision(float posX1, float posY1, float posX2, float posY2, int radius1, int radius2);
float CC(float posY);
float LeftTopX(float posX, float width);
float LeftTopY(float posY, float height);
float LeftBottomX(float posX, float width);
float LeftBottomY(float posY, float height);
float RightTopX(float posX, float width);
float RightTopY(float posY, float height);
float RightBottomX(float posX, float width);
float RightBottomY(float posY, float height);
float CenterC(float leftTopX, float leftTopY, float width, float height, int n);
float isBoxCollision(float posX1, float posY1, float posX2, float posY2, float width, float height, float width2, float height2);
float IsOutOfScreen(float posX, float posYn, int ScreenSizeX, int ScreenSizeY);
float BoxPointCollision(float BoxLtX, float BoxLtY, float BoxRbX, float BoxRbY, int pointX, int pointY);
void CalculateVertex(Vertex& vertex);
void CalculatePlayerVertex(Player& player);
void newDrawQuad(Vertex vertex, int textureHandle);
void CalculateQuadMapMapNumber(Player& player, const int MapChipSize);
void VertexScreenPrintf(Player player, int x, int y);