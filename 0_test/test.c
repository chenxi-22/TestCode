#include <stdio.h>
#include <string.h>

int main()
{
    char* str[10];
    char buf[100] = {0};
    scanf("%s",buf);

    char* ptr = strtok(buf," ");

    while(ptr != NULL) {
        ptr = strtok(NULL," ");
        str[0] = ptr;
    }

    printf("%s\n",str[0]);

    return 0;
}
//
////
//#include <stdio.h>
//#include <unistd.h>
//#include <string.h>
//
//int main()
//{
//    const char* msg0 = "hello prntf\n";
//    const char* msg1 = "hello fwrite";
//    const char* msg2 = "hello write\n";
//
//    printf("%s",msg0);
//    fwrite(msg1,strlen(msg1),1,stdout);
//    write(1,msg2,strlen(msg2));
//
//
//    fork();
//
//    return 0;
//}
//
//int main()
//{
//    close(1);
//    int fd = open("myfile",O_WRONLY|O_CREAT, 00644);
//    if(fd < 0)
//    {
//        perror("open");
//        return 1;
//    }
//    printf("fd: %d\n",fd);
//    fflush(stdout);
//
//    close(fd);
//
//    return 0;
//}
//
//#include <stdio.h>
//#include <unistd.h>
//
//#include <stdlib.h>
//
//int main()
//{
//    int ret = 0;
//
//    printf("hello world!");
//
//    ret = fork();
//
//    if(ret == -1)
//    {
//        printf("Error...\n");
//        exit(1);
//    }
//    if(ret == 0)
//    {
//        printf("i am child!\n");
//    }
//
//    return 0;
//}
//
//
//
//
////#include <stdio.h>
////#include <stdlib.h>
//
//int value = 100;
//
//int main()
//{
//    int pid = 0;
//
//    pid = vfork();
//    
//    if(pid == -1)
//    {
//        perror("fork"),exit(1);
//    }
//    if(pid == 0)
//    {
//        value = 200;
//        sleep(3);
//        printf("child value = %d\n",value);
//        exit(1);
//    }
//    else
//    {
//        printf("father value = %d\n",value);
//    }
//
//    return 0;
//}
////
////
////#include <stdio.h>
////#include <unistd.h>
////
////int main()
////{
////    int pid;
//
//    int value = 10;
//
//    pid = fork();
//
//    if(pid == 0)
//    {
//        printf("child value %p",value);
//    }
//
//    if(pid != 0)
//    {
//        printf("parents value %p",value);
//        sleep(1); 
//    }
//    if(pid == 0)
//    {
//        value = 100;
//        printf("child value %p",value);
//    }
//
//    if(pid != 0)
//    {
//        printf("parents value %p",value);
//    }
//
//
//
//    return 0;
//}
