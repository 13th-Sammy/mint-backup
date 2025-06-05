class container
{
    public: 
    int index = 0; int *ptr[];
    void push(int args)
    {
        ptr[index] = new int;
        *ptr[index] = args;
        index++;
    }
    ~container()
    {
        for(int i=0; i<=index; i++)
        {
            delete ptr[index];
        }
    }
    container()
    {
        for(int i=0; i<=index; i++)
            this->ptr[0]= new int;
    }

};
int main()
{
    container c;
    c.push(5);
}