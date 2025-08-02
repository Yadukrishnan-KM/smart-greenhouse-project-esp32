class Add {
  public:
    int16_t x;

    Add(){
      // default contructor
    }

    Add(int16_t xIn, int16_t yIn){
      x = xIn+yIn;
      print(x);
    }

    int sum(int a,int b)
    {
      x=a+b;
      return x;
    }
};

Add a=new Add(10,12);
int b=a.sum(2,3);
print(x);


Add summation(int a,int b)
{
  return Add(a,b);
}

 Add c=summation(10,12);
