#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <io.h>
using namespace std;
int main()
{
FILE* file;
file = fopen("input.txt", "r+");
long pos = 0;
char g, a;
fseek(file, 0, SEEK_END);
long razmer = ftell(file);
rewind(file);
while (!feof(file))
{
int cifr = 0;
int sum = 0;
bool check = false;
pos = ftell(file);
g = fgetc(file);
if (g != ' ')
{
check = true;
sum = g - '0';
for(;;)
{
cifr++;
a = fgetc(file);
if (a == ' ' || feof(file))
break;
sum = sum * 10 + (a - '0');
}
}
if (sum % 2 == 0 && check == true)
{
fseek(file, pos, SEEK_SET);
for (int temp = 0; temp < cifr+1; temp++)
{
int i = pos;
while (!feof(file))
{
i++;
fseek(file, i, SEEK_SET);
char testing = fgetc(file);
if (feof(file))
{
break;
}
fseek(file, i - 1, SEEK_SET);
fputc(testing, file);
}
razmer = razmer - 1;
if (razmer <= 0)
razmer = 0;
_chsize(_fileno(file), razmer);
fseek(file, pos, SEEK_SET);
}
}
}
fclose(file);
return 0;
}
