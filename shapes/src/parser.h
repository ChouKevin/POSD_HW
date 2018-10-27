#if !defined(PARSER_H)
#define PARSER_H
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Parser{
    public:
        Parser(string input){
            this->splite(input);
        }
        string getShapeName(){
            return this->_shapeName;
        }
        vector<double> getParams(){
            return this->_params;
        }
        vector<string> splite(string input){
            stringstream ss(input);
            string token;
            vector<string> tokens;
            while(getline(ss, token, ' ')){
                tokens.push_back(token);
            }
            this->_shapeName = tokens.at(0);
            this->parseParam(tokens.at(1));
            return tokens;
        }
    private:
        void parseParam(string param){
            string num;
            for (auto const c : param){
                if(isdigit(c) || c == '.') num+=c;
                else{
                    if (num.length()){
                        this->_params.push_back(stod(num));
                        num = "";
                    }
                }
            }
        }
        string _shapeName;
        vector<double> _params;
};

#endif // PARSER_H
