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
void BF(int matrix[20][20], int number_vertices, char start,int *value, int *previous){
    int a = convert_char_to_enum(start); 
    value[a] = 0; 
    for(int u = 0;  u < number_vertices; u++){
        for(int v = 0; v < number_vertices; v++){
            int weight = matrix[u][v];
            if(weight == 0){
                continue; 
            }else{
                if((value[u] + weight < value[v])&& (value[u] != INF)){
                    value[v] = value[u]+weight;
                    previous[v] = u;   
                }
            }
        }
    }
}