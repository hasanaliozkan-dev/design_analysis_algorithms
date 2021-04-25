#include <iostream> 
#include <list>
int main (){
    std::list<int> mylist;
    for (int i=5; i<10; ++i) 
        mylist.push_back(i); 

    std::cout << "Popping out elements..."; 
    while (!mylist.empty()){
        std::cout << ' ' << mylist.front()<<"\n";
        mylist.pop_front(); 
    }
    

    return 0; 
}