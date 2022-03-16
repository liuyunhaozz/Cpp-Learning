class ConstRef {
    public:
        ConstRef(int ii);
    private:
        int i;
        const int ci = 0;
        int &ri = i;
};

ConstRef::ConstRef(int ii) {
    i = ii;
    // ci = ii;
}

int main()
{
    ConstRef A(1);
    
    return 0;
}