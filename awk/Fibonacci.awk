function F(n)
{
    if(n<=1){return n}
    return F(n-1)+F(n-2)
}

BEGIN{
    printf("Enter a positive integer: ")
    getline n < "-"
    n = int(n)
    print "FIB("n") = " F(n)
}