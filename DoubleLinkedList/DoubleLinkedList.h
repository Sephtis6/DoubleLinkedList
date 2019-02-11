#pragma once
#include "pch.h"
#include "DoubleLinkedList.h"
#include <iostream>

using namespace std;
//template used
template <typename T>
//node of the linked list
struct node
{
	//data used
	T data;
	//pointers to next and previous nodes in list
	node <T> *next;
	node <T> *prev;
};

//template used
template <typename T>
//class used
class linkedlist
{
	//private data used
private:
	//nodes for the head and tail of the linked list
	node <T> *head;
	node <T> *tail;
public:
	//sets the head and tail of the linked list to null
	linkedlist()
	{
		head = nullptr;
		tail = nullptr;
	}
	//void for adding a new node to the list at the end
	void Add(T new_data)
	{
		//makes a new node and then uses that node to hold the new data
		//then takes that node and inputes it as either the head or id one is in the head already
		//it inputes it into the next slot and moves the tail futher back
		node<T> *temp = new node <T>;
		temp->data = new_data;
		temp->next = nullptr;
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
			temp = nullptr;
		}
		else
		{
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
	}
	//void for showing the entire lists data
	void Show()
	{
		//takes the data and inputes it into a temp node and then goes through the entire list while displaying
		//the data as an output and then tells the user when all nodes are shown
		node <T> *temp = new node <T>;
		temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << "All nodes shown" << endl;
	}
	//void for deleting a node from the list
	void DelPos(T data_to_del)
	{
		//looks first to see if the head == null and if so prints that there is no list to use
		if (head == nullptr)
		{
			cout << "There is no list to delete from." << endl;
			return;
		}
		//creates a node pointer to the node of the data to find using the find function
		node<T>* delNode = Find(data_to_del);
		//if the find function returns nullptr returns nothing
		if (delNode == nullptr)
		{
			return;
		}
		//otherwise runs through the following statements
		else
		{
			//if the node is the head and tail or otherwise known as the only one in the list it will set both to nullptr thus deleting the list
			if (delNode == head && delNode == tail)
			{
				head = nullptr;
				tail = nullptr;
				delete delNode;
			}
			//otherwise if it is the head it takes the next node and sets it to head and sets the new heads prev pointer to nullptr
			else if (delNode == head)
			{
				head = head->next;
				head->prev = nullptr;
				delete delNode;
			}
			//does the same with the tail only it is the previous node and the next pointer it sets to nullptr
			else if (delNode == tail)
			{
				tail = tail->prev;
				tail->next = nullptr;
				delete delNode;
			}
			//otherwise it sets the next nodes prev to the node before the data to delete and then sets the previous next node to the node after the data to delete
			//this leaves those to connected and removes the deleted data from the list
			else
			{
				delNode->next->prev = delNode->prev;;
				delNode->prev->next = delNode->next;
				delete delNode;
			}
		}
	}
	//void to find a node in the list
	node<T>* Find(T data_to_find)
	{
		//takes the number of hte node to find and then runs it thorugh the list till
		//it finds the number of the node and displays it otherwise it displays that there is no data node at that number
		node <T>* current = new node <T>;
		node <T>* previous = new node <T>;
		current = head;
		//if there is no list to search through returns no list
		if (head == nullptr)
		{
			cout << "No list to search in" << endl;
			return nullptr;
		}
		else
		{
			while(current->data != data_to_find)
			{
				if (current->data != data_to_find)
				{
					cout << "Searching" << endl;
					if (current->next == nullptr)
					{
						cout << "Data not found" << endl;
						return nullptr;
					}
				}
				current = current->next;
			}
			if (current->data == data_to_find)
			{
				cout << "Data is at point " << &current << endl;
				return current;
			}
		}
	}
	//void to find the max key in the list
	int findMax()
	{
		//if there is no list to search through returns no list
		if (head == nullptr)
		{
			cout << "No list to search in" << endl;
			return NULL;
		}
		//sets the node to head to start off
		node <T>* max = head;
		//the data is set to the head data
		T testMax = head->data;
		//runs through the list to test each node data against the max data to see if they are bigger or not
		//if it is larger that data becomes the new max data and goes through till the end of the list
		if (max != tail)
		{
			if (testMax > max->data)
			{
				testMax = max->data;
			}

			max = max->next;
		}
		else if (max == tail)
		{
			if (testMax > max->data)
			{
				testMax = max->data;
			}
		}
		//then it displays the largest set of dat it could find in the list
		cout << "The largest set of data in the list is: " << testMax << endl;
		return testMax;
	}
	//void to find the min key in the list
	int findMin()
	{
		//if there is no list to search through returns no list
		if (head == nullptr)
		{
			cout << "No list to search in" << endl;
			return NULL;
		}
		//sets the node to head to start off
		node <T>* min = head;
		//the data is set to the head data
		T testMin = head->data;
		//runs through the list to test each node data against the min data to see if they are smaller or not
		//if it is smaller that data becomes the new min data and goes through till the end of the list
		if (min != tail)
		{
			if (testMin < min->data)
			{
				testMin = min->data;
			}

			min = min->next;
		}
		else if (min == tail)
		{
			if (testMin < min->data)
			{
				testMin = min->data;
			}
		}
		//then it displays the smallest set of dat it could find in the list
		cout << "The largest set of data in the list is: " << testMin << endl;
		return testMin;
	}
};