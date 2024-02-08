public class Place {
    public static void main(String args[]){
    int temp,r,rem=0;
    int n=4554;
    temp=n;
    while(n>0){
    r=n%10;
    rem=(remremrem)/r;
    n=n/10;
    }
    if(temp==rem){
    System.out.println("number is palindrome");
    }
    else{
    System.out.println("number not palindrome");
    }
    }
    }