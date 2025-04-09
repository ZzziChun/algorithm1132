#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node
{
    int freq;
    char ch;
    Node *left;
    Node *right;
    bool isLeaf;
    int id; // for tie-breaking

    Node(char c, int f, int _id) : freq(f), ch(c), left(nullptr), right(nullptr), isLeaf(true), id(_id) {}
    Node(Node *l, Node *r, int _id) : left(l), right(r), freq(l->freq + r->freq), ch(0), isLeaf(false), id(_id) {}
};

// 建立編碼表
void buildCode(Node *root, string code, unordered_map<char, string> &codes)
{
    if (!root)
        return;
    if (root->isLeaf)
    {
        codes[root->ch] = code;
    }
    buildCode(root->left, code + "0", codes);
    buildCode(root->right, code + "1", codes);
}

// 比較兩個節點，用於 R 和 N 的混合選取
bool cmpNode(Node *a, Node *b)
{
    if (a->freq != b->freq)
        return a->freq < b->freq;
    return a->id < b->id; // 決定先出現的優先
}

int main()
{
    string line, input;
    while (getline(cin, line))
    {
        if (line.empty())
            break;
        input += line + "\n"; // 保留換行符號
    }

    unordered_map<char, int> freq;
    vector<Node *> R;
    int id_counter = 0;

    for (char ch : input)
    {
        freq[ch]++;
    }

    for (char ch : input)
    {
        if (freq[ch] != -1)
        {
            R.push_back(new Node(ch, freq[ch], id_counter++));
            freq[ch] = -1;
        }
    }

    vector<Node *> N;

    while (R.size() + N.size() > 1)
    {
        vector<Node *> candidates;
        if (!R.empty())
            candidates.push_back(R[0]);
        if (R.size() > 1)
            candidates.push_back(R[1]);
        if (!N.empty())
            candidates.push_back(N[0]);
        if (N.size() > 1)
            candidates.push_back(N[1]);
        if (R.size() >= 1 && N.size() >= 1)
        {
            candidates.push_back(R[0]);
            candidates.push_back(N[0]);
        }

        Node *a = nullptr;
        Node *b = nullptr;

        // 全部收集起來選出最小兩個
        vector<Node *> all;
        all.insert(all.end(), R.begin(), R.end());
        all.insert(all.end(), N.begin(), N.end());
        sort(all.begin(), all.end(), cmpNode);

        a = all[0];
        b = all[1];

        // 從原來的集合移除 a, b
        auto remove_node = [](vector<Node *> &vec, Node *target)
        {
            for (auto it = vec.begin(); it != vec.end(); ++it)
            {
                if (*it == target)
                {
                    vec.erase(it);
                    break;
                }
            }
        };
        remove_node(R, a);
        remove_node(R, b);
        remove_node(N, a);
        remove_node(N, b);

        // 建立父節點，依據來源放左右
        Node *parent;
        if (a->isLeaf && b->isLeaf)
        {
            // 兩個都來自 R，依據 id 小的在左
            if (a->id < b->id)
                parent = new Node(a, b, id_counter++);
            else
                parent = new Node(b, a, id_counter++);
        }
        else if (!a->isLeaf && !b->isLeaf)
        {
            // 兩個都來自 N，N 中較前的放左
            if (a->id < b->id)
                parent = new Node(a, b, id_counter++);
            else
                parent = new Node(b, a, id_counter++);
        }
        else
        {
            // 一個來自 R, 一個來自 N，N 在左
            if (!a->isLeaf)
                parent = new Node(a, b, id_counter++);
            else
                parent = new Node(b, a, id_counter++);
        }

        N.push_back(parent);
    }

    Node *root = N[0];
    unordered_map<char, string> codes;
    buildCode(root, "", codes);

    // collect and sort output
    vector<pair<string, char>> output;
    for (auto &[ch, code] : codes)
    {
        output.emplace_back(code, ch);
    }

    // sort by binary value, then length descending if same
    sort(output.begin(), output.end(), [](auto &a, auto &b)
         {
        int val_a = stoi(a.first, nullptr, 2);
        int val_b = stoi(b.first, nullptr, 2);
        if (val_a != val_b) return val_a < val_b;
        return a.first.length() > b.first.length(); });

    for (auto &[code, ch] : output)
    {
        if (ch == '\n')
            cout << code << " -> " << endl;
        else
            cout << code << " -> " << ch << endl;
    }

    return 0;
}
