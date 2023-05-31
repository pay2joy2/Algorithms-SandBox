                                                                          //СОРТИРОВКА ПО УБЫВАНИЮ
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <io.h>
using namespace std;
int main() {
FILE* file1, * file2, * output;
file1 = fopen("file1.dat","rb");
file2 = fopen("file2.dat", "rb");
output = fopen("output.txt", "w");
int num1, num2;
int count1 = 0;
int count2 = 0;
while (!feof(file1))
{
fread(&num1, sizeof(int), 1, file1);
if (feof(file1))
break;
count1++;
}
while (!feof(file2))
{
fread(&num2, sizeof(int), 1, file2);
if (feof(file2))
break;
count2++;
}
int counter;
count1 = count1 * 4;
count2 = count2 * 4;
if (count1 >= 8)
{
count1 = count1 - 4;
}
if (count2 >= 8) {
count2 = count2 - 4;
}
bool check = false;
while (count1 != 0 || count2 != 0)
{
if (num1 < num2)
{
fprintf(output, "%d ", num1);
fseek(file1, count1 = (count1 - 4), SEEK_SET);
fread(&num1, sizeof(int), 1, file1);
if (count1 == 0)
{
fprintf(output, "%d ", num1);
if (check == true)
{
fseek(file2, count2 = (count2 + 4), SEEK_SET);
check = false;
}
while (count2 != 0)
{
fseek(file2, count2 = (count2 - 4), SEEK_SET);
fread(&num2, sizeof(int), 1, file2);
fprintf(output, "%d ", num2);
}
}
}
else if (num1 == num2)
{
fprintf(output, "%d ", num1);
fprintf(output, "%d ", num2);
fseek(file1, count1 = (count1 - 4), SEEK_SET);
fseek(file2, count2 = (count2 - 4), SEEK_SET);
fread(&num1, sizeof(int), 1, file1);
fread(&num2, sizeof(int), 1, file2);
check = true;
}
else if (num1 > num2)
{
fprintf(output, "%d ", num2);
fseek(file2, count2 = (count2 - 4), SEEK_SET);
fread(&num2, sizeof(int), 1, file2);
if (count2 == 0)
{
fprintf(output, "%d ", num2);
if (check == true)
{
fseek(file2, count2 = (count2 + 4), SEEK_SET);
check = false;
}
while (count1 != 0)
{
fseek(file1, count1 = (count1 - 4), SEEK_SET);
fread(&num1, sizeof(int), 1, file1);
fprintf(output, "%d ", num1);
}
}
}
}
fclose(file1);
fclose(file2);
fclose(output);
return 0;
}
                                                                //СОРТИРОВКА ПО ВОЗРАСТАНИЮ
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <io.h>
int main() {
 FILE* file1, * file2,* output;
 file1 = fopen("file1.dat", "rb");
 file2 = fopen("file2.dat", "rb");
 output = fopen("output.txt", "w");
 int num1, num2;
 fread(&num1, sizeof(int), 1, file1);
 fread(&num2, sizeof(int), 1, file2);
 while (!feof(file1) || !feof(file2)) {
 if (feof(file1) || num1 < num2) {

 fprintf(output, "%d ", num2);
 fread(&num2, sizeof(int), 1, file2);
 if (feof(file2))
 {
 fprintf(output, "%d ", num1);
 while (fread(&num1, sizeof(int), 1, file1))
 {
 fprintf(output, "%d ", num1);
 }
 }
 }
 else if (feof(file2) || num1 >= num2) {
 fprintf(output, "%d ", num1);
 fread(&num1, sizeof(int), 1, file1);
 if (feof(file1))
 {
 fprintf(output, "%d ", num2);
 while (fread(&num2, sizeof(int), 1, file2))
 {
 fprintf(output, "%d ", num2);
 }
 }
 }
 }
 fclose(file1);
 fclose(file2);
 fclose(output);
return 0;
}
