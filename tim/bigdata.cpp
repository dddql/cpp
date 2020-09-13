struct nums{
    int arg[MAXN], len;
    nums(){
        memset(arg, 0, sizeof(arg));
        len = 1;
    }

    void print(){
        for (int i = len - 1; i >= 0;i--)
            cout << arg[i];
        cout << endl;
    }

    void scan(){
        char a[MAXN];
        cin >> a;
        *this = a;
    }

    void cleanZero(){
        while(!arg[len-1]&&len > 1)
            len--;
    }

    nums operator=(char *a){
        nums b;
        b.len = strlen(a);
        for (int i = 0; i < b.len;i++)
            b.arg[i] = a[b.len - i - 1] - '0';
        b.cleanZero();
        *this = b;
        return *this;
    }

    nums operator=(int a){
        char b[MAXN];
        sprintf(b, "%d", &a);
        *this = b;
        return *this;
    }

    nums operator+(nums a){
        nums sum;
        int x, l = sum.len = max(len, a.len);
        for (int i = 0; i < l;i++){
            x = sum.arg[i] + arg[i] + a.arg[i];
            sum.arg[i] = x % 10;
            sum.arg[i + 1] = x / 10;
        }
        if(sum.arg[sum.len] > 0)
            sum.len++;
        return sum;
    }

    nums operator+(int a){
        nums b;
        b = a;
        return (*this + b);
    }

    nums operator-(nums a){
        nums dif;
        int x,l = dif.len = max(len,a.len);
        for (int i = 0; i < l;i++){
            x = arg[i] - a.arg[i] - dif.arg[i];
            if(x < 0){
                dif.arg[i] = x + 10;
                dif.arg[i + 1] = 1;
            }else
                dif.arg[i] = x;
        }
        dif.cleanZero();
        return dif;
    }

    nums operator-(int a){
        nums b;
        b = a;
        return (*this - b);
    }

    nums operator*(nums a){
        nums prod, tmp;
        int x = 0;
        for (int i = 0; i < a.len;i++){
            tmp = 0;
            for (int j = 0; j < len;j++){
                x = arg[j] * a.arg[i] + tmp.arg[i+j];
                tmp.arg[i + j] = x % 10;
                tmp.arg[i + j + 1] = x / 10;
            }
            tmp.len = (tmp.arg[i + len] > 0) ? (len + 1) : (len);
            prod = prod + tmp;
        }
        prod.cleanZero();
        return prod;
    }

    nums operator*(int a){
        nums b;
        b = a;
        return (*this * b);
    }

    nums operator/(int a){
        nums quo;
        int x;
        for (int i = len - 1; i >= 0; i--){
            x = x * 10 + arg[i];
            quo.arg[i] = x / a;
            x = x % a;
        }
        quo.len = len;
        quo.cleanZero();
        return quo;
    }

    bool operator<=(nums a){
        if(len > a.len)
            return false;
        else if(len < a.len)
            return true;
        for (int i = len - 1; i >= 0;i--){
            if(arg[i] < a.arg[i])
                return true;
            else if(arg[i] > a.arg[i])
                return false;
        }
        return true;
    }

    bool operator<=(int a){
        nums b;
        b = a;
        return (*this <= b);
    }

    bool operator<(nums a){
        if(len > a.len)
            return false;
        else if(len < a.len)
            return true;
        for (int i = len - 1; i >= 0;i--){
            if(arg[i] < a.arg[i])
                return true;
            else if(arg[i] > a.arg[i])
                return false;
        }
        return false;
    }

    bool operator<(int a){
        nums b;
        b = a;
        return (*this < b);
    }

    bool operator==(nums a){
        if(len != a.len)
            return false;
        for (int i = len - 1; i >= 0;i--)
            if(arg[i] != a.arg[i])
                return false;
        return true;
    }

    bool operator==(int a){
        nums b;
        b = a;
        return (*this == b);
    }
};

int main(){
    nums a, b,c;
    int l = 15;
    a.scan();
    b.scan();

    c = (a + b);
    c.print();
    c = (a - b);
    c.print();
    c = (a * b);
    c.print();
    c = (a / l);
    c.print();

    cout << (a <= b) << endl;
    cout << (a == b) << endl;
    cout << (a < b) << endl;

    a = l;
    a.print();

    return 0;
}