#include<stdio.h>
#include<string.h>
#include<stdlib.h>

double convert_lat_to_float(char *latitude_string)
{
		float latitude_float;
    latitude_float = strtod(latitude_string,NULL);
    return latitude_float;
}



double convert_lon_to_float(char *longitude_string)
{
		float longitude_float;
    longitude_float = strtod(longitude_string,NULL);
    return longitude_float;
} 

