#include<iostream>
#include<string>

using namespace std;

class Queue
{
private:
    string* data_;          // Pointer to dynamically allocated array
    size_t size_;      // Number of elements currently in the vector
    size_t capacity_;  // Capacity of the vector (how many elements it can hold)

public:
    Queue() : size_(0), capacity_(1) // Constructor
    {
        cout<<"constructor called"<<endl;
        data_ = new string[capacity_];  // Allocate memory for 1 element
    }
    

    Queue(const Queue& other)//copy constuctor
    {
        cout<<"copy constructor called"<<endl;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new string[capacity_];
        for(int i =0;i<size_;i++)   data_[i]=other.data_[i];
    }


    Queue& operator=(const Queue &rhs) //copy assignment operator
    {
        cout<<"copy assignment called "<<endl;
        if (this != &rhs) 
        {
            size_ = rhs.size_;
            capacity_ = rhs.capacity_;
            delete[] data_; // clear what was there before
            data_ = new string[capacity_];
            for(int i =0;i<size_;i++)   data_[i]=rhs.data_[i];
        }
        return *this;
    }


    Queue(Queue&& other)//move constuctor
    {
        cout<<"move constructor called"<<endl;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_=other.data_;

        // must delete cause you want to rid the data of other object
        other.size_=0;
        other.capacity_=1;
        other.data_=new string[other.capacity_];
    }


    Queue& operator=(Queue &&rhs) //move assignment operator
    {
        cout<<"move assignment called"<<endl;
        if (this != &rhs)
        {
            size_ = rhs.size_;
            capacity_ = rhs.capacity_;
            delete[] data_; // clear what was there before
            data_ = rhs.data_;

            // must delete cause you want to rid the data of rhs object
            rhs.size_=0;
            rhs.capacity_=1;
            rhs.data_=new string[rhs.capacity_];
        }
        return *this;
    }

    
    // Destructor
    ~Queue()
    {
        cout<<"destructor called"<<endl;
        delete[] data_;  // Free dynamically allocated memory
    }


    // Method to add an element to the back of queue
    void push(const string& value)
    {
        if (size_ == capacity_) resize();  // Resize if capacity is reached

        data_[size_] = value;
        size_++;
    }


    // Method to remove an element from the front of queue
    string pop()
    {
        if (size_ == 0) return "Nothing to pop";
        string popped = data_[0];
        for(int i=1;i<size_;i++) data_[i-1]=data_[i];
        size_--;
        return popped;
    }


    //return first element
    string front() const
    {
        if (size_ == 0) return "Empty queue";
        else return data_[0];
    }


    //return last element
    string back() const
    {
        if (size_ == 0) return "Empty queue";
        else return data_[size_-1];
    }


    // check is queue is empty 
    bool isEmpty() const
    {
        if(size_==0)return true;
        else return false;
    }


    // Method to get the size of the vector
    size_t getSize() const { return size_; }

private:
    // Helper method to resize the vector when capacity is reached
    void resize() 
    {
        capacity_ *= 2;  // Double the capacity
        string* newData = new string[capacity_];  // Allocate larger array

        // Copy old data to new array
        for (size_t i = 0; i < size_; i++)  newData[i] = data_[i];

        delete[] data_;  // Delete old array
        data_ = newData;  // Point to new array
    }

};


int main()
{
    Queue q1; // object created using constructor

    // Add elements to the queue
    q1.push("Jane");
    q1.push("Ana");
    q1.push("Bob");
    q1.push("Alan");
    q1.push("Tom");
    q1.push("Sarah");
    q1.push("Chris");
    q1.push("Jenn");

    //Queue q2(q1); // copy constructor called
    // Queue q2(move(q1)); // move constructor called
    // q1.pop();
    
    Queue q2;
    q2.push("Tim");
    q2.push("Kenny");
    q2.push("Beatriz");
    cout<<"BEFORE CHANGES!!"<<endl;
    cout<<"q1(front, back): " << "("<<q1.front()<<", "<<q1.back()<<")"<<endl;
    cout<<"q2(front, back): " << "("<<q2.front()<<", "<<q2.back()<<")"<<endl;

    q2=q1; //copy assignment
    //q2=move(q2);//move assignment

    cout<<"AFTER CHANGES!!"<<endl;
    cout<<"q1(front, back): " << "("<<q1.front()<<", "<<q1.back()<<")"<<endl;
    cout<<"q2(front, back): " << "("<<q2.front()<<", "<<q2.back()<<")"<<endl;

    return 0;
}
