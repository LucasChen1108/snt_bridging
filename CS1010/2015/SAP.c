# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

typedef struct {
char code[9];                              // Module code, eg: "CS1010"
int mc;                                    // Number of modular credits
char grade[3];                             // Grade
char su[6];                                // To S/U or not?
} module_t;

int readResults(module_t modules[]);
float gradeToPt(char grade[]);
float computeSAP(module_t modules[], int size);

int main(void) {
module_t modules[7];                       // A student may take up to 7 modules
int num_modules;                           // Actual number of modules he takes
float sap;                                 // Semester Aggregate Point
num_modules = readResults(modules);
sap = computeSAP(modules, num_modules);
printf("SAP = %.2f\n", sap);
return 0;
}

int readResults(module_t modules[])
{
    FILE *indata = fopen("results.inf", "r");
    if (indata == NULL) {
        printf("File open failed\n\n");
        return 1;
    }
    int size;
    fscanf(indata, "%d%*c", &size);


    for(int i = 0; i < size; i++)
    {
        fscanf(indata, "%s%*c", modules[i].code);
        modules[i].code[strcspn(modules[i].code, "\n")] = '\0';
        
        fscanf(indata, "%d%*c", &modules[i].mc);

        fscanf(indata, "%s%*c", modules[i].grade);
        modules[i].grade[strcspn(modules[i].grade, "\n")] = '\0';

        
        fscanf(indata, "%s%*c", modules[i].su);
        modules[i].su[strcspn(modules[i].su, "\n")] = '\0';
        for (int j = 0; modules[i].su[j] != '\0'; j++) 
        {
            modules[i].su[j] = toupper((unsigned char)modules[i].su[j]);
        }
    }
    return size;
}


float gradeToPt(char grade[])
{
    // Declare the grade strings and corresponding point values
    char *grades[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "D+", "D", "F"};
    float pts[]    = { 5.0, 5.0, 4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0};

    int num_grades = sizeof(pts) / sizeof(pts[0]);

    // Compare input grade with known grades
    for (int i = 0; i < num_grades; i++) {
        if (strcmp(grade, grades[i]) == 0) {
            return pts[i];
        }
    }

    // If grade not found, return -1.0 to indicate error
    return -1.0;
}

float computeSAP(module_t modules[], int size)
{
    int mc_sum = 0;
    float cross = 0.0;
    for (int i = 0; i < size; i++)
    {
        if(strcmp(modules[i].su, "TRUE") != 0)
        {
            cross += (modules[i].mc * gradeToPt(modules[i].grade));
            mc_sum += modules[i].mc;
        }
    }
    return cross / (float) mc_sum;
}

