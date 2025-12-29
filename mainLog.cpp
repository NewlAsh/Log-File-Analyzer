#include <bits/stdc++.h>
using namespace std;



class logEntry{
    private:
        string level;
        string message;
        string timestamps;

    public:
        logEntry(const string& lvl, const string& msg, const string& ts){
            level = lvl;
            message = msg;
            timestamps = ts;
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
        // vector<logEntry>logs;
        map<string,int>levelCNT;
        map<string,int>msgCNT;
        map<string,int>time;
        vector<string>errorTime;
        vector<string>warnTime;
        vector<string>warnMSG;
    public:
        logAnalyzer(const string& filename){
            ifstream fin(filename);
            string line;

            while(getline(fin, line)){
                string timestamp = line.substr(0,19);
                time[timestamp]++;
                size_t lvlstart = 20;
                
                size_t pos = line.find(' ', 20);

                
                string level = line.substr(lvlstart, pos-lvlstart);
                string message = line.substr(pos+1);
                if(level == "ERROR"){
                    errorTime.push_back(timestamp);
                }
                else if(level == "WARN"){
                    warnTime.push_back(timestamp);
                    warnMSG.push_back(message);
                }

                

                levelCNT[level]++;
                msgCNT[message]++;
                
            }

        }
        void summaryTXT(){
            ofstream fout("summary.txt");
            fout<<"Summary Of the LOG FILE"<<endl<<"-----------------------"<<endl<<endl<<endl;

            fout<<"LOG TIME RANGE: "<<endl;
            fout<<"From:  ";
            for(auto t : time){
                fout<<t.first<<endl;
                break;
            }
            fout<<"To:  ";
            auto tEnd = *time.rbegin();
            fout<<tEnd.first<<endl<<endl<<endl;

            fout<<"The counts of level are mentioned below"<<endl<<endl;

            int maxcntLEVEL=INT_MIN, maxcntMSG=INT_MIN, errorcnt=0, warncnt=0;
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
            for(const auto& e : levelCNT){
                if(e.first == "WARN"){
                    warncnt = e.second;
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

            fout<<"WARNINGS were shown and following are the timestamps:"<<endl;
            for(auto wt : warnTime){
                fout<<wt<<endl;
            }
            fout<<endl;
            
            fout<<"ERROR was shown and following are following timestamps:"<<endl;
            for(auto et : errorTime){
                fout<<et<<endl;
            }
            fout<<endl;

            fout<<"MOST FREQUENT LEVEL SEEN: "<<"\""<<maxLEVEL<<"\""<<", that occured "<<maxcntLEVEL<<" times"<<endl;
            fout<<"MOST FREQUENT MESSAGE NOTICED WAS: "<<"\""<<maxMSG<<"\""<<", that occured "<<maxcntMSG<<" times"<<endl<<endl<<endl;

            if(errorcnt>1){
                fout<<"ERROR faced for more than once, take actions accordingly."<<endl<<endl;
            }
            if(warncnt>1){
                fout<<"WARNING was shown for the following reasons: "<<endl;
            }
            for(const auto m : warnMSG){
                fout<<m<<endl;
            }
            fout<<endl<<endl<<endl;
            fout<<"END OF SUMMARY"<<endl;
            
        }
};


int main() {
    
    
    logAnalyzer analyze("log.txt");
    analyze.summaryTXT();

    return 0;



}

