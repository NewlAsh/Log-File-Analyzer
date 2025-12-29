#include <bits/stdc++.h>
using namespace std;

class logEntry{
    private:
        string level;
        string message;

    public:
        logEntry(const string& lvl, const string& msg){
            level = lvl;
            message = msg;
        }
    string getlevel() const{
        return level;
    }
    string getmsg() const{
        return message;
    }
};

class logAnalyzer{
    private:
        vector<logEntry>logs;
        map<string,int>levelCNT;
        map<string,int>msgCNT;
    public:
        logAnalyzer(const string& filename){
            ifstream fin(filename);
            string line;

            while(getline(fin, line)){
                size_t pos = line.find(' ');
                string level = line.substr(0,pos);
                string message = line.substr(pos+1, line.size());

                levelCNT[level]++;
                msgCNT[message]++;
                
            }

        }
        void summaryTXT(){
            ofstream fout("summary.txt");
            fout<<"Summary Of the LOG FILE"<<endl<<"-------------------------"<<endl<<endl<<endl;
            fout<<"The counts of level are mentioned below"<<endl<<endl;

            int maxcntLEVEL=INT_MIN, maxcntMSG=INT_MIN, errorcnt=0;
            string maxMSG, maxLEVEL;

            for(const auto& e : levelCNT){
                if(e.second>maxcntLEVEL){
                    maxcntLEVEL = e.second;
                    maxLEVEL = e.first;
                }
                fout<<e.first<<" :   "<<e.second<<endl;
            }
            for(const auto& e : levelCNT){
                if(e.first == "ERROR"){
                    errorcnt = e.second;
                }
                
            }
            fout<<endl<<endl;
            fout<<"The counts of message are mentioned below"<<endl<<endl;
            
            for(const auto& e : msgCNT){
                if(e.second>maxcntMSG){
                    maxcntMSG = e.second;
                    maxMSG = e.first;
                }
                fout<<e.first<<" :   "<<e.second<<endl;
            }
            fout<<endl<<endl;
            
            fout<<"SHORT SUMMARY BASED ON ITERATIONS:-"<<endl<<endl;

            fout<<"MOST FREQUENT LEVEL SEEN: "<<"\""<<maxLEVEL<<"\""<<", that occured "<<maxcntLEVEL<<" times"<<endl;
            fout<<"MOST FREQUENT MESSAGE NOTICED WAS: "<<"\""<<maxMSG<<"\""<<", that occured "<<maxcntLEVEL<<" times"<<endl<<endl<<endl;

            if(errorcnt>1){
                fout<<"ERROR faced for more than once, take actions accordingly."<<endl<<endl<<endl;
            }
            fout<<"END OF SUMMARY"<<endl;
            
        }
};


int main() {
    
    
    logAnalyzer analyze("log.txt");
    analyze.summaryTXT();

    return 0;



}

