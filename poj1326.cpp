//
//  poj1326.cpp
//  poj
//
//  Created by zp007 on 9/19/15.
//  Copyright (c) 2015 zp007. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string org, suborg;
    int i, mileage, res = 0;
    char ClassCode;
    while(1){
        getline(cin, org);
        if(org == "0")
            break;
        
        for(i = 0; org[i] > '9' || org[i] == ' '; i++);
        suborg = "";
        while(org[i] != ' '){
            suborg += org[i];
            i++;
        }
        mileage = atoi(suborg.c_str());
        ClassCode = org[++i];
        
        switch(ClassCode){
            case 'F':
                res += mileage * 2;
                break;
            case 'B':
                res += mileage;
                res += (mileage + 1) / 2;
                break;
            case 'Y':
                if(mileage >= 500)
                    res += mileage;
                else
                    res += 500;
                break;
            default:
                break;
        }
    }
    
    cout << res << endl;
    
    return 0;
}
