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

struct teacher_info {
    int t_no;
    char name[20];
    int age;
    char sex[10];
    char tele[30];
    struct teacher_info *next;
};

void s_menue(void);
void t_menue(void);
int sinfo_input(void);
int sinfo_review(void);
int sinfo_search(void);
int tinfo_input(void);
int tinfo_review(void);
int tinfo_search(void);

int main(void)
{
    int first_choose;
	printf("-------------欢迎使用师生信息管理系统---------------\n");
	printf("请选择对象：1.教师  2.学生\n");
	scanf("%d", &first_choose);
	if(first_choose==1)
	t_menue();
	else if(first_choose==2)
	s_menue();
	else if(first_choose>2)
	printf("error!");

    return 0;
}

void s_menue(void)
{
    int s_choose;

    system("clear");

    printf("-------------学生信息管理系统---------------\n");
    printf("\t\t1. 学生信息录入\n");
    printf("\t\t2. 学生信息浏览\n");
    printf("\t\t3. 学生信息查询\n");
    printf("\t\t4. 学生信息的删除与修改\n");
    printf("\t\t0. 退出系统\n");
    printf("--------------------------------------------\n");

    printf("请输入您的选择(0~~4): ");
    scanf("%d", &s_choose);

    switch (s_choose) {
        case 0:
            exit(0);
            break;
        case 1:
            sinfo_input();
            break;
        case 2:
            sinfo_review();
            break;
        case 3:
            sinfo_search();
            break;
    }

    while (s_choose > 4 || s_choose < 1) {
        printf("您输入了一个无效的选择，请重新输入(0-4): ");
        scanf("%d", &s_choose);
    }

}

void t_menue(void)
{
    int t_choose;

    system("clear");

    printf("-------------教师信息管理系统---------------\n");
    printf("\t\t1. 教师信息录入\n");
    printf("\t\t2. 教师信息浏览\n");
    printf("\t\t3. 教师信息查询\n");
    printf("\t\t4. 教师信息的删除与修改\n");
    printf("\t\t0. 退出系统\n");
    printf("--------------------------------------------\n");

    printf("请输入您的选择(0~~4): ");
    scanf("%d", &t_choose);

    switch (t_choose) {
        case 0:
            exit(0);
            break;
        case 1:
            tinfo_input();
            break;
        case 2:
            tinfo_review();
            break;
        case 3:
            tinfo_search();
            break;
    }

    while (t_choose > 4 || t_choose < 1) {
        printf("您输入了一个无效的选择，请重新输入(0-4): ");
        scanf("%d", &t_choose);
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
int sinfo_input(void)
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
            s_menue();
            break;
        }
    }

    rear->next = NULL;

    return 0;
}

int tinfo_input(void)
{
    struct teacher_info *head = NULL, *rear = NULL;
    FILE *fp;
    int flag = 1;

    head = (struct teacher_info *)malloc(sizeof(struct teacher_info));
    rear = head;

    while (flag) {
        struct teacher_info *stu = NULL;

        stu = (struct teacher_info *)malloc(sizeof(struct teacher_info));

        // FILE *fopen(const char *path, const char *mode);
        fp = fopen("stuinfo.txt", "a+b");
        fseek(fp, sizeof(struct teacher_info), 2);


        system("clear");
        printf("-----请依次输入教师的信息-----\n");



        printf("工号: ");
        scanf("%d", &stu->t_no);

        printf("姓名: ");
        scanf("%s", stu->name);

        printf("年龄: ");
        scanf("%d", &stu->age);

        printf("电话: ");
        scanf("%s", stu->tele);

        fwrite(stu, sizeof(struct teacher_info), 1, fp);

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
            t_menue();
            break;
        }
    }

    rear->next = NULL;

    return 0;
}

// 2. 学生信息浏览
// size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
int sinfo_review(void)
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
        s_menue();
        exit(0);
    }

    return 0;
}

int tinfo_review(void)
{
    struct teacher_info stu;

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
        ret = fread(&stu, sizeof(struct teacher_info), 1, fp);
        //read(fd, stdout, sizeof(struct student_info));

        printf("------------------------------------------------------------------------------------------------------\n");
        printf("%d\t%s\t%d\t%s\t%d\t%s\t%s\t%s\n", stu.t_no, stu.name, stu.age, stu.sex, stu.tele);
    }

    fclose(fp);
    printf("=====================^-^=====================   ====================^-^==================\n");

    printf("退出请按0, 返回上一级菜单请按1: ");
    scanf("%d", &flag);

    if (flag == 0) {
        exit(0);
    }

    if (flag == 1) {
        t_menue();
        exit(0);
    }

    return 0;
}

// 学生信息查询

int sinfo_search(void) 
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
            s_menue();
            break;
        }
    }
    return 0;

}

int tinfo_search(void) 
{
    system("clear");

    struct teacher_info *stu1 = NULL, *stu2 = NULL;
    stu1 = (struct teacher_info *)malloc(sizeof(struct teacher_info));
    stu2 = (struct teacher_info *)malloc(sizeof(struct teacher_info));

    int ret = 1, i = 0, flag = 1;

    FILE *fp = fopen("stuinfo.txt", "rb");

    printf("=====按姓名查询请输入1, 按学号查询请输入2=====\n");
    scanf("%d", &i);

    while (flag) {
        if (i == 1) {
            printf("请输入教师的姓名: ");
            scanf("%s", stu1->name);

            do {
                if (ret == 0) {
                    printf("没有这个人哦^*^\n");
                    exit(0);
                }
                ret = fread(stu2, sizeof(struct teacher_info), 1, fp);
            } while (strcmp(stu1->name, stu2->name));

            printf("您要找的人信息如下: \n");
            printf("%d\t%s\t%d\t%s\t%d\t%s\t%s\t%s\n", stu2->t_no, stu2->name, stu2->age, stu2->sex,stu2->tele);
        }

        if (i == 2) {
            printf("请输入教师的学号: ");
            scanf("%d", stu1->t_no);

            do {
                if (ret == 0) {
                    printf("没有这个人哦^*^\n");
                    exit(0);
                }
                ret = fread(stu2, sizeof(struct student_info), 1, fp);
            } while (stu2->t_no != stu1->t_no);

            printf("您要找的人信息如下: \n");
            printf("%d\t%s\t%d\t%s\t%d\t%s\t%s\t%s\n",stu2->t_no, stu2->name, stu2->age, stu2->sex,stu2->tele);
        }

        printf("=====继续查询请按1，返回上一级菜单请按2=====\n");
        scanf("%d", &flag);

        if (flag == 1)
            continue;
        if (flag == 2) {
            t_menue();
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
