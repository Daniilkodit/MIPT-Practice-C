#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "u_template.h"
/*
Problem TS -- площадь треугольника
Вам заранее задан тип данных треугольника
struct point_t {
  int x, y;
};
struct triangle_t {
  struct point_t pts[3];
}
Ваша задача написать функцию с заданным наперёд именем double_area,
которая возвращает его удвоенную площадь
int double_area(struct triangle_t tr);
*/

int double_area(struct triangle_t tr)
{
    return abs(tr.pts[1].x * tr.pts[2].y + tr.pts[2].x * tr.pts[0].y + tr.pts[0].x * tr.pts[1].y - tr.pts[1].x * tr.pts[0].y - tr.pts[0].x * tr.pts[2].y - tr.pts[2].x * tr.pts[1].y); 
}