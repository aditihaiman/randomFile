#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>




int randNum(){
    int fd = open("/dev/random", O_RDONLY);
    int buff[1];
    int bytesRead = read(fd, buff, sizeof(int));
    //printf("bytesRead: %d\n", bytesRead);
    return buff[0];
}


int main(){
    printf("Generating random numbers\n");
    int rands[10];
    for(int a = 0; a < 10; a++){
        rands[a] = randNum();
        printf("random 0: %d\n", rands[a]);
    }
    //char test[10] = "hello";
    printf("Writing numbers to file\n");
    int output = open("output.txt", O_WRONLY);
    int bytes = write(output, rands, 40);
    printf("bytes written: %d\n", bytes);
    //printf("output fd: %d\n", output);

    printf("Reading numbers from file\n");
    int verify[10];
    output = open("output.txt", O_RDONLY);
    bytes = read(output, verify, 40);
    
    printf("bytes read: %d\n", bytes);

    
    printf("Verifying numbers:\n");
    for(int a = 0; a < 10; a++){
        printf("random 0: %d\n", verify[a]);
    }
    //int x = randNum();
    return 0;
}
