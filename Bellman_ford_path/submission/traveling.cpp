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
    result = result + " " + str_vertice; 
}
string Traveling(int G[20][20], int num_vertices, char start){
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
        for(int i = 0; i < num_vertices; i++){
            if(i == source){
                continue; 
            }else{
                string short_path = "";
                print_path(i, previous,short_path);
                char end = convert_enum_to_char(i);  
                reverse(short_path.begin(), short_path.end()+1);
                string str_end(1,end); 
                short_path = short_path+" "+str_end; 
                result = result+"\n"+short_path;  
            }
        } 
    }else{
        cout<<"Has a negative cycle"<<endl; 
        return result; 
    }
    return result; 
}