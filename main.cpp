/**
 * @file main.cpp
 * @brief includes the main user interface handling
 */

#include "board.h"
#include "memtrace.h"

using std::cin;
using std::cout;

/**
 * @brief   main loop for user
 *          1. reads in a txt file name and builds the circuit
 *          2. user can either
 *              1. calc: give the INPUT-s a starting value and display the value of the OUTPUT-s
 *              2. print: if calc has been called at least once prints the value of all gates into a file
 *              3. exit: exits the program
 *          3. passing anything else results in no error just a request for new input
 * 
 * @return int 
 */
#if defined(SIM)
int main()
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

            cout << "File name: ";
            string outF;
            cin >> outF;

            std::ofstream out(outF);

            board.printAllResults(out);

            cout << "exported the circuit into: " << outF << "\n\n";
        }
        else if(temp == "exit")
        {
            return 0;
        }
        else
            cout << "unrecognized input" << endl;
    }
    
    return 0;
}

#endif