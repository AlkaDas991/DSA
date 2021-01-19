import java.util.*;
class Driver{
    public static void main(String[] args){
        Map<Character,Integer> mpp=new HashMap<Character,Integer>();
        mpp.put('<',1);
        mpp.put('(',3);
        mpp.put('{',5);
        mpp.put('[',7);
        mpp.put('>',2);
        mpp.put(')',6);
        mpp.put('}',10);
        mpp.put(']',14);
        Stack<Character> stk=new Stack<Character>();
        Scanner sc=new Scanner(System.in);
        boolean flag=true;
        System.out.println("Enter a string");
        String str=sc.next();
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)=='<' || str.charAt(i)=='(' || str.charAt(i)=='{'|| str.charAt(i)=='[')
                stk.push(str.charAt(i));
            else if(stk.empty()){
                flag=false;
                break;
            }
            else if(mpp.get(str.charAt(i))==2*mpp.get(stk.peek())){
                stk.pop();
            }
        }
        if(!stk.empty()) flag=false;
        if(flag)
            System.out.println("Balanced Parenthesis");
        else
            System.out.println("Not Balanced Parenthesis");
    }
}