class Cube
{
private:
    int points[8][3];
    int pointsP[8][3];
    int pointsR[8][3];

public:
    int length = 400;
    int center[3] = {0, 0, 0};
    int rel[12][2][3];

    int x_pos = 0;
    int y_pos = 0;
    int z_pos = 0;
    void update();
    void rotateX(int x, int y);
    Cube();
    void getRelations();

    ~Cube();
};