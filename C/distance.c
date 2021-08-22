// distance.c
// It accepts the distance between two cities
// in km and prints distance in m and cm
// Author: Adarsh, Date: 06/09/2020

# include <stdio.h>

int main()
{
    float dist_km, dist_m, dist_cm;

    printf("Enter the distance in km:\n");
    scanf("%f", &dist_km);

    dist_m = dist_km * 1000;
    dist_cm = dist_m * 100;

    printf("\nDistance in km: %f km\n", dist_km);
    printf("Distance in m: %f m\n", dist_m);
    printf("Distance in cm: %f cm\n", dist_cm);

    return 0;
}
