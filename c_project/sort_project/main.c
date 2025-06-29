#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> // 需要此头文件以控制光标

// --- 游戏设置 ---
#define WIDTH 40
#define HEIGHT 20

// --- 全局变量 ---
int gameOver;
int x, y;           // 蛇头坐标
int fruitX, fruitY; // 食物坐标
int score;
int tailX[100], tailY[100];
int nTail;
// 新增变量，用于记录蛇尾最后一格的旧位置，以便擦除它
int oldTailX, oldTailY;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
enum eDirection dir;
HANDLE hConsole; // 控制台句柄

// --- 函数声明 ---
void gotoxy(int x, int y);
void Setup();
void Draw();
void Input();
void Logic();

// --- 主函数 ---
int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        // 可以适当调整Sleep时间来改变游戏速度
        Sleep(80);
    }
    gotoxy(0, HEIGHT + 2); // 将光标移动到游戏区域下方
    printf("Game Over! Your score: %d\n", score);
    return 0;
}

/**
 * @brief 将光标移动到控制台的指定位置 (x, y)
 * @param x 列坐标
 * @param y 行坐标
 */
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
}

/**
 * @brief 初始化游戏状态 (重写)
 */
void Setup()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 获取控制台句柄
    // 隐藏光标，让画面更干净
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(hConsole, &cursor_info);

    gameOver = 0;
    dir = STOP;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
    nTail = 0;

    // --- 只在Setup中绘制一次静态内容 ---
    system("cls"); // 开始前清一次屏即可

    // 绘制上下边框
    for (int i = 0; i < WIDTH + 2; i++)
    {
        gotoxy(i, 0);
        printf("#");
        gotoxy(i, HEIGHT + 1);
        printf("#");
    }
    // 绘制左右边框
    for (int i = 0; i < HEIGHT + 1; i++)
    {
        gotoxy(0, i);
        printf("#");
        gotoxy(WIDTH + 1, i);
        printf("#");
    }

    // 初始绘制食物
    gotoxy(fruitX + 1, fruitY + 1);
    printf("o");
}

/**
 * @brief 绘制游戏界面 (重写为增量更新)
 */
void Draw()
{
    // 1. 绘制新的蛇头
    gotoxy(x + 1, y + 1);
    printf("@");

    // 2. 如果蛇在移动，将旧的蛇头位置绘制成身体
    if (nTail > 0)
    {
        gotoxy(tailX[0] + 1, tailY[0] + 1);
        printf("@");
    }

    // 3. 擦除蛇尾的最后一格
    // 只有当蛇移动了（dir != STOP）并且有尾巴时才擦除
    if (dir != STOP)
    {
        gotoxy(oldTailX + 1, oldTailY + 1);
        printf(" ");
    }

    // 4. 更新分数显示
    gotoxy(0, HEIGHT + 2);
    printf("Score: %d", score);
}

/**
 * @brief 处理用户输入 (无变化)
 */
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            if (dir != RIGHT)
                dir = LEFT;
            break;
        case 'd':
            if (dir != LEFT)
                dir = RIGHT;
            break;
        case 'w':
            if (dir != DOWN)
                dir = UP;
            break;
        case 's':
            if (dir != UP)
                dir = DOWN;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}

/**
 * @brief 更新游戏逻辑 (微调)
 */
void Logic()
{
    // 记录移动前蛇尾的最后一格坐标
    if (nTail > 0)
    {
        oldTailX = tailX[nTail - 1];
        oldTailY = tailY[nTail - 1];
    }
    else
    { // 如果没有尾巴，就记录当前蛇头位置，因为蛇头移动后这里需要被清空
        oldTailX = x;
        oldTailY = y;
    }

    // 1. 更新蛇身位置 (逻辑和之前一样)
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    if (nTail > 0)
    {
        tailX[0] = x;
        tailY[0] = y;
    }
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // 2. 根据方向更新蛇头位置 (逻辑和之前一样)
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    // 3. 碰撞检测 (有微调，撞墙现在是撞到边界内)
    if (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0)
    {
        gameOver = 1;
    }
    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = 1;
        }
    }

    // 4. 吃食物检测
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        nTail++;
        // 重新生成食物并立即绘制
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        gotoxy(fruitX + 1, fruitY + 1);
        printf("o");
    }
}