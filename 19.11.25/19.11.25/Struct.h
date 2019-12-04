#pragma once

struct Vector3
{
	float x, y;
};

struct Object
{
	char* pTexture;
	Vector3 Position;
	Vector3 Scale;

	int Rotate;
};