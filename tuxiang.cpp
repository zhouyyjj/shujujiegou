#include <stdio.h>
#define M1 3    //输入图像的行号
#define N1 3 //输入图像的列号 
#define M2 3    //卷积核的行号
#define N2 3 //卷积核的列号

int f[M1][N1] = { { 1, 2, 3 }, { 1, 2, 3 }, { 1, 2, 3 } };
int w[M2][N2] = { { 2, 2, 2 }, { 1, 1, 1 }, { 3, 3, 3 } };
int g[M1 + M2 - 1][N1 + N2 - 1] = {0};
int g2[M1][N1];

void conv(int f[M1][N1], int con[M2][N2], int g[M1+M2-1][N1+N2-1])
{
    int i, j, m, n;
    for (i = 0; i < M1 + M2 - 1; i++)
    {
        for (j = 0; j < N1 + N2 - 1; j++)
        {
            float temp = 0;
            for (m = 0; m < M1; m++)
            {
                for (n = 0; n < N1; n++)
                    if ((i - m) >= 0 && (i - m)<M2 && (j - n) >= 0 && (j - n)<N2)
                        temp += f[m][n] * con[i - m][j - n];
                g[i][j] = temp;
            }
        }
    }

    for (i = 0; i < M1; i++)
    {
        for (j = 0; j < N1; j++)
        {
            g2[i][j] = g[i + (M2 - 1)/2][j + (N2 - 1) / 2];
        }
    }
}


void main(int)
{
    conv(f, w, g);
    //输出卷积的结果
    for (int i = 0; i < M1+M2-1; i++)
    {
        for (int j = 0; j < N1+N2-1; j++)
        {
            printf("%2d ", g[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    //图像处理中输出与输入维数相同的矩阵
    for (int i = 0; i < M1; i++)
    {
        for (int j = 0; j < N1; j++)
        {
            printf("%2d ", g2[i][j]);
        }
        printf("\n");
    }
    getchar();
}
