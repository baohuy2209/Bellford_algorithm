#include <string> 
enum Vertices {
    A, B, C, D, E, F, G, H, I, J,
    K, L, M, N, O, P, Q, R, S, T,
    U, V, W, X, Y, Z
};
enum Vertices convert_char_to_enum(char mychar);
char convert_enum_to_char(int vertices);
void print_path(int destination, int *previous, string &result);
void BF(int matrix[][1000], int *value, int *previous,int number_vertices, char start);
string BF_path(int matrix[][1000], int num_vertices, char start, char end);
