#include <iostream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;


void print(int a[], int sz) {
	for (int i = 0; i < sz;  i++ ) cout << a[i] << " ";
		cout << endl;
}

void CountingSort(int arr[], int sz) {
	int i, j, k;
	int idx = 0;
	int min, max;
 
	min = max = arr[0];
	for(i = 1; i < sz; i++) {
		min = (arr[i] < min) ? arr[i] : min;
		max = (arr[i] > max) ? arr[i] : max;
	}
 
	k = max - min + 1;
	/* creates k buckets */
	int *B = new int [k]; 
	for(i = 0; i < k; i++) B[i] = 0;

	for(i = 0; i < sz; i++) B[arr[i] - min]++;
	for(i = min; i <= max; i++) 
		for(j = 0; j < B[i - min]; j++) arr[idx++] = i;
 
	//print(arr,sz);

	delete [] B;
}

int main(){
///////////Lectura de files.txt//////////
	int cc=0;
    int con=0;
    int numeros[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    string f="File_";
    string e=".txt";
    string concat;
    cc=100;
    int b=0;
    while (cc<=500) {
		con=cc;
		concat=f+to_string(con)+e;
        cout<<concat<<endl;
        string array[2];
        short x=0;
		string line="";
		string temp="";
		int d[100000]={0};
		int j=0;
		ifstream myfile (concat);

		if (myfile.is_open()){
			while (! myfile.eof() ){
				getline (myfile,line);
				array[x] = line;
				//cout << array[x] << endl;
				x++;
			}
			myfile.close();
		}
		else cout << "Error al abrir";


	/////////////////////////////////////////////  

	   for (int i=0;i<line.length();i++)
	   {
			if(line[i]=='[' ){}
			else{
				if(line[i]!=','){
					temp += line[i];
				}
				else{
					d[j]=stoi(temp);
					temp="";
					j++;
				}
			}
			
		}
		

		/////////////////////////////////////////////

		int n = sizeof(d) / sizeof(d[0]);
		cout << "Datos entrantes: \n";
		//print(d,n);       //Datos entrantes
		auto start = high_resolution_clock::now();
		CountingSort(d, n);	
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
		numeros[b]=duration.count();
		b++;
		cout << "\nDatos ordenados: \n";
		//print(d,n);		//Datos ordenados
		
		
        
        cc=cc+400;
    }
    
    
    cc=1000;
    while (cc<=100000) {
		con=cc;
		concat=f+to_string(con)+e;
        cout<<concat<<endl;
        
        string array[2];
        short x=0;
		string line="";
		string temp="";
		int d[100000]={0};
		int j=0;
		ifstream myfile (concat);

		if (myfile.is_open()){
			while (! myfile.eof() ){
				getline (myfile,line);
				array[x] = line;
				//cout << array[x] << endl;
				x++;
			}
			myfile.close();
		}
		else cout << "Error al abrir";


	/////////////////////////////////////////////  

	   for (int i=0;i<line.length();i++)
	   {
			if(line[i]=='[' ){}
			else{
				if(line[i]!=','){
					temp += line[i];
				}
				else{
					d[j]=stoi(temp);
					temp="";
					j++;
				}
			}
			
		}
		

		/////////////////////////////////////////////

		int n = sizeof(d) / sizeof(d[0]);
		cout << "Datos entrantes: \n";
		//print(d,n);       //Datos entrantes
		
		auto start = high_resolution_clock::now();
		CountingSort(d, n);	
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
		numeros[b]=duration.count();
		b++;
		cout << "\nDatos ordenados: \n";
		//print(d,n);		//Datos ordenados
        
        if (cc>=1000 and cc<10000){
			cc=cc+1000;
		}
		if (cc>=10000 and cc<1000000){
			cc=cc+10000;
		}
    }
    cout << "\nTIEMPO DE EJECICION: \n";
    for(unsigned int i = 0; i < 20; i++){
		
		cout<<numeros[i]<<" ";
	}
    
    return 0;
    
}
