using Internal;
using System;

namespace _2_7
{
    class Programm
    {
        static void Main()
        {
            Console.WriteLine("Please input a,b,c=");
            string inS = Console.ReadLine();
            string[] inSS=innS.Split(' ');
            double a = Convert.ToDouble(inSS[0]);
            double b = Convert.ToDouble(inSS[1]);
            double c = Convert.ToDouble(inSS[2]);
            double delta = b*b-4*a*c;
            double p = -b/(2*a);
            double q = Math.Sqrt(Math.Abs(delta))/(2*a);
            if(delta>=0)
            {
                Console.WriteLine("x1={0}",p+q);
                Console.WriteLine("x2={0}",p-q);
            }
            else
            {
                Console.WriteLine("x1={0}+{1}",p,q);
                Console.WriteLine("x2={0}-{1}i",p,q);
            }
        }
    }
}