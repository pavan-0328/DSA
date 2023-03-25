#include<iostream>
#include<vector>
using namespace std;


class Binheap{
    private:
        vector<int> heap;
        int heap_size=0;
        
    public:
        int parent(int i){return (i-1)/2;}
        int left_child(int i){return (2*i + 1);}
        int right_child(int i){return (2*i + 2);}

        Binheap(int max_size){
            heap  = vector<int>(max_size+1,0);
            heap_size = 0;
        }
        bool is_empty(){
            if(heap_size == 0) return true;
            return false;
        }
        void insert(int val){
            //insert at the end of array and hepifyup  
        
            heap[heap_size] = val;
            //to satisfy heap property hepifyup
            heap_up(heap_size);
            heap_size++;
        }
        int min(){
            if(is_empty()){
                return -1;
            }
            return heap[0];
        }
        int removeMin(){
            return delete_ith(0);
        }
        int delete_ith(int i){
            if(is_empty()) return -1;
            int val = heap[i];
            //swap the ith element with last element of array
             swap(heap[i],heap[heap_size-1]); // reduce heap size before swaping
             //decriment hte heap size
             heap_size--;
             //heapify down with from ith node
             heap_down(i);
             return val;
        }
        void heap_up(int i){
            /*
            --> Algo 
            --> if child is grater than parent swap child with parent
            --> repeat the above till parent is less than child or we reached root
            */
            int temp = heap[i];
            while(i>0 && temp < heap[parent(i)]){
                heap[i] = heap[parent(i)];
                i = parent(i);
            }
            heap[i] = temp;
        }
        void heap_down(int i){
            /*
            --> Algo
            --> if parent is grater than the child then take the max of both the child and swap them 
            --> till we reach the parent is less than childs 
            */
            int temp = heap[i];
            while(left_child(i) < heap_size){
                int m_child;
                if(heap[left_child(i)] > heap[right_child(i)]) m_child = right_child(i);
                else m_child = left_child(i);
                if(temp > heap[m_child]) heap[i] = heap[m_child];
                else break; 
                i = m_child;
            }
            heap[i] = temp; 
        }
        void print(){
            for(const int i: heap){
                cout << i << " ";
            }
            cout << endl;
        }

        
};
int main(){
    Binheap *obj = new Binheap(20);
    cout << obj->removeMin() << endl;
    obj->insert(10);

    obj->insert(5);
    obj->insert(20);
    obj->insert(6);
    obj->insert(7);
    obj->insert(12);
    obj->print();
    cout << "Now remove"<< endl;
    cout << obj->removeMin() << endl;
    obj->print();
    return 0;
}