#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Represents a 2-D cartesian point.
 *
 */
typedef struct {
  double x;
  double y;
} point_t;

/**
 * @brief Represents a path on a 2-D plane.
 *
 */
typedef struct {
  point_t *points; // dynamic array of points
  int count;       // number of points on the path
} path_t;

/**
 * @brief Returns the distance between the given two 2D points using the
 * distance formula d((x1,y1), (x2,y2)) = sqrt((x1-x2)^2 + (y1-y2)^2).
 *
 */
double distance(point_t *p1, point_t *p2) {
  return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

/**
 * @brief Creates and returns a path_t object from the user input
 * (the number of points followed by the (x, y) coordinates of
 * each point).
 *
 */
path_t *get_path() {
  path_t *p = malloc(sizeof(path_t));
  scanf(" %d", &p->count);
  p->points = malloc(sizeof(point_t) * p->count);
  for (int i = 0; i < p->count; i++) {
    scanf("%lf %lf", &p->points[i].x, &p->points[i].y);
  }

  return p;
}

/**
 * @brief Display the given path as a comma-separated sequence of points.
 *
 */
void display_path(path_t *p) {
  // TODO Implement the function
  printf("[");
  for (int i = 0; i < p->count; i++) {
    printf("(%.2lf,%.2lf)", p->points[i].x, p->points[i].y);
    if (i != p->count - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

/**
 * @brief Computes the total distance of the path from the starting point to the
 * last one.
 *
 */
double path_distance(path_t *p) {
  double total = 0;
  for (int i = 0; i < p->count - 1; i++) {
    total += distance(&p->points[i], &p->points[i + 1]);
  }
  return total;
}

int main() {
  printf("Enter the number of points along the path (at least two), followed "
         "by the x,y coordinates of each point:\n");
  path_t *path = get_path();
  printf("This program supports two operations:\n");
  printf("\t1. Display the given path\n");
  printf("\t2. Compute the total distance\n");
  printf("Enter your choice: ");
  int option;
  scanf("%d", &option);
  if (option == 1) {
    printf("Given path: ");
    display_path(path);
  } else if (option == 2) {
    printf("Total distance: %.2lf\n", path_distance(path));
  }

  return 0;
}
