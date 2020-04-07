public class dynamic extend stack{

    public dynamic()
    {
        super();
    }

    public dynamic(int size)
    {
        super();
    }
    @Override
    public void push(int val) // this push function must be in stack class and we are allowing the compl
                                // to use our push function
    {
        super.push(10); // with super i can even call a function 
    }
}