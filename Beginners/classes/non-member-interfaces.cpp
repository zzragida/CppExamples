namespace ns
{
    class  foo
    {
    public:
        void member()
        {

        }
    };

    void non_member(foo obj) 
    {
        obj.member();
    }
}

void non_member_interface()
{
    ns::foo obj;
    ns::non_member(obj);
}