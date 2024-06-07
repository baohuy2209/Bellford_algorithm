#define INF 1000000
int x[100]; // luu cau hinh 
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
    }
    return Vertices::Z; 
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
    }
    return 'Z'; 
}
void backtracking_traveling(int i, int cost, string &short_path, string short_temp,int &result_cost, int cost_min, int number_vertice, int visited[], int matrix[20][20], int source){
    for(int j = 0; j < number_vertice; j++){
        if(visited[j] == 0){
            visited[j] = 1; 
            x[i] = j; // luu vertice 
            cost +=  matrix[x[i-1]][x[i]];
            char dest = convert_enum_to_char(x[i]); 
            string dest_str(1, dest); 
            short_temp += dest_str+" "; 
            if(i == number_vertice-1){
                if(result_cost > cost+matrix[x[i]][source]){
                    result_cost = cost+matrix[x[i]][source];
                    short_path = short_temp; 
                }
            }else if(((cost + (number_vertice-i+1)*cost_min) < result_cost)){
                backtracking_traveling(i+1, cost, short_path, short_temp, result_cost, cost_min, number_vertice, visited, matrix, source); 
            }
            visited[j] = 0; 
            cost -= matrix[x[i-1]][x[i]]; 
            short_temp.erase(short_temp.length() - 2); 
        }
    }
}
string Traveling(int matrix[20][20], int num_vertices, char start){
    string str_start(1, start); 
    string result = str_start+" "; 
    string temp = str_start+" "; 
    int result_cost = INF; 
    int cmin = INF; 
    for(int i = 0; i < num_vertices; i++){
        for(int j = 0; j < num_vertices; j++){
            if(matrix[i][j] != 0){
                cmin = min(cmin, matrix[i][j]);
            }
        }
    }
    int visited[100]; 
    for(int i = 0; i < num_vertices; i++){
        visited[i] = 0; 
    }
    int source = convert_char_to_enum(start); 
    visited[source] = 1; // danh dau da di tu diem bat dau 
    x[0] = source; 
    int cost = 0; 
    backtracking_traveling(1, cost, result , temp,result_cost, cmin, num_vertices, visited, matrix, source); 
    result += str_start; 
    return result; 

}
