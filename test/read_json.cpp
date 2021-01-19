#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
 
int main()
{
    // 以二进制形式读取json文件内容
    ifstream is("./test.json", ios::binary);
 
    if (!is.is_open())
    {
        cout << "open json file failed." << endl;
        return -1;
    }
    
    Json::Reader reader;
    Json::Value root;
 
    int nRole = 0;
    string strOccupation;
    string strCamp;
 
    // 解析json内容
    if (reader.parse(is, root))
    {
        nRole = root["role_id"].asInt();
        strOccupation = root["occupation"].asString();
        strCamp = root["camp"].asString();
    }
 
    is.close();
 
    cout << "role_id is: " << nRole << endl;
    cout << "occupation is: " << strOccupation << endl;
    cout << "camp is: " << strCamp << endl;
 
    return 0;
}
 
 
