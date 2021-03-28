#include <iostream>
using namespace std;
#include <string>
#include<math.h>
#include <fstream>
#include<iomanip>

int main(){
    int n; // end term of summation
    float x; // (pi)^4/x is the value at which function converges.
    ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
    cerr << "Unable to open file input.txt";
    exit(1);   // call system to stop
    }
    int i;
    float k;
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

    float pi = 2*acos(0.0);
    float ans = pow(pi,4)/(x);
    // cout << ans <<endl;
    // cout<<x;
    float res1 = 0;
    float res2 = 0;

    ofstream myfile;
    myfile.open("iteration.txt");
    if (myfile.is_open()){
        myfile << "True Value: ";
        myfile << std::fixed;
        myfile << setprecision(8);
        myfile << ans << endl ;
    }
    float case1[n];
    float case2[n];
    float error1[n];
    float error2[n];

    for (int j=1; j<=n ; j++){
        res1+= (pow(j,-4));
        float err1 = abs(res1-ans)*100/(ans);
        case1[j-1] = res1;
        error1[j-1] = err1;
        myfile << "Approximate value from 1 to " << j << " is :";
        myfile << res1 << endl ;
        myfile << "True Percent relative error for 1 to " << j << " is :";
        myfile << err1 << endl ;
    }
    myfile << "\n \n ";


    for (int j=n; j>=1 ; j--){
        res2+= (pow(j,-4));
        float err2 = abs(res2-ans)*100/(ans);
        case2[n-j] = res2;
        error2[n-j] = err2;
        myfile << "Approximate value from " << j  <<" to 1 is :";
        myfile << res2 << endl ;
        myfile << "True Percent relative error for " << j <<" to 1 is :";
        myfile << err2 << endl ;
    }

    myfile << "\n \n ";
    // myfile << "Approximate value from " << n  <<" to 1 is :";
    // myfile << res2 << endl ;
    // myfile << "True Percent relative error for " << n <<" to 1 is :";
    // myfile << err2 << endl ;
    // myfile << "\n \n ";

    float err1 = abs(res1-ans)*100/(ans);
    float err2 = abs(res2-ans)*100/(ans);

    

    std::cout << std::fixed;
    cout<<std::setprecision(8);
    ofstream myfile1;
    myfile1.open("output.txt");
    if (myfile1.is_open()){
        myfile1 << "True Value: ";
        myfile1 << std::fixed;
        myfile1 << setprecision(8);
        myfile1 << ans << endl ;
        myfile1 << "Approximate value from 1 to " << n << " is :";
        myfile1 << res1 << endl ;
        myfile1 << "True Percent relative error for 1 to " << n << " is :";
        myfile1 << err1 << endl ;
        myfile1 << "Approximate value from " << n  <<" to 1 is :";
        myfile1 << res2 << endl ;
        myfile1 << "True Percent relative error for " << n <<" to 1 is :";
        myfile1 << err2 << endl ;}  

    

    fstream fout;
    fout << std::fixed;
    fout << setprecision(8);
    fout.open("report1.csv",ios::out | ios :: app);
    
    fout << "Terms" << ",";
    fout << "True Value" << ",";
    fout << "Case-1 Approx value" << ",";
    fout << "Case-2 Approx Value" << "," ;
    fout << "Case-1 True Relative error" << ",";
    fout << "Case-2 True Relative error";
    fout << "\n";

    for (int i=0;i<n;i+=1){
        
        fout << (i+1) << ",";
        fout << ans << "," ;
        fout << case1[i] << "," ;
        fout << case2[i] << ",";
        fout << error1[i] << ",";
        fout << error2[i] << ",";
        fout << "\n";
    }       
}