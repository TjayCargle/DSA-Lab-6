#pragma once
template <typename Type>
class BST
{
private:
	struct Node
	{
		Type mData;
		
		Node * mLeft = nullptr;
		Node* mRight = nullptr;
		unsigned int mKids = 0;
	};

	Node* mRoot = nullptr;
	
public:


	/////////////////////////////////////////////////////////////////////////////
	// Function : Constuctor
	// Notes : constucts an empty BST
	/////////////////////////////////////////////////////////////////////////////
	BST()
	{
		
	}

		/////////////////////////////////////////////////////////////////////////////
		// Function : Destructor
		// Notes : destroys the BST cleaning up any dynamic memory
		/////////////////////////////////////////////////////////////////////////////
	~BST()
	{

	}

		/////////////////////////////////////////////////////////////////////////////
		// Function : assignment operator
		/////////////////////////////////////////////////////////////////////////////
		BST& operator=(const BST& that)
		{
			return *this;
		}
	/////////////////////////////////////////////////////////////////////////////
	// Function: copy constructor
	/////////////////////////////////////////////////////////////////////////////
		BST(const BST& that)
		{

		}

	/////////////////////////////////////////////////////////////////////////////
	// Function : insert
	// Parameters :  v - the item to insert 
	/////////////////////////////////////////////////////////////////////////////
		void insert(const Type& v)
		{

			
			Node* curr = mRoot;
			Node* temp = new Node;
			temp->mData = v;
			if (mRoot == nullptr)
			{
				mRoot = temp;
			}
			else
			{
				while (true)
				{
					if (curr)
					{
						if (temp->mData < curr->mData) // Left
						{
							if (curr->mLeft == nullptr)
							{
								curr->mLeft = temp;
								curr->mKids++;
								break;
							}
							else
							{		
								curr = curr->mLeft;
								continue;
							}
						}
						else if (temp->mData >= curr->mData) // Right
						{

							if (curr->mRight == nullptr)
							{
								curr->mRight = temp;
								curr->mKids++;
								break;
							}
							else
							{
								curr = curr->mRight;
								continue;
							}
						}
					}
				

					break;
				}
			}
		}
		/////////////////////////////////////////////////////////////////////////////
		// Function : findAndRemove
		// Parameters : v - the item to find (and remove if it is found)
		// Return : bool - true if the item was removed, false otherwise
		/////////////////////////////////////////////////////////////////////////////
		void deleteNodeCase0(Node * curr)
		{
			delete curr;
			curr = nullptr;
			
		}
		void deleteNodeCase1(Node * parent, Node * curr)
		{
			if (parent != nullptr)
			{
				if (curr->mLeft != nullptr)
				{
					if (curr->mLeft->mData < parent->mData)
					{
						parent->mLeft = curr->mLeft;
						delete curr;
						curr = nullptr;
					}
					else
					{
						parent->mRight = curr->mLeft;
						delete curr;
						curr = nullptr;
					}

				}
				else
				{
					if (curr->mRight->mData < parent->mData)
					{
						parent->mLeft = curr->mRight;
						delete curr;
						curr = nullptr;
					}
					else
					{
						parent->mRight = curr->mRight;
						delete curr;
						curr = nullptr;
					}
				}
				parent->mKids--;
			}
			else
			{
				if (curr->mLeft != nullptr)
				{
					mRoot = curr->mLeft;
					delete curr;
					curr = nullptr;
				}
				else
				{
					mRoot = curr->mRight;
					delete curr;
					curr = nullptr;
				}
			}


		}
		bool findAndRemove(const Type& v)
		{
			bool found = false;
			Node* temp = new Node;
			temp->mData = v;
			Node* curr = mRoot;
			Node* parent = nullptr;
			int theKids = 0;
			while (true)
			{
				if (curr != nullptr)
				{
					if (temp->mData == curr->mData)
					{
						found = true;
						theKids = curr->mKids;
						switch (theKids)
						{
						case 0:
							deleteNodeCase0(curr);
							parent->mKids--;
							break;
						case 1:
							deleteNodeCase1(parent, curr);
							parent->mKids--;
						case 2:
							break;
						default:
							break;
						}
						break;
					}
					else if (temp->mData < curr->mData) // Left
					{
						parent = curr;
						curr = curr->mLeft;
						continue;
					}
					else if (temp->mData >= curr->mData) // Right
					{
						parent = curr;
						curr = curr->mRight;
						continue;
					}
				}
				break;
			}
			delete temp;
			return found;

		}

		/////////////////////////////////////////////////////////////////////////////
		// Function : find
		// Parameters : v - the item to find
		// Return : bool - true if the item was found, false otherwise
		/////////////////////////////////////////////////////////////////////////////
		bool find(const Type& v) const
		{
			bool found = false;
			Node* temp = new Node;
			temp->mData = v;
			Node* curr = mRoot;
			while (true)
			{
				if (curr)
				{
					if (temp->mData == curr->mData)
					{
						found = true;
					}
					else if (temp->mData < curr->mData) // Left
					{
						curr = curr->mLeft;
						continue;
					}
					else if (temp->mData >= curr->mData) // Right
					{
						curr = curr->mRight;
						continue;
					}
				}
				break;
			}
			delete temp;
			return found;

		}

		/////////////////////////////////////////////////////////////////////////////
		// Function : clear
		// Notes : clears the BST, cleaning up any dynamic memory
		/////////////////////////////////////////////////////////////////////////////
		void clear()
		{
			recursiveDelete(mRoot);
			mRoot = nullptr;
		}
		/////////////////////////////////////////////////////////////////////////////
		// Function : printInOrder
		// Notes : prints the contents of the BST to the screen, in ascending order
		/////////////////////////////////////////////////////////////////////////////
			void printInOrder() const
		{
			print(mRoot);
			cout << endl;
		}

		void print(Node* yo) const
			{
				if (yo)
				{
					if (yo->mLeft)
						print(yo->mLeft);
					cout << yo->mData << ' ';
					if (yo->mRight)
						print(yo->mRight);
				}
			}

		void recursiveDelete(Node* yo) 
		{
			if (yo!= nullptr)
			{
				
					recursiveDelete(yo->mLeft);
			
					recursiveDelete(yo->mRight);
				delete yo;
				yo = nullptr;
				
			}
		}


};
