//
// Created by alexey on 17.10.16.
//


#include <stdio.h>
#include <fcntl.h>
#include <zconf.h>
#include <errno.h>

#define BUF_SIZE 8192

int main(int argc, char *argv[]) {
    fprintf(stdout, "Обработка запроса начата\n");

    int fd;
    const char *filename = "/home/alexey/tst.txt";
    fd = open(filename, O_RDONLY);

    if (fd == -1) {
        fprintf(stdout, "Ошибка файла\n");
    }

    char buffer[BUF_SIZE];
    ssize_t ret_in;
    ssize_t  ret_out;

    int out_file_id = open("/home/alexey/out.txt" , O_WRONLY|O_CREAT , 0777);


    while (BUF_SIZE != 0 && (ret_in = read(fd, &buffer, BUF_SIZE)) > 0) {

        if (ret_in == -1) {
            perror("Ошибка считывания файла");
            return 4;
        }
        printf(buffer);

        ret_out =  write(out_file_id , &buffer , ret_in );

        if(ret_out ==-1) {

            if(errno == EBADF) {
                printf("Ошибка записи - не верный дескриптор файла");
            }

        }
        fsync(out_file_id);

    }
    close(fd);
    close(out_file_id);


    return 0;
};