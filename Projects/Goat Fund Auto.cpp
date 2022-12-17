#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>

using namespace std;

void getParams(map<string,vector<string>> &params){
    string swagger = "@swagger_auto_schema(manual_parameters = [";
    for (auto param : params) {
        string type = param.first;
        for (string s : param.second) {          
            cout << s << "_param = openapi.Parameter(\'" << s << "\', openapi.IN_QUERY, description = \'"<<s<<"\', type = openapi.TYPE_" << type << ")\n";
            swagger += s + "_param, ";
        }
    }
    swagger += "])\n";
    cout << swagger;



}

int main()
{
    map<string, vector<string>> params;
    params["INTEGER"] = { "investment_order_id","recieving_partner_id"};
    params["FLOAT"] = {  };
    params["STRING"] = { "customer_payment_ref_id", };
    //params["BOOL"] = { "c","d" };
    //params["STRING"] = { "e","f" };
    getParams(params);

    return 0;
}
