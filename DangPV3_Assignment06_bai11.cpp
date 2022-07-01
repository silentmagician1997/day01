#include "DangPV3_Assignment06_bai11.h"

using namespace std;


//**********************************************************
// Name:		CLine
// Description:	Constructor of CLine class
// Arguments:	input_length: length  of the CCircle
//            
//              input_color: color of the line
// Return:		Object CCircle.
//**********************************************************
CLine::CLine(int input_length, int input_color)
{

    length = input_length;
    color = input_color;
}

//**********************************************************
// Name:		draw
// Description:	draw CLine
// Arguments:	x: Console screen horizontal coordinates
//              y: Console screen vertical coordinates
//              device_context: Logical output device associated with physical output device 
// Return:		Object CLine.
//**********************************************************
void CLine::draw(int x, int y, HDC device_context)
{

    HPEN pen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
    SelectObject(device_context, pen);
    MoveToEx(device_context, x, y, NULL);
    LineTo(device_context, x + length, y);
}


//**********************************************************
// Name:		CCircle
// Description:	Constructor of CCircle class
// Arguments:	input_radium: radium  of the CCircle
//            
//              input_color: color of the line
// Return:		Object CCircle.
//**********************************************************
CCircle::CCircle(int input_radium, int input_color)
{
    radium = input_radium;
    color = input_color;
}

//**********************************************************
// Name:		draw
// Description:	draw CCircle
// Arguments:	x: Console screen horizontal coordinates
//              y: Console screen vertical coordinates
//              device_context: Logical output device associated with physical output device 
// Return:		Object CCircle.
//**********************************************************
void CCircle::draw(int x, int y, HDC device_context)
{
    HPEN pen = CreatePen(PS_SOLID, 4, RGB(200, 12, 212));
    SelectObject(device_context, pen);
    Ellipse(device_context, x, y, x + 2 * radium, y + 2 * radium);
}


//**********************************************************
// Name:		CRectangle
// Description:	Constructor of CRectangle class
// Arguments:	input_width: widht  of the CRectangle
//              input_height: height of the CRectangle
//              input_color: color of the line
// Return:		Object CSquare.
//**********************************************************
CRectangle::CRectangle(int input_width, int input_height, int input_color)
{
    width = input_width;
    height = input_height;
    color = input_color;
}

//**********************************************************
// Name:		draw
// Description:	draw CRectangle
// Arguments:	x: Console screen horizontal coordinates
//              y: Console screen vertical coordinates
//              device_context: Logical output device associated with physical output device 
// Return:		Object CSquare.
//**********************************************************
void CRectangle::draw(int x, int y, HDC device_context)
{
    HPEN pen = CreatePen(PS_SOLID, 4, RGB(150, 42, 100));
    SelectObject(device_context, pen);
    Rectangle(device_context, x, y, x + width, y + height);
}

//**********************************************************
// Name:		CSquare
// Description:	Constructor of CSquare class
// Arguments:	input_side: widht heaght of the Square
//              input_color: color of the line
// Return:		Object CSquare.
//**********************************************************
CSquare::CSquare(int input_side, int input_color)
{
    width = input_side;
    height = input_side;
    color = input_color;
}




int main()
{
    CPicture Picture;
    Picture.picture[0] = new CLine(300, 8000);
    Picture.picture[1] = new CCircle(100, 3000);
    Picture.picture[2] = new CRectangle(140, 80, 1500);
    Picture.picture[3] = new CSquare(70, RGB(150, 42, 100));

    HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

  
    cout << "1.Line " << endl;
    cout << "2.Circle " << endl;
    cout << "3.Rectangle " << endl;
    cout << "4.Square " << endl;

    string order;
    while (1)
{
    string order;
    cout << "Enter your numerical order (example: 1234): ";
    cin >> order;


    //Get Console To Paint
    HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    int int_input;
    for (int i = 0; i < 4; i++)
    {
        int_input = order[i] - '0';
        if (int_input < 1 || int_input > 4)
            exit(0);
 
        //Draw a shape
        Picture.picture[int_input - 1]->draw(10, 200, device_context);
    }
    cout << "Check result picture below: ";
    ReleaseDC(console_handle, device_context);
    return 0;
}
}
