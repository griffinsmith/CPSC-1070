#include <stdio.h>
#include <math.h>

int main()
{
double sides, rad;
printf("Enter sides: ");
scanf("%lf", &sides);  
printf("Enter radius (in): ");
scanf("%lf", &rad);

double degrees, radians;
degrees=360/sides;
radians=degrees*M_PI/180;
printf("Angle is %.2lf radians (%.2lf degrees)\n", radians, degrees);

double a=rad;
double b=rad;
double sideLength,sideHeight;
sideLength=(a*a)+(b*b)-((2*a*b)*(cos(radians)));
sideHeight=sqrt(sideLength);
printf("Side is: %.2lf inches\n", sideHeight);

double perimeter, perimeterFeet;
perimeter=sideHeight*sides;
perimeterFeet=perimeter/12;
printf("Perimeter is %.2lf inches and %.2lf feet.\n", perimeter, perimeterFeet);
    return 0;
}


