#include "board.h"
#include "memtrace.h"
#include "gtest_lite.h"
#include <sstream>

using std::cin;
using std::cout;

//#define JTEST
#if !defined(SIM)
int main()
{
    INPUT *i1 = new INPUT();
    INPUT *i2 = new INPUT();

    TEST(Gate, constructor)
    {
        AND a(0);
        EXPECT_EQ(0, a.getID());
        EXPECT_STREQ("AND", a.getName().c_str());
        EXPECT_EQ(NULL, a.getVal());
    }
    END
    TEST(Gate calc, _in00)
    {
        AND a(i1,i2,0);
        OR o(i1,i2,0);
        XOR xo(i1,i2,0);


        i1->changeValue(0);
        i2->changeValue(0);

        EXPECT_FALSE(a.calculate());
        EXPECT_FALSE(o.calculate());
        EXPECT_FALSE(xo.calculate());
    }
    END
    TEST(Gate calc, _in01)
    {
        AND a(i1,i2,0);
        OR o(i1,i2,0);
        XOR xo(i1,i2,0);


        i1->changeValue(0);
        i2->changeValue(1);

        EXPECT_FALSE(a.calculate());
        EXPECT_TRUE(o.calculate());
        EXPECT_TRUE(xo.calculate());
    }
    END
    TEST(Gate calc, _in10)
    {
        AND a(i1,i2,0);
        OR o(i1,i2,0);
        XOR xo(i1,i2,0);

        i1->changeValue(1);
        i2->changeValue(0);

        EXPECT_FALSE(a.calculate());
        EXPECT_TRUE(o.calculate());
        EXPECT_TRUE(xo.calculate());
    }
    END
    TEST(Gate calc, _in11)
    {
        AND a(i1,i2,0);
        OR o(i1,i2,0);
        XOR xo(i1,i2,0);

        i1->changeValue(1);
        i2->changeValue(1);

        EXPECT_TRUE(a.calculate());
        EXPECT_TRUE(o.calculate());
        EXPECT_FALSE(xo.calculate());
    }
    END
    TEST(Gate calc NOT-OUT, 0-1)
    {
        NOT n(i1,0);
        OUTPUT o(i1,0);

        i1->changeValue(0);
        EXPECT_TRUE(n.calculate());
        EXPECT_FALSE(o.calculate());

        i1->changeValue(1);
        EXPECT_FALSE(n.calculate());
        EXPECT_TRUE(o.calculate());
    }
    END
    TEST(Gate, write)
    {
        i1->changeValue(1);
        i2->changeValue(0);

        AND a(i1,i2,0);
        OR o(i1, &a, 0);

        a.calculate();
        o.calculate();

        EXPECT_FALSE(a.getVal());
        EXPECT_TRUE(o.getVal());

        std::stringstream ss;
        string temp;

        a.write(ss);
        getline(ss, temp);

        EXPECT_STREQ("AND id: 0 val: 0", temp.c_str());
        
        o.write(ss);
        getline(ss, temp);

        EXPECT_STREQ("OR id: 0 val: 1", temp.c_str());
    }
    END
    TEST(List, constructor and stored type)
    {
        
        List l;
        List valL(new AND);

        EXPECT_STREQ("", l.getType().c_str());
        EXPECT_STREQ("AND", valL.getType().c_str());

        valL.add(new AND);
        l.add(new OR);
        EXPECT_STREQ("AND", valL.getType().c_str());
        EXPECT_STREQ("OR", l.getType().c_str());

        valL.add(new OR);
        EXPECT_STREQ("multiple types", valL.getType().c_str());
    }
    END
    TEST(List, add-remove)
    {
        List l;
        EXPECT_EQ((size_t)0, l.count());

        l.add(new AND);
        EXPECT_EQ((size_t)1, l.count());

        l.add(new AND);
        EXPECT_EQ((size_t)2, l.count());

        l.remove(0);
        EXPECT_EQ((size_t)1, l.count());
        
        EXPECT_ANY_THROW(l.remove(10));
    }
    END
    //board.clalculate is formatted so tests need multiple getline-s to get to actual info
    TEST(Board, circuit1)
    {
        Board b;

        b.prepareCircuit("inputs/test1.txt");

        EXPECT_EQ(2, b.types());
        EXPECT_EQ(1, b.inputNum());

        EXPECT_TRUE(nullptr == b.findType("AND"));

        std::stringstream ss;
        string temp;

        b.calculate("0",ss);
        std::getline(ss, temp);
        std::getline(ss, temp);
        std::getline(ss, temp);
        EXPECT_STREQ("OUTPUT id: 0 val: 0", temp.c_str());
        std::getline(ss, temp);

        b.calculate("1",ss);
        std::getline(ss, temp);
        std::getline(ss, temp);
        std::getline(ss, temp);
        EXPECT_STREQ("OUTPUT id: 0 val: 1", temp.c_str());
        std::getline(ss, temp);
    }   
    END
    TEST(Board, circuit2)
    {
        Board b;

        b.prepareCircuit("inputs/test2.txt");

        std::stringstream ss;
        string temp;

        b.calculate("00",ss);
        std::getline(ss, temp);
        std::getline(ss, temp);
        std::getline(ss, temp);
        EXPECT_STREQ("OUTPUT id: 0 val: 0", temp.c_str());
        std::getline(ss, temp);

        b.calculate("01",ss);
        std::getline(ss, temp);
        std::getline(ss, temp);
        std::getline(ss, temp);
        EXPECT_STREQ("OUTPUT id: 0 val: 0", temp.c_str());
        std::getline(ss, temp);

        b.calculate("11",ss);
        std::getline(ss, temp);
        std::getline(ss, temp);
        std::getline(ss, temp);
        EXPECT_STREQ("OUTPUT id: 0 val: 1", temp.c_str());
        std::getline(ss, temp);
    }   
    END
    TEST(Board, circuit3_write)
    {
        Board b;

        b.prepareCircuit("inputs/test2.txt");

        std::stringstream ss;
        string temp;

        b.calculate("01",ss);
        std::getline(ss, temp);
        std::getline(ss, temp);
        std::getline(ss, temp);
        EXPECT_STREQ("OUTPUT id: 0 val: 0", temp.c_str());
        std::getline(ss, temp);

        b.printAllResults(ss);

        std::getline(ss, temp);
        EXPECT_STREQ("INPUT id: 0 val: 0", temp.c_str());

        std::getline(ss, temp);
        EXPECT_STREQ("INPUT id: 1 val: 1", temp.c_str());

        std::getline(ss, temp);
        EXPECT_STREQ("", temp.c_str());

        std::getline(ss, temp);
        EXPECT_STREQ("AND id: 0 val: 0", temp.c_str());

        std::getline(ss, temp);
        EXPECT_STREQ("", temp.c_str());

        std::getline(ss, temp);
        EXPECT_STREQ("OUTPUT id: 0 val: 0", temp.c_str());
    }   
    END
    TEST(Board, bad_file)
    {
        Board b;

        EXPECT_THROW(b.prepareCircuit("asdjkfiksaf.txt"), const char*);
        EXPECT_THROW(b.prepareCircuit("inputs/test3.txt"), const char*);
        EXPECT_THROW(b.prepareCircuit("inputs/test4.txt"), const char*);
        EXPECT_THROW(b.prepareCircuit("inputs/test5.txt"), const char*);
    }   
    END
    TEST(Board, bad_input)
    {
        Board b;

        b.prepareCircuit("inputs/test2.txt");
        EXPECT_THROW(b.calculate(""), const char*);
        EXPECT_THROW(b.calculate("0"), const char*);
        EXPECT_THROW(b.calculate("000"), const char*);
    }   
    END 
    TEST(Board, complex circuit)
    {
        Board b;
        b.prepareCircuit("inputs/5-11.txt");

        std::stringstream ss;
        string temp;

        cout << "input : 00000\n";
        b.calculate("00000");
        b.calculate("00000",ss);
        std::getline(ss, temp);
        std::getline(ss, temp);
        std::getline(ss, temp);
        EXPECT_STREQ("OUTPUT id: 0 val: 0", temp.c_str());
        std::getline(ss, temp);


        cout << "input : 11111\n";
        b.calculate("11111");
        b.calculate("11111",ss);
        std::getline(ss, temp);
        std::getline(ss, temp);
        std::getline(ss, temp);
        EXPECT_STREQ("OUTPUT id: 0 val: 0", temp.c_str());
        std::getline(ss, temp);

        cout << "input : 01011\n";
        b.calculate("01011");
        b.calculate("01011",ss);
        std::getline(ss, temp);
        std::getline(ss, temp);
        std::getline(ss, temp);
        EXPECT_STREQ("OUTPUT id: 0 val: 1", temp.c_str());
        std::getline(ss, temp);

        ss.clear();
        b.printAllResults();
    }   
    END
    TEST(Board, jporta_input)
    {
        Board board;

        while (true)
        {
            try
            {
                cout << "Input file name: ";
                string fileIn;
                cin >> fileIn;
                board.prepareCircuit(fileIn);
                break;
            }
            catch(const char* e)
            {
                cout << e;
            }
        }

        cout << "finished building circuit \n\n";

        bool calcDone = false;
        while(true)
        {
            cout << "Command (calc, print, exit): ";
            string temp;
            cin >> temp;

            if(temp == "calc")
            {
                while(true)
                {
                    try
                    {
                        cout << "Input values (" << board.inputNum() << "): ";
                        string inp;
                        cin >> inp;
                        board.calculate(inp);
                        break;
                    }
                    catch(const char* e)
                    {
                        cout << e << '\n';
                    }
                }

                calcDone = true;
            }
            else if(temp == "print")
            {
                if(!calcDone)
                {
                    cout << "Call calc before printing\n";
                    continue;
                }

                /*
                    cout << "File name: ";
                    string outF;
                    cin >> outF;

                    std::ofstream out(outF);
                */
                
                //no file output for jporta, printed to cout
                board.printAllResults();

                //cout << "exported the circuit into: " << outF << "\n\n";
            }
            else if(temp == "exit")
            {
                break;
            }
            else
                cout << "unrecognized input" << endl;
        }
    }
    END

    delete i1;
    delete i2;
}
#endif