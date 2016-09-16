#include "p2Defs.h"
#include "p2DynArray.h"
#include "p2SList.h"
#include "p2List.h"
#include "p2Point.h"
#include "p2Queue.h"
#include "p2Queue2.h"
#include "p2Stack.h"
#include "p2Stack2.h"
#include "p2String.h"
#include "p2Graph.h"
#include "p2Vec3.h"

uint done = 0;
uint failed = 0;

#define TEST(msg, test) done++; printf("\t%s\t%s\n", !(##test) ? failed++,"FAIL" : "OK", msg)

int main()
{
	// DynArray -------------------
	{
		printf("Testing DynArray ...\n");
		p2DynArray<int> container;
		TEST("Empty constructor", container.capacity() == DYN_ARRAY_BLOCK_SIZE);
		p2DynArray<int> container1(5);
		TEST("Capacity constructor", container1.capacity() == 5);
		container.push_back(1);
		container.push_back(2);
		container.push_back(3);
		TEST("Push Back", container[2] == 3 && container.size() == 3);
		TEST("Front", *(container.front()) == 1);
		TEST("Back", *(container.back()) == 3);
		TEST("Empty", container.empty() == false);
		int d;
		container.pop_back(d);
		container.pop_back(d);
		container.pop_back(d);
		TEST("Pop Back", d == 1 && container.pop_back(d) == false);
		container.push_back(3);
		container.push_back(1);
		container.push_back(6);
		container.push_back(4);
		container.push_back(5);
		container.push_back(2);
		TEST("Bubble Sort", container.BubbleSort() == 8);
		container.clear();
		TEST("Clear", container.size() == 0);
		container.push_back(3);
		container.push_back(1);
		container.push_back(6);
		container.push_back(4);
		container.push_back(5);
		container.push_back(2);
		TEST("Bubble Sort Optimized", container.BubbleSortOptimized() == 7);
		container.clear();
		TEST("Clear Again", container.size() == 0);
	}

	// List -------------------
	{
		printf("\nTesting Double Linked List ...\n");
		p2List<int> container;
		container.push_back(4);
		container.push_back(5);
		container.push_back(6);
		TEST("Push Back", container.size() == 3);
		TEST("Front", *(container.front()) == 4);
		TEST("Back", *(container.back()) == 6);
		TEST("Empty", container.empty() == false);
		container.push_front(2);
		container.push_front(1);
		TEST("Push Front", container.size() == 5);	
		container.insert(3, 2);
		TEST("Insert", *(container.at(2)) == 3 && container.size() == 6);
		int d;
		container.pop_back(d);
		container.pop_front(d);
		container.pop_back(d);
		container.pop_back(d);
		container.pop_back(d);
		container.pop_back(d);
		TEST("Pop Back and Pop Front", d == 2 && container.pop_back(d) == false);
		container.push_back(3);
		container.push_back(1);
		container.push_back(6);
		container.push_back(4);
		container.push_back(5);
		container.push_back(2);
		TEST("Bubble Sort", container.BubbleSort() == 25);
		container.clear();
		TEST("Clear", container.size() == 0);
	}

	// Single List -------------------
	{
		printf("\nTesting Single Linked List ...\n");
		p2SList<int> container;
		container.push_back(4);
		container.push_back(5);
		container.push_back(6);
		TEST("Push Back", container.size() == 3);
		TEST("Front", *(container.front()) == 4);
		TEST("Back", *(container.back()) == 6);
		TEST("Empty", container.empty() == false);
		container.push_front(2);
		container.push_front(1);
		TEST("Push Front", container.size() == 5);
		container.insert(3, 2);
		TEST("Insert", *(container.at(2)) == 3 && container.size() == 6);
		int d;
		container.pop_back(d);
		container.pop_front(d);
		container.pop_back(d);
		container.pop_back(d);
		container.pop_back(d);
		container.pop_back(d);
		TEST("Pop Back and Pop Front", d == 2 && container.pop_back(d) == false);
		container.push_back(3);
		container.push_back(1);
		container.push_back(6);
		container.push_back(4);
		container.push_back(5);
		container.push_back(2);
		TEST("Bubble Sort", container.BubbleSort() == 25);
		container.clear();
		TEST("Clear", container.size() == 0);
	}

	// Queue List -------------------
	{
		printf("\nTesting Queue implemented with Single Linked List ...\n");
		p2Queue<int> container;
		container.push(1);
		container.push(2);
		container.push(3);
		TEST("Push", container.size() == 3);
		TEST("Empty", container.empty() == false);
		TEST("Peek", *(container.peek()) == 1);
		int d;
		container.pop(d);
		TEST("Peek Again after 1 Pop", *(container.peek()) == 2);
		container.pop(d);
		container.pop(d);
		TEST("Pop", d == 3 && container.pop(d) == false);
		container.clear();
		TEST("Clear", container.size() == 0);
	}

	// Queue2 DynArray -------------------
	{
		printf("\nTesting Queue implemented with Dynamic Array ...\n");
		p2Queue2<int> container;
		container.push(1);
		container.push(2);
		container.push(3);
		TEST("Push", container.size() == 3);
		TEST("Empty", container.empty() == false);
		TEST("Peek", *(container.peek()) == 1);
		int d;
		container.pop(d);
		TEST("Peek Again after 1 Pop", *(container.peek()) == 2);
		container.pop(d);
		container.pop(d);
		TEST("Pop", d == 3 && container.pop(d) == false);
		TEST("Empty", container.empty() == true);
		container.push(1);
		container.clear();
		TEST("Clear", container.size() == 0);
	}

	// Stack DynArray -------------------
	{
		printf("\nTesting Stack implemented with Dynamic Array ...\n");
		p2Stack<int> container;
		container.push(1);
		container.push(2);
		container.push(3);
		container.push(4);
		TEST("Push", container.size() == 4);
		TEST("Empty", container.empty() == false);
		TEST("Peek", *(container.peek()) == 4);
		int d;
		container.pop(d);
		TEST("Peek Again after 1 Pop", *(container.peek()) == 3);
		container.pop(d);
		container.pop(d);
		container.pop(d);
		TEST("Pop", d == 1 && container.pop(d) == false);
		container.clear();
		TEST("Clear", container.size() == 0);
	}

	// Stack2 List -------------------
	{
		printf("\nTesting Stack implemented with SIngle Linked List ...\n");
		p2Stack2<int> container;
		container.push(1);
		container.push(2);
		container.push(3);
		container.push(4);
		TEST("Push", container.size() == 4);
		TEST("Empty", container.empty() == false);
		TEST("Peek", *(container.peek()) == 4);
		int d;
		container.pop(d);
		TEST("Peek Again after 1 Pop", *(container.peek()) == 3);
		container.pop(d);
		container.pop(d);
		container.pop(d);
		TEST("Pop", d == 1 && container.pop(d) == false);
		container.clear();
		TEST("Clear", container.size() == 0);
	}

	// String -------------------
	{
		printf("\nTesting String ...\n");
		p2String str;
		TEST("Empty Constructor", str.capacity() == 1 && str.size() == 0);
		p2String str1(25);
		TEST("Capacity Constructor", str1.capacity() == 25 && str1.size() == 0);
		p2String str2("hello world");
		TEST("C String Constructor", str2.capacity() == 12 && str2.size() == 11);
		TEST("Operator == string", !(str2 == str1));
		TEST("Operator == c string", str2 == "hello world");
		str1 = str2;
		TEST("Operator = string", str1 == "hello world");
		str2 = "bye world";
		TEST("Operator = c string", str2 == "bye world");
		str2 += " test";
		TEST("Operator += c string", str2 == "bye world test");
		str2 += str1;
		TEST("Operator += string", str2 == "bye world testhello world");
		str2.clear();
		TEST("Clear", str2.size() == 0);
	}

	// Point -------------------
	{
		printf("\nTesting Point ...\n");
		iPoint a(2, 2);
		iPoint b = a + a;
		iPoint c = b - a;

		TEST("Operator + Point", b == iPoint(4, 4));
		TEST("Operator - Point", c == iPoint(2, 2));
		TEST("Operator -= Point", (b -= a) == iPoint(2, 2));
		TEST("Operator += Point", (c += b) == iPoint(4, 4));
		TEST("Negate", c.Negate() == iPoint(-4, -4));
		TEST("Set to Zero", c.SetToZero() == iPoint(0, 0));
		TEST("Is Zero", c.IsZero() == true);
		TEST("Distance", iPoint(2, 2).DistanceTo(iPoint(2,5)) == 3);
	}

	// Graph -------------------
	{
		printf("\nTesting Graph ...\n");
		p2Graph<int> container;
		TEST("Empty", container.empty() == true);
		p2Graph<int>::vertice* vertice_1 = container.push_back(1);
		p2Graph<int>::vertice* vertice_2 = container.push_back(2);
		p2Graph<int>::vertice* vertice_3 = container.push_back(3);
		TEST("Push Back", container.size() == 3);
		vertice_1->links.push_back(vertice_2);
		vertice_2->links.push_back(vertice_3);
		vertice_3->links.push_back(vertice_3); // loop
		vertice_3->links.push_back(vertice_2);
		TEST("Push Back", container.size() == 3);
		TEST("is_reachable_iterative A", container.is_reachable_iterative(vertice_1, vertice_3) == true);
		TEST("is_reachable_iterative B", container.is_reachable_iterative(vertice_3, vertice_1) == false);
		TEST("is_reachable_recursive A", container.is_reachable_recursive(vertice_1, vertice_3) == true);
		TEST("is_reachable_recursive B", container.is_reachable_recursive(vertice_3, vertice_1) == false);
		container.clear();
		TEST("Clear", container.size() == 0);
	}

	printf("\nFailures: %d/%d", failed, done);
	printf("\nSuccess: %d/%d", done - failed, done);
	printf("\nPress Intro to exit.", "%s");

	getchar();
	return 0;
};