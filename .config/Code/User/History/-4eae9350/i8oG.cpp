class container
{
    public: int index = 0; int *ptr[];
    push(int args)
    {
        ptr[index]= new int*2;
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
        
    }

}