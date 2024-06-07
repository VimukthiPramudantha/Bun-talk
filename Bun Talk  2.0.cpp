#include<iostream>
#include <vector>
#include <iomanip>
using namespace std;

int adminBackGround();
int cashierBackGround();
int mainlogging();
int loggingBackground();
int adminBackGround();
int selectBitems();
int ViewBakeryItem();
int ncart();

struct User
{
	string name;
	int Id;
	string password;

};
struct Item
{
	int id;
	string Name;
	float price;
	int quantity;
};

struct Cart
{
	Item item;
	int quantity;

};

User admin;
vector<User> cashiers;
vector<Item> items;
vector<Cart> cart;

void printBill()
{
	cout << "Logging < Cashier < View Bakery Item < Select items <  view Cart < Print Bill " << endl << endl;

	cout << "\t      ************* BUN TALK ************" << endl << endl << endl;

	cout << "\t Item List " << endl << endl;
	cout << "-----------------------------------------------------------------" << endl;

	int noOfCartItems = cart.size();
	float total = 0;

	cout << left << setw(15) << "Item ID" << left << setw(20) << "Item Name" << left << setw(20) << "Item Quantity" << left << setw(10) << "Item Price" << endl
		<< endl;

	for (int i = 0; i < noOfCartItems; i += 1)
	{
		float itemTotalPrice = cart[i].quantity * cart[i].item.price;
		total += itemTotalPrice;

		cout
			<< left << setw(15) << cart[i].item.id << left << setw(20) << cart[i].item.Name << left << setw(20) << cart[i].quantity << left << setw(10) << itemTotalPrice << endl;
	}
	cout << "-----------------------------------------------------------------" << endl;

	cout << "Net Total - " << "                                        " << "Rs." << total << endl << endl << endl;

	cout << "----------------------------Thank You----------------------------" << endl;
	cout << "                          See You Again                         " << endl << endl;

	cout << "Please Call Our Hotline 0119966558 for Your Valued Suggestions   " << endl << "and Comments" << endl << endl << endl << endl;

	exit(0);
}

int ncart()
{
	cout << "Logging < Cashier < View Bakery Item < Select items <  view Cart " << endl << endl;

	int option;

	int noOfCartItems = cart.size();
	cout << "items :- " << endl;

	cout << left << setw(15) << "Item ID" << left << setw(20) << "Item Name" << left << setw(20) << "Item Quantity" << left << setw(10) << "Item Price" << endl << endl;

	for (int i = 0; i < noOfCartItems; i += 1)
	{
		cout << left << setw(15) << cart[i].item.id << left << setw(20) << cart[i].item.Name << left << setw(20) << cart[i].quantity << left << setw(10) << cart[i].quantity * cart[i].item.price << endl;
	}

	cout << endl << endl;
	cout << "\t1. Print Bill " << endl << "\t2. Back " << endl << "\t";
	cin >> option;

	switch (option)
	{
	case 1:
		system("cls");
		printBill();
		break;

	case 2:
		system("cls");
		ViewBakeryItem();
		break;

	}

	return 0;

}

int newBakeryItem()
{
	int option;
	cout << " Logging < Admin < Add New Bakery Items " << endl << endl;

	Item newItem;
	cout << "\tEnter Item Id - ";
	cin >> newItem.id;
	cout << "\tEnter Item Name - ";
	cin >> newItem.Name;
	cout << "\tEnter Item Price - ";
	cin >> newItem.price;
	cout << "\tEnter Item Quantity - ";
	cin >> newItem.quantity;
	items.push_back(newItem);

	cout << endl << endl << "\tPress 1 To Go Back - ";
	cin >> option;

	switch (option)
	{
	case 1:
		system("cls");
		adminBackGround();
		break;

	default:
		break;
	}

	return 0;
}

int selectBitems()
{
	cout << "Logging < Cashier < View Bakery Item < Select items " << endl << endl;
	int option;
	int quantity;

	int noOfItems = items.size();

	cout << left << setw(20) << "Item Name" << left << setw(10) << "Item ID" << left << setw(15) << "Item Price" << left << setw(10) << "Quantity" << endl << endl;
	for (int i = 0; i < noOfItems; i += 1)
	{
		cout << left << setw(20) << items[i].Name << left << setw(10) << items[i].id << left << setw(0) << "Rs." << left << setw(15) << items[i].price << left << setw(10) << items[i].quantity << endl;
	}


	cout << endl << endl;
	int itemId;
	cout << "\tSelect Item Id - ";
	cin >> itemId;
	cout << "\tSelect Quantity - ";
	cin >> quantity;

	for (int i = 0; i < noOfItems; i += 1) {
		Item item = items[i];
		if (item.id == itemId) {
			Cart cartItem;
			cartItem.item = item;
			cartItem.quantity = quantity;
			cart.push_back(cartItem);
		}
	}

	cout << endl << endl;

	cout << "\t1. Add More Items " << endl << "\t2. view Cart" << endl << "\t3. Back " << endl << "\t";
	cin >> option;

	switch (option)
	{
	case 1:
		system("cls");
		selectBitems();
		break;

	case 2:
		system("cls");
		ncart();
		break;

	case 3:
		system("cls");
		ViewBakeryItem();
		break;

	}

	return 0;
}

int addNewStaff()
{
	int option;
	cout << "Logging < Admin < Add staff Details " << endl << endl;

	User newuser;
	cout << "\tEnter id - ";
	cin >> newuser.Id;
	cout << "\tEnter Name - ";
	cin >> newuser.name;
	cout << "\tEnter Password - ";
	cin >> newuser.password;
	cashiers.push_back(newuser);

	cout << endl << endl << "\tPress 1 To Go Back - " << endl << "\t";
	cin >> option;

	switch (option)
	{
	case 1:
		system("cls");
		adminBackGround();
		break;

	default:
		cout << "Invalid Option..... !!!  ";
		break;
	}
	return 0;
}
void ViewStaffDeatils()
{
	int option;

	cout << "Logging < Admin < View Staff Details " << endl << endl;

	int noOfStarf = cashiers.size();

	cout << left << setw(25) << "Name" << left << setw(10) << "Id" << left << setw(10) << "Password" << endl << endl;

	for (int i = 0; i < noOfStarf; i += 1)
	{
		cout << left << setw(25) << cashiers[i].name << left << setw(10) << cashiers[i].Id << left << setw(10) << cashiers[i].password << endl;
	}

	cout << endl << endl << "\tPress 1. To Go Back " << endl << "\tPress 2. To Add Staff " << endl << "\t";
	cin >> option;

	switch (option)
	{
	case 1:
		system("cls");
		adminBackGround();
		break;

	case 2:
		system("cls");
		addNewStaff();
		break;

	default:
		cout << "****** Invalid Option ******";
		break;

	}
}

int ViewBakeryItemAdmin()
{
	cout << endl <<  "Logging < Admin <  View Bakery Items " << endl << endl;

	int option;
	int noOfItems = items.size();

	cout << left << setw(10) << "Item ID" << left << setw(20) << "Item Name" << left << setw(15) << "Item Price" << left << setw(10) << "Quantity" << endl << endl;
	for (int i = 0; i < noOfItems; i += 1)
	{
		cout << left << setw(10) << items[i].id << left << setw(20) << items[i].Name << left << setw(0) << "Rs." << left << setw(15) << items[i].price << left << setw(10) << items[i].quantity << endl ;
	}
	cout << endl << "\tPress 1 To Add Items " << endl << "\tPress 2 To Go Back " << endl << "\t";
	cin >> option;

	switch (option)
	{
	case 1:
		system("cls");
		newBakeryItem();
		break;

	case 2:
		system("cls");
		adminBackGround();
		break;

	}
	return 0;
}

int ViewBakeryItem()
{
	cout << "Logging < Cashier < View Bakery Item " << endl << endl;

	int option;
	int noOfItems = items.size();

	cout << left << setw(10) << "Item ID" << left << setw(20) << "Item Name" << left << setw(15) << "Item Price" << left << setw(10) << "Quantity" << endl << endl;
	for (int i = 0; i < noOfItems; i += 1)
	{
		cout << left << setw(10) << items[i].id << left << setw(20) << items[i].Name << left << setw(0) << "Rs." << left << setw(15) << items[i].price << left << setw(10) << items[i].quantity << endl;
	}


	cout << endl << endl << "\tSelect Option - " << endl << "\t1. Select items " << endl << "\t2. View Bill " << endl << "\t3. Back " << endl << "\t";
	cin >> option;

	switch (option)
	{
	case 1:
		system("cls");
		selectBitems();
		break;

	case 2:
		system("cls");
		ncart();
		break;

	case 3:
		system("cls");
		cashierBackGround();
		break;
	}
	return 0;
}

int adminBackGround()
{
	int option;

	cout << endl << endl << "Logging < Admin " << endl;

	cout << endl << endl << "\tSelect your option : " << endl;
	cout << "\t1. View Bakery Items " << endl;
	cout << "\t2. Add New Bakery Items " << endl;
	cout << "\t3. View Staff Details " << endl;
	cout << "\t4. Add Staff Details " << endl;
	cout << "\t5. Log Out " << endl;
	cout << "\t";
	cin >> option;

	switch (option)
	{
	case 1:
		system("cls");
		ViewBakeryItemAdmin();
		break;
	case 2:
		system("cls");
		newBakeryItem();
		break;
	case 3:
		system("cls");
		ViewStaffDeatils();
		break;

	case 4:
		system("cls");
		addNewStaff();
		break;

	case 5:
		system("cls");
		loggingBackground();

	}
	int(vimu);

	return 0;
}

void Adminlogging()
{
	string adminUser_name;
	string adminPassword;

	adminUser_name = "admin123";
	adminPassword = "admin12#";
	cout << "Logging < Admin " << endl << endl;

	for (int a = 1; a <=3; a++)
	{

	cout << "\tEnter Your User Name : ";
	cin >> adminUser_name;
	cout << "\tEnter Password : ";
	cin >> adminPassword;



		if ((adminUser_name == "admin123") && (adminPassword == "admin12#"))
		{
			cout << " " << endl;
			cout << "\t    Logging Successful...!   " << endl;
			adminBackGround();
		}
		else
		{
			cout << " " << endl;
			cout << "Logging Failed!" << endl << endl;
		}
		int(vimu);

	}

}

int cashierBackGround()
{
	cout << "Logging < Cashier " << endl;

	int option;

	cout << endl << endl << "\tSelect your option : " << endl;
	cout << "\t1. View Bakery Items " << endl;
	cout << "\t2. Log Out " << endl << endl << "\t";
	cin >> option;

	switch (option)
	{
	case 1:
		system("cls");
		ViewBakeryItem();
		break;
	case 2:
		system("cls");
		loggingBackground();
		break;

	}
	int(vimu);
	return 0;
}

void cashierLogging()
{
	cout << "Logging < Cashier " << endl << endl;
	string cashierUser_name;
	string cashierPassword;

	cashierUser_name = "logging123";
	cashierPassword = "logging12#";

	for (int a = 1; a <= 3 ; a++)
	{


		cout << "\tEnter your User Name : ";
		cin >> cashierUser_name;
		cout << "\tEnter Your Password : ";
		cin >> cashierPassword;


		if ((cashierUser_name == "logging123") && (cashierPassword == "logging12#"))
		{

			cout << endl << "\tLogging successful..." << endl << endl;
			cashierBackGround();
		}
		else
		{
			cout << endl << "\tLogging Failed.....! " << endl << endl;
		}

	}

}

int loggingBackground()
{

	int option;
	cout << "Logging " << endl;
	cout << endl << endl << "\t\t*** Welcome to Bun Talk *** " << endl << endl;

	cout << "\tSelect the option " << endl << "\t1 = Admin" << endl << "\t2 = Cashier" << endl;
	cout << "\t";
	cin >> option;

	switch (option)
	{
	case 1:
		system("cls");
		Adminlogging();
		break;
	case 2:
		system("cls");
		cashierLogging();
		break;

	}
	return 0;
}

void Help()
{
	int option;

	cout << "Login < Help " << endl << endl;
	cout << "\tStep 01" << endl << "\tPress Logging " << endl << endl;
	cout << "\tStep 02" << endl << "\tEnter Your User Name " << endl << endl;
	cout << "\tStep 03" << endl << "\tEnter Your Password " << endl << endl;
	cout << "\tStep 04" << endl << "\tLogin " << endl << endl;
	cout << "\tIf You Have Any Doubt :- " << endl << "\tContact num : +94119966558" << endl << "\tOur Email : buntalk@gmail.com " << endl << endl;

	cout << "Press 1 to Main Manu - ";
	cin >> option;

	switch (option)
	{
	case 1:
		system("cls");
		mainlogging();
		break;

	default:
		break;
	}
	return;
}
int mainlogging()
{
	cout << "Login " << endl << endl;

	int option;

	cout << "\tSelect option " << endl << "\t1 = Login " << endl << "\t2 = Help " << endl << "\t3 = Exit " << endl << "\t";
	cin >> option;

	switch (option)
	{
	case 1:
		system("cls");
		loggingBackground();
		break;

	case 2:
		system("cls");
		Help();
		break;
	case 3:
		exit(0);
		break;
	}
	return 0;
}

int main()
{
	float id;
	string name;
	string password;


	Item fishBun;
	fishBun.id = 111;
	fishBun.Name = "Fish Bun";
	fishBun.quantity = 10;
	fishBun.price = 70;
	items.push_back(fishBun);

	Item sosejasBun;
	sosejasBun.id = 112;
	sosejasBun.Name = "Sosejas Bun";
	sosejasBun.quantity = 14;
	sosejasBun.price = 120;
	items.push_back(sosejasBun);

	Item cheeseCake;
	cheeseCake.id = 113;
	cheeseCake.Name = "Cheese Cake";
	cheeseCake.quantity = 13;
	cheeseCake.price = 150;
	items.push_back(cheeseCake);

	Item cinnamonRolls;
	cinnamonRolls.id = 114;
	cinnamonRolls.Name = "Cinnamon rolls";
	cinnamonRolls.quantity = 20;
	cinnamonRolls.price = 130;
	items.push_back(cinnamonRolls);

	User vimukthi;
	vimukthi.Id = 154;
	vimukthi.name = "Vimukthi Pramudantha";
	vimukthi.password = "admin12#";
	cashiers.push_back(vimukthi);

	User sandakan;
	sandakan.Id = 165;
	sandakan.name = "Sandakan Nipun";
	sandakan.password = "admin12#";
	cashiers.push_back(sandakan);

	User sanuja;
	sanuja.Id = 146;
	sanuja.name = "Sanuja Menath";
	sanuja.password = "logging12#";
	cashiers.push_back(sanuja);

	User chamod;
	chamod.Id = 145;
	chamod.name = "Chamod Gihan";
	chamod.password = "logging12#";
	cashiers.push_back(chamod);


	User sasara;
	sasara.Id = 144;
	sasara.name = "Sasara Kavishan";
	sasara.password = "logging12#";
	cashiers.push_back(sasara);



	mainlogging();


	return 0;
}