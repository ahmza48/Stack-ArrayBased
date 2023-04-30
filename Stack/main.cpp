#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;

bool isBalanceExpression(const char* s)
{	
	Stack<char>expression(10);

	int i = 0;
	while (s[i] != '\n') {

		if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
			expression.push(s[i]);
			//cout << "At Push Top: " << expression.getTop() << endl;
		}else {
			if (expression.getTopValue() == '(' &&	s[i] == ')' || expression.getTopValue() == '{' &&	s[i] == '}' || expression.getTopValue() == '[' &&	s[i] == ']'){
				expression.pop();
				//cout << "At Pop Top: " << expression.getTop() << endl;
			}
			else if(s[i] == ']' || s[i] == '}' || s[i] == ')'){
				expression.push(s[i]);
			}
		}
		i++;
	}
	if ( expression.getTop() ==-1)
	{
		return true;
	}
	else {
		return false;
	}
}
//a+b*c/e*f-e
string infixToPostfix(string exp) {

	Stack<char>operators(10);
	string postfix = "";
	int i = 0;
	while (exp[i] != '\n')
	{
		if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/') {
			postfix = postfix + exp[i];
		}
		else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
			if (exp[i] == '+')
			{
				while (operators.getTopValue() == '+' || operators.getTopValue() == '-' || operators.getTopValue() == '*' || operators.getTopValue() == '/')
				{
					postfix = postfix + operators.getTopValue();
					operators.pop();
				}
				operators.push(exp[i]);
			}

			if (exp[i] == '-')
			{
				while (operators.getTopValue() == '+' || operators.getTopValue() == '-' || operators.getTopValue() == '*' || operators.getTopValue() == '/')
				{
					postfix = postfix + operators.getTopValue();
					operators.pop();
				}
				operators.push(exp[i]);
			}

			if (exp[i] == '*')
			{
				while (operators.getTopValue() == '*' || operators.getTopValue() == '/')
				{
					postfix = postfix + operators.getTopValue();
					operators.pop();
				}
				operators.push(exp[i]);
			}

			if (exp[i] == '/')
			{
				while (operators.getTopValue() == '*' || operators.getTopValue() == '/')
				{
					postfix = postfix + operators.getTopValue();
					operators.pop();
				}
				operators.push(exp[i]);
			}
		}
		i++;
	}
	while (operators.getTop() != -1)
	{
		postfix = postfix + operators.getTopValue();
		operators.pop();
	}
	return postfix;
}

int longestValidParentheses(string s) {
	Stack<char>operators(10);
	int i = 0;
	int count = 0;
	while (s[i]!='\n')
	{
		if (s[i] == '(' && s[i] != ')') {
			operators.push(s[i]);
		}
		if (s[i] == ')'&&operators.getTopValue() == '(') {
			operators.pop();
			count += 2;

		}
		i++;
	}
	return count;
}

void nextGreatestElement(int a[],int size) {
	Stack<char>array(10);
	Stack<int>NGE(15);
	//NGE.push(a[0]);
	//for (int i = 1; i < size; i++) {
	//	array.push(a[i]);
	//}
	////NGE.push(-1);
	////NGE.push(array.getTopValue());
	//array.pop();
	//if (array.getTopValue()<NGE.getTopValue()) {
	//	NGE.push(array.getTopValue());
	//	array.pop();
	//}


	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (a[i]<a[j]) {
				NGE.push(a[j]);
				break;
			}
		}
		if (i == size - 1) {
			NGE.push(-1);
		}
	}

	NGE.display();
	//
	//for (int i = 1; i < size; i++)
	//{
	//	//array.push(a[i]);
	//	if (a[i]p>array.getTopValue()) {
	//		NGE.push(array.getTopValue());
	//		NGE.push(a[i]);
	//		/*array.push(a[i]);
	//		NGE.push(array.getTopValue());
	//		NGE.push(a[i]);*/
	//	}if (a[i] < array.getTopValue()) {
	//		int temp = a[i];
	//	}
	//
	//}
	


}

void removeDuplicates(const char * s) {

	Stack<char>temp(15);
	int i = 0;
	while (s[i]!='\n') {
		if (s[i] != temp.getTopValue()) {
			temp.push(s[i]);
	
		}
		else {
			temp.pop();
		}
		i++;
	}
	temp.display();
}


int main() 
{
	Stack<int>s1(5);

	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.pop();
	s1.display();
	//string expression ="(ax{b+c}-4/x+[e-5])\n" ;
	cout << endl;
	int check=isBalanceExpression("(ax{b+c})-4/x+[e-5])\n" /*expression*/);
	if (check == true) {
		cout << "Expression is balanced!" << endl;
	}
	else {
		cout << "Expression is not balanced!" << endl;
	}

	string expression = "a+b-c/e*f*f-e\n";
	string postfix = infixToPostfix(expression);
	cout << "POSTFIX EXPRESSION IS:" << postfix << endl;
	int length = longestValidParentheses("()))\n");
	cout << "Length of valid parenthesis is: " << length << endl;
	int arr[] = { 4,5,2,25 };
	nextGreatestElement(arr, 4);


	removeDuplicates("abbaca\n");
	
	return 0;
}