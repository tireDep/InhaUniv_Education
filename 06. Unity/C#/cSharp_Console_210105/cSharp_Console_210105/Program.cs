using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cSharp_Console_210105
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Hello");
            Console.WriteLine("HelloWorld"); /// 개행 추가
            // >> 유니티에선 사용 할 일 x

            // ===================================================
            Console.WriteLine("===================================================");

            int a = 10;
            // int a = new int(); // 같은 의미
            // c#은 클래스화 되어 있음
            object b = 10;

            if (Int32.MaxValue > a)
            {
                // 값과 메소드들이 정의되어 있음
                Console.WriteLine(a);
                Console.WriteLine(a.ToString());
            }

            // ===================================================
            // >> Nullable
            Console.WriteLine("===================================================");

            int? c = null;

            // Console.WriteLine(c.HasValue);
            // 
            // c = 10;
            // Console.WriteLine(c.HasValue);
            // Console.WriteLine(c);
            // Console.WriteLine(c.Value);

            c = 10;

            if (c.HasValue)
                Console.WriteLine(c);
            else
                Console.WriteLine("Null");

            // ===================================================
            Console.WriteLine("===================================================");

            var va = 20;
            Console.WriteLine("Type : {0}, value : {1}", va.GetType(), va);

            var vb = 3.1414213;
            Console.WriteLine("Type : {0}, value : {1}", vb.GetType(), vb);

            var vc = "HelloWorld";
            Console.WriteLine("Type : {0}, value : {1}", vc.GetType(), vc);

            var vd = new int[] { 10, 20, 30 };
            Console.Write("Type : {0}, value : ", vd.GetType());
            foreach (var e in vd)
            {
                Console.Write("{0} ", e);
            }

            Console.WriteLine();

            // ===================================================
            Console.WriteLine("===================================================");

            Mammal mammal = new Dog();
            Dog dog;

            if (mammal is Dog)
            {
                dog = (Dog)mammal;
                dog.Bark();
            }
            // >> is : 객체가 해당 형식에 해당하는지를 검사하여 그 결과를 bool 값으로 반환

            Mammal mammal2 = new Cat();
            Cat cat = mammal2 as Cat;

            if (cat != null)
                cat.Meow();

            Cat cat2 = mammal as Cat;
            if (cat2 != null)
                cat2.Meow();
            else
                Console.WriteLine("cat2 is not a Cat");
            // >> as : 형식 변환 연산자와 같은 역할
            //         형 변환 연산자가 변환에 실패하는 경우 예외를 던지는 반면에
            //         as 연산자는 객체 참조를 null로 만든다는 것이 다름

        } // << : Main

        class Mammal
        {
            public void Nurse()
            {
                Console.WriteLine("Nurse()");
            }
        }

        class Dog : Mammal
        {
            public void Bark()
            {
                Console.WriteLine("Bark()");
            }
        }

        class Cat : Mammal
        {
            public void Meow()
            {
                Console.WriteLine("Meow()");
            }
        }

    } // << : class 

}
