// DoubleLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "DoubleLinkedList.h"
#include <iostream>
using namespace std;

void DisplayUserCommands();
void Test();

//main function that the program runs off of
int main()
{
	//stores the data to be used and creates a new list for the user
	int number;
	int listdata;
	linkedlist <int> userlist;
	//welcomes the user
	cout << "Welcome to the double linked list assignment" << endl;
//checkpoint that can be returnes to
start:
	//calling a function to display the list of user commands
	DisplayUserCommands();
	//get's the user's choice and does something based on it
	cout << "Please enter a number: " << endl;
	cin >> number;
	//does something based on the number the user picks
	switch (number)
	{
		//clears the system of outputs and then loads a function based on the number picked
	case 1:
		system("CLS");
		cout << "Please enter a number to add to the list" << endl;
		cin >> listdata;
		userlist.Add(listdata);
		goto start;
		break;
	case 2:
		system("CLS");
		cout << "Please enter what data you want to search" << endl;
		cin >> listdata;
		userlist.Find(listdata);
		goto start;
		break;
	case 3:
		system("CLS");
		cout << "Displaying smallest value in list" << endl;
		userlist.findMin();
		goto start;
	case 4:
		system("CLS");
		cout << "Displaying largrest value in list" << endl;
		userlist.findMax();
		goto start;
	case 5:
		system("CLS");
		cout << "Please enter what spot on the list that you want to delete" << endl;
		cin >> listdata;
		userlist.DelPos(listdata);
		goto start;
		break;
	case 6:
		system("CLS");
		cout << "Displaying all sets of data in list" << endl;
		userlist.Show();
		goto start;
		break;
	case 7:
		system("CLS");
		Test();
		goto start;
		break;
	case 8:
		system("CLS");
		return 0;
		break;
	default:
		cout << "You chose an unavailable option. Program will close soon." << endl;
		break;
	}

	system("pause");	
	return 0;
}
// funtion to display the list of user commands
void DisplayUserCommands() {
	cout << "List of choices:" << endl;
	cout << "1 Add to the linked list" << endl;
	cout << "2 Search for a set of data" << endl;
	cout << "3 Search for smallest data in list" << endl;
	cout << "4 Search for largest data in list" << endl;
	cout << "5 Delete a set of data from the linked list" << endl;
	cout << "6 Show the linked list data points" << endl;
	cout << "7 Run the premade automated test" << endl;
	cout << "8 Exit out of the program" << endl;
}
//test void that goes through the functions of the list and diplays the results at vaious points in the process
void Test()
{
	linkedlist <int> newlist;
	newlist.Find(10);
	newlist.DelPos(2);
	newlist.Add(25);
	newlist.Add(50);
	newlist.Add(90);
	newlist.Add(40);
	cout << "Displaying all nodes" << endl;
	newlist.Show();
	cout << "Adding new node" << endl;
	newlist.Add(55);
	newlist.Show();
	cout << "Deleting node 4" << endl;
	newlist.DelPos(3);
	newlist.Show();
	newlist.Find(100);
	newlist.DelPos(20);
	newlist.findMin();
	newlist.findMax();
	newlist.Show();

	system("Pause");
}