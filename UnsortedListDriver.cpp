
// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include "UnsortedList.cpp"
#include "Student.cpp"
using namespace std;
void testIntegerList();
void testStudentList();
int main()
{
	int datatype;
	// Prompt user to enter type of elements 
	cout << "Enter Elements Type\n1 for integer\n2 for Student\n";
	cin >> datatype;
	switch (datatype)
	{
	case 1: testIntegerList();
		    break;
	case 2: testStudentList();
		    break;
	}
	//�.append any needed code here
	return 0;
}


void testIntegerList()
{
	UnsortedList<int> list(5);
	string command;
	ifstream inFile;
	ofstream outFile;
	inFile.open("intcommands.txt");
	outFile.open("outFile.txt");
	int number;
	inFile >> command; // read commands from a text file

	while (command != "Quit")
	{
		try

		{
			if (command == "MakeEmpty")
				(list.makeEmpty());

			else if (command == "IsEmpty")
				if (list.isEmpty())
					outFile << "list is empty\n";
				else
					outFile << "list is not empty\n";
			else if (command == "IsFull")
			{
				if (list.isFull())
					outFile << "List is full\n";
				else
					outFile << "List is not full\n";
			}
			else if (command == "PutItem")
			{
				inFile >> number;
				list.putItem(number);
			}
			else if (command == "DeleteItem")
			{
				inFile >> number;
				list.deleteItem(number);
			}

			else if (command == "GetLength")
				outFile << list.getLength() << "\n";
			else if (command == "PrintList")
			{
				outFile << "List Items: ";
				int value;
				for (int index = 0; index < list.getLength(); index++)
				{
					value = list.getAt(index);
					outFile << value << " ";
				}
				outFile << "\n";
			}

			else if (command == "GetAt")
			{
				int index;
				inFile >> index;
				outFile << "Item at index " << index << " is:" << list.getAt(index) << endl;
			}
			else
				outFile << "Unrecognized command";
			inFile >> command;
			
		} // try

		catch (FullList)
		{
			outFile << "List is full, Insertion failed" << endl;
			inFile >> command;
		}
		catch (DuplicateItem)
		{
			outFile << "Duplicate Item, Insertion failed" << endl;
			inFile >> command;
		}
		catch (OutOfBound)
		{
			outFile << "Index is out of range" << endl;
			inFile >>command;
		}
		catch (ItemNotFound)
		{
			outFile << "Item is not in the list" << endl;
			inFile >> command;
		}
	} // while
} // testIntegerList

void testStudentList()
{
  UnsortedList<Student> studentList(10);
  string command;
  ifstream inFile;
  ofstream outFile;
  inFile.open("studcommands.txt");
  outFile.open("outFile.txt");
  Student number;
  string name;
  inFile >> command;

  while (command != "Quit") {
    try {
      if (command == "MakeEmpty")
	(studentList.makeEmpty());
      else if (command == "IsEmpty") {
	if (studentList.isEmpty())
	  outFile << "list is empty\n";
	else
	  outFile << "list is not empty\n";     
      } else if (command == "IsFull") {
	if (studentList.isFull())
	  outFile << "List is full\n";
	else
	  outFile << "List is not full\n";
      } 
      else if (command == "PutItem")
	{
	  inFile >> number;
	  studentList.putItem(number);
	}
      else if (command == "DeleteItem")
	{
	  inFile >> number;
	  studentList.deleteItem(number);
	}

      else if (command == "GetLength")
	outFile << studentList.getLength() << "\n";
      else if (command == "PrintList")
	{
	  outFile << "List Items: ";
	  Student value;
	  for (int index = 0; index < studentList.getLength(); index++)
	    {
	      value = studentList.getAt(index);
	      outFile << value << " ";
	    }
	  outFile << "\n";
	}

      else if (command == "GetAt")
	{
	  int index;
	  inFile >> index;
	  outFile << "Item at index " << index << " is:" << studentList.getAt(index) << endl;
	}
      else
	outFile << "Unrecognized command";
      inFile >> command;
			
    }
    catch (FullList)
      {
	outFile << "List is full, Insertion failed" << endl;
	inFile >> command;
      }
    catch (DuplicateItem)
      {
	outFile << "Duplicate Item, Insertion failed" << endl;
	inFile >> command;
      }
    catch (OutOfBound)
      {
	outFile << "Index is out of range" << endl;
	inFile >>command;
      }
    catch (ItemNotFound)
      {
	outFile << "Item is not in the list" << endl;
	inFile >> command;
      }
  } // while
}// test StudentList
