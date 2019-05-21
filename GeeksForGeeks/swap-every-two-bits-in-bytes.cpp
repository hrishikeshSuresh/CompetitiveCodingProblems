#define M 8
typedef long long int lli;
using namespace std;

int swap_every_two_bits(int x){
    return ((x&0xAA)>>1)|((x&0x55)<<1);
}

int main(){
    lli T, N;
    cin >> T;
    while(T--){
        cin >> N;
        int swapped_number = swap_every_two_bits(N);
        cout << swapped_number << endl;
    }
}
