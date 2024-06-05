#define INF 1000000
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
void print_path(int destination, int *previous, string &result){
    int v = previous[destination]; 
    if(v == -1){
        return; 
    }
    print_path(v, previous, result); 
    char vertice = convert_enum_to_char(v); 
    string str_vertice(1,vertice); 
    result = " "+str_vertice + result; 
}
string BF_Path(int matrix[][20], int num_vertices, char start, char end){
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
                    if((value[u] + weight < value[v]) && (value[u] != INF)){
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
                if((value[u] + weight < value[v]) && (value[u] != INF)){
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
        reverse(short_path.begin(), short_path.end()+1);
        short_path = short_path+" "+str_end; 
        short_path = short_path.substr(1);
        return short_path; 
    }else{
        cout<<"Has a negative cycle"<<endl; 
        return short_path; 
    }
}