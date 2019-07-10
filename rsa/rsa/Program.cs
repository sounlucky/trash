
using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void extended_euclidean(BigInteger a, BigInteger b, out BigInteger x, out BigInteger y, out BigInteger d)
        {
            BigInteger q = 0, r = 0, x1 = 0, x2 = 1, y1 = 1, y2 = 0;
            while (b > 0){
                q = a / b;
                r = a - q * b;
                x = x2 - q * x1;
                y = y2 - q * y1;
                a = b;
                b = r;
                x2 = x1;
                x1 = x;
                y2 = y1;
                y1 = y;
            }
            d = a;
            x = x2;
            y = y2;
        }

        static BigInteger find_d(BigInteger e, BigInteger phi_n)
        {
            BigInteger d, x, y;
            extended_euclidean(e, phi_n, out x, out y, out d);
            if (d == 1){
                return x;
            }
            return 0;
        }

        static void messageProc(string[] args, out BigInteger e, out BigInteger n, out List<BigInteger> message)
        {
            message = new List<BigInteger>();
            if (args.Length < 4)
            {
                help();
                return;
            }
            if (!BigInteger.TryParse(args[1], out e) || (!BigInteger.TryParse(args[2], out n)))
                Console.WriteLine("could not parse key");

            for (int i = 3; i < args.Length; i++)
            {
                if (!BigInteger.TryParse(args[i], out BigInteger temp))
                {
                    Console.WriteLine("could not parse message");
                    return;
                }
                message.Add(temp);
            }
        }

        static bool is_prime(uint a)
        {
            if (a <= 1)
                return false;
            for (uint i = 2; i <= Math.Sqrt(a); i++)
            {
                if (a % i == 0)
                    return false;
            }
            return true;
        }

        static bool prime_pair(BigInteger phi, BigInteger num)
        {
            BigInteger a = phi, b = num, r = a % b;
            while (r != 0)
            {
                a = b;
                b = r;
                r = a % b;
            }
            if (b == 1)
                return true;
            else
                return false;
        }

        static BigInteger find_e(BigInteger phi_n)
        {
            List<BigInteger> eList = new List<BigInteger>();
            for (BigInteger i = 2; i < phi_n; i++){
                if (prime_pair(phi_n, i))
                    eList.Add(i);
            }
            Random rand = new Random();
            return eList[rand.Next() % eList.Count];
        }

        static void keygen(uint p, uint q)
        {
            BigInteger n = p * q;
            BigInteger phi_n = (p - 1) * (q - 1);
            BigInteger e = find_e(phi_n);
            BigInteger d = find_d(e, phi_n);
            if (d < 0)
                d = phi_n + d;
            Console.WriteLine(@"

     public : " + e + " " + n + @"
    private : " + d + " " + n + @"
          n : " + n + @"

pay extra attention to message length. 
it cannot exceed n!

            ");
        }

        static void keygenProc(string[] args)
        {
            if (args.Length < 3){
                help();
                return;
            }
            if (!uint.TryParse(args[1], out uint num1))
                Console.WriteLine("could not parse first number");
            else if (!uint.TryParse(args[2], out uint num2))
                Console.WriteLine("could not parse second number");
            else if (!(is_prime(num2) && is_prime(num1)))
                Console.WriteLine("both numbers must be prime!");
            else
                keygen(num1, num2);
        }

        static void crypt(string[] args)
        {
            messageProc(args, out BigInteger d, out BigInteger n, out List<BigInteger> message);
            Console.WriteLine("result: " + String.Join(" ", from number in message select BigInteger.Pow(number, (int)d) % n));
        }

        static void help()
        {
            Console.WriteLine(
@"

    RSA algorithm

availiable commands: 
           
keygen - 
    generating public/private keys
arguments required : 
    p q
            
 crypt - 
    crypting/encrypting message
arguments required : 
    <public/private key> <message as a sequence of numbers>

   cls - 
    clear console
");
        }

        static void Main(string[] args)
        {
            help();
            do
            {
                Console.Write('>');
                string[] input = Console.ReadLine().Split(' ');
                switch (input[0])
                {
                    case "keygen":
                        keygenProc(input);
                        break;
                    case "crypt":
                        crypt(input);
                        break;
                    case "help":
                        help();
                        break;
                    case "cls":
                        Console.Clear();
                        break;
                    default:
                        Console.WriteLine("no such command, type help to see availiable commands");
                        break;
                }
            } while (true);
        }
    }
}