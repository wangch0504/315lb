#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

struct student_info {
    int s_no;
    char name[20];
    int age;
    char sex[10];
    int birth;
    char addr[30];
    char tele[30];
    char email[30];
    struct student_info *next;
};

void menue(void);
int info_input(void);
int info_review(void);
int info_search(void);

int main(void)
{
    menue();

    return 0;
}

void menue(void)
{
    int choose;

    system("clear");

    printf("-------------学生信息管理系统---------------\n");
    printf("\t\t1. 学生信息录入\n");
    printf("\t\t2. 学生信息浏览\n");
    printf("\t\t3. 学生信息查询\n");
    printf("\t\t4. 学生信息的删除与修改\n");
    printf("\t\t0. 退出系统\n");
    printf("--------------------------------------------\n");

    printf("请输入您的选择(0~~4): ");
    scanf("%d", &choose);

    switch (choose) {
        case 0:
            exit(0);
            break;
        case 1:
            info_input();
            break;
        case 2:
            info_review();
            break;
        case 3:
            info_search();
            break;
    }

    while (choose > 4 || choose < 1) {
        printf("您输入了一个无效的选择，请重新输入(0-4): ");
        scanf("%d", &choose);
    }

}

/*
    ssize_t read(int fd, void *buf, size_t count);
    ssize_t write(int fd, const void *buf, size_t count);
    int open(const char *pathname, int flags, mode_t mode);

    FILE *fopen(const char *path, const char *mode);
    size_t fwrite(const void *ptr, size_t size, size_t nmemb,
              FILE *stream);
*/

int creat_list(void)
{
    return 0;
}

// 1. 学生信息录入
int info_input(void)
{
    struct student_info *head = NULL, *rear = NULL;
    FILE *fp;
    int flag = 1;

    head = (struct student_info *)malloc(sizeof(struct student_info));
    rear = head;

    while (flag) {
        struct student_info *stu = NULL;

        stu = (struct student_info *)malloc(sizeof(struct student_info));

        // FILE *fopen(const char *path, const char *mode);
        fp = fopen("stuinfo.txt", "a+b");
        fseek(fp, sizeof(struct student_info), 2);


        system("clear");
        printf("-----请依次输入学生的信息-----\n");



        printf("学号: ");
        scanf("%d", &stu->s_no);

        printf("姓名: ");
        scanf("%s", stu->name);

        printf("年龄: ");
        scanf("%d", &stu->age);

        printf("性别: ");
        scanf("%s", stu->sex);

        printf("出生年月: ");
        scanf("%d", &stu->birth);

        printf("地址: ");
        scanf("%s", stu->addr);

        printf("电话: ");
        scanf("%s", stu->tele);

        printf("E-mail: ");
        scanf("%s", stu->email);

        fwrite(stu, sizeof(struct student_info), 1, fp);

        rear->next = stu;
        rear = stu;

        fclose(fp);

        printf("继续输入请按1，返回上一级菜单请按2，退出请按0: ");
        scanf("%d", &flag);

        if (flag == 0) {
            exit(0);
        }

        if (flag == 1) {
            continue;
        }

        if (flag == 2) {
            menue();
            break;
        }
    }

    rear->next = NULL;

    return 0;
}

// 2. 学生信息浏览
// size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
int info_review(void)
{
    struct student_info stu;

    int ret = 1;
    int flag = 0;

    FILE *fp = fopen("stuinfo.txt", "rb");
    //int fd = open("stuinfo.txt", O_RDONLY);


    if (fp == NULL) {
        perror("fopen");
        exit(0);
    }

    while (ret != 0) {   /*返回值为1时表示读取的字节数不足sizeof(struct student_info), 返回0表示读取成功*/
        /*  */
        ret = fread(&stu, sizeof(struct student_info), 1, fp);
        //read(fd, stdout, sizeof(struct student_info));

        printf("------------------------------------------------------------------------------------------------------\n");
        printf("%d\t%s\t%d\t%s\t%d\t%s\t%s\t%s\n", stu.s_no, stu.name, stu.age, stu.sex, stu.birth, stu.addr, stu.tele, stu.email);
    }

    fclose(fp);
    printf("=====================^-^=====================   ====================^-^==================\n");

    printf("退出请按0, 返回上一级菜单请按1: ");
    scanf("%d", &flag);

    if (flag == 0) {
        exit(0);
    }

    if (flag == 1) {
        menue();
        exit(0);
    }

    return 0;
}

// 学生信息查询

int info_search(void) 
{
    system("clear");

    struct student_info *stu1 = NULL, *stu2 = NULL;
    stu1 = (struct student_info *)malloc(sizeof(struct student_info));
    stu2 = (struct student_info *)malloc(sizeof(struct student_info));

    int ret = 1, i = 0, flag = 1;

    FILE *fp = fopen("stuinfo.txt", "rb");

    printf("=====按姓名查询请输入1, 按学号查询请输入2=====\n");
    scanf("%d", &i);

    while (flag) {
        if (i == 1) {
            printf("请输入学生的姓名: ");
            scanf("%s", stu1->name);

            do {
                if (ret == 0) {
                    printf("没有这个人哦^*^\n");
                    exit(0);
                }
                ret = fread(stu2, sizeof(struct student_info), 1, fp);
            } while (strcmp(stu1->name, stu2->name));

            printf("您要找的人信息如下: \n");
            printf("%d\t%s\t%d\t%s\t%d\t%s\t%s\t%s\n", stu2->s_no, stu2->name, stu2->age, stu2->sex, stu2->birth, stu2->addr, stu2->tele, stu2->email);
        }

        if (i == 2) {
            printf("请输入学生的学号: ");
            scanf("%d", stu1->s_no);

            do {
                if (ret == 0) {
                    printf("没有这个人哦^*^\n");
                    exit(0);
                }
                ret = fread(stu2, sizeof(struct student_info), 1, fp);
            } while (stu2->s_no != stu1->s_no);

            printf("您要找的人信息如下: \n");
            printf("%d\t%s\t%d\t%s\t%d\t%s\t%s\t%s\n", stu2->s_no, stu2->name, stu2->age, stu2->sex, stu2->birth, stu2->addr, stu2->tele, stu2->email);
        }

        printf("=====继续查询请按1，返回上一级菜单请按2=====\n");
        scanf("%d", &flag);

        if (flag == 1)
            continue;
        if (flag == 2) {
            menue();
            break;
        }
    }
    return 0;

}

// 学生信息删除

int info_delete(void)
{

}

// 学生信息修改
int info_alter(void)
{

}
