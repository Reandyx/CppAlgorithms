/*
1 3
6 8
10 10
-1  0  0  0  0 -1  0 -1 -1 -1
-1  0 -1  0  0  0 -1  0  0 -1
-1 -1  0 -1  0  0 -1 -1  0 -1
-1  0  0 -1  0 -1 -1  0  0 -1
-1 -1  0 -1  0  0 -1 -1 -1  0
 0 -1 -1 -1  0  0  0  0 -1  0
 0  0  0 -1 -1 -1  0  0 -1  0
 0 -1  0 -1  0 -1  0 -1 -1  0
 0 -1  0 -1 -1 -1  0  0 -1  0
 0  0  0  0 -1 -1 -1 -1 -1  0
*/

#include "graphics.h"
#include <fstream>
#include <queue>
#define DMAX 20

using namespace std;

typedef int Labirint[DMAX][DMAX];
Labirint L;

queue < pair <int, int> > C;
pair <int, int> ps, pf, tableTopLeftCorner, tableBottomRightCorner;

int dl[] = { -1, 0, 1,  0 };
int dc[] = { 0, 1, 0, -1 };
int N, M;

const int screenWidth = 1024;
const int screenHeight = 700;
const int tableSquare = 60;

pair <int, int> getSquareXYByLC(int l, int c)
{
    return make_pair(tableTopLeftCorner.first + (c - 1) * tableSquare + 1, tableTopLeftCorner.second + (l - 1) * tableSquare + 1);
}

void drawSquareByXY(pair <int, int> point, int color)
{
    setfillstyle(SOLID_FILL, color);
    bar(point.first, point.second, point.first + tableSquare - 1, point.second + tableSquare - 1);
}

void squareTextXY(pair <int, int> point, int value)
{
    char* s;
    sprintf(s, "%d", value);

    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(15);
    outtextxy(point.first + tableSquare / 2, point.second + tableSquare / 2, s);
}

void drawTable()
{
    int tableWidth = M * tableSquare;
    int tableHeight = N * tableSquare;
    tableTopLeftCorner = make_pair(getmaxx() / 2 - tableWidth / 2, getmaxy() / 2 - tableHeight / 2);
    tableBottomRightCorner = make_pair(tableTopLeftCorner.first + tableWidth, tableTopLeftCorner.second + tableHeight);

    rectangle(tableTopLeftCorner.first, tableTopLeftCorner.second, tableBottomRightCorner.first, tableBottomRightCorner.second);
    for (int i = 1; i < N; i++)
        line(tableTopLeftCorner.first, tableTopLeftCorner.second + i * tableSquare, tableBottomRightCorner.first, tableTopLeftCorner.second + i * tableSquare);
    for (int i = 1; i < M; i++)
        line(tableTopLeftCorner.first + i * tableSquare, tableTopLeftCorner.second, tableTopLeftCorner.first + i * tableSquare, tableBottomRightCorner.second);

    drawSquareByXY(getSquareXYByLC(ps.first, ps.second), 4);        //punctul de start colorat cu rosu
    drawSquareByXY(getSquareXYByLC(pf.first, pf.second), 2);        //punctul final colorat cu verde

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (L[i][j] == -1)
                drawSquareByXY(getSquareXYByLC(i, j), 15);
}

void lee()
{
    pair <int, int> pc, v;
    int prim = 0, ultim = 0, i;

    C.push(ps);
    L[ps.first][ps.second] = 1;

    squareTextXY(getSquareXYByLC(ps.first, ps.second), L[ps.first][ps.second]);
    delay(1000);

    while (!C.empty() && L[pf.first][pf.second] == 0)
    {
        pc = C.front(); C.pop();
        for (i = 0; i < 4; i++)
        {
            v.first = pc.first + dl[i];
            v.second = pc.second + dc[i];
            if (L[v.first][v.second] == 0)
            {
                L[v.first][v.second] = L[pc.first][pc.second] + 1;
                C.push(v);

                squareTextXY(getSquareXYByLC(v.first, v.second), L[v.first][v.second]);
                delay(1000);
            }
        }
    }
}

void readData()
{
    ifstream f("lee.in");
    f >> ps.first >> ps.second;
    f >> pf.first >> pf.second;
    f >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            f >> L[i][j];

    f.close();
}

void bordMatrix()
{
    for (int j = 0; j <= M + 1; j++)
        L[0][j] = L[N + 1][j] = -1;

    for (int i = 0; i <= N + 1; i++)
        L[i][0] = L[i][M + 1] = -1;
}

int main(void)
{
    /* initialize graphics window at 800 x 600 */
    initwindow(screenWidth, screenHeight);

    readData();
    bordMatrix();
    drawTable();
    lee();

    /* clean up */
    getch();
    closegraph();

    return 0;
}