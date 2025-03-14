#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char fName [20];
    char lName [20];
    char MI;
} name ;

typedef struct {
    name empName ;
    int idNum ;
    int grossSalary ;
    int rate ;
    int hrsWorked ;
    float takeHomeSalary ;
} employeeInfo ;

typedef struct {
    employeeInfo *employees ;
    int count ;
} employeeRecord ;


typedef struct {
    employeeRecord employeeList ;
    employeeRecord bracket1 ;
    employeeRecord bracket2 ;
    employeeRecord bracket3 ;
} companyRecord ;

void populate(employeeRecord *, int);
void addName(char *, char *, char *);
void grossSalary (employeeInfo *);
void taxBracketSeparation(companyRecord *);
void displayCompanyList(companyRecord *);

int main(){
    int n;
    printf("Input how many employee: ");
    scanf(" %d", &n);
    companyRecord Record;
    Record.employeeList.employees = (employeeInfo *)malloc(n * sizeof(employeeInfo));
    Record.employeeList.count = n;
    int i;
    for(i = 0; i < n; i++){
        populate(&Record.employeeList, i);
    }
    taxBracketSeparation(&Record);
    displayCompanyList(&Record);
    free(Record.employeeList.employees);
    return 0;
}

void displayCompanyList(companyRecord *rec){
    printf("\n\n==BRACKET 1==\n");
    int i;
    for(i = 0; i < rec->bracket1.count; i++){
        printf("%d - %s, %s %c --- Php %.2f\n", rec->bracket1.employees[i].idNum, rec->bracket1.employees[i].empName.lName, rec->bracket1.employees[i].empName.fName, rec->bracket1.employees[i].empName.MI, rec->bracket1.employees[i].takeHomeSalary);
    }
    printf("\n==BRACKET 2==\n");
    for(i = 0; i < rec->bracket2.count; i++){
        printf("%d - %s, %s %c --- Php %.2f\n", rec->bracket2.employees[i].idNum, rec->bracket2.employees[i].empName.lName, rec->bracket2.employees[i].empName.fName, rec->bracket2.employees[i].empName.MI, rec->bracket2.employees[i].takeHomeSalary);
    }
    printf("\n==BRACKET 3==\n");
    for(i = 0; i < rec->bracket3.count; i++){
        printf("%d - %s, %s %c --- Php %.2f\n", rec->bracket3.employees[i].idNum, rec->bracket3.employees[i].empName.lName, rec->bracket3.employees[i].empName.fName, rec->bracket3.employees[i].empName.MI, rec->bracket3.employees[i].takeHomeSalary);
    }
}

void taxBracketSeparation (companyRecord *companyList){
    companyList->bracket1.employees = (employeeInfo *)malloc(companyList->employeeList.count * sizeof(employeeInfo));
    companyList->bracket2.employees = (employeeInfo *)malloc(companyList->employeeList.count * sizeof(employeeInfo));
    companyList->bracket3.employees = (employeeInfo *)malloc(companyList->employeeList.count * sizeof(employeeInfo));
    
    companyList->bracket1.count = 0;
    companyList->bracket2.count = 0;
    companyList->bracket3.count = 0;
    int i;
    for(i = 0; i < companyList->employeeList.count; i++){
        grossSalary(&companyList->employeeList.employees[i]);
        if(companyList->employeeList.employees[i].grossSalary < 15000){
            companyList->employeeList.employees[i].takeHomeSalary = (float)companyList->employeeList.employees[i].grossSalary * 0.90;
            companyList->bracket1.employees[companyList->bracket1.count] = companyList->employeeList.employees[i];
            companyList->bracket1.count++;
            companyList->bracket1.employees = (employeeInfo *)realloc(companyList->bracket1.employees, companyList->bracket1.count * sizeof(employeeInfo));
        } else if(companyList->employeeList.employees[i].grossSalary >= 15000 && companyList->employeeList.employees[i].grossSalary < 26000){
            companyList->employeeList.employees[i].takeHomeSalary = (float)companyList->employeeList.employees[i].grossSalary * 0.85;
            companyList->bracket2.employees[companyList->bracket2.count] = companyList->employeeList.employees[i];
            companyList->bracket2.count++;
            companyList->bracket2.employees = (employeeInfo *)realloc(companyList->bracket2.employees, companyList->bracket2.count * sizeof(employeeInfo));
        } else {
            companyList->employeeList.employees[i].takeHomeSalary = (float)companyList->employeeList.employees[i].grossSalary * 0.80;
            companyList->bracket3.employees[companyList->bracket3.count] = companyList->employeeList.employees[i];
            companyList->bracket3.count++;
            companyList->bracket3.employees = (employeeInfo *)realloc(companyList->bracket3.employees, companyList->bracket3.count * sizeof(employeeInfo));
        }
    }
}

void grossSalary(employeeInfo *emp){
    emp->grossSalary = emp->hrsWorked * emp->rate;
}

void populate(employeeRecord *rec, int count){
    printf("\n===EMPLOYEE %d===\n", count+1);
    printf("Enter ID number: ");
    scanf(" %d", &rec->employees[count].idNum);
    addName(rec->employees[count].empName.fName, rec->employees[count].empName.lName, &rec->employees[count].empName.MI);
    printf("Enter Hourly Rate: ");
    scanf(" %d", &rec->employees[count].rate);
    printf("Enter Hours Worked: ");
    scanf(" %d", &rec->employees[count].hrsWorked);
}

void addName(char *fName, char *lName, char *MI){
    printf("Enter First Name: ");
    scanf(" %[^\n]", fName);
    printf("Enter Last Name: ");
    scanf(" %[^\n]", lName);
    printf("Enter Middle Initial: ");
    scanf(" %c", MI);
}

