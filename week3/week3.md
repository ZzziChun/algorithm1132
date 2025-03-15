以下程式的 fibonacci number 都宣告為 `unsigned long long` 型態, 並且使用 `<local.h>` 函式庫中的 `setlocale` 函數, 讓輸出數字加上逗號分隔以方便閱讀.

## <font color="#449df9"> **方法一 (Recursive Approach) :** </font>

**code :**

```cpp

```

**Output :**
![](assets/a1.png)

- 時間複雜度爲 `O(2^n)`
  每次呼叫遞迴時, 會進行兩次子問題的計算, 造成大量重複計算.
- 空間複雜度爲 `O(n)`
  空間複雜度 n 爲遞迴呼叫堆疊的深度.

<span style="color:green;">優點:</span>

1.  寫法簡潔直觀, 容易理解.
2.  易於實現, 尤其對於小的 n 值.

<span style="color:red;">缺點:</span>

1.  效率低, 因為有大量重複的計算.
2.  不適合處理大範圍的數字.

## <font color="#449df9"> **方法二 (Iterative Approach) :** </font>

**code :**

```cpp

```

**Output :**
![](assets/a2.png)

- 時間複雜度爲 `O(n)`
  每次僅計算前兩項數字, 避免了遞迴的重複計算.
- 空間複雜度爲 `O(1)`
  只需要常數空間來保存當前計算過的數字, 因此空間複雜度是常數.

<span style="color:green;">優點:</span>

1. 計算效率高, 適用於較大的 n.
2. 空間使用非常節省, 只需少量變數.

<span style="color:red;">缺點:</span>

1. 寫法稍微複雜一些, 不如遞迴直觀.

## <font color="#449df9"> **方法三(Matrix Exponentiation) :** </font>

**code :**

```cpp

```

**Output :**
![](assets/a3.png)

- 時間複雜度爲 `O(log n)`
  利用矩陣的快速幂算法, 每次把問題的規模縮小一半, 快速算 Fibonacci 數列.
- 空間複雜度爲 `O(1)`
  除了矩陣外, 只需要少量額外空間, 空間複雜度為常數.

<span style="color:green;">優點:</span>

1. 計算速度極快, 對於非常大的 n 特別高效.
2. 空間非常節省, 適合大範圍的數字計算.

<span style="color:red;">缺點:</span>

1. 實現上較為複雜, 需要理解矩陣運算與快速幂算法.
2. 當 n 很小時, 過度使用矩陣運算可能反而不夠高效.
   根據 **黃金比例公式** 近似：

\[
F(n) \approx \frac{\varphi^n}{\sqrt{5}}
\]

其中：

\[
\varphi = \frac{1 + \sqrt{5}}{2} \approx 1.618
\]

令：

\[
\frac{\varphi^n}{\sqrt{5}} \leq 2^{64} - 1
\]

取對數：

\[
n \log_2(\varphi) \leq \log_2((2^{64} - 1) \times \sqrt{5})
\]

已知：

- \( \log_2(\varphi) \approx 0.694 \)
- \( \log_2(\sqrt{5}) \approx 1.161 / 2 = 0.581 \)
- \( \log_2(2^{64} - 1) \approx 64 \)

\[
n \times 0.694 \leq 64 + 0.581
\]

\[
n \leq \frac{64.581}{0.694} \approx 93.1
\]

所以，最大整數 `n` 為 **93**。

---

## 確認 `F(93)` 和 `F(94)`

實際計算：

\[
F(93) = 12,200,160,415,121,876,738
\]
（小於 `2^{64} - 1`，可存入 `unsigned long long`）

\[
F(94) = 19,740,274,219,868,223,167
\]
（大於 `2^{64} - 1`，超過 `unsigned long long` 範圍）

因此，**`F(93)` 是 `unsigned long long` 能夠存的最大費氏數，`n = 93`**。
