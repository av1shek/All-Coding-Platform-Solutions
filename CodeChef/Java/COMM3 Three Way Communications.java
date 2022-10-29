/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc = new Scanner(System.in);
		int tcases = sc.nextInt();
		while(tcases-->0)
		{
		    int r = sc.nextInt();
		    int cx = sc.nextInt();
		    int cy = sc.nextInt();
		    int hx = sc.nextInt();
		    int hy = sc.nextInt();
		    int sx = sc.nextInt();
		    int sy = sc.nextInt();
		    int count = 0;
		    if(Math.sqrt(Math.pow((cx-hx),2)+Math.pow((cy-hy),2))<=r)
		        count++;
		    if(Math.sqrt(Math.pow((cx-sx),2)+Math.pow((cy-sy),2))<=r)
		        count++;
		    if(Math.sqrt(Math.pow((sx-hx),2)+Math.pow((sy-hy),2))<=r)
		        count++;
		    if(count==0 || count==1)
		        System.out.println("no");
		    else System.out.println("yes");
		}
	}
}
