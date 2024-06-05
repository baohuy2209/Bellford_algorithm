#include <iostream>
#include <vector>
#include <fstream>
#define INF 1000000
using namespace std;
int X[100]; // luu cau hinh 
// Định nghĩa enum từ A đến Z
enum Vertices {
    A, B, C, D, E, F, G, H, I, J,
    K, L, M, N, O, P, Q, R, S, T,
    U, V, W, X, Y, Z
};
enum Vertices convert_char_to_enum(char mychar){
    switch(mychar){
        case 'A':
            return Vertices::A; 
        case 'B':
            return Vertices::B; 
        case 'C':
            return Vertices::C; 
        case 'D':
            return Vertices::D; 
        case 'E':
            return Vertices::E; 
        case 'F':
            return Vertices::F; 
        case 'G':
            return Vertices::G; 
        case 'H':
            return Vertices::H; 
        case 'I':
            return Vertices::I; 
        case 'J':
            return Vertices::J; 
        case 'K':
            return Vertices::K; 
        case 'L':
            return Vertices::L; 
        case 'M':
            return Vertices::M; 
        case 'N':
            return Vertices::N; 
        case 'O':
            return Vertices::O; 
        case 'P':
            return Vertices::P; 
        case 'Q':
            return Vertices::Q; 
        case 'R':
            return Vertices::R; 
        case 'S':
            return Vertices::S; 
        case 'T':
            return Vertices::T; 
        case 'U':
            return Vertices::U; 
        case 'V':
            return Vertices::V; 
        case 'W':
            return Vertices::W; 
        case 'X':
            return Vertices::X; 
        case 'Y':
            return Vertices::Y; 
        case 'Z':
            return Vertices::Z; 
    }
}
char convert_enum_to_char(int vertices){
    switch(vertices){
        case Vertices::A:
            return 'A'; 
        case Vertices::B:
            return 'B'; 
        case Vertices::C:
            return 'C'; 
        case Vertices::D:
            return 'D'; 
        case Vertices::E:
            return 'E'; 
        case Vertices::F:
            return 'F'; 
        case Vertices::G:
            return 'G'; 
        case Vertices::H:
            return 'H'; 
        case Vertices::I:
            return 'I'; 
        case Vertices::J:
            return 'J'; 
        case Vertices::K:
            return 'K'; 
        case Vertices::L:
            return 'L'; 
        case Vertices::M:
            return 'M'; 
        case Vertices::N:
            return 'N'; 
        case Vertices::O:
            return 'O'; 
        case Vertices::P:
            return 'P'; 
        case Vertices::Q:
            return 'Q'; 
        case Vertices::R:
            return 'R'; 
        case Vertices::S:
            return 'S'; 
        case Vertices::T:
            return 'T'; 
        case Vertices::U:
            return 'U'; 
        case Vertices::V:
            return 'V'; 
        case Vertices::W:
            return 'W'; 
        case Vertices::X:
            return 'X'; 
        case Vertices::Y:
            return 'Y'; 
        case Vertices::Z:
            return 'Z'; 
    }
}
void BF(int matrix[][1000], int number_vertices, char start,int *value, int *previous){
    int a = convert_char_to_enum(start); 
    value[a] = 0; 
    for(int u = 0;  u < number_vertices; u++){
        for(int v = 0; v < number_vertices; v++){
            int weight = matrix[u][v];
            if(weight == 0){
                continue; 
            }else{
                if(value[u] + weight < value[v]){
                    value[v] = value[u]+weight;
                    previous[v] = u;   
                }
            }
        }
    }
}
void print_path(int destination, int *previous, string &result){
    int v = previous[destination]; 
    if(v == -1){
        return; 
    }
    print_path(v, previous, result); 
    char vertice = convert_enum_to_char(v); 
    string str_vertice(1,vertice); 
    result = result + " " + str_vertice; 
}
string BF_path(int matrix[][1000], int num_vertices, char start, char end){
    string short_path = ""; 
    int value[num_vertices]; 
    int previous[num_vertices]; 
    for(int i = 0 ; i < num_vertices ; i++){
        value[i] = INF; 
        previous[i] = -1; 
    }
    int source = convert_char_to_enum(start); 
    int destination = convert_char_to_enum(end);
    value[source] = 0; // source 

    for(int i = 1; i < num_vertices; i++){
        for(int u = 0; u < num_vertices; u++){
            for(int v = 0; v < num_vertices; v++){
                int weight = matrix[u][v]; 
                if(weight == 0){
                    continue; 
                }else{
                    if(value[u] + weight < value[v]){
                        value[v] = value[u]+weight; 
                        previous[v] = u; 
                    }
                }
            }
        }
    }
    bool has_negative_cycle = false; 
    for(int u = 0; u < num_vertices; u++){
        for(int v = 0; v < num_vertices; v++){
            int weight = matrix[u][v];
            if(weight == 0){
                continue; 
            }else{
                if(value[u] + weight < value[u]){
                    has_negative_cycle = true; 
                    break; 
                }
            }
        }
    }
    if(!has_negative_cycle){
        // short_path(source, destination, previous); 
        print_path(destination, previous, short_path); 
        string str_end(1,end); 
        short_path = short_path+" "+str_end; 
        return short_path; 
    }else{
        cout<<"Has a negative cycle"<<endl; 
        return short_path; 
    }
}
void backtracking_traveling(int i, int cost, string& short_path, int& result_cost, int cost_min, int number_vertice, int visited[], int matrix[20][20], int previous[], int source){
    for(int j = 0; j < number_vertice; j++){
        if(visited[j] == 0){
            visited[j] = 1; 
            X[i] = j // luu vertice 
            cost +=  matrix[X[i-1]][X[i]];
            if(i == n){
                if(previous[0] == j){
                    result_cost = min(result_cost, cost+matrix[X[i]][0]); 
                    char endpoint = convert_enum_to_char(source);
                    string str(1, endpoint);  
                    short_path += " "+str; 
                }else{
                    return; 
                }
            }else if(((cost + (number_vertice-i+1)*cost_cost) < result_cost) && (previous[j] = source)){
                short_path
                backtracking_traveling(i+1, cost, )
            }
        }
    }
}
int traveling(int matrix[][1000], int num_vertices, char start){
    string result = ""; 
    int value[num_vertices]; 
    int previous[num_vertices]; 
    for(int i = 0 ; i < num_vertices ; i++){
        value[i] = INF; 
        previous[i] = -1; 
    }
    int source = convert_char_to_enum(start);
    value[source] = 0; // source 

    for(int i = 1; i < num_vertices; i++){
        for(int u = 0; u < num_vertices; u++){
            for(int v = 0; v < num_vertices; v++){
                int weight = G[u][v]; 
                if(weight == 0){
                    continue; 
                }else{
                    if(value[u] + weight < value[v]){
                        value[v] = value[u]+weight; 
                        previous[v] = u; 
                    }
                }
            }
        }
    }
    bool has_negative_cycle = false; 
    for(int u = 0; u < num_vertices; u++){
        for(int v = 0; v < num_vertices; v++){
            int weight = G[u][v];
            if(weight == 0){
                continue; 
            }else{
                if(value[u] + weight < value[u]){
                    has_negative_cycle = true; 
                    break; 
                }
            }
        }
    }
    if(!has_negative_cycle){
        // short_path(source, destination, previous); 
        
    }else{
        cout<<"Has a negative cycle"<<endl; 
        return result; 
    }
    return result; 
}
void printarr(int arr[100], int num){
    for(int i = 0; i < num; i++){
        cout<<arr[i]<<" "; 
    }
    cout<<endl;
}
int main() { 
    int number_vertices = 6;
    int matrix[number_vertices][1000] = {
        {0, 10, 5, 18, 0, 0}, 
        {0, 0, 0, 12, 0, 0}, 
        {0, 0, 0, 5, 14, 5}, 
        {0, 0, 0, 0, 0, 8}, 
        {0, 0, 0, 0, 0, 7}, 
        {0, 0, 0, 0, 0, 0}, 
    }; 
    cout<<"================================================"<<endl; 
    cout<<"Exercise 1 : "<<endl; 
    int value[number_vertices] = {0, 10, 5, 18, INF, INF}; 
    int previous[number_vertices] = {-1, 0, 0, 0, -1, -1}; 
    for(int i = 1 ; i <= 5; i++){
        BF(matrix, number_vertices, 'A',value, previous); 
        cout<<"Step"<<i<<endl; 
        cout<<"Value: "<<endl; 
        printarr(value, number_vertices); 
        cout<<"Previous: "<<endl; 
        printarr(previous, number_vertices); 
    }
    cout<<"================================================"<<endl; 
    cout<<"================================================"<<endl; 
    cout<<"Exercise 2 : "<<endl; 
    string final = BF_path(matrix, number_vertices, 'A', 'F');
    cout<<final<<endl; 
    cout<<"================================================"<<endl; 
    cout<<"Exercise 3 : "<<endl; 
    int result = traveling(matrix, number_vertices, 'A'); 
    return 0;
}
