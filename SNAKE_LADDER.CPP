#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <time.h>

int score1;
int score2;

void drawBoard()
{
  setcolor(8);
  rectangle(20, 20, 420, 440);
  // Horizontal lines
  for (int i = 1; i < 10; i++)
  {
    line(20, 20 + i * 42, 420, 20 + i * 42);
  }
  // vertical lines
  for (int j = 1; j < 10; j++)
  {
    line(20 + j * 40, 20, 20 + j * 40, 440);
  }

  // fill with numbers
  int num = 1;
  char str[5];
  int x = 25;
  int y = 430;
  int xd = 40;
  int yd = 42;
  int color = 1;
  for (int row = 1; row < 101; row++)
  {
    color++;
    if (color == 6 || color == 8)
    {
      color++;
    }

    setfillstyle(SOLID_FILL, color);
    floodfill(x, y, 8);

    if (color == 15)
    {
      color = 1;
    }
    setcolor(0);
    sprintf(str, "%d", num);
    outtextxy(x, y, str);

    x += xd;

    if (x < 25 || x > 385)
    {
      xd = -xd;
      y -= yd;
      if (xd > 0)
        x = 25;
      else
        x = 385;
    }

    num++;
  }
}

void drawDice(int value)
{
  setcolor(8);

  rectangle(480, 40, 570, 120);
  rectangle(479, 39, 569, 119);
  setfillstyle(SOLID_FILL, 15);
  floodfill(490, 90, 8);

  switch (value)
  {
  case 1:
    setfillstyle(SOLID_FILL, 1);
    circle(525, 80, 10);
    floodfill(525, 80, 8);
    break;
  case 2:
    setfillstyle(SOLID_FILL, 1);
    circle(500, 60, 10);
    floodfill(500, 60, 8);
    circle(550, 100, 10);
    floodfill(550, 100, 8);
    break;
  case 3:
    setfillstyle(SOLID_FILL, 1);
    circle(525, 80, 10);
    floodfill(525, 80, 8);
    circle(500, 60, 10);
    floodfill(500, 60, 8);
    circle(550, 100, 10);
    floodfill(550, 100, 8);
    break;
  case 4:
    setfillstyle(SOLID_FILL, 1);
    circle(500, 60, 10);
    floodfill(500, 60, 8);
    circle(500, 100, 10);
    floodfill(500, 100, 8);
    circle(550, 60, 10);
    floodfill(550, 60, 8);
    circle(550, 100, 10);
    floodfill(550, 100, 8);
    break;

  case 5:
    setfillstyle(SOLID_FILL, 1);
    circle(525, 80, 10);
    floodfill(525, 80, 8);
    circle(500, 60, 10);
    floodfill(500, 60, 8);
    circle(500, 100, 10);
    floodfill(500, 100, 8);
    circle(550, 60, 10);
    floodfill(550, 60, 8);
    circle(550, 100, 10);
    floodfill(550, 100, 8);
    break;
  case 6:
    setfillstyle(SOLID_FILL, 1);
    circle(500, 59, 8);
    floodfill(500, 59, 8);
    circle(500, 101, 8);
    floodfill(500, 101, 8);

    circle(500, 80, 8);
    floodfill(500, 80, 8);

    circle(550, 80, 8);
    floodfill(550, 80, 8);

    circle(550, 59, 8);
    floodfill(550, 59, 8);
    circle(550, 101, 8);
    floodfill(550, 101, 8);
    break;
    ;
  }
}

void drawSnakeLadder()
{
  // Snakes
  setfillstyle(SOLID_FILL, 6);
  fillellipse(85, 60, 5, 8);
  ellipse(85, 60, 0, 360, 5, 8);
  fillellipse(250, 140, 5, 8);
  ellipse(250, 140, 0, 360, 5, 8);
  setcolor(6);
  for (int i = 0; i < 5; i++)
  {
    arc(185, 60, 180, 270, 100 + i);
    arc(180, 265, 0, 90, 100 + i);
    arc(150, 130, 285, 350, 100 + i);
    arc(195, 330, 100, 190, 100 + i);
  }

  // Ladders
  setcolor(0);
  setlinestyle(SOLID_LINE, 0, 3);
  line(335, 380, 250, 220);
  line(320, 380, 235, 220);
  for (int j = 1; j < 10; j++)
  {
    line(315 - 8 * j, 370 - 15 * j, 330 - 8 * j, 370 - 15 * j);
  }

  line(325, 90, 375, 200);
  line(310, 90, 360, 200);
  for (int k = 0; k < 7; k++)
  {
    line(355 - 6 * k, 190 - 14 * k, 370 - 6 * k, 190 - 14 * k);
  }
}

void drawPlayer(int x, int y, int color)
{
  setcolor(BLACK);
  circle(x, y, 6);
  setfillstyle(2, color);
  floodfill(x, y, BLACK);
}
int p1x = 40, p1y = 425;

int p2x = 40, p2y = 410;

int xd1 = 40, yd1 = 42;
int xd2 = 40, yd2 = 42;

void players(int value, int turn)
{
  setcolor(BLACK);
  int inc = value;

  if (score1 + value > 100)
  {
    value = 100 - score1;
  }

  if (score2 + value > 100)
  {
    value = 100 - score2;
  }

  if (turn == 1 && score1 < 100)
  {
    for (int position = score1; position < score1 + value; position++)
    {
      p1x += xd1;

      if (p1x < 40 || p1x > 385)
      {
        xd1 = -xd1;
        p1y -= yd1;
        value--;

        if (xd1 > 0)
          p1x = 40;
        else
          p1x = 400;
      }
    }
    score1 += inc;
  }
  else if (turn == -1 && score2 < 100)
  {
    for (int position = score2; position < score2 + value; position++)
    {
      p2x += xd2;
      if (p2x < 40 || p2x > 385)
      {
        xd2 = -xd2;
        p2y -= yd2;
        value--;

        if (xd2 > 0)
          p2x = 40;
        else
          p2x = 400;
      }
    }
    score2 += inc;
  }
  // snake sliding logic
  if (p1x == 80 && p1y == 47)
  {
    p1x = 280;
    p1y = 257;
    score1 = 47;
    xd1 = -xd1;
  }
  else if (p1x == 240 && p1y == 131)
  {
    p1x = 80;
    p1y = 326;
    score1 = 22;
    xd1 = -xd1;
  }
  if (p2x == 80 && p2y == 32)
  {
    p2x = 280;
    p2y = 242;
    score2 = 47;
    xd2 = -xd2;
  }
  else if (p2x == 240 && p2y == 116)
  {
    p2x = 80;
    p2y = 341;
    score2 = 22;
    xd2 = -xd2;
  }

  // stairs logic
  if (p1x == 320 && p1y == 383)
  {
    p1x = 240;
    p1y = 215;
    score1 = 55;
    xd1 = -xd1;
  }
  else if (p1x == 360 && p1y == 215)
  {
    p1x = 320;
    p1y = 89;
    score1 = 88;
  }
  if (p2x == 320 && p2y == 368)
  {
    p2x = 240;
    p2y = 200;
    score2 = 55;
    xd1 = -xd1;
  }
  else if (p2x == 360 && p2y == 200)
  {
    p2x = 80;
    p2y = 74;
    score2 = 88;
  }

  drawPlayer(p1x, p1y, BLUE);
  drawPlayer(p2x, p2y, RED);
}

int turn = 1;

void play()
{
  srand(time(NULL));

  char ch;
  drawBoard();
  drawSnakeLadder();
  drawPlayer(p1x, p1y, BLUE);
  drawPlayer(p2x, p2y, RED);

  while (1)
  {

    kbhit();
    {
      ch = getch();

      if (ch == '\r')
      {
        if (score1 == 100)
        {
          cleardevice();
          settextstyle(1, 0, 5);
          setcolor(RED);
          outtextxy(170, 190, "Player 1 Won");
          return;
        }
        else if (score2 == 100)
        {
          cleardevice();
          settextstyle(1, 0, 5);
          setcolor(RED);
          outtextxy(170, 190, "player 2 Won");
          return;
        }
        turn = -turn;
        int number = 1 + rand() % 6;
        cleardevice();
        drawBoard();
        drawDice(number);
        drawSnakeLadder();
        players(number, turn);
      }
      else if ((int)ch == 27)
      {
        cleardevice();
        settextstyle(1, 0, 5);
        setcolor(RED);
        outtextxy(170, 190, "Game Over");
        getch();
        return;
      }
    }
  }
}

void main()
{
  int gd = DETECT, gm;

  initgraph(&gd, &gm, "C:\\turboc3\\BGI");

  settextstyle(5, 0, 4);
  setcolor(RED);
  outtextxy(120, 190, "Welcome to Snake and Ladders");
  outtextxy(170, 230, "Press any key to play!");
  getch();
  settextstyle(0, 0, 0);

  cleardevice();

  play();
  getch();
  closegraph();
}
