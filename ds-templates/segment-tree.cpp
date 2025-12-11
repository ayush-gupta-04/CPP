class SegmentTree{

private :
    vector<int> seg;
    int N;

public: 
    SegmentTree(int N){
        this->N = N;
        this->seg.resize(4*N + 5);
    }

    void build(int idx ,int low ,int high ,vector<int>& nums){
        if(low == high){
            seg[idx] = nums[low];
            return;
        }
        int m = low + (high - low)/2;
        build(2*idx + 1 , low , m , nums);
        build(2*idx + 2 , m+1 , high , nums);
        seg[idx] = min(seg[2*idx + 1] , seg[2*idx + 2]);
    }

    int query(int idx , int low , int high , int l , int r){
        // no overlap.
        if(r < low || high < l){
            return 1e9;
        }else if(l <= low && high <= r){
            return seg[idx];
        }

        int m = low + (high - low)/2;
        int left = query(2*idx + 1, low , m , l , r);
        int right = query(2*idx + 2 , m + 1 ,high , l , r);
        return min(left , right);
    }

    void update(int idx , int low , int high , int i , int val){
        if(low == high){
            seg[idx] = val;
            return;
        }

        int m = low + (high - low)/2;
        if(i <= m){
            //left 
            update(2*idx + 1, low , m , i , val);
        }else{
            update(2*idx + 2 , m + 1 ,high , i , val);
        }
        seg[idx] = min(seg[2*idx + 1] , seg[2*idx + 2]);
        return;
    }

    ~SegmentTree(){};
};
