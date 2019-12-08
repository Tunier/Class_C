#pragma once

struct Vector
{
	int x, y;
};

struct Object
{
	char* pTexture;
	Vector Position;
	Vector Scale;

	int Rotate;
	int Turn;
};
