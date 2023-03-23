using Internal;
using System;

namespace _2_8
{
    class Programm
    {
        static void Main()
        {
            Console.Write("请输入一个华氏温度");
            double f = Convert.ToDouble(Console.ReadLine());
            double c = 5.0d/9.0d*(f-32d);
            Console.WriteLine("对应于华氏温度{0}的摄氏温度为{1}",f,c);
        }
    }
}