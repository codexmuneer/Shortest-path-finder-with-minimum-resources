#include <iostream>
using namespace std;


class node {

	int data;
	node* next;

public:
	node() { data = 0; next = NULL; }
	node(int v) {

		data = v;
	}

	void setdata(int  v) {

		data = v;
	}

    void setnext(node* v) {
		next = v;
	}

	node* getnext() {

		return next;
	}
    int getdata() {

		return data;
	}


};


class Queue : public node {

	node* front;
	node* rear;

public:

	Queue() {

		front = NULL;
		rear = NULL;
	}

	void enQueue(int x) {

		if (isEmpty()) {
			rear = new node(x);
			front = rear;
		}
		else {
			rear->setnext(new node(x));
			rear = rear->getnext();
		}
		
	}

	int deQueue()
	{   
        int x;

		if (front == NULL) {
			return 0;
		}
			
		node* temp = front;
		if (front == rear) {
			front = rear = NULL;
		}
		else {
            x = front->getdata();
			front = front->getnext();
		}
		
		delete (temp);

        return x;
	}

	int showFront() {
		if (front == NULL) {
			return 0;
		}
		return front->getdata();
	}

	int showRear() {
		if (rear == NULL) {
			return 0;
		}
		return rear->getdata();
	}

	bool isEmpty() {
		if (front == NULL && rear == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

    int sizeofQueue(){
        node* temp = front;
        int count = 0;
        while(temp != NULL){
            count += 1;
            temp = temp->getnext();
        }

        return count;
    }

    void display(){
        node* temp = front;
        while(temp != NULL){
            cout<<temp->getdata()<<" ";
            temp = temp->getnext();
        }
    }

	

};



int si;
int* sh = new int[si+1];
int count = 0;


// Structure of Linked Lists
struct info {
	int data;
	int weight;
	info* next;
};

class adjacencylist
{
    public:
	// Pointer To Pointer Array
	info** head;
	bool* visited;
	// Array of pointers to info struct
	// of size
	
    
    adjacencylist(int size){
        head = new info*[size];
	// Initialize pointer array to NULL
	    for (int i = 0; i < size; ++i) {
		    *(head + i) = NULL;
	    }
		visited = new bool[size];
		for(int i = 0; i < size; i++){
			visited[i] = false;
		}
    }

    void insert(int x,int y, int w){
			info* n1 = new info;
			info* n2 = new info;
			n1->data = y;
			n1->weight = w;
			n1->next = NULL;
			n2->data = x;
			n2->weight = w;
			n2->next = NULL;

			if(*(head + x)== NULL){
				*(head + x) = n1;
				*(head + (n1->data)) = n2;
			}
			else{
				info* temp1 = *(head + x);
				while(temp1->next != NULL){
					temp1 = temp1->next;
				}
				temp1->next = n1;
				if(*(head + (n1->data)) == NULL){
					*(head + (n1->data)) = n2;
				}
				else{
					info* temp2 = *(head + (n1->data));
					while(temp2->next != NULL){
						temp2 = temp2->next;
					}
					temp2->next = n2;
				}

			}
			

    }



// will find all possible paths
void findAllPaths(int start, int end, int size)
{
    // Mark all the vertices as not visited

    // Create an array to store paths
    int* path = new int[size];
	int* wpath = new int[size];
    int path_index = 0; // Initialize path[] as empty
	int w;
    // Call the recursive helper function to print all paths
    AllPathsUtil(start, end,w,visited, path,wpath ,path_index);
}
 
// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void AllPathsUtil(int u, int d,int w ,bool visited[], int path[],int wpath[] ,int& path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
	wpath[path_index] = w;
	int max = 0;
    path_index++;
		
    // If current vertex is same as destination, then print
    // current path[]
    if (u == d) {
        for (int i = 0; i < path_index; i++){
			path[i];
		}           
		int k = wpath[1];
		for (int i = 1; i < path_index; i++){
            wpath[i];
			if(wpath[i] < k){
				k = wpath[i];
			}
		}
		sh[count] = k;
		count+=1;
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current
        // vertex
		info* temp = *(head + u);
		// int m = temp->weight;
		while(temp != NULL){
			int adjVertex = temp->data; 
			
      		if (!visited[adjVertex]) {
				AllPathsUtil(adjVertex, d,temp->weight, visited, path,wpath,path_index);
			}

			temp = temp->next;
		}

    }
 
    // Remove current vertex from path[] and mark it as
    // unvisited
    path_index--;
    visited[u] = false;
}

 int trips(){
	int max = sh[0];
	for(int i = 0; i < count; i++){
		if(sh[i] > max){
			max = sh[i];
		}
	}
	
	return max;
 }


    void display(int size){
	// Print the array of linked list
	for (int i = 0; i < size; ++i) {
		info* temp = *(head + i);

		// Linked list number
		cout << i << "-->\t";

		// Print the Linked List
		while (temp != NULL) {
			cout << temp->data << " " <<temp->weight << " ";
			temp = temp->next;
		}

		cout << '\n';
	    }

    }

};


int main(){
	int vertices, edges ,v1,v2,weights,ans,x,y,tourists;
    vertices = si;
	cout<<"enter vertices and edges: "<<endl;
	cin>> vertices >> edges;
    adjacencylist l(vertices+1);
	cout<<"Enter vertices ,edges and weights: "<<endl;
	for(int i = 0; i < edges; i++){
		cin>> v1 >> v2 >> weights;
		l.insert(v1,v2,weights);

	}
    cout<<"Enter starting ,ending and tourists to see their trip"<<endl;
    cin>> x >> y >> tourists;
	if(x == y){
		cout<<"invalid"<<endl;
		
	}
	else{
		l.findAllPaths(x,y,vertices);
	ans = l.trips();
	int div = tourists/ans;

	if(ans*div != tourists){
		div++;
	}

	cout<<"total trips would take to transfer all the tourists are: "<<div<<endl;

	}




    return 0;
}


