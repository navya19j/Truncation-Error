#include <iostream>
using namespace std;
#include <string>
#include<math.h>
#include <fstream>
#include<iomanip>

long int fac(int n){
    int f = 1;
    for (int i=1; i<=n;i++){
        f = f*i;
    }
    return f;
}

int main(){
    int n; //number of significant figures.
    double x; // Value/pi at which approximation is to be calculated.
    ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
    cerr << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
    }
    int i;
    double k;
    i = 0;
    int arr[2]; //initializing an array of length of lines in input file
    while (inFile>>k){
        if (i==0){
            arr[i] = k;
            n = arr[0];
        }
        else{
            arr[i] = k;
            x = k;
        }
        i++;
    }
    inFile.close();

    long double pi = 2*acos(0.0);
    long double y = pi*x;
    long double error_a = 0.5*pow(10,2-n);
    long double res = pow(-1,0)*pow(y,0)/fac(0); // for only a single term
    int j = 2;
    ofstream myfile;
    myfile.open("output.txt");
    if (myfile.is_open()){
        myfile << "For 1 term, approximate value: ";
        myfile << std::fixed;
        myfile << setprecision(n);
        myfile << res << endl ;
    }
    while ((pow(y,j)/fac(j))*100/(res)>=error_a){
        res += pow(-1,j/2)*pow(y,j)/fac(j);
        j+=2;
        double err = (pow(y,j)/fac(j))*100/(res);
        if (myfile.is_open()){
        myfile << "For " << j/2 << " term, approximate value : ";
        myfile << res << endl ;
        myfile << "For " << j/2 << " term, truncation error: ";
        myfile << err << endl ;
        }
        /*cout<<res<<endl;
        cout<<err<<endl;*/
    }
    if (myfile.is_open()){
        myfile << "Number of terms required : " << (j/2) << endl;
        myfile << "Approximate value: "<< res;
        }
    /*cout<<n<<endl;
    cout<<x;*/
}
