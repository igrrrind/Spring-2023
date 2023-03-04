
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 100

int add(int a[],int *n);
int isFull(int n);
int search(int x,int a[],int n);
void removeOne(int x, int a[], int* n);
void printA(int a[],int n);
void ascSort(int a[],int n);
void desSort(int a[],int n);
void collumn(int x,int a[], int n);
int countOdd(int a[],int n);

int main() {
    int a[MAXN];
    int n = 0;
    int x;
    int option = 1;
    
    do{
        printf("\n\nThe 1D ARRAY MANAGEMENT SYSTEM, or TODAMS.\n");
        printf("1- Add  a value\n2- Search a value\n3- Remove the first existence of a value\n4- Remove all existences of a value\n5- Print out the array\n6- Print out the array in ascending order (positions of elements are preserved)\n7- Print out the array in descending order (positions of elements are preserved)\n8- Print Array as Collumns\n9- Count Odd Numbers in Array\nOthers- Quit\n\nSelect: ");
        
        
        
        
        scanf("%d",&option);
        switch (option){
            case 1:
                if (isFull(n)==0){
                    break;
                }
                add(a,&n);
                break;
                
            case 2:
                printf("\nFind the position for the first instance of:  ");
                scanf("%d",&x);
                if (search(x,a,n)==-1){
                    printf("Value not found");
                    break;
                }
                //print at position found at the first instance of the value from the function
                printf("You can find this value at index number %d",search(x,a,n));
                break;
                
                
            case 3:
                printf("\nRemove the first instance of the value:  ");
                scanf("%d",&x);
                if (search(x,a,n)==-1){
                    printf("Value not found");
                    break;
                }
                removeOne(search(x,a,n),a,&n);
                printf("Successfully removed");
                break;
                
            case 4:
                printf("\nRemove the all instances of the value:  ");
                scanf("%d",&x);
                if (search(x,a,n)==-1){
                    printf("Value not found");
                    break;
                }
                do{
                    removeOne(search(x,a,n),a,&n);
                }
                while (search(x,a,n)!=-1);
                printf("Successfully removed");
                break;
                

            case 5:
                printf("Here's your array: ");
                printA(a,n);
                break;
                
            case 6:
                printf("Here's your array, in ascending order: ");
                ascSort(a,n);
                break;
            
            case 7:
                printf("Here's your array, in descending order: ");
                desSort(a,n);
                break;
                
            case 8:
                printf("How many collumns do you want to print: ");
                scanf("%d",&x);
                collumn(x,a,n);
                break;
                
            case 9:
                printf("There are currently %d odd numbers in this array",countOdd(a,n));
                break;
                
            default:
                printf("Goodbye.\n");
                break;
        }
    } while (option > 0 && option < 10);
    
}


int add(int a[],int* n){
    printf("What number will you add to box %d: ",*n);
    scanf("%d",(a+ *n));
    printf("Success.\n");
    *n = *n + 1 ;
    return 1;
}

int isFull(int n){
    printf("Checking for space:...\n");
    if (n > MAXN){
        printf("Full");
        return 0;
    }
    return 1;
}

int search(int x,int a[],int n){
    int i;
    for (i = 0; i<n ;i++ ){
        if (a[i] == x){
            return i;
        }
    }
    return -1;
}

void removeOne(int pos, int a[],int* n){
    int j = pos;
    for (int i = pos + 1; i <= *n; i++){
        a[j] = a[i];
        j++;
    }
    *n = *n - 1;
}

void printA(int a[], int n){
    for (int i =0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void ascSort(int a[],int n){
    int a2[n];
    int tmp;
    for (int i=0;i<n;i++){
        a2[i] = a[i];
    }
    for (int i = 0;i <n-1;i++){
        for(int j= n-1;j>i;j--){
            if(a2[j]<a2[j-1]){
                tmp = a2[j-1];
                a2[j-1] = a2[j];
                a2[j] = tmp;
            }
        }
    }
    printA(a2,n);
}

void desSort(int a[],int n){
    int a2[n];
    int tmp;
    //copy array1 to array2
    for (int i=0;i<n;i++){
        a2[i] = a[i];
    }
    //bubble sort from front to back
    for (int i = 0;i <n-1;i++){
        for(int j= n-1;j>i;j--){
            if(a2[j-1]<a2[j]){
                tmp = a2[j-1];
                a2[j-1] = a2[j];
                a2[j] = tmp;
            }
        }
    }
    printA(a2,n);
}


//building collumn dunction
void collumn(int collumns,int a[],int n){
    int temp=0;
    //initialising row count
    double count = ceil((n+1)/collumns);
    //jump from row to row
    for (int j = 1; j <= count;j++){
        //jump from collumn to collumn
        for (int i = temp; i < j + count*(collumns-1);i+= count){
            printf("%d      ",a[i]);
        }
        printf("\n");
        temp++;
    }
    printf("\n");
}

int countOdd(int a[],int n){
    int count=0;
    for (int i =0; i<n;i++){
        if (a[i]% 2 !=0){
            count++;
        }
    }
    return count;
}

