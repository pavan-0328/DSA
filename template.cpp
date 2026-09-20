#include <bits/stdc++.h>

using namespace std;


//sorting algo
//selction sort 
void selction_sort(vector<int>& arr, int n){
    int min_idx,min_ele;
    min_idx = 0;
    min_ele = arr[min_idx];
    for(int i=0;i<n;i++){
        //min_idx = i;
        min_ele = arr[i];
        for(int j=i;j<n;j++){
            if(arr[j] <= min_ele){
                min_idx = j;
                min_ele = arr[j];
            }
        }
        swap(arr[i],arr[min_idx]);
    }
    return;
}

//bubblbe sort 
void bubble_sort(vector<int>& arr,int n){
    for(int i=n-1;i>=0;i--){

        for(int j=0;j<i;j++){
            if(arr[j] > arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
    return;
}

//insertion sort
void insertion_sort(vector<int>& arr,int n){
    for(int i=1;i<n;i++){
        int j=0;
        while(arr[i] >= arr[j]) j++;
        int temp = arr[i];
        int k=i;
        while(k>j){
            swap(arr[k],arr[k-1]);
            k--;
        }
        arr[j] = temp;
    }
}

//merge sort 
void merge(vector<int>& arr,int left,int mid,int right){
    
    int i,j,k;
    i = 0;j = 0;
    k = left;
    int n1 = mid - left+1;
    int n2 = right - mid;
    vector<int> left_arr(n1);
    vector<int> right_arr(n2);
    for(int i=0;i<n1;i++){
        left_arr[i] = arr[left + i];
    }
    for(int i=0;i<n2;i++){
        right_arr[i] = arr[mid + 1 + i];
    }
    while(i < n1 && j < n2){
        if(left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }else{
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = left_arr[i];
        k++;i++;
    }
    while(j<n2){
        arr[k] = right_arr[j];
        k++;j++;
    }
return;
}

void merge_sort(vector<int>& arr,int left,int right){ // 0 to n-1
    if(left >= right) return;
    int mid = left + (right - left)/2;
    merge_sort(arr,left,mid);
    merge_sort(arr,mid+1,right);
    merge(arr,left,mid,right);
}

//heap sort
void heapify(vector<int>& arr,int n,int idx){
    //if(2*idx+1 > n) return;
    
    int largest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;
    if(largest != idx){
        swap(arr[largest],arr[idx]);
        heapify(arr,n,largest);
    }   
}

void heap_sort(vector<int>& arr,int n){
    for(int i=n/2 -1 ;i>=0;i--){
        heapify(arr,n,i);
    }
    int len=n;
    while(n>0){
        
        swap(arr[0],arr[n-1]);
        n--;
        heapify(arr,n,0);
        
    }
}

int main(){
    vector<int> arr = {12,5,7,9,3,11,0,125};

    cout << "Before Sorting\n"; 
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }cout << "\nAfter Sortinig\n";

    //selction_sort(arr,arr.size());
   // bubble_sort(arr,arr.size());
   //insertion_sort(arr,arr.size());
   //merge_sort(arr,0,arr.size()-1);
   heap_sort(arr,arr.size()); 
   for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }cout << "\n";

}
