package learning;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Code {
	public static BigInteger calc(int bit,BigInteger base,BigInteger n)//
	{
		BigInteger result=BigInteger.valueOf(1);
		BigInteger  t=BigInteger.valueOf(1);
	   for(int i=1;i<bit;i++)
	   {

	       t=t.multiply(base);
	       result =result.add(t);
	       if(result.compareTo(n)>0)
	        return result;
	   }
	   return result;
	}
	public static BigInteger Search(int i, BigInteger n)
	{   
		BigInteger l,r,basepos=null;
		r=n;
		l=BigInteger.valueOf(2);
		while(l.compareTo(r)<0)
	    {
			BigInteger mid;
	        mid = (l.add(r)).divide(BigInteger.valueOf(2));
	        if(calc(i,mid,n).compareTo(n)<0)//
	        {
	            l = mid.add(BigInteger.valueOf(1));
	            basepos= l;
	        }
	        else
	        {
	            r = mid;
	            basepos=r;
	        }

	    }
	    if(n.equals(calc(i,basepos,n)))
	     return basepos;
	    return BigInteger.valueOf(-1);
	}
	public static BigInteger solve(BigInteger n)
	{    
		BigInteger base = null;
		BigInteger consOne=new BigInteger("1");
		BigInteger consMinusOne=new BigInteger("-1");
		base=n.subtract(consOne);
		int i;
		for(i=60;i>=2;i--)
	      {
	          base =Search(i,n);
	          if(base.equals(consMinusOne))
	              continue;
	          else
	        	  break;
	      }
		return base;
	}
        /**
         *java版 读写测试数据
         *
         */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger n,res;
		int t,m;
		m=0;
		Scanner in =new Scanner(System.in);
		try{ 
			  in=new Scanner(new FileInputStream("D:\\B-large-practice.in"));
		   }
		  catch(Exception e){}
		t=in.nextInt();
		while(t>0)
	    {  
			t--;
	        n=in.nextBigInteger();
	        String s=null;
	        s="Case #"+(++m)+": "+solve(n)+"\n";
	       System.out.println(s);
	       try {
				FileOutputStream out = new FileOutputStream("D:\\BigResults.out",true);//追加写入文件
				try {
					out.write(s.getBytes());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			} catch (FileNotFoundException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
	    }
		in.close();
		
	}

}



