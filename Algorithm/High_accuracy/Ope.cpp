#include<bits/stdc++.h>
using namespace std;
struct nums{
    int len;
    int arg[505];

	void init (){
		len = 1;
    	memset(arg, 0, sizeof(arg));
	}

    void print(){
        for (int i = len - 1; i >= 0; i--)
            cout<<arg[i];
        cout<<endl;
    }

    void CharToNums(char *str){
        len = strlen(str);
        for (int i = 0; i < len; i++){
            arg[i] = str[len - i - 1] - '0';
        }
        while(arg[len-1] == 0){
            len--;
        }
    }

    friend bool operator==(nums r, nums w){
        if (r.len != w.len) return false;
        int i = r.len - 1;
        while (i >= 0){
            if (r.arg[i] != w.arg[i])
                return false;
            i--;
        }
        return true;
    }
    friend bool operator<=(nums r, nums w){
        if (r.len < w.len) return true;
        else if (w.len < r.len) return false;
        int i = r.len - 1;
        while (i >= 0){
            if (r.arg[i]<w.arg[i])
                return true;
            else if (r.arg[i]>w.arg[i])
                return false;
            i--;
        }
        return true;
    }
    friend nums operator+(int r, nums w){
        w.arg[0] += r;
        int i = 0;
        while (w.arg[i] >= 10){
            w.arg[i + 1] += w.arg[i] / 10;
            w.arg[i] = w.arg[i] % 10;
            i++;
        }
        if(w.arg[i]) i++;
        w.len = i > w.len ? i : w.len;
        return w;
    }
    friend nums operator+(nums w, int r){
        w.arg[0] += r;
        int i = 0;
        while (w.arg[i] >= 10){
            w.arg[i + 1] += w.arg[i] / 10;
            w.arg[i] = w.arg[i] % 10;
            i++;
        }
        if(w.arg[i]) i++;
        w.len = i > w.len ? i : w.len;
        return w;
    }
    friend nums operator-(nums r, nums w){
        for (int i = 0; i < r.len; i++){
            if (r.arg[i] >= w.arg[i])
                r.arg[i] = r.arg[i] - w.arg[i];
            else{
                r.arg[i] = r.arg[i] + 10;
                r.arg[i + 1] = r.arg[i + 1] - 1;
                r.arg[i] = r.arg[i] - w.arg[i];
            }
        }
        while (r.arg[r.len - 1] == 0 && r.len > 1)
            r.len--;
        return r;
    }
    friend nums operator*(int x, nums w){
        nums r;
		r.init();
        if(x == 0 || (w.len == 1 && w.arg[0] == 0)){
            return r;
        }
        for (int i = 0; i < w.len; i++){
            r.arg[i] += w.arg[i] * x;
            r.arg[i + 1] += r.arg[i] / 10;
            r.arg[i] = r.arg[i] % 10;
        }
        int i = r.arg[w.len] == 0 ? w.len-1 : w.len;
        while (r.arg[i] >= 10){
            r.arg[i + 1] = r.arg[i] / 10;
            r.arg[i] = r.arg[i] % 10;
            i++;
        }
        r.len = (i >= 0) ? i + 1 : 1;
        return r;
    }
    friend nums operator*(nums r, nums w){
        nums v;
		v.init();
        if((r.len == 1 && r.arg[0] == 0)|| (w.len == 1 && w.arg[0] == 0))
            return v;
        for (int i = 0; i < r.len; i++){
            for (int k = 0; k < w.len; k++){
                v.arg[i + k] += w.arg[k] * r.arg[i];
                v.arg[i + k + 1] += v.arg[i + k] / 10;
                v.arg[i + k] = v.arg[i + k] % 10;
            }
        }
        int i = w.len + r.len - 1;
        i = v.arg[i] == 0 ? i-1 : i;
        while (v.arg[i] >= 10){
            v.arg[i + 1] = v.arg[i] / 10;
            v.arg[i] = v.arg[i] % 10;
            i++;
        }
        v.len = (i >= 0) ? i + 1 : 1;
        return v;
    }

    nums sqrt(){
        nums w, r;
		w.init();
		r.init();
        w.len = r.len = 0;
        int lens = len - 1;
        if(len == 1 && arg[0] == 1)
            return *this;
        r.arg[r.len++] = arg[lens--];
        if (len % 2 == 0)
            r = arg[lens--] + 10 * r;
        while (lens >= -1){
            int i = 0;
            while ((i*(i + 20 * w)) <= r){
                i++;
            }
            i--;
            if (i == -1 || (r.len == 1 && r.arg[0] == 1))
                i = 0;
            r = r - (i*(i + 20 * w));
            w = i + 10 * w;
            if(lens >= 0){
                r = arg[lens--] + 10 * r;
                r = arg[lens--] + 10 * r;
            }
            else
                lens -= 2;
        }
        return w;
    }
};

int main(){
	// printf("1");
	// for(int i = 0;i < 500;i++)
	// 	printf("0");
    char strn[505];
	cin>>strn;	
    nums a,sq;
	a.init();
    a.CharToNums(strn);
	sq = a.sqrt();
    a = sq*sq;
    a.print();
    return 0;
}