#include <iostream>
#include <list>
using namespace std;

class Hashing
{
      int hash_bucket; // No. of buckets

      // Pointer to an array containing buckets
      list<int> *hashtable;

public:
      Hashing(int V); // Constructor

      // inserts a key into hash table
      void insert_key(int val);

      // deletes a key from hash table
      void delete_key(int key);

      // hash function to map values to key
      int hashFunction(int x)
      {
            return (x % hash_bucket);
      }

      void displayHash();
};

Hashing::Hashing(int b)
{
      this->hash_bucket = b;
      hashtable = new list<int>[hash_bucket];
}

// insert to hash table
void Hashing::insert_key(int key)
{
      int index = hashFunction(key);
      hashtable[index].push_back(key);
}

void Hashing::delete_key(int key)
{
      // get the hash index for key
      int index = hashFunction(key);

      // find the key in (inex)th list
      list<int>::iterator i;
      for (i = hashtable[index].begin();
           i != hashtable[index].end(); i++)
      {
            if (*i == key)
                  break;
      }
      // if key is found in hash table, remove it
      if (i != hashtable[index].end())
            hashtable[index].erase(i);
}

// display the hash table
void Hashing::displayHash()
{
      for (int i = 0; i < hash_bucket; i++)
      {
            cout << i;
             for (auto x : hashtable[i])
                  cout << " --> " << x;
      
            cout<<endl;
      }
}
// main program
int main()
{
      Hashing sr;
      int x;
      // array that contains keys to be mapped
      //int hash_array[] = {11, 12, 21, 14, 15};
      printf("1. Insert\n2. Search\n3. Display\n4. Exit");
      //int n = sizeof(hash_array) / sizeof(hash_array[0]);

      Hashing h(7); // Number of buckets = 7

    //// insert the keys into the hash table
    //for (int i = 0; i < n; i++)
    //      h.insert_key(hash_array[i]);
    //// display the Hash table
    //cout <<"Hash table created:";
    //out <<endl;
    //h.displayHash();

    //// delete 12 from hash table
    //h.delete_key(12);

    //// display the Hash table
    //out<<"Hash table after deletion of key 12:" ;
    //cout <<endl;
    //h.displayHash();

     while (1)
      {
            printf("\nEnter your choice: ");
            int ch;
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                  system("cls");
                  printf("Insert Mode\n");
                  printf("Input x: ");
                  scanf("%d", &x);
                  sr.insert_key(x);
                  break;
            case 2:
                  system("cls");
                  printf("Delete Mode\n");
                  printf("Input x: ");
                  scanf("%d", &x);
                  sr.delete_key(x);
                  break;
            case 3:
                  sr.displayHash();
                  break;
            case 4:
                  exit(0);
            default:
                  printf("Invalid\n");
            }
      }

      return 0;
}