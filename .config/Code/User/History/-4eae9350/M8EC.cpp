class Container
{
    public insert(auto it, int a)
    {
        *it = a;
    }

}
int main()
{
    Container C;
    C.insert(C.begin(), 5);
}