#pragma once
#include "../../../src/classes/stack.h"
class Queue
{

	private:
		Stack s1;
		Stack s2;

	public:

		void push(int item) {
			s1.push(item);
		}
		int pop() {
			if (s2.isEmpty())
			{
				while (!s1.isEmpty())
				{
					s2.push(s1.pop());
				}
			}
			if (s2.isEmpty())
			{
				std::cout << "Error: stack is empty";
				return NULL;

			}
			return s2.pop();
		}
};
