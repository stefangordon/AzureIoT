// Experimenting with trying to redefine these here, no luck yet.  Source is sdk/iot_logging

#define LogUsage //(void)printf
#define LogInfo(...) //(void)printf("Info: " __VA_ARGS__)
#define LogError(FORMAT, ...) //{ time_t t = time(NULL); (void)fprintf(stderr,"Error: Time:%.24s 
