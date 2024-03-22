#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
int main(){

    int choice;

    
    loadStudentsFromFile("students.txt");

do {
    printf("\n========================\n");
    printf("QUAN LY DANH SACH SINH VIEN\n");
    printf("========================\n");
    printf("1. Them hoc sinh\n");
    printf("2. Sap xep danh sach theo diem\n");
    printf("3. In danh sach\n");
    printf("4. Tim kiem hoc sinh\n");
    printf("5. Xoa hoc sinh\n");
    printf("6. Luu danh sach vao file\n");
    printf("0. Thoat\n");
    printf("Nhap lua chon cua ban: ");
    scanf("%d", &choice);
    getchar();  // Xóa ký tự xuống dòng sau khi đọc lựa chọn

    switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            sortStudentsByScore();
            break;
        case 3:
            printStudents();
            break;
        case 4:
            searchStudent();
            break;
        case 5:
            deleteStudent();
            break;
        case 6:
            saveStudentsToFile("students.txt");
            printf("Da luu danh sach vao file.\n");
            break;
        case 0:
            printf("Tam biet!\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
            break;
    }
} while (choice != 0);

    return 0;
}
struct Student {
    char name[50];
    float score;
   
};

struct Student studentList[MAX_SIZE];
int studentCount = 0;

void loadStudentsFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    char line[50];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';  //x�a ki tu xuong dong 
        strcpy(studentList[studentCount].name, strtok(line, ","));
        studentList[studentCount].score = atof(strtok(NULL, ","));
        studentCount++;
    }

    fclose(file);
}

void saveStudentsToFile(const char* filename)
 {int i,j;
    FILE* file = fopen(filename, "w");
    if (file == NULL)
	
	 {
        printf("Khong the mo file.\n");
        return;
    }
    for (i = 0; i < studentCount; i++) {
        fprintf(file, "%s,%.2f\n", studentList[i].name, studentList[i].score);
    }

    fclose(file);
}

void addStudent() {
    if (studentCount == MAX_SIZE) {
        printf("Danh sach da day.\n");
        return;
    }

    printf("Nhap ten hoc sinh: ");
    char name[50];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Xóa ký tự xuống dòng

    printf("Nhap diem hoc sinh: ");
    float score;
    scanf("%f", &score);
    getchar();  // Xóa ký tự xuống dòng

    strcpy(studentList[studentCount].name, name);
    studentList[studentCount].score = score;
    studentCount++;

    printf("Da them hoc sinh.\n");
}

void sortStudentsByScore() {
	int i,j;
    if (studentCount == 0) {
        printf("Danh sach rong.\n");
        return;
    }

    // Sắp xếp danh sách sinh viên theo điểm tăng dần
    for (i = 0; i < studentCount - 1; i++) {
        for (j = i + 1; j < studentCount; j++) {
            if (studentList[i].score > studentList[j].score) {
                struct Student temp = studentList[i];
                studentList[i] = studentList[j];
                studentList[j] = temp;
            }
        }
    }

    printf("Danh sach da sap xep theo diem.\n");
}

void printStudents() {
	int i,j;
    if (studentCount == 0) {
        printf("Danh sach rong.\n");
        return;
    }

    printf("Danh sach hoc sinh:\n");
    for ( i = 0; i < studentCount; i++) {
        printf("Ten: %s - Diem: %.2f\n", studentList[i].name, studentList[i].score);
    }
}

void searchStudent() {int i,j;
    if (studentCount == 0) {
        printf("Danh sach rong.\n");
        return;
    }

    printf("Nhap ten hoc sinh can tim: ");
    char name[50];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Xóa ký tự xuống dòng

    int found = 0;
    for ( i = 0; i < studentCount; i++) {
        if (strcmp(studentList[i].name, name) == 0) {
            found = 1;
            printf("Thong tin hoc sinh:\n");
            printf("Ten: %s - Diem: %.2f\n", studentList[i].name, studentList[i].score);
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay hoc sinh.\n");
    }
}

void deleteStudent() {int i,j;
    if (studentCount == 0) {
        printf("Danh sach rong.\n");
        return;
    }

    printf("Nhap ten hoc sinh can xoa: ");
    char name[50];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Xóa ký tự xuống dòng

    int found = 0;
    for ( i = 0; i < studentCount; i++) {
        if (strcmp(studentList[i].name, name) == 0) {
            found = 1;
            
            for (j = i; j < studentCount - 1; j++) {
                studentList[j] = studentList[j + 1];
            }
            studentCount--;
            printf("Da xoa hoc sinh.\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay hoc sinh.\n")    ;
    }
}


