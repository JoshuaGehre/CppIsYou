#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>

#define FILENAME "CppIsYou.cpp"

using namespace std;

// Load this cpp file and use it as the level
class Level{
    private:
        char * C = nullptr;
        int height_ = 0;
        int width_ = 0;
    public:
        Level(string fileName){
            ifstream file(fileName);
            vector<string> A(0);
            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    A.push_back(line);
                    if(line.length() > width_){
                        width_ = line.length();
                    }
                }
                file.close();
            }
            height_ = A.size();
            int l = width_ * height_;
            C = new char[l];
            for(int i = 0; i < l; i++) C[i] = ' ';
            for(int i = 0; i < height_; i++){
                for(int j = 0; j < A[i].length(); j++){
                    C[j + i * width_] = A[i].at(j);
                }
            }
        };
        ~Level(){ if(C) delete C; };
        inline int height() { return height_; };
        inline int width() { return width_; };
        inline bool inBounds(int x, int y) {
            return ((x >= 0) && (y >= 0) &&
                (x < width_) && (y < height_));
        };
        inline char& chr(int x, int y) {
            return C[x + width_ * y];
        };
};

// A selection of specific characters
struct CharList{
    bool B[0x100];
    bool& operator[](int i){return B[i & 0xff];};
    CharList(){
        for(int i = 0; i < 0x100; i++) B[i] = false;
    }
    // Load from string
    CharList(string S) : CharList(){
        for(int i = 0; i < S.length(); i++){
            B[S.at(i) & 0xff] = true;
        }
    }
    void invert() {
        for(int i = 0; i < 0x100; i++) B[i] = !B[i];
    };
};

void printLevel(Level &L, string file){
    // Print to console and file
    ofstream out(file);
    for(int y = -1; y <= L.height(); y++){
        for(int x = -1; x <= L.width(); x++){
            if(L.inBounds(x, y)){
                std::cout << L.chr(x, y);
                out << L.chr(x, y);
            }else{
                std::cout << "#";
            }
        }
        std::cout << "\n";
        if(((y + 1) != L.height()) && (y != -1)) out << "\n";
    }
    out.close();
}

void levelComplete(){
    // Call this function to complete the level
    cout << "\n\n";
    #define S "            "
    cout << S S "+==================+\n";
    cout << S S "| Level Complete ! |\n";
    cout << S S "+==================+\n";
    #undef S
    cout << "\n\n";
}

void movePlayerAt(Level &L,
    CharList &Playable,
    CharList &Moveable,
    int dx, int dy,
    int x, int y)
{
    if(!Playable[L.chr(x, y)]) return;
    // Check if the player can move
    // and what characters will be pushed
    int s = 1;
    while(true){
        if(!L.inBounds(x + s * dx, y + s * dy)) return;
        char c = L.chr(x + s * dx, y + s * dy);
        if(c == ' ') break;
        if(!Moveable[c]) return;
        s++;
    }
    for(int t = s - 1; t >= 0; t--){
        L.chr(x + (t + 1) * dx, y + (t + 1) * dy)
            = L.chr(x + t * dx, y + t * dy);
    }
    L.chr(x, y) = ' ';
}

void movePlayer(Level &L,
    CharList &Playable,
    CharList &Moveable,
    int dx, int dy)
{
    // Check for playable characters
    // Loop direction is based on the direction
    // the player tries to move in
    #define CALL movePlayerAt(L, Playable, Moveable, dx, dy, x, y)
    #define IterY if(dy > 0){\
                for(int y = L.height() - 1; y >= 0; y--) CALL;\
            }else{\
                for(int y = 0; y < L.height(); y++) CALL;\
            }
    if(dx > 0){
        for(int x = L.width() - 1; x >= 0; x--) IterY
    }else{
        for(int x = 0; x < L.width(); x++) IterY
    }
    #undef IterY
    #undef CALL
}

int main(int argc, char *argv[], char *envp[])
{
    // Everything is moveable
    // Control every two in this file
    CharList Moveable("");
    CharList Player("");
    Moveable.invert();
    //
    Player[0b00110010] = true;
    //
    // v += 12;
    //
    // Load the source file
    Level L(FILENAME);
    // If an argument is specified make the player move
    if(argc > 1){
        string step = argv[1];
        if(step == "Up") movePlayer(L, Player, Moveable, 0, -1);
        if(step == "Down") movePlayer(L, Player, Moveable, 0, 1);
        if(step == "Right") movePlayer(L, Player, Moveable, 1, 0);
        if(step == "Left") movePlayer(L, Player, Moveable, -1, 0);
    }
    // Output to the console and to the .cpp file
    printLevel(L, FILENAME);
    //
    int v = 35;
    //
    if(v == 45) levelComplete();
    //
    return 0;
}
