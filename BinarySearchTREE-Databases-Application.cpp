#include <iostream>
using namespace std;

//Program Databases: With "Binary Search Tree" : Author : @_mhmdriduan11

struct Node {
	int data{};
	Node* left{};
	Node* right{};
};

void addDatabases(Node** superuser, int keyword){
	if ((*superuser) == nullptr)
	{
		Node* temp = nullptr ;
		temp = new Node();
		temp->data = keyword ;
		temp->left = temp->right = nullptr ;

		(*superuser) = temp ;
		(*superuser)->left = (*superuser)->right = nullptr ;

	}else if (keyword < (*superuser)->data)
	{
		addDatabases(&(*superuser)->left, keyword);
	}else if (keyword > (*superuser)->data)
	{
		addDatabases(&(*superuser)->right, keyword);
	}else{
		cout << "Data telah tersedia di dalam databases" <<  endl ;
	}
}
struct Node * minValue(struct Node* superuser){
	struct Node* temp = superuser ;
	while(temp && temp->left != nullptr){
		temp = temp->left ;
	}
	return temp ;
}
struct Node * deleteDatabases(struct Node* superuser, int keyword){
	if (superuser == nullptr)
	{
		return superuser ;
	}else if (keyword > superuser->data)
	{
		superuser->right = deleteDatabases(superuser->right, keyword);
	}else if (keyword < superuser->data)
	{
		superuser->left = deleteDatabases(superuser->left, keyword);
	}else{
		if (superuser->left == nullptr)
		{
			struct Node* temp = superuser->right ;
			delete superuser ;
			return temp ;
		}
		if (superuser->right = nullptr)
		{
			struct Node* temp = superuser->left ;
			delete superuser ;
			return temp ;
		}

		struct Node* temp = minValue(superuser->right);
		superuser->data = temp->data ;
		superuser->right = deleteDatabases(superuser->right, temp->data);

	}
	return superuser ;
}

//Display Databases:
void preorder(Node* superuser){
	if (superuser != nullptr)
	{
		cout << "\033[34m" << superuser->data << " " ;
		preorder(superuser->left);
		preorder(superuser->right);
	}
}
void inorder(Node* superuser){
	if (superuser != nullptr)
	{
		inorder(superuser->left);
		cout << "\033[34m" << superuser->data << " " ;
		inorder(superuser->right);
	}
}
void postorder(Node* superuser){
	if (superuser != nullptr)
	{
		postorder(superuser->left);
		postorder(superuser->right);
		cout << "\033[34m" << superuser->data << " " ;
	}
}
//User Interface:
int userInterface(){
	system("clear");
	int user{}, count{1};
	cout << "\n\t\033[31m   ====== DATABASES APPLICATION ======   \n\033[0m" ;
	string menu[]{"View Databases","Add Databases","Remove Databases","Close"};
	for(const auto get : menu){
		cout << " [" << count++ << "] " << get << endl ;
	} 
	cout << "Masukan[?] " ; cin >> user ;
	return user ;
}

int viewInterface(){
	system("clear");
	int user{},count{1};
	cout << "\n\t\033[31m   ====== VIEW - DATABASES APPLICATION ======   \n\033[0m" ;
	string menu[]{"Display-With-PreOrder","Display-With-InOrder","Display-With-PostOrder","Close"};
	for(const auto get : menu){
		cout << " [" << count++ << "] " << get << endl ;
	} 
	cout << "Masukan[?] " ; cin >> user ;
	return user ;
}

void view(Node* superuser){
		if (superuser != nullptr)
		{
			char status{};

					int temp = viewInterface();
					enum us{PREORDER=1,INORDER,POSTORDER,CLOSE};
				
					while(temp != CLOSE){
						switch(temp){
							case PREORDER:
								cout << "\n\t\033[31m   ====== DATABASES WITH PREORDER ====== \n\033[0m" ;
								preorder(superuser);
								break;
							case INORDER:
								cout << "\n\t\033[31m   ====== DATABASES WITH INORDER ====== \n\033[0m" ;
								inorder(superuser);
								break;
							case POSTORDER:
								cout << "\n\t\033[31m   ====== DATABASES WITH POSTORDER ====== \n\033[0m" ;
								postorder(superuser);
								break;
							default:
								system("pause");
								break;
						}

						cout << endl ; 
						back:
						cout << "\033[0mBack[y/n]: " ; cin >> status ;
						if (tolower(status) == 'y')
						{
							temp = viewInterface();
						}else if (tolower(status) == 'n')
						{
							break;
						}else{
							goto back;
						}
					}	

		
		}else{
			cout << "\n\t\033[32m   Databases Empty \n\033[0m\n" ;
		}
}
void handleClient(Node** superuser, string options){
	int user{};
	if (options == "add")
	{
		cout << "\n\t\033[32m   ====== [+] DATABASES [+] ====== \n\033[33m" ;
		cout << "Entry[+]: " ; cin >> user ;
		addDatabases(&(*superuser), user);
		cout << "\033[31mSuccesfully\033[0m" << endl; 

	}else if (options == "del")
	{
		if ((*superuser) != nullptr)
		{
 			cout << "\n\t\033[32m   ====== [-] DATABASES [-] ====== \n\033[33m" ;
			cout << "\033[32mDatabases: " ; inorder(*superuser);
			cout << "\n\033[33mEntry[-]: " ; cin >> user ;
			deleteDatabases((*superuser), user);
			cout << "\033[31mSuccesfully\033[0m" << endl;
		} 
		else{
			cout << "\n\t\033[32m   Databases Empty \n\033[0m\n" ;
		}
	}
}

int main(){
	char status{};
	Node* superuser ;
	superuser = nullptr ;
	int temp = userInterface();
	enum us {VIEW=1,ADD,DEL,CLOSE};
	while(temp != CLOSE){
		switch(temp){
			case VIEW:
				view(superuser);
				break;
			case ADD:
				handleClient(&superuser,"add");
				break;
			case DEL:
				handleClient(&superuser,"del");
				break;
			default:
				system("pause");
				break;
		}

		back:
		cout << "Back[y/n]: " ; cin >> status ;
		if (tolower(status) == 'y')
		{
			temp = userInterface();
		}else if (tolower(status) == 'n')
		{
			break;
		}else{
			goto back;
		}
	}
	
	cin.get();
	return 0 ;
}
