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

    int x_rot = 0;
    int y_rot = 0;
    int z_rot = 0;

    Cube();
    void update();
    void rotate();
    void getRelations();
    ~Cube();
};