#include<bits/stdc++.h>
#include "RailNetwork.cpp"
#include"Ticket.cpp"
using namespace std;
class Train{
    public: 
        int line;
        int start;
        int end;
        Train(){
            line = -1;
            start = -1;
            end = -1;
        }
};
// global variable 
fstream file;
string temp;
int n; 
vector<string> stationIndexing;
vector<vector<int>> edges;
vector<vector<int>> rails; 
vector<string> lines;
vector<int> shortest_path;
vector<Train> trains;
vector<string> split(const string& str, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
void stationListDistance(){
    // reading the distances
    file.open("lineDistance.txt", ios::in);  // opening file in reading mode 
    getline(file,temp);
    n = stoi(temp);
    for(int i = 0;i<n;i++){
        string temp;
        getline(file,temp);
        int u,v,x;
        vector<string> storage = split(temp,' ');
        u = stoi(storage[0]);
        v = stoi(storage[1]);
        x = stoi(storage[2]);
        vector<int> arr;
        arr.push_back(u);
        arr.push_back(v);
        arr.push_back(x);
        edges.push_back(arr);
    }
    file.close();
}
void stationIndexInput(){
    file.open("stationIndex.txt", ios::in);  // opening file in reading mode
    getline(file,temp);
    n = stoi(temp);
    // it stores the list of stations 
    for(int i = 0;i<n;i++){
        string temp;
        getline(file,temp);
        vector<string> storage = split(temp,' ');
         stationIndexing.push_back(storage[1]);
    }
    file.close();
}
void totalLines()
{
    file.open("totalLine.txt", ios::in);  // opening file in reading mode 
    getline(file,temp);
    n = stoi(temp);
    for(int i = 0;i<n;i++){
        string temp;
        getline(file,temp);
        vector<string> storage = split(temp,' ');
        lines.push_back(storage[0]);
        int m = stoi(storage[1]);
        getline(file,temp);
        vector<string> storage2 = split(temp,' ');
        vector<int> arr;
        for(int j=0;j<m;j++){
            arr.push_back(stoi(storage2[j]));
        }
        rails.push_back(arr);
    }
    file.close();
}
int findLine(int x){
    for(int i = 0;i < rails.size();i++){
        for(int j = 0;j < rails[i].size();j++){
            if(rails[i][j]==x) return i;
        }
    }
    return -1;
}
void matchTheTrains(int x,int y){
    unordered_map<int,vector<int>> maps;
    for(int i = 0;i < rails.size();i++){
        for(int j = 0;j < rails[i].size();j++){
            if(maps.count(rails[i][j])>0){
                maps[rails[i][j]].push_back(i);
            } else {
                vector<int> temp = {};
                temp.push_back(i);
                maps[rails[i][j]] = temp;
            }
        }
    }    
    Train train;
     train.line = findLine(x);
     train.start = x;
     train.end = x;
    // shortest path 
    for(int node : shortest_path){
        if(node==x) continue;
        vector<int> lines = maps[node];
        int prev = train.end;
        for(int line : lines){
            if(train.line == line){
                train.end = node;
                break;
            }
        }
        if(prev == train.end){
            Train temp;
                temp.start = train.end;
                temp.end = node;
                temp.line = lines[0];
                trains.push_back(train);
                train = temp;
        }
    }
    trains.push_back(train);
}
void printTrain(){
    for(Train train : trains){
        cout<<"Train "<<train.line+1<<": ["<<train.start+1<<" , "<<train.end+1<<"]"<<endl;
    }
}
int main(){
    stationIndexInput();
    stationListDistance();
    totalLines();
    RailNetwork railnetwork(stationIndexing.size());
    for(auto edge : edges){
        railnetwork.railNetworkInput(edge.at(0),edge.at(1),edge.at(2));
        railnetwork.railNetworkInput(edge.at(1),edge.at(0),edge.at(2));
    }
    cout<<"Given the List of Stations: "<<endl;
    for(int i = 0;i<stationIndexing.size();i++){
        cout<<i+1<<" "<<stationIndexing[i]<<endl;
    }
    cout<<"\nGiven the list of metros: "<<endl;
    for(int i = 0;i < rails.size();i++){
        cout<<i+1<<" : ";
        for(int j = 0;j < rails[i].size();j++){
            cout<<rails[i][j]+1<<" ";
        }
        cout<<endl;
    }
    string x,y;
    cout<<"Enter the departure Station Name: ";
    cin>>x;
    cout<<"Enter the destination Station Name: ";
    cin>>y;
    int x_index,y_index;
    for(int i = 0;i<stationIndexing.size();i++){
        if(stationIndexing[i].compare(x)==0) x_index = i;
        if(stationIndexing[i].compare(y)==0) y_index = i;
    }
    shortest_path = railnetwork.dijkstra(x_index,y_index);
    matchTheTrains(x_index,y_index);
    printTrain();
    // Ticket booking is separate part of the code 
    cout<<"\nGenerate the Ticket for given list of stations: "<<endl;
    for(int i = 0;i<10;i++){
        cout<<i+1<<" "<<stationIndexing[i]<<endl;
    }
    int num_seats = 10;
    int num_stations = 10;
    BookTicket bookticket(num_seats,num_stations);
    bookticket.bookingTicket();
    return 0;
}