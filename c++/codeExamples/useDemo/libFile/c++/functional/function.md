// 与函数指针功能类似，但function功能更强大

// definition:
std::function<returnType(parameter1,parameter2)> obj;
// declare and assign:
std::function<int(int,int)> func;
int add(inta ,int b){return a+b};
func=add; 
// call:
func(2,3);