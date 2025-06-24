#include "json.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>

using json = nlohmann::json;
using namespace std;

// json序列化示例1
string func1()
{
    json js;
    js["msg_type"] = 2;
    js["from"] = "dzy";
    js["to"] = "msby";
    js["msg"] = "hello";

    string sendBuf = js.dump();
    // cout << js << endl;
    // cout << sendBuf.c_str() << endl;
    return sendBuf;
}

// json序列化示例2
string func2()
{
    json js;
    // 添加数组
    js["id"] = {1, 2, 3, 4, 5};
    // 添加key-value
    js["name"] = "zhang san";
    // 添加对象
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shuo"] = "hello china";
    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};
    // cout << js << endl;
    return js.dump();
}

// json序列化示例3
string func3()
{
    json js;

    // 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);

    js["list"] = vec;

    // 直接序列化一个map容器
    map<int, string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});

    js["path"] = m;

    string sendBuf = js.dump();
    // cout << js << endl;
    // cout << sendBuf.c_str() << endl;
    return sendBuf;
}

int main()
{
    // func1();
    // func2();
    // func3();
    string recvBuf = func3();
    json jsBuf = json::parse(recvBuf);
    // cout << jsBuf["msg_type"] << endl;
    // cout << jsBuf["from"] << endl;
    // cout << jsBuf["to"] << endl;
    // cout << jsBuf["msg"] << endl;

    // cout << jsBuf["id"] << endl;
    // auto arr = jsBuf["id"];
    // cout << arr[2] << endl;

    // auto msgjs = jsBuf["msg"];
    // cout << msgjs["zhang san"] << endl;
    // cout << msgjs["liu shuo"] << endl;

    vector<int> vec = jsBuf["list"];
    for(int &v : vec){
        cout<<v<<" ";
    }
    cout << endl;

    map<int,string> mymap=jsBuf["path"];
    for(auto &p : mymap){
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;

    return 0;
}
