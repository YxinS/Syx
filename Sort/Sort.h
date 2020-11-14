#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include<assert.h>


// 支持动态增长的栈
typedef int Type;
typedef struct Stack
{
    Type* _a;
    int _top; // 栈顶
    int _capacity; // 容量
}Stack;
// 初始化栈
void StackInit(Stack* ps){
    ps->_a = NULL;
    ps->_capacity = 0;
    ps->_top = 0;
}
// 入栈
void StackPush(Stack* ps, Type data){
    assert(ps != NULL);
    if(ps->_top == ps->_capacity){
        size_t newcapacity = ps->_capacity == 0?4:ps->_capacity*2;
        ps->_a = (Type*)realloc(ps->_a,sizeof(Type)*newcapacity);
        ps->_capacity = newcapacity;
    }
    ps->_a[ps->_top] = data;
    ps->_top++;

}
// 出栈
void StackPop(Stack* ps){
    assert(ps && ps->_top > 0);
    --ps->_top;
}
// 获取栈顶元素
Type StackTop(Stack* ps){
    assert(ps);
    return ps->_a[ps->_top-1];
}
// 获取栈中有效元素个数
int StackSize(Stack* ps){
    assert(ps);
    return ps->_top;
    
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps){
    assert(ps);
    return ps->_top == 0 ? 1: 0;
}
// 销毁栈
void StackDestroy(Stack* ps){
    assert(ps);
    free(ps->_a);
    ps->_a = NULL;
    ps->_top = ps->_capacity = 0;
}





// 排序实现的接口
// 插入排序
void InsertSort(int* a, int n){
    for(int i = 0;i < n -1;++i){
        int end = i;
        int tmp = a[end+1];
        while(end >= 0){
            if(a[end] > tmp){
                a[end+1] = a[end];
                --end;
            }
            else{
                break;
            }
        }
        a[end + 1] = tmp;
    }
}
// 希尔排序
void ShellSort(int* a, int n){
    int gap = n;
    while(gap > 1){
        gap = gap/3 + 1;
        for(int i = 0; i < n - gap; ++i){
            int end = i;
            int tmp = a[end + gap];
            while(end >= 0){
                if(a[end] > tmp){
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else{
                    break;
                }
            }
            a[end + gap] = tmp;
        }
    }
}

void Swap(int* a,int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// 选择排序
void SelectSort(int* a, int n){
    int begin = 0, end = n - 1;
    while(begin < end){
        int mini = begin, maxi = end;
        for(int i = begin; i <= end; ++i){
            if(a[i] > a[maxi]){
                maxi = i;
            }
            if(a[i] < a[mini]){
                mini = i;
            }
        }
        Swap(&a[begin],&a[mini]);
        if(begin == maxi)
            maxi = mini;
        Swap(&a[end],&a[maxi]);
        ++begin;
        --end;
    }

}
// 向下调整算法
void AdjustDown(int* a, int n, int root){
    int parent = root;
    int child = parent*2+1;
    while(child < n){
        if(child+1 < n && a[child+1] > a[child]){
            child++;
        }
        if(a[parent] < a[child]){
            int tmp = a[parent];
            a[parent] = a[child];
            a[child] = tmp;

            parent = child;
            child = parent*2+1;
        }
        else{
            break;
        }
    }
}
// 堆排序
void HeapSort(int* a, int n){
    for(int i = (n-1-1)/2;i>= 0;i--){
        AdjustDown(a,n,i);
    }
    int end = n - 1;
    while(end > 0){
        int tmp = a[end];
        a[end] = a[0];
        a[0] = tmp;
        AdjustDown(a,end,0);
        end--;
    }
}
// 冒泡排序
void BubbleSort(int* a, int n){
    // for(int i = 0; i< n; i++){
    //     for(int j = 0; j < n - i -1;j++){
    //         if(a[j] > a[j+1]){
    //             int tmp = a[j+1];
    //             a[j+1] = a[j];
    //             a[j] = tmp;
    //         }
    //     }
    // }
    for(int i = n-1; i > 0; i--){
        int flag = 0;//优化
        for(int j = 0; j < i;j++){
            if(a[j] > a[j+1]){
                int tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}
// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right){
    int key = a[right];
    int keyindex = right;
    while(left < right){
        while(left <right && a[left] <= key){
            left++;
        }
        while(left < right && a[right] >= key){
            right--;
        }
        int tmp = a[left];
        a[left] = a[right];
        a[right] = tmp;
    }
    int tmp = a[left];
    a[left] = a[keyindex];
    a[keyindex] = tmp;
    return left;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right){
    int key = a[left];
    int keyindex = left;
    while(left < right){
        while(left < right && a[right] >= key){
            right--;
        }
        a[left] = a[right];
        while(left < right && a[left] <= key){
            left++;
        }
        a[right] = a[left]; 
    }
    a[left] = key;
    return left;
}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right){
    int key = a[right];
    int cur = left;
    int pre = left-1;
    while(cur < right){
        if(a[cur] < key && ++pre!= cur){
            Swap(&a[pre],&a[cur]);
        }
        cur++;
    }
    pre++;
    Swap(&a[pre],&a[right]);
    return pre;
}
void QuickSort1(int* a, int left, int right){
    if(left >= right)return;
    int keyindex = PartSort1(a,left,right);
    QuickSort1(a,left,keyindex-1);
    QuickSort1(a,keyindex+1,right);
}
void QuickSort2(int* a, int left, int right){
    if(left >= right)return;
    int keyindex = PartSort2(a,left,right);
    QuickSort2(a,left,keyindex-1);
    QuickSort2(a,keyindex+1,right);
}
void QuickSort3(int* a, int left, int right){
    if(left >= right)return;
    int keyindex = PartSort3(a,left,right);
    QuickSort3(a,left,keyindex-1);
    QuickSort3(a,keyindex+1,right);
}
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right){
    Stack st;
    StackInit(&st);
    StackPush(&st, left);
    StackPush(&st, right);
    while (!StackEmpty(&st)){
        int end = StackTop(&st);
        StackPop(&st);
        int begin = StackTop(&st);
        StackPop(&st);
        int div = PartSort1(a, begin, end);
        if (begin < div - 1){
            StackPush(&st, begin);
            StackPush(&st, div - 1);
        }
        if (div + 1 < end){
            StackPush(&st, div + 1);
            StackPush(&st, end);
        }
    }
}
// // 归并排序递归实现
// void MergeSort(int* a, int n){}
// // 归并排序非递归实现
// void MergeSortNonR(int* a, int n){}
// // 计数排序
// void CountSort(int* a, int n){}

