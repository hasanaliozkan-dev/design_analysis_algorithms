#include <iostream> 
#include <stack>

int main(){
    std::stack<int> mystack;
    for (int i = 0; i < 10; i++)
    {
        mystack.push(i);
    }
    while (!mystack.empty())
    {
        std::cout << "" << mystack.top()<< "," ;
        mystack.pop();  
    }
    std::cout<<'\n';
    std::cout<<mystack.size();
    std::cout<<'\n';
    return 0;
}