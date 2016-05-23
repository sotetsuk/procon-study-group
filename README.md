# プロコン（アルゴリズム・データ構造）勉強会

[プログラミングコンテスト攻略のためのアルゴリズムとデータ構造](http://www.amazon.co.jp/dp/4839952957/ref=pd_lpo_sbs_dp_ss_3?pf_rd_p=187205609&pf_rd_s=lpo-top-stripe&pf_rd_t=201&pf_rd_i=4839942390&pf_rd_m=AN1VRQENFRJN5&pf_rd_r=13KZVTWSE06JN0HF2WRE)

# 日程
基本的に毎週月曜だが、参加者の都合に合わせて柔軟に調整。

# 参加者（発表順）

1. @sotetsuk (AOJ: sotetsuk, POJ: sotetsuk, AtCoder: sotetsuk)
2. @nishimuuu (AOJ: nishimuuuuuu)
3. @ryof (AOJ: ryof)
4. @chiiia12 (AOJ: chiiia12)
5. @kikunantoka (AOJ: kikunantoka, AtCoder: kikunantoka)
6. @toiroakr (AOJ: a_Higu)
7. @sat0yu (AOJ: sat0yu)
8. @cauchym (AOJ: cauchym)
9. @nsasaki128 (AOJ: sassan)
10. @akito0107 (AOJ: akito0107)
11. @nonkoz1207 (AOJ: non1207)

# 進め方

1. 毎週（2題）をそれぞれ割当られた担当者が解説（各20min以内程度）
2. 皆で解く（事前に問いてくるのが理想）
  - AOJの問題を通す
  - 解いた問題をmasterにプルリクを送る（レビューが欲しければ誰かにassignする、どうでも良ければ自分でマージ）
  - （slackの#procon_notificationに通知が行きます）
  - 基本的には解けたら帰る

## gitのルール
1. 基本的に1つの問題につき、各自commitは1回まで。
2. レビュー反映などでminor fixがある場合はmasterにマージする前にrebaseしてcommitをまとめる。

# 問題リスト

## 基礎編 プロコンのためのアルゴリズムとデータ構造

### 2章 アルゴリズムと計算量
- 2.5 導入問題 [ALDS1_1_D: Maximum Profit](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_D&lang=jp)

### 3章 初等的整列
- 3.2 挿入ソート [ALDS1_1_A: Insertion Sort](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_A&lang=jp)
- 3.3 バブルソート [ALDS1_2_A: Bubble Sort](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A&lang=jp)
- 3.4 選択ソート [ALDS1_2_B: Selection Sort](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_B&lang=jp)
- 3.5 安定なソート [ALDS1_2_C: Stable Sort](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_C&lang=jp)
- 3.6 シェルソート [ALDS1_2_D: Shell Sort](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_D&lang=jp)

### 4章 データ構造
- 4.2 スタック [ALDS1_3_A: Stack](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=jp)
- 4.3 キュー [ALDS1_3_B: Queue](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_B&lang=jp)
- 4.4 連結リスト [ALDS1_3_C: Doubly Linked List](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_C&lang=jp)
- 4.6 データ構造の応用:面積計算 [ALDS1_3_D: Areas on the Cross-Section Diagram](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_D&lang=jp)

### 5章 探索
- 5.2 線形探索 [ALDS1_4_A: Linear Search](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_A&lang=jp)
- 5.3 二分探索 [ALDS1_4_B: Binary Search](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=jp)
- 5.4 ハッシュ [ALDS1_4_C: Dictionary](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_C&lang=jp)
- 5.6 探索の応用:最適解の計算 [ALDS1_4_D: Allocation](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_D&lang=jp)

### 6章 再帰・分割統治法
- 6.2 全探索 [ALDS1_5_A: Exhaustive Search](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=jp)
- 6.3 コッホ曲線 [ALDS1_5_C: Koch Curve](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_C&lang=jp)

### 7章 高等的整列
- 7.1 マージソート [ALDS1_5_B: Merge Sort](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_B&lang=jp)
- 7.2 パーティション [ALDS1_6_B: Partition](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_B&lang=jp)
- 7.3 クイックソート [ALDS1_6_C: Quick Sort](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_C&lang=jp)
- 7.4 計数ソート [ALDS1_6_A: Counting Sort](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_A&lang=jp)
- 7.6 反転数 [ALDS1_5_D: The Number of Inversions](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=jp)
- 7.7 最小コストソート [ALDS1_6_D: Minimum Cost Sort](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_D&lang=jp)

### 8章 木
- 8.2 根付き木の表現 [ALDS1_7_A: Rooted Trees](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_A&lang=jp)
- 8.3 二分木の表現 [ALDS1_7_B: Binary Tree](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_B&lang=jp)
- 8.4 木の巡回 [ALDS1_7_C: Tree Walk](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_C&lang=jp)
- 8.5 木巡回の応用: 木の復元 [ALDS1_7_D: Reconstruction of the Tree](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_D&lang=jp)

### 9章 二分探索木
- 9.2 二分探索木:挿入 [ALDS1_8_A: Binary Search Tree 1](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_A&lang=jp)
- 9.3 二分探索木:探索 [ALDS1_8_B: Binary Search Tree 2](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_B&lang=jp)
- 9.4 二分探索木:削除 [ALDS1_8_C: Binary Search Tree 3](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_C&lang=jp)

### 10章 ヒープ
- 10.2 完全二分木 [ALDS1_9_A: Complete Binary Tree](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_A&lang=jp)
- 10.3 最大・最小ヒープ [ALDS1_9_B: Maximum Heap](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_B&lang=jp)
- 10.4 優先度付きキュー [ALDS1_9_C: Priority Queue](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C&lang=jp)

### 11章 動的計画法
- 11.2 フィボナッチ数列 [ALDS1_10_A: Fibonacci Number](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_A&lang=jp)
- 11.3 最長共通部分列 [ALDS1_10_C: Longest Common Subsequence](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=jp)
- 11.4 連鎖行列積 [ALDS1_10_B: Matrix Chain Multiplication](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_B&lang=jp)

### 12章 グラフ
- 12.2 グラフの表現 [ALDS1_11_A: Graph](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_A&lang=jp)
- 12.3 深さ優先探索 [ALDS1_11_B: Depth First Search](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B&lang=jp)
- 12.4 幅優先探索 [ALDS1_11_C: Breadth First Search](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=jp)
- 12.5 連結成分 [ALDS1_11_D: Connected Components](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D&lang=jp)

### 13章 重み付きグラフ
- 13.2 最小全域木 [ALDS1_12_A: Minimum Spanning Tree](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A&lang=jp)
- 13.3 単一始点最短経路 [ALDS1_12_B: Single Source Shortest Path 1](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B&lang=jp)
- 13.3 単一始点最短経路 [ALDS1_12_C: Single Source Shortest Path 2](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_C&lang=jp)

## 応用編 プロコン必携ライブラリ

### 14章 高度なデータ構造
- 14.1 互いに素な集合 [DSL_1_A: Disjoint Set: Union and Find Tree](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp)
- 14.2 領域探索 [DSL_2_C: Range Search Tree (kD Tree)](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C&lang=jp)

### 15章 高度なグラフアルゴリズム
- 15.1 全点対間最短経路 [GRL_1_C: All Pairs Shortest Path](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp)
- 15.2 トポロジカルソート [GRL_4_B: Topological Sort](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp)
- 15.3 関節点 [GRL_3_A: Articulation Point](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=jp)
- 15.4 木の直径 [GRL_5_A: Diameter of a Tree](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&lang=jp)
- 15.5 最小全域木 [GRL_2_A: Minimum Spanning Tree](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp)

### 16章 計算幾何学
- 16.2 直線の直交・平行判定 [CGL_2_A: Parallel/Orthogonal](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A&lang=jp)
- 16.3 射影 [CGL_1_A: Projection](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A&lang=jp)
- 16.4 反射 [CGL_1_B: Reflection](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B&lang=jp)
- 16.5 距離 [CGL_2_D: Distance](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D&lang=jp)
- 16.6 反時計回り [CGL_1_C: Counter-Clockwise](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C&lang=jp)
- 16.7 線分の交差判定 [CGL_2_B: Intersection](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B&lang=jp)
- 16.8 線分の交点 [CGL_2_C: Cross Point](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C&lang=jp)
- 16.9 円と直線の交点 [CGL_7_D: Cross Points of a Circle and a Line](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D&lang=jp)
- 16.10 円と円の交点 [CGL_7_E: Cross Points of Circles](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E&lang=jp)
- 16.11 点の内包 [CGL_3_C: Polygon-Point Containment](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C&lang=jp)
- 16.12 凸包 [CGL_4_A: Convex Hull](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A&lang=jp)
- 16.13 線分交差問題 [CGL_6_A: Segment Intersections: Manhattan Geometry](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A&lang=jp)

### 17章 動的計画法
- 17.1 コイン問題 [DPL_1_A: Coin Changing Problem](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A&lang=jp)
- 17.2 ナップザック問題 [DPL_1_B: 0-1 Knapsack Problem](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=jp)
- 17.3 最長増加部分列 [DPL_1_D: Longest Increasing Subsequence](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp)
- 17.4 最大正方形 [DPL_3_A: Largest Square](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_A&lang=jp)
- 17.5 最大長方形 [DPL_3_B: Largest Rectangle](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B&lang=jp)

### 18章 整数論
- 18.1 素数判定 [ALDS_1_C: Prime Numbers](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS_1_C&lang=jp)
- 18.2 最大公約数 [ALDS1_1_B: Greatest Common Divisor](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B&lang=jp)
- 18.3 べき乗 [NTL_1_B: Power](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&lang=jp)

### 19章 ヒューリスティック探索
- 19.1 8クイーン問題 [ALDS1_13_A: 8 Queens Problem](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_13_A&lang=jp)
- 19.2 8パズル [ALDS1_13_B: 8 Puzzle](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_13_B&lang=jp)
- 19.3 15パズル [ALDS1_13_C: 15 Puzzle](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_13_C&lang=jp)

# 食事について
[マクドナルドJR東京駅店](http://www.mcdonalds.co.jp/shop/map/map.php?strcode=13928) テイクアウト推奨
