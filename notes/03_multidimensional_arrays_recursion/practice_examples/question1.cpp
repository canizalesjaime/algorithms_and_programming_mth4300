#include<iostream>


using namespace std;

int recursive_pow(int base, int exp)
{
    if(exp==0) return 1;

    return base*recursive_pow(base,exp-1);
}

int main()
{
    int rows,cols;
    cout<<"Enter rows:"<<endl;
    cin>>rows;
    cout<<"Enter cols:"<<endl;
    cin>>cols;
    int matrix[rows][cols];

    for(int i = 0 ; i < rows; i++)
    {
        for(int j = 0 ; j < cols; j++)
        {
            if(i==0 && j==0)
            {
                matrix[i][j]=0;
            }
            else if(j%2==0)
            {
                matrix[i][j]=recursive_pow(i,j);
            }
            else
            {
                matrix[i][j]=0;
            }
        }
    }

    for(int i = 0 ; i < rows; i++)
    {
        for(int j = 0 ; j < cols; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

