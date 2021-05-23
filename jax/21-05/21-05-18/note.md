## Problems

### A. Beautiful String

选择填充字符时，使用一个自定义函数去除掉不满足条件的字符可以简化判断：  
```cpp
inline void remove(string &s, char ch) {
    size_t pos = s.find(ch);
    if (pos > s.length()) return;
    s.erase(pos, 1);
}
```

### E. Long Beautiful Integer

没有看清条件是 `y >= x`，以为是 `y > x`，导致错误频出，下次在重新审题的时候要重新设计程序逻辑

## Tricks

### 1. 使用“#”区分输入与输出
```cpp
inline void no() {
    cout << "#";
    puts("0 0 0");
}
```