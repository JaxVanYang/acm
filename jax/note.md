# 笔记

## 目录

[1. 语言相关](#1-语言相关)

[2. 技巧](#2-技巧)

[3. 细节](#3-细节)

[4. 词汇表](#4-词汇表)

[参考](#参考)


## 1. 语言相关

> 也可以说是 C++ 相关。

### 1.1 常量

| 常量名 | 常量值 | 备注 |
| --- | --- | --- |
| INT32_MAX | 2^31 - 1 = 2147483647 = 0x7fffffff > 2e9 | 属于 `<stdint.h>` 库 |
| INT64_MAX | 2^63 - 1 = 9223372036854775807 > 9e18 | 同上 |
| UINT32_MAX | 2^32 - 1 = 4294967295 > 4e9 | 同上 |

### 1.2 常用函数

| 函数 | 描述 | 备注 |
| --- | --- | --- |
| to_string | 将一个数值转换成字符串 | 属于 `<string>` 库 |
| stoi | 将一个字符串解析成 int | 属于 `<string>` 库 |
| stol | 将一个字符串解析成 long int | 属于 `<string>` 库 |
| stod | 将一个字符串解析成 double | 属于 `<string>` 库 |

### 1.3 STL

1. `priority_queue`：优先队列

    > 优先队列即大根堆，可以理解为优先的数较大

    属于 `<queue>` 库。
    
    如果要使用小根堆可以使用 `priority_queue<type, vector<type>, greater<type>>`。

## 2. 技巧

1. 读取多组输入：

    ```cpp
    while (cin >> num) { /* ... */ }
    // or
    while (EOF != scanf("%d", &num)) { /* ... */ }
    ```

    `cin >>` 的返回值是 `istream` 对象，如果读取失败会返回值会被检验为 `false`；

    `scanf()` 的返回值是读取成功的元素数，如果读取到文件末尾会返回 `EOF` 宏，这个值通常为 `-1`，所以也可以通过取反来判断，因为 `~(-1) = 0`。

2. 使用异或代替加减法

    如果只需要考虑结果的奇偶性，那么就可以使用 `^` 来代替加减法，而且能避免溢出，例如：[acw108_奇数码问题.cc](../share/algorithm-advance-算法进阶指南/0x00-basic/acw108_奇数码问题.cc)。

3. O(1) 计算 `log2(n)`：

    ```cpp
    int h[37];
    for (int i = 0; i < 36; ++i) {
        h[(1ll << i) % 37] = i;
    }

    auto log2 = [&](int n) { return h[n % 37]; };
    ```

    这里利用到了一个数学技巧：2 的 0 到 35 次方对 37 取模的结果刚好取遍 1 到 36，所以可以将 2 的 0 到 35 次方映射到长度为 37 的数组上。

4. 存储树时使用双向边代替单向边，即可将树扩展成图，并且可以从任意一点遍历所有结点，对于某些没有给出根结点的题目有帮助，例如：[acw-144 最长异或路径](https://www.acwing.com/problem/content/description/146/)。

5. 读入一整行的几种方法

    1. `gets()` 读入 `char[]`:
        ```cpp
        char s[1024];
        gets(s);
        ```

    2. `getline()` 读入 `string` 或 `char[]`:
        ```cpp
        std::string s1;
        getline(std::cin, s1);

        char s2[1024];
        std::cin.getline(s2, 1024);
        ```

## 3. 细节

### 3.1 易错

1. 取整

    浮点数到整形的强制转型是向下取整，而 `printf("%.6lf", num)` 的取整方式不确定。
    
    
    原因可参考[为什么(2.55).toFixed(1)等于2.5？](https://www.cnblogs.com/zhangycun/p/7880580.html)。

    > Solution：推荐使用 `<cmath>` 库函数 `floor()`, `round()`, `ceil()` 进行取整操作。

    ```cpp
    printf("1.25 => %.1lf\n", 1.25);    // 1.25 => 1.2
    printf("1.26 => %.1lf\n", 1.26);    // 1.26 => 1.3

    // round
    printf("1.25 => %.1lf\n", round(1.25 * 10) / 10);   // 1.25 => 1.3
    printf("1.26 => %.1lf\n", round(1.26 * 10) / 10);   // 1.26 => 1.3
    ```

2. 强制转型

    > 最佳实践是尽量避免强制转型。

    整型强制转型的策略是“大转小丢弃高位，小转大保留符号位高位补零”，“小转大”通常不会有什么问题，而“大转小有时可能会出现意想不到的情况，例如：

    ```cpp
    long long a = 0xffffffff;
	cout << a << endl;  // 4294967295
	int b = a;
	cout << b << endl;  // -1
    ```

3. 想要修改已存在的对象时，获取到的却是副本，常发生在使用 `auto` 时忘记加引用修饰符 `&`，如：

    ```cpp
    auto node = nodes[i];
    node.val = 1;   // 获取的是副本，所以并没有修改 nodes[i]
    ```

4. 读取字符的时候需要小心空白字符

    `scanf("%c", &ch)` 和 `getchar()` 都不会忽略空白字符，使用 `cin >> ch` 可以忽略空白字符。

### 3.2 优化

1. `memset()` 太慢

    对于部分时间要求严格的题目，使用 `memset()` 可能会 TLE，可以在重置的时候只重置必要的部分，比如 `Trie` 的重置：

    ```cpp
    void insert(int num) {
        /* ... */
            if (trie[p][val] == 0) {
                trie[p][val] = ++tot;
                // 因为字典树可能只被部分重置，所以需要在扩展新结点的时候动态重置
                trie[tot][0] = trie[tot][1] = 0;
                end[tot] = 0;
            }
        /* ... */
    }
    void reset() {
        trie[1][0] = trie[1][1] = 0;
        end[1] = 0;
        tot = 1;
    }
    ```

### 3.3 杂项

1. `long double` 在十进制下的**有效数字**有 18～19位，刚好和 `long long` 差不多。

## 4. 词汇表

## 参考

[为什么(2.55).toFixed(1)等于2.5？](https://www.cnblogs.com/zhangycun/p/7880580.html)

[C/C++如何整行读入字符串？](https://www.cnblogs.com/AlvinZH/p/6798023.html)
