#include "Walker.h"
#include <iostream>
#include <random>
#include <array>
#include <vector>

using namespace std;

// 시드값을 얻기 위한 random_device 생성.
random_device rd;

// random_device 를 통해 난수 생성 엔진을 초기화 한다.
mt19937 gen(rd());

// 0 부터 3까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
uniform_int_distribution<int> dis(0, 3);

/*
int make2DArray(int cols, int rows) {
//vector<int> arr;
//int *arr = new int(cols);
int _cols = cols;
int _rows = rows;

array<int,_cols> arr;
  for (int i = 0; i < arr.size(); i++) {
    arr[i] = new Array(rows);
  }
  return arr;
}
*/
Walker::Walker(int x, int y)
{
    _x = x;
    _y = y;
    //_x = 600;
    //_y = 400;

    cols = floor(_y / spacing);
    rows = floor(_x / spacing);
    __x = cols / 2;
    __y = rows / 2;
    //_arr[__y][__x]={0,};

    //grid = make2DArray(cols, rows);
}

void Walker::update()
{
    const int choice = dis(gen);

    switch (choice) {
    case 0:
        _x = _x + spacing;
        break;
    case 1:
        _x = _x - spacing;
        break;
    case 2:
        _y = _y + spacing;
        break;
    case 3:
        _y = _y - spacing;
        break;
    }

    _arr[_y][_x] += 1;

    switch (_arr[_y][_x])
    {
    case 0:
        color = 0x00000000;
        break;
    case 1:
        color = 0x33333333;
        break;
    case 2:
        color += 0x66666666;
        break;
    case 3:
        color = 0x99999999;
        break;
    case 4:
        color = 0xBBBBBBBB;
        break;
    case 5:
        color = 0xEEEEEEEE;
        break;
    default:
        color = 0xFFFFFFFF;
        break;
    }

}

void Walker::draw(SDL_Renderer* renderer)
{
    //circleColor(renderer, _x, _y, 10, 0xffffffff); 
    filledCircleColor(renderer, _x, _y, spacing * 0.5, color);
}
