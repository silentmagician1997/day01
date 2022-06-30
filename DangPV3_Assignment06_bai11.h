
#pragma once
#include <Windows.h>
#include <iostream>
#include <cstdlib>


class CShape
{
public:
	int color;
	virtual void draw(int x, int y, HDC device_context) = 0;
};

class CLine : public CShape
{
public:
	void draw(int x, int y, HDC device_context);
	CLine(int length, int color);
private:
	int length;
};

class CCircle : public CShape
{
public:
	void draw(int x, int y, HDC device_context);
	CCircle(int radium, int color);
private:
	int radium;
};

class CRectangle : public CShape
{
public:
	CRectangle(){};
	void draw(int x, int y, HDC device_context);
	CRectangle(int width, int height, int color);
protected:
	int width, height;
};

class CSquare : public CRectangle
{
public:
	CSquare(int side, int color);
};

class CPicture
{
public:
	CShape* picture[4];
};
