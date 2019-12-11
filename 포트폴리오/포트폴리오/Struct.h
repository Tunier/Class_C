#pragma once

struct Vector
{
	int x, y;
};

Vector MarkLocation[3];

struct Object
{
	char* pTexture;
	Vector Position;
	Vector Scale;

	int Rotate;
};

struct BlockScore
{
	int Efficiency;
	int ID;
};

BlockScore Block[9];