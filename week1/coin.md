## 分成3堆
A堆 : `a1`, `a2`, `a3`
B堆 : `b1`, `b2`, `b3`
C堆 : `c1`, `c2`
+ 比較A、B堆
    1. A = B, 比較 `a1`, `a2`
        + `a1` = `a2`, 比較 `a1`, `a3`
            + `a1` = `a3`, **則假幣爲 `c1`, `c2`**。(3 times)
            + ~~`a1` > `a3`~~ 
            + `a1` < `a3`,  `a3` 為假幣, 比較 `c1`, `c2` 
                + `c1` = `c2`, 比較 `b1, `b2`
                    + `b1` = `b2`, `b3` 為假幣, **則假幣爲 `a3`, `b3`**。(5 times)
                    + `b1` > `b2`, `b1` 為假幣, **則假幣爲 `a3`, `b1`**。(5 times)
                    + `b1` < `b2`, `b2` 為假幣, **則假幣爲 `a3`, `b2`**。(5 times)
                + `c1` > `c2`, `c1` 為假幣, **則假幣爲 `a3`, `c1`**。(4 times)
                + `c1` < `c2`, `c2` 為假幣, **則假幣爲 `a3`, `c2`**。(4 times)
        + `a1` > `a2`, `a1` 為假幣, 比較 `b1`, `b2`
            + `b1` = `b2`, `b3` 為假幣, **則假幣爲 `a1`, `b3`**。(3 times)
            + `b1` > `b2`, `b1` 為假幣, **則假幣爲 `a1`, `b1`**。(3 times)
            + `b1` < `b2`, `b2` 為假幣, **則假幣爲 `a1`, `b2`**。(3 times)
        + `a1` < `a2`, `a2` 為假幣, 比較 `b1`, `b2`
            + `b1` = `b2`, `b3` 為假幣, **則假幣爲 `a2`, `b3`**。(3 times)
            + `b1` > `b2`, `b1` 為假幣, **則假幣爲 `a2`, `b1`**。(3 times)
            + `b1` < `b2`, `b2` 為假幣, **則假幣爲 `a2`, `b2`**。(3 times)
    2. A > B, 比較 `c1`, `c2`
        + `c1` = `c2`, 比較 `a1`, `a2`
            + `a1` = `a2`, **則假幣爲 `a3`, `a3`**。(3 times)
            + `a1` > `a2`, **則假幣爲 `a1`, `a3`**。(3 times)
            + `a1` < `a2`, **則假幣爲 `a2`, `a3`**。(3 times)
        + `c1` > `c2`, `c1` 為假幣, 比較 `a1`, `a2`
            + `a1` = `a2`, `a3` 為假幣,**則假幣爲 `a3`, `c1`**。(3 times)
            + `a1` > `a2`, `a1` 為假幣,**則假幣爲 `a1`, `c1`**。(3 times)
            + `a1` < `a2`, `a2` 為假幣,**則假幣爲 `a2`, `c1`**。(3 times)
        + `c1` < `c2`, `c2` 為假幣, 比較 `a1`, `a2`
            + `a1` = `a2`, `a3` 為假幣,**則假幣爲 `a3`, `c2`**。(3 times)
            + `a1` > `a2`, `a1` 為假幣,**則假幣爲 `a1`, `c2`**。(3 times)
            + `a1` < `a2`, `a2` 為假幣,**則假幣爲 `a2`, `c2`**。(3 times)
    3. A < B, 比較 `c1`, `c2`
        + `c1` = `c2`, 比較 `b1`, `b2`
            + `b1` = `b2`, **則假幣爲 `b3`, `b3`**。(3 times)
            + `b1` > `b2`, **則假幣爲 `b1`, `b3`**。(3 times)
            + `b1` < `b2`, **則假幣爲 `b2`, `b3`**。(3 times)
        + `c1` > `c2`, `c1` 為假幣, 比較 `b1`, `b2`
            + `b1` = `b2`, `b3` 為假幣,**則假幣爲 `b3`, `c1`**。(3 times)
            + `b1` > `b2`, `b1` 為假幣,**則假幣爲 `b1`, `c1`**。(3 times)
            + `b1` < `b2`, `b2` 為假幣,**則假幣爲 `b2`, `c1`**。(3 times)
        + `c1` < `c2`, `c2` 為假幣, 比較 `b1`, `b2`
            + `b1` = `b2`, `b3` 為假幣,**則假幣爲 `b3`, `c2`**。(3 times)
            + `b1` > `b2`, `b1` 為假幣,**則假幣爲 `b1`, `c2`**。(3 times)
            + `b1` < `b2`, `b2` 為假幣,**則假幣爲 `b2`, `c2`**。(3 times)
