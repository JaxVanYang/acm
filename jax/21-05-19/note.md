## Tricks

### 1. 定义工厂函数可以简化有多个相同类型参数的模板函数或类的使用

我们可以定义一个工厂函数构造各种类型的最小堆：  
```cpp
template<typename T>
inline priority_queue<T, vector<T>, greater<T>> min_heap() {
    return priority_queue<T, vector<T>, greater<T>>();
}

// 类型声明时需要使用 auto 推导
auto pq = min_heap<int>();
```

### 2. 合理利用运算顺序和使用常用公式可以简化逻辑表达式

原理：  
1. 逻辑表达式从左到右运算  

2. 优先级：`&& > ||`  

3. 逻辑代数基本公式  

比如使用消去律：  
```cpp
// 下式与 pq.empty() || pq.size() && pq.top() > guards[i].first 等价
if (pq.empty() || pq.top() > guards[i].first) {
    ++cnt;
} else {
    pq.pop();
}
```

### 3. 根据数据范围确定变量上界防止溢出

尤其是二分查找的上界不容易确定的时候，最好是先设置一个最大上界常量：  
```cpp
// 立方最大为 1e18，所以设置最大上界为 1e18 的立方根 1e6
const int maxr = 1e6 + 5;

ll cube_root(ll num) {
    // 防止 mid^3 溢出
    ll l = 0, r = maxr;
    while (l <= r) {
        ll mid = l + r >> 1;
        ll val = mid * mid * mid;
        // cout << "val = " << val << endl;
        if (val == num) {
            return mid;
        }
        if (val < num) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}
```

## Record

没想到 C 题直接模拟也能过。