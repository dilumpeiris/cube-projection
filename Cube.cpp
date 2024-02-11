#include <iostream>
#include "math.h"
#include "Cube.h"

Cube::Cube()
{
    int half = (int)length / 2;
    int rel[12][2][3];

    int x = center[0];
    int y = center[1];
    int z = center[2];

    points[0][0] = x - half;
    points[0][1] = y + half;
    points[0][2] = z + half;

    points[1][0] = x + half;
    points[1][1] = y + half;
    points[1][2] = z + half;

    points[2][0] = x + half;
    points[2][1] = y - half;
    points[2][2] = z + half;

    points[3][0] = x - half;
    points[3][1] = y - half;
    points[3][2] = z + half;

    points[4][0] = x - half;
    points[4][1] = y + half;
    points[4][2] = z - half;

    points[5][0] = x + half;
    points[5][1] = y + half;
    points[5][2] = z - half;

    points[6][0] = x + half;
    points[6][1] = y - half;
    points[6][2] = z - half;

    points[7][0] = x - half;
    points[7][1] = y - half;
    points[7][2] = z - half;

    std::copy(&points[0][0], &points[0][0] + 3 * 8, &pointsP[0][0]);
    std::copy(&points[0][0], &points[0][0] + 3 * 8, &pointsR[0][0]);
}

void Cube::getRelations()
{

    rel[0][0][0] = pointsP[0][0];
    rel[0][0][1] = pointsP[0][1];
    rel[0][0][2] = pointsP[0][2];

    rel[0][1][0] = pointsP[1][0];
    rel[0][1][1] = pointsP[1][1];
    rel[0][1][2] = pointsP[1][2];

    rel[1][0][0] = pointsP[1][0];
    rel[1][0][1] = pointsP[1][1];
    rel[1][0][2] = pointsP[1][2];

    rel[1][1][0] = pointsP[2][0];
    rel[1][1][1] = pointsP[2][1];
    rel[1][1][2] = pointsP[2][2];

    rel[2][0][0] = pointsP[2][0];
    rel[2][0][1] = pointsP[2][1];
    rel[2][0][2] = pointsP[2][2];

    rel[2][1][0] = pointsP[3][0];
    rel[2][1][1] = pointsP[3][1];
    rel[2][1][2] = pointsP[3][2];

    rel[3][0][0] = pointsP[3][0];
    rel[3][0][1] = pointsP[3][1];
    rel[3][0][2] = pointsP[3][2];

    rel[3][1][0] = pointsP[0][0];
    rel[3][1][1] = pointsP[0][1];
    rel[3][1][2] = pointsP[0][2];

    rel[4][0][0] = pointsP[4][0];
    rel[4][0][1] = pointsP[4][1];
    rel[4][0][2] = pointsP[4][2];

    rel[4][1][0] = pointsP[5][0];
    rel[4][1][1] = pointsP[5][1];
    rel[4][1][2] = pointsP[5][2];

    rel[5][0][0] = pointsP[5][0];
    rel[5][0][1] = pointsP[5][1];
    rel[5][0][2] = pointsP[5][2];

    rel[5][1][0] = pointsP[6][0];
    rel[5][1][1] = pointsP[6][1];
    rel[5][1][2] = pointsP[6][2];

    rel[6][0][0] = pointsP[6][0];
    rel[6][0][1] = pointsP[6][1];
    rel[6][0][2] = pointsP[6][2];

    rel[6][1][0] = pointsP[7][0];
    rel[6][1][1] = pointsP[7][1];
    rel[6][1][2] = pointsP[7][2];

    rel[7][0][0] = pointsP[7][0];
    rel[7][0][1] = pointsP[7][1];
    rel[7][0][2] = pointsP[7][2];

    rel[7][1][0] = pointsP[4][0];
    rel[7][1][1] = pointsP[4][1];
    rel[7][1][2] = pointsP[4][2];

    rel[8][0][0] = pointsP[0][0];
    rel[8][0][1] = pointsP[0][1];
    rel[8][0][2] = pointsP[0][2];

    rel[8][1][0] = pointsP[4][0];
    rel[8][1][1] = pointsP[4][1];
    rel[8][1][2] = pointsP[4][2];

    rel[9][0][0] = pointsP[1][0];
    rel[9][0][1] = pointsP[1][1];
    rel[9][0][2] = pointsP[1][2];

    rel[9][1][0] = pointsP[5][0];
    rel[9][1][1] = pointsP[5][1];
    rel[9][1][2] = pointsP[5][2];

    rel[10][0][0] = pointsP[2][0];
    rel[10][0][1] = pointsP[2][1];
    rel[10][0][2] = pointsP[2][2];

    rel[10][1][0] = pointsP[6][0];
    rel[10][1][1] = pointsP[6][1];
    rel[10][1][2] = pointsP[6][2];

    rel[11][0][0] = pointsP[3][0];
    rel[11][0][1] = pointsP[3][1];
    rel[11][0][2] = pointsP[3][2];

    rel[11][1][0] = pointsP[7][0];
    rel[11][1][1] = pointsP[7][1];
    rel[11][1][2] = pointsP[7][2];
}

void Cube::update()
{
    for (size_t i = 0; i < 8; i++)
    {
        int x = pointsR[i][0];
        int y = pointsR[i][1];
        int z = pointsR[i][2];

        int new_x = (int)(400 * ((double)(x + x_pos) / (double)(600 - z)));
        int new_y = (int)(400 * ((double)(y + y_pos) / (double)(600 - z)));

        printf("%d \n", new_x);

        pointsP[i][0] = new_x;
        pointsP[i][1] = new_y;
        pointsP[i][2] = z;
    }
}
void Cube::rotateX(int x, int y)
{
    double x_rot = (double)x / 100;
    double y_rot = (double)y / 100;

    for (size_t i = 0; i < 8; i++)
    {
        double x = (double)points[i][0];
        double y = (double)points[i][1];
        double z = (double)points[i][2];

        double new_x = (double)x * cos(x_rot) - (double)y * sin(x_rot);
        double new_y = (double)x * sin(x_rot) + (double)y * cos(x_rot);

        double newest_x = (double)new_x * cos(y_rot) + (double)z * sin(y_rot);
        double new_z = -(double)new_x * sin(y_rot) + (double)z * cos(y_rot);

        pointsR[i][0] = (int)newest_x;
        pointsR[i][1] = (int)new_y;
        pointsR[i][2] = (int)new_z;
    }
}
Cube::~Cube()
{
}
