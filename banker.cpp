#include <iostream>
#include <sstream>
#include <fstream>

int main(int argc, char *argv[])
{
        int task[5][3][3];//there will be 5 processes with 3 columns and 3 value in those columns
        int avail[3], ss[5], foo=0, check = 0;
        int arr[5] = {0, 0, 0, 0, 0};
        std::ifstream file;
        if(argc == 1)
        {
            std::cout << "Please enter a text file." << std::endl;
            return 0;
        }
        file.open(argv[1]);
        if(file.is_open())
        {
            std::string str;
            while(std::getline(file, str))
            {
              int bar = 0;
              std::istringstream ss(str); std::string val;
              while(std::getline(ss, val, ' '))
              {
                    if (bar != 0)
                    {
                        int num = stoi(val);
                        if(bar == 1 || bar == 2 || bar == 3)
                        {
                          task[foo][0][bar-1] = num;
                        }
                        if(bar == 4 || bar == 5 || bar == 6)
                        {
                          task[foo][1][bar-4] = num;
                        }
                        if(bar == 7 || bar == 8 || bar == 9)
                        {
                          avail[bar-7] = num;
                        }
                    }
                ++bar;
              }
              ++foo;
            }
          file.close();
        }
      for(int i = 0; i < 5; ++i)
      {
            task[i][2][0] = task[i][1][0] - task[i][0][0];
            task[i][2][1] = task[i][1][1] - task[i][0][1];
            task[i][2][2] = task[i][1][2] - task[i][0][2];
      }

      std::cout << "Process  Allocation \t Max \t\t Need"<< std::endl;

      for(int i = 0; i < 5; ++i)
      {
          std::cout << "p" << i << "\t " << task[i][0][0] <<" "<< task[i][0][1] << " " << task[i][0][2] << '\t';
          std::cout << '\t' << task[i][1][0] <<" "<< task[i][1][1] << " " << task[i][1][2] << '\t';
          std::cout << '\t'<<task[i][2][0] <<" "<< task[i][2][1] << " " << task[i][2][2] << std::endl;
      }
      int tmp=0;
      for(int j = 0; tmp <= 4; ++j)
      {
          int i = (j%6);
          if(task[i][2][0] <= avail[0] & task[i][2][1] <= avail[1] & task[i][2][2] <= avail[2] & arr[i] == 0)
          {
              avail[0] = avail[0]+task[i][0][0];
              avail[1] = avail[1]+task[i][0][1];
              avail[2] = avail[2]+task[i][0][2];
              ss[tmp] = i;
              ++tmp;
              check = 0;
              arr[i] = 1;
          }
          else
          {
              ++check;
          }
          if(check == 5)
          {
              break;
          }
      }
      if(check == 5)
      {
          std::cout << "Safe State." << std::endl;
      }
      else
      {
          std::cout << "Safe State. Safe Sequence: \n";
          for(int i = 0; i < 5; ++i){
            std::cout << 'p' << ss[i] << ' ';
          }
          std::cout << std::endl;
      }
}
