#pragma once

struct vector3
{
	float x, y;
};

struct Object
{
	char* pTexture;
	vector3 Position;
	vector3 Scale;
	
	int Rotate;
};