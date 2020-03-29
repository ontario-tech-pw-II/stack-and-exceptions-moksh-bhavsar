// RPN calculator

#include <iostream> 
#include <string>
#include <stack> 

using namespace std;
bool is_str_digit(string);  // returns true if input parameter string is and integer (e.g., "127343")
bool is_str_operator(string); // returns true if the input parameter is an operator character (e.g., "+", "*")

class DivisionByZero{ };
class LessOperand{ };
class IncompleteProcess{ };
class InvalidInput { };

int main() 
{
    string in;
    stack<string> st;   // stack definition

    cin >> in;

    while(in != "q")
    {
		try {
			if ((!is_str_digit(in)) && (!is_str_operator(in)))
				throw InvalidInput();
			
			if(is_str_digit(in)){
				// add your code here
				st.push(in);
			}
			else if(is_str_operator(in))
			{
				// add your code here 
				try {
					if (st.size() <2){
						throw LessOperand();
					}

					int value3;
					int value1 = stoi(st.top());
					st.pop();
					int value2 = stoi(st.top());
					st.pop();

					switch(in[0])
					{
						case '+':
							value3 = value2 + value1;
							break;

						case '-':
							value3 = value2 - value1;
							break;

						case '*':
							value3 = value2 * value1;
							break;

						case '/':
							try {
								if (value1 == 0)
									throw DivisionByZero();
								
									value3 = value2 / value1;
									break;
							}
							catch (DivisionByZero){
								cout << "Division by zero detected!!" << endl;
								exit(0);
							}

					}
					
					st.push(to_string(value3));
				}
				catch (LessOperand){
					cout << "Less operands detected!!" << endl;
					exit(0);	
				}

			}
		}
		catch (InvalidInput){
			cout << "Recieved an invalid input!!" << endl;
			exit(0);
		}
		
        cin >> in;
    }
	
	try{
		if (st.size() !=1)
			throw IncompleteProcess();
		cout << "The answer is : " << st.top() << endl;
	}
	catch (IncompleteProcess){
		cout << "Less operators used!!" << endl;
	}
	
    return 0; 
}

bool is_str_digit(string s)
{
    for (int i = 0; i < s.length(); ++i)
    {
            if(!isdigit(s[i]))
                return false;
    }
    return true;
}
bool is_str_operator(string s)
{
    return (s.length()==1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0]== '/'));
}
