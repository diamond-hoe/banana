#include "DrawPad.hpp"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RandomColor()
{
    int r = random() % 256;
    int g = random() % 256;
    int b = random() % 256;
    return ((r << 16) | (g << 8) | b);
}

void DrawMain()
{
    // 乱数の初期化
    srandom((unsigned)time(NULL));
    
    // モデルの初期化
    double x[10] = {};  // 初期値を書かなければすべて0で初期化
    double y[10] = {};  // 初期値を書かなければすべて0で初期化
    double vx[10];
    double vy[10];
    int colors[10];
    for (int i = 0; i < 10; i++) {
        double angle = ((random() % 201) / 100.0) * M_PI;
        vx[i] = cos(angle) * 8;
        vy[i] = sin(angle) * 8;
        colors[i] = RandomColor();
    }

    // ループ処理
    while (true) {
        // 描画の処理
        StartBatch();
        Clear(kColorBlack);
        for (int i = 0; i < 10; i++) {
            FillCircle(x[i], y[i], 20, colors[i]);
        }
        EndBatch();

        // モデルの変更
        for (int i = 0; i < 10; i++) {
            if (x[i] + vx[i] < -310 || x[i] + vx[i] > 309) {
                vx[i] *= -1;
            }
            x[i] += vx[i];

            if (y[i] + vy[i] < -230 || y[i] + vy[i] > 229) {
                vy[i] *= -1;
            }
            y[i] += vy[i];
        }

        // 一時休止
        Sleep(0.0167);
    }
}

