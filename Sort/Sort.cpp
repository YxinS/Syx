#include"Sort.h"

// 测试排序的性能对比
void TestOP()
{
    srand(time(0));
    const int N = 15000;
    int* a1 = (int*)malloc(sizeof(int)*N);
    int* a2 = (int*)malloc(sizeof(int)*N);
    int* a3 = (int*)malloc(sizeof(int)*N);
    int* a4 = (int*)malloc(sizeof(int)*N);
    int* a5 = (int*)malloc(sizeof(int)*N);
    int* a6 = (int*)malloc(sizeof(int)*N);
    int* a7 = (int*)malloc(sizeof(int)*N);
    int* a8 = (int*)malloc(sizeof(int)*N);
    // int* a9 = (int*)malloc(sizeof(int)*N);
    // int* a10 = (int*)malloc(sizeof(int)*N);
    // int* a11 = (int*)malloc(sizeof(int)*N);
    // int* a12 = (int*)malloc(sizeof(int)*N);
    for (int i = 0; i < N; ++i)
    {
    a1[i] = rand();
    a2[i] = a1[i];
    a3[i] = a1[i];
    a4[i] = a1[i];
    a5[i] = a1[i];
    a6[i] = a1[i];
    a7[i] = a1[i];
    a8[i] = a1[i];
    // a9[i] = a1[i];
    // a10[i] = a1[i];
    // a11[i] = a1[i];
    // a12[i] = a1[i];
    }
    int begin1 = clock();
    InsertSort(a1, N);
    int end1 = clock();

    int begin2 = clock();
    ShellSort(a2, N);
    int end2 = clock();

    int begin3 = clock();
    SelectSort(a3, N);
    int end3 = clock();
    
    int begin4 = clock();
    HeapSort(a4, N);
    int end4 = clock();
    
    int begin5 = clock();
    BubbleSort(a5, N);
    int end5 = clock();
    
    int begin6 = clock();
    QuickSort1(a6, 0, N-1);
    int end6 = clock();
    
    int begin7 = clock();
    QuickSort2(a7, 0, N-1);
    int end7 = clock();
    
    int begin8 = clock();
    QuickSort3(a8, 0, N-1);
    int end8 = clock();

    // int begin9 = clock();
    // QuickSortNonR(a9,0,N-1);
    // int end9 = clock();

    // int begin10 = clock();
    // MergeSort(a10, N);
    // int end10 = clock();
    
    // int begin11 = clock();
    // MergeSortNonR(a11, N);
    // int end11 = clock();

    // int begin12 = clock();
    // CountSort(a12, N);
    // int end12 = clock();
    
    printf("InsertSort:%d\n", end1 - begin1);
    printf("ShellSort:%d\n", end2 - begin2);
    printf("SelectSort:%d\n", end3 - begin3);
    printf("HeapSort:%d\n", end4 - begin4);
    printf("BubblleSort:%d\n", end5 - begin5);
    printf("QuickSort1:%d\n", end6 - begin6);
    printf("QuickSort2:%d\n", end7 - begin7);
    printf("QuickSort3:%d\n", end8 - begin8);
    // printf("QuickSortNonR:%d\n", end9 - begin9);
    // printf("MergeSort:%d\n", end10 - begin10);
    // printf("MergeSortNonR:%d\n", end11 - begin11);
    // printf("CountSort:%d\n", end12 - begin12);
    free(a1);
    free(a2);
    free(a3);
    free(a4);
    free(a5);
    free(a6);
    free(a7);
    free(a8);
    // free(a9);
    // free(a10);
    // free(a11);
    // free(a12);
}

//打印
void PrintSt(int* a,int n){
    for(int i = 0;i< n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}



int main(){


    //TestOP();

    // int a[] = { 3,2,5,7,9,1,8,4,6};
    // PrintSt(a,sizeof(a)/sizeof(int));
    // InsertSort(a,sizeof(a)/sizeof(int));
    // PrintSt(a,sizeof(a)/sizeof(int));
    // int b[] = { 3,2,5,7,9,1,8,4,6};
    // PrintSt(b,sizeof(b)/sizeof(int));
    // ShellSort(b,sizeof(b)/sizeof(int));
    // PrintSt(b,sizeof(b)/sizeof(int));
    // int c[] = { 9,2,5,7,9,7,1,8,4,6};
    // PrintSt(c,10);
    // SelectSort(c,10);
    // PrintSt(c,10);
    // int d[] = { 9,2,5,7,9,7,1,8,4,6};
    // PrintSt(d,10);
    // HeapSort(d,10);
    // PrintSt(d,10);
    // int e[] = { 9,2,5,7,9,7,1,8,4,6,1};
    // PrintSt(e,11);
    // BubbleSort(e,11);
    // PrintSt(e,11);
    int f[] = {9,2,5,7,9,7,1,8,4,6,1};
    PrintSt(f,11);
    QuickSortNonR(f,0,10);
    PrintSt(f,11);
    // int g[] = { 9,2,5,7,9,7,1,8,4,6,1};
    // PrintSt(g,11);
    // MergeSort(g,11);
    // PrintSt(g,11);
    


    return 0;
    system("pause");
}