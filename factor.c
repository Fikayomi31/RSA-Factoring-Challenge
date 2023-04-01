#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    // Check that a file argument was provided
    if (argc != 2) {
        printf("Usage: factors <file>\n");
        return 1;
    }
    
    // Open the input file
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: unable to open file %s\n", argv[1]);
        return 1;
    }
    
    // Loop through each line in the file and factorize the numbers
    char line[1024];
    while (fgets(line, 1024, fp)) {
        // Parse the input number
        long long n = strtoll(line, NULL, 10);
        
        // Find the factors of the number
        for (long long i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                printf("%lld=%lld*%lld\n", n, i, n / i);
                break;
            }
        }
    }
    
    // Close the input file
    fclose(fp);
    
    return 0;
}

