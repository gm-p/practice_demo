
int countWays(vector<int> penny, int n, int aim) {
    if(n <=0 || aim < 0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(aim+1, 0));
    for(int i=0; i<n; i++)
        dp[i][0] = 1;
    for(int j=penny[0]; j<=aim; j+=penny[0])
        dp[0][j] = 1;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=aim; j++)
        {
            if(j - aim[i] >= 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-penny[i]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n-1][aim];
}

int countWays(int n) {
    if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
    int a = 1, b = 2;
    int c = 0;
    for(int i=3; i<=n; i++)
    {
        c = (a + b) % 1000000007;
        a = b;
        b = c;
    }
    return c;
}

int getMin(vector<vector<int>> map, int n, int m)
{
    if(n < 0 || m < 0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = map[0][0];
    for(int i=1; i<n; i++)
        dp[i][0] = dp[i-1][0] + map[i][0];
    for(int j=1; j<m; j++)
        dp[0][j] = dp[0][j-1] + map[0][j];
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + map[i][j];
        }
    }
    return dp[n-1][m-1];
}

int getLIS(vector<int> A, int n) {
    if(n <= 0)
        return 0;
    vector<int> dp(n, 1);
    int res = dp[0];
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(A[i] > A[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
        res = max(res, dp[i]);
    }
    return res;
}

int findLCS(string A, int n, string B, int m) {
    if(n <= 0 || m <= 0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    if(A[0] == B[0])
        dp[0][0] = 1;
    for(int i=1; i<n; i++)
    {
        if(A[i] == B[0] || dp[i-1][0] == 1)
            dp[i][0] = 1;
    }
    for(int j=1; j<m; j++)
    {
        if(B[j] == B[0] || dp[0][j-1] == 1)
            dp[0][j] = 1;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(A[i] == B[j])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
        }
    }
    return dp[n-1][m-1];
}

int maxValue(vector<int> w, vector<int> v, int n, int cap) {
    vector<int> dp(cap+1, 0);
    for(int j=w[0]; j<=cap; j++)
        dp[j] = v[0];
    for(int i=1; i<n; i++)
    {
        for(int j=cap; j>=w[i]; j--)
            dp[j] = max(dp[j],  dp[j-w[i]]+v[i]);
    }
    return dp[cap];
}

int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++)
        dp[i][0] = i * c1;
    for(int j=1; j<=m; j++)
        dp[0][j] = j * c0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            dp[i][j] = min(dp[i-1][j] + c1, dp[i][j-1] + c0);
            if(A[i-1] == B[j-1])
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + c2);
        }
    }
    return dp[n][m];
}

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v, TreeNode* l=NULL, TreeNode* r=NULL): val(v), left(l), right(r)
    {}
}
void preOrder(TreeNode* root, vector<int>& nodes)
{
    if(root)
    {
        nodes.push_back(root->val);
        if(root->left)
            preOrder(root->left, nodes);
        if(root->right)
            preOrder(root->right, nodes);
    }
}
void inOrder(TreeNode* root, vector<int>& nodes)
{
    if(root)
    {
        if(root->left)
            inOrder(root->left, nodes);
        nodes.push_back(root->val);
        if(root->right)
            inOrder(root->right, nodes);
    }
}
void postOrder(TreeNode* root, vector<int>& nodes)
{
    if(root)
    {
        if(root->left)
            postOrder(root->left, nodes);
        if(root->right)
            postOrder(root->right, nodes);
        nodes.push_back(root->val);
    }
}

// 非递归
void preOrder(TreeNode* root, vector<int>& nodes)
{
    if(root)
    {
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* p = NULL;
        while(!s.empty())
        {
            p = s.top();
            s.pop();
            if(p->right)
                s.push(p->right);
            if(p->left)
                s.push(p->left);
            nodes.push_back(p->val);
        }
    }
}
void inOrder(TreeNode* root, vector<int>& nodes) 
{
    if(root)
    {
        stack<pair<TreeNode*, int>> s;
        s.push(make_pair(root, 0));
        TreeNode* p = NULL;
        int time = 0;
        while(!s.empty())
        {
            p = s.top().first;
            time = s.top().second;
            s.pop();
            if(time == 1)
            {
                nodes.push_back(p->val);
            }
            else
            {
                if(p->right)
                    s.push(make_pair(p->right, 0))
                s.push(make_pair(p, 1));
                if(p->left)
                    s.push(make_pair(p->left, 0));
            }
            
        }
    }
}
void postOrder(TreeNode* root, vector<int>& nodes)
{
    if(root)
    {
        stack<pair<TreeNode*, int>> s;
        s.push(make_pair(root, 0));
        TreeNode* p = NULL;
        int time = 0;
        while(!s.empty())
        {
            p = s.top().first;
            time = s.top().second;
            s.pop();
            if(time == 1)
            {
                nodes.push_back(p->val);
            }
            else
            {
                s.push(make_pair(p, 1));
                if(p->right)
                    s.push(make_pair(p->right, 0));
                if(p->left)
                    s.push(make_pair(p->left, 0));
            }
        }
    }
}

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(NULL), right(NULL)
    {}
};
// 按层遍历
vector<vector<int>> printTree(TreeNode* root) {
    vector<vector<int>> res;
    if(root)
    {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* last = root;
        TreeNode* nlast = root;
        TreeNode* p = NULL;
        vector<int> nodes;
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            nodes.push_bqck(p->val);
            if(p->left)
            {
                q.push(p->left);
                nlast = p->left;
            }
            if(p->right)
            {
                q.push(p->right);
                nlast = p->right;
            }
            if(p == last)
            {
                last = nlast;
                res.push_back(nodes);
                nodes.clear();
            }
        }
    }
    return res;
}
// 二叉树的序列化(先序)
string toString(TreeNode* root) {
    if(root == NULL)
        return "#!";
    string s = to_string(root->val) + "!";
    s += toString(root->left) + toString(root->right);
    return s;
}
// 平衡二叉树判断
bool checkTree(TreeNode* root) {
    if(root == NULL)
        return true;
    int depth = 1;
    return checkTreeCore(root, depth);
}
bool checkTreeCore(TreeNode* root, int& depth)
{
    if(root == NULL)
        return true;
    int ldepth = 0, rdepth = 0;
    if(checkTreeCore(root->left, ldepth) && checkTreeCore(root->right, rdepth) && abs(ldepth - rdepth) < 2)
    {
        depth = max(ldepth, rdepth) + 1;
        return true;
    }
    else
        return false;
}


// 
void bubbleSort(int* A, int n) {   // 冒泡排序
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            if(A[j] > A[j+1])
                swap(A[j], A[j+1]);
        }
    }
}

void selectSort(int* A, int n) {   // 选择排序
    for(int i=1; i<n; i++)
    {
        int k = n - i;
        for(int j=0; j<n-i; j++)
        {
            if(A[j] > A[k])
                k = j;
        }
        if(k != n - i)
            swap(A[n-i], A[k]);
    }
}

void insertSort(int* A, int n) {  // 插入排序
    for(int i=1; i<n; i++)
    {
        if(A[i] < A[i-1])
        {
            int val = A[i];
            // int k = i;
            // for(int j=i-1; j>=0; j--)
            // {
            //     if(A[j] < val)
            //         break;
            //     A[k] = A[j];
            //     k = j;
            // }
            // A[k] = val;
            int j = i - 1;
            while(j >= 0 && A[j] > val)
            {
                A[j+1] = A[j];
                j--; 
            }
            A[j+1] = val;
        }
    }
}

void shellSort(int* A, int n) {  // 希尔排序
    int gap = n/2;
    while(gap > 1)
    {
        for(int i=gap; i<n; i++)
        {
            // int k = i;
            // int val = A[i];
            // for(int j=i-gap; j>=0; j-=gap)
            // {
            //     if(A[j] < val)
            //         break;
            //     A[k] = A[j];
            //     k = j;
            // }
            // A[k] = val;
            int val = A[i];
            int j = i - gap;
            while(j >= 0 && A[j] > val)
            {
                A[j+gap] = A[j];
                j -= gap;
            }
            A[j+gap] = val;
        }
        gap /= 2;
    }
}

void quickSort(int* A, int n) {  // 快排
    quickSortCore(A, 0, n-1);
}
void quickSortCore(int* A, int start, int end) 
{
    if(start < end)
    {
        int mid = partition(A, start, end);
        quickSortCore(A, start, mid);
        quickSortCore(A, mid+1, end);
    }
}
int partition(int* A, int start, int end)
{
    int key = A[start]
    while(start < end)
    {
        while(start < end && A[end] >= key)
            end--;
        A[start] = A[end];
        while(start < end && A[start] <= key)
            start++;
        A[end] = A[start];
    }
    A[start] = key;
    return stasrt;
}

void mergeSort(int* A, int n) {  // 归并排序
    mergeSortCore(A, 0, n-1);
}
void mergeSortCore(int* A, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end) / 2;
        mergeSortCore(A, start, mid);
        mergeSortCore(A, mid+1, end);
        merge(A, start, mid, end);
    }
}
void merge(int* A, int start, int mid, int end)
{
    vector<int> B(end-start+1);
    int i = start, j = mid+1;
    int k = 0;
    while(i <= mid && j <= end)
    {
        if(A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    while(i <= mid)
        B[k++] = A[i++];
    while(j <= end)
        B[k++] = A[j++];
    for(int i=start,k=0; i<=end; i++, k++)
        A[i] = B[k];
}

void heapSort(int* A, int n) {   // 堆排
    for(int i=n/2; i>=0; i--)
        heapAdjust(A, i, n-1);
    for(int i=n-1; i>=1; i--)
    {
        swap(A[0], A[i]);
        heapAdjust(A, 0, i-1);
    }
}
void heapAdjust(int* A, int start, int end)
{
    if(start < end)
    {
        int val = A[start];
        int i = 2 * start + 1;
        while(i <= end)
        {
            if(i + 1 <= end && A[i] < A[i+1])
                i++;
            if(A[i] <= val)
                break;
            A[start] = A[i];
            start = i;
            i = 2 * i + 1;
        }
        A[start] = val;
    } 
}

// 计数排序
int* countingSort(int* A, int n) {
    if(n <= 1)
        return A;
    int maxA = minA = A[0];
    for(int i=1; i<n; i++)
    {
        maxA = max(maxA, A[i]);
        minA = min(minA, A[i]);
    }
    vector<int> B(maxA-minA+1, 0);
    for(int i=0; i<n; i++)
    {
        B[A[i]-minA]++;
    }
    for(int i=minA; i<=maxA; i++)
    {
        for(int j=0; j<B[i-minA]; j++)
            A[i-minA] = i;
    }
    return A;
}

// 基数排序
int* radixSort(int* A, int n) {
    queue<int> q[10];
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<n; j++)
        {
            int digit = A[j];
            for(int k=0; k<i; k++)
                digit /= 10;
            queue[digit % 10].push(A[j]);
        }
        int k = 0;
        for(int j=0; j<10; j++)
        {
            while(!q[j].empty())
            {
                A[k++] = q[j].front();
                q[j].pop();
            }
        }
    }
    return A;
}

// 几乎有序数组排序
vector<int> sortElement(vector<int> A, int n, int k) {
    if(A.empty() || n < k)
        return A;
    vector<int> B(k);
    int j = 0;
    for(int i=n-k; i<n; i++)
        B[j++] = A[i];
    for(int i=k/2; i>=0; i--)
        heapAdjust(B, i, k-1);
    for(int i=n-1; i>=k; i--)
    {
        A[i] = B[0];
        B[0] = A[i-k];
        // swap(A[i], B[0]);
        heapAdjust(B, 0, k-1);
    }
    for(int i=k-1; i>=1; i--)
    {
        A[i] = B[0];
        swap(B[0], B[i]);
        // swap(A[i], B[0]);
        heapAdjust(B, 0, i-1);
    }
    return A;
}
void heapAdjust(vector<int>& A, int start, int end)
{
    if(start < end)
    {
        int val = A[start];
        int i = 2 * start + 1;
        while(i <= end)
        {
            if(i + 1 <= end && A[i+1] > A[i])
                i++;
            if(A[i] <= val)
                break;
            A[start] = A[i];
            start = i;
            i = 2 * i + 1;
        }
        A[start] = val;
    }
}

// 判断数组是否有重复值
bool checkDuplicate(vector<int> a, int n) {
    if(n <= 1)
        return false;
    sort(a.begin(), a.end());
    for(int i=1; i<n; i++)
    {
        if(a[i] == a[i-1])
            return true;
    }
    return false;
}

// 有序数组合并
int* mergeAB(int* A, int* B, int n, int m) {
    int i = n - 1;
    int j = m-1;
    int k = n + m -1;
    while(i >= 0 && j >= 0)
    {
        if(A[i] > B[j])
            A[k--] = A[i--];
        else
            A[k--] = B[j--];
    }
    while(j >= 0)
        A[k--] = B[j--];
    return A;
}

// 三角排序
vector<int> sortThreeColor(vector<int> A, int n) {
    int i = -1, j = n;
    int k = 0;
    while(k != j)
    {
        if(A[k] == 1)
            k++;
        else if(A[k] == 0)
        {
            swap(A[++i], A[k]);
            k++;
        }
        else
            swap(A[--j], A[k]);
    }
    return A;
}

// 有序矩阵查找
bool findX(vector<vector<int>> mat, int n, int m, int x) {
    if(n < 0 || m < 0)
        return false;
    int row = 0, col = m-1;
    while(row < n && col >= 0)
    {
        if(mat[row][col] == x)
            return true;
        else if(mat[row][col] < x)
            row++;
        else
            col--;
    }
    return false;
}

// 最短子数组
int shortestSubsequence(vector<int> A, int n) {
    if(n < 2)
        return 0;
    int left = -1, right = -1;
    int maxA = A[0], minA = A[n-1];
    for(int i=1; i<n; i++)
    {
        if(A[i] > maxA)
            maxA= A[i];
        else if(A[i] < maxA)
            left = i;
    }
    for(int i=n-2; i>=0; i--)
    {
        if(A[i] < minA)
            minA = A[i];
        else if(A[i] > minA)
            right = i;
    }
    if(left == -1 && right == -1)
        return 0;
    return left - right + 1;
}

// 相邻两数的最大差值
int maxGap(vector<int> A, int n) {
    int minA = A[0], maxA = A[0];
    for(int i=1; i<n; i++)
    {
        minA = min(minA, A[i]);
        maxA = max(maxA, A[i]);
    }
    if(maxA == minA)
        return 0;
    vector<bool> hasNum(n+1, 0);
    vector<int>  maxNum(n+1, INT_MIN);
    vector<int>  minNum(n+1, INT_MAX);
    for(int i=0; i<n; i++)
    {
        bucket = bid(A[i], maxA, minA, n);
        maxNum[bucket] = hasNum[bucket] ? max(maxNum[bucket], A[i]): A[i];
        minNum[bucket] = hasNum[bucket] ? min(minNum[bucket], A[i]): A[i];
        hasNum[i] = true;
    }
    int i = 0;
    int lastMax = INT_MIN;
    while(i <= n)
    {
        if(hasNum[i])
        {
            lastMax = maxNum[i];
            break;
        }
        i++;
    }
    int res = 0;
    while(i < n)
    {
        if(hasNum[i])
        {
            res = max(res, minNum[i]-lastMax)
            lastMax = maxNum[i];
        }
    }
    return res;
}
int bid(int num, int maxA, int minA, int len)
{
    return int((num - minA) * len / (maxA - minA));
}

// 拓扑结构相同的子树
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
bool chkIdentical(TreeNode* A, TreeNode* B) {
    string strA = serialize(A);
    string strB = serialize(B);
    return KMP(strA, strB);
}
string serialize(TreeNode* root)
{
    if(root == NULL)
        return "#!";
    string res = serialize(root->left) + to_string(root->val) + "!" + serialize(root->right);
    return res;
}
void getNext(const string& match, vector<int>& next)
{
    int n = next.size();
    next[0] = -1;
    int i = 0, k = -1;
    while(i < n-1)
    {
        if(k == -1 || match[i] == match[k])
            next[++i] = ++k;
        else 
            k = next[k];
    }
}
bool KMP(const string& s, const string& match)
{
    if(s.empty() || match.empty() || match.size() < 1 || s.size() < match.size())
        rerurn false;
    int m = s.size();
    int n = match.size();
    vector<int> next(n, 0);
    getNext(match, next);
    int i = 0, j = 0;
    while(i < m && j < n)
    {
        if(s[i] == match[j])
        {
            i++;
            j++;
        }
        else if(next[j] == -1)
            i++;
        else
            j = next[j];
    }
    if(j == n)
        return true;
    return false;
}

// 词语变形词
bool chkTransform(string A， int lena, string B, int lenb) {
    if(A.empty() || B.empty() || lena != lenb)
        return false;
    vector<int> count(256, 0);
    for(int i=0; i<lena; i++)
        count[A[i]]++;
    for(int i=0; i<lenb; j++)
        count[B[i]]--;
    for(int i=0; i<256; i++)
        if(count[i])
            retuurn false;
    return true;
}

// 两串旋转
bool chkRotation(string A, int lena, string B, int lenb) {
    if(A.empty() || B.empty() || lena != loenB)
        return false;
    string s = A + A;
    return KMP(s, B);
}
void getNext(const string& match, vector<int>& next)
{
    int n = next.size();
    next[0] = -1;
    int i = 0, k = -1;
    while(i < n-1)
    {
        if(k == -1 || next[i] == next[k])
            next[++i] = ++k;
        else 
            k = next[k];
    }
}
bool KMP(const string& s, const string& match)
{
    int m = s.size();
    int n = match.size();
    vector<int> next(n, 0);
    getNext(match, next);
    int i = 0, j = 0;
    while(i < m && j < n)
    {
        if(s[i] == match[j])
        {
            i++;
            j++;
        }
        else if(next[j] == -1)
            i++;
        else
            j = next[j];
    }
    if(j == n)
        return true;
    return false;
}

// 句子的逆序
string reverseSentence(string A, int n) {
    if(A.empty())
        return A;
    int start = -1;
    int i = 0;
    reverse(A, 0, n-1);
    while(i < n)
    {
        if(A[i] == ' ')
        {
            if(start == -1)
            {
                i++;
            }
            else
            {
                reverse(A, start, i-1);
                start = i+1; // -1;
                i++;
            }
        }
        else if(i == n-1)
            reverse(A, start, i-1);
        else
        {
            if(start == -1)
                start = i;
        }
    }
    return A;
}
void reverse(string& A, int start, int end)
{
    while(start < end)
    {
        swap(A[start], A[end]);
        start++;
        end--;
    }
}

// 字符串移位
string stringTranslation(string A, int n, int len) {
    if(A.empty())
        return A;
    len %= n;
    reverse(A, 0, len-1);
    reverse(A, len, n-1);
    reverse(A, 0, n-1);
    return A;
}
vodi reverse(string& A, int start, int end)
{
    while(start < end)
    {
        swap(A[start], A[end]);
        start++;
        end--;
    }
}

// 拼接最小字典序
static bool cmp(const string& s1, const string& s2)
{
    string s1s2 = s1 + s2;
    string s2s1 = s2 + s1;
    return s1s2 < s2s1;
}
string findSamllest(vector<string> strs, int n) {
    if(strs.empty())
        return "";
    sort(strs.begin(), str2.end(), cmp);  //sort(strs.begin(), strs.end(), [&](string a, string b){string s1 = a + b; string s2 = b + a; return a < b;});
    string res = "";
    for(int i=0; i<n; i++)
        res += strs[i];
    return res;
}

// 空格替换
string replaceSpace(string iniString, int length) {
    int blank = 0;
    for(int i=0; i<length; i++)
    {
        if(iniString[i] == ' ')
            blank++;
    }
    int i = length, j = length + 2 * blank;
    iniString.resize(j);
    while(j > i)
    {
        if(iniString[i] == ' ')
        {
            iniString[j--] = '0';
            iniString[j--] = '2';
            iniString[j--] = '%';
        }
        else
            iniString[j--] = iniString[i];
        i--;
    }
    return iniString;
}

// 合法的括号序列判断
bool chkParenthesis(string A, int n) {
    if(A.empty())
        return true;
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(A[i] == '(')
            cnt++;
        else if(A[i] == ')')
            cnt--;
        else
            return false;
        if(cnt < 0)
            return false;
    }
    if(cnt == 0)
        return true;
    return false;
}

// 最大无重复字符子串
int longestSubstring(string A, int n) {
    if(A.empty())
        return 0;
    int res = 1;
    int pre = -1;
    int cur = 0;
    vector<int> hash(256, -1);
    for(int i=0; i<n; i++)
    {
        pre = max(pre, hash[A[i]]);
        cur = i - pre;
        res = max(res, cur);
        hash[A[i]] = i;
    }
    return res;
}

// 可查找最值的栈
class Solution {
public:
    stack<int> sData;
    stack<int> sMin;
    void push(int val) {
        sData.push(val);
        if(sMin.empty() || sMin.top() > val)
            sMin.push(val);
        else
            sMin.push(sMin.top());
    }
    void pop() {
        sData.pop();
        sMin.pop();
    }
    int top() {
        return sData.top();
    }
    int getMin() {
        return sMin.top();
    }
}

// 双栈队列
class TwoStack {
public:
    stack<int> s1;
    stack<int> s2;

    vector<int> twoStack(vector<int> ope, int n) {
        vector<int> res;
        for(int i=0; i<n; i++)
        {
            if(ope[i] == 0)
            {
                if(s2.empty())
                {
                    while(!s1.empty())
                    {
                        s2.push(s1.top());
                        s1.pop();
                    }
                    res.push_back(s2.top());
                    s2.pop();
                }
                else
                    s1.push(ope[i]);
            }
        }
        return res;
    }
}

// 栈的反转
int get(vector<int>& A)
{
    int res = A.back();
    A.pop_back();
    if(A.size() == 0)
        return res;
    else
    {
        //return get(A);
        int last = get(A);
        A.push_back(res);
        return last;
    }
        
}
void reverse(vector<int>& A)
{
    if(A.size() == 1)
        return 
    else
    {
        int last = get(A);
        reverse(A);
        A.push_back(last);
    }
}
vector<int> reverseStack(vector<int> A, int n) {
    reverse(A);
    return A;
}

// 双栈排序
vector<int> twoStackSort(vector<int> numbers) {
    if(numbers.empty())
        return numbers;
    stack<int> help;
    int n = numbers.size();
    int val = numbers.back();
    number.pop_back();
    while(numbers.size() < n)
    {
        while(!help.empty() && help.top() > val)
        {
            numbers.push_back(help.top());
            help.pop();
        }
        if(help.empty() || help.top() <= val)
            help.push(val);
        if(help.size() == n)
        {
            while(!help.empty())
            {
                numbers.push_back(help.top());
                help.pop();
            }
        }
        if(number.size() == n)
            break;
        val = number.back();
        number.pop_back();
    }
    return numbers;
}

// 滑动窗口
vector<int> slide(vector<int> arr, int n, int w) {
    vector<int> res;
    res.reserve(n-w+1);
    deque<int> dq;
    while(int i=0; i<w; i++)
    {
        while(!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);
    for(int i=w; i<n; i++)
    {
        while(!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();
        dq.push_back(i);
        if(i - dq.front() >= w)
            dq.pop_front();
        res.push_back(arr[dq.front()]);
    }
    return res;
}

// 数组变树
vector<int> buildMaxTree(vector<int> A, int n) {
    vector<int> res(n);
    stack<int> lStack;
    vector<int> lMax(n);
    for(int i=0; i<n; i++)
    {
        while(!lStack.empty() && A[lStack.top()] <= A[i])
            lStack.pop();
        if(lStack.empty)
            lMax[i] = -1;
        else
            lMax[i] = lStack.top();
        lStack.push(i);
    }
    stack<int> rStack;
    vector<int> rMax(n);
    for(int i=n-1; i>=0; i--)
    {
        while(!rStack.empty() && A[rStack.top()] <= A[i])
            rStack.pop();
        if(rStack.empty())
            rMax[i] = -1;
        else
            rMax[i] = rStack.top();
        rStack.push(i);
    }
    for(int i=0; i<n; i++)
    {
        if(lMax[i] == -1 && rMax[i] == -1)
            res[i] = -1;
        else if(lMax[i] == -1)
            res[i] = rMax[i];
        else if(rMax[i] == -1)
            res[i] = lMax[i];
        else
            res[i] = arr[lmax[i]] < arr[rMax[i]] ? lmax[i] : rMax[i];
    }
    return res;
}

// 环形链表插值
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL)
    {}
};
ListNode* insert(vector<int> A, vector<int> nxt, int val) {
    if(A.empty())
        return new ListNode(val);
    ListNode* pHead = NULL;
    ListNode* pre = NULL;
    ListNode* p = NULL;
    if(A[0] >= val)
    {
        pHead = new ListNode(val);
        pre = pHead;
        for(int i=0; i<n; i++)
        {
            p = new ListNode(A[i]);
            pre->next = p;
            pre = p;
        }
    }
    else
    {
        pHead = new ListNode(A[0])
        pre = pHead;
        int i = 1;
        for(; i<n && A[i] < val; i++)
        {
            p = new ListNode(A[i]);
            pre->next = p;
            pre = p;
        }
        p = new ListNode(val);
        pre->next = p;
        pre = p;
        for(; i<n; i++)
        {
            p = new ListNode(A[i]);
            pre->next = p;
            pre = p;
        }
    }
    return pHead;
}

// 访问单个节点的删除
ListNode* removeNode*ListNode* pHead, int delVal) {
    if(pHead == NULL)
        return NULL;
    ListNode* pre = pHead;
    ListNode* p = pHeaad->next;
    if(pHead->val == delVal)
    {
        delete pHeaad;
        return p;
    }
    while(p)
    {
        if(p->val == delVal)
        {
            ListNode* pToBeDelete = p;
            pre->next = p->next;
            delete pToBeDelete;
            break;
        }
        pre = p;
        p = p->next;
    }
    return pHeaad;
}

// 链表的分化
ListNode* listDivide(ListNode* head, int val) {
    if(head == NULL)
        return head;
    ListNode* p1 = NULL, *t1 = NULL;
    ListNode* p2 = NULL, *tail = NULL;
    while(head)
    {
        if(head->val <= val)
        {
            if(h1 == NULL)
            {
                h1 = head;
                t1 = head;
            }
            else
            {
                t1->next = head;
                t1 = head;
            }
        }
        else
        {
            if(h2 == NULL)
            {
                h2 = head;
                t2 = head;
            }
            else
            {
                t2->next = head;
                t2 = head;
            }
        }
        head = head->next;
    }
    if(h1 == NULL)
        return h2;
    else 
    {
        t1->next = h2;
        if(t2)
            t2->next = NULL;
        return h1;
    }   
}

// 打印两个链表的公共值
vector<int> findCommonParts(ListNode* headA, ListNode* headB) {
    vector<int> res;
    ListNode* pA = headA;
    ListNode* pB = headB;
    while(pA && pB)
    {
        if(pA->val == pB->val)
        {
            res.push_back(pA->val);
            pA = pA->next;
            pB = pB->next;
        }
        else if(pA->val < pB->val)
            pA = pA->next;
        else 
            pB = pB->next;
    }
    return res;
}

// 链表的K逆序
ListNode* inverse(ListNode* head, int k) {
    if(head == NULL)
        return head;
    int cnt = 0;
    ListNode* p = head;
    while(p)
    {
        cnt++;
        p = p->next;
    }
    if(cnt < k || k < 2)
        return head;
    ListNode* start = NULL;
    ListNode* pn = head;
    ListNode* pHead = NULL;
    ListNode* tail = NULL;
    for(int i=0; i<cnt/k; i++)
    {
        start = pn;
        p = pn;
        for(int j=1; j<k; j++)
        {
            p = p->next;
        }
        pn = p->next;
        reverse(start, p);
        if(pHead == NULL)
        {
            pHead = start;
            tail = p;
        }
        else
        {
            tail->next = start;
            tail = p;
        }
    }
    tail->next = pn;
    return pHead;
}
void reverse(ListNode*& head, ListNode*& tail)
{
    ListNode* p = head;
    ListNode* pre = NULL;
    ListNode* pn = NULL;
    while(p != tail)
    {
        pn = p->next;
        p->next = pre;
        pre = p;
        p = pn;
    }
    p->next = pre;
    tail = head;
    head = pn;
}

// 链表指定值清除
ListNode* clear(ListNode* head, int val) {
    if(head == NULL)
        return NULL;
    ListNode* p = head;
    ListNode* newHead = NULL;
    ListNode* tail = NULL;
    ListNode* pToBeDelete = NULL;
    ListNode* pn = NULL;
    while(p)
    {
        if(p->val == val)
        {
            pn = p->next;
            pToBeDelete = p;
            delate pToBeDelete
            p = pn;
        }
        else
        {
            if(newHead == NULL)
            {
                newHead = p;
                tail = p;
            }
            else
            {
                tail->next = p;
                tail = p;
            }
            p = p->next;
        }
    }
    return newHead;
}

// 链表的回文结构
bool isPalindrome(ListNode* pHead) {
    if(pHead == NULL)
        return true;
    ListNode* fast = pHead;
    ListNode* slow = pHead;
    bool res = true;
    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next)
    {
        fast = fast->next;
        slow = slow->next;
        reverse(slow, fast);
    }
    else
        reverse(slow, fast);
    ListNode* p = pHead;
    ListNode* q = fast;
    while(p != slow)
    {
        if(p->val == q->val)
        {
            p = p->next;
            q = q->next;
        }
        else
        {
            res = false;
            break;
        }
    }
    reverse(fast, slow); //reverse(slow, fast);
    return res;
}
void reverse(ListNode* start, listNode* end)
{
    ListNode* pre = NULL;
    ListNode* p = start;
    ListNode* pn = NULL;
    while(p != end)
    {
        pn = p->next;
        p->nnext = pre;
        pre = p;
        p = pn;
    }
    p->next = pre;
}

// 复杂链表的复制
struct RandomListNode{
    int label;
    struct RandomListNode* next, *random;
    RandomListNode(int x):
        label(x), next(NULL), random(NULL) {}
};
RandomListNode* Clone(RandomListNode* pHead) {
    if(pHead == NULL)
        return NULL;
    copyNode(pHead);
    copyRandom(pHead);
    return splitNode(pHead);
}
void copyNode(RandomListNode* pHead)
{
    RandomListNode* p = pHead;
    RandomListNode* pn = NULL;
    while(p)
    {
        pn = p->next;
        RandomListNode* pNew = new RandomListNode(p->label);
        p->next = pNew;
        pNew->next = pn;
        p = pn;

    }
}
void copyRandom(RandomListNode* pHead)
{
    RandomListNode* p = pHead;
    RandomListNode* pNew = NULL;
    while(p)
    {
        pNew = p->next;
        if(p->random)
            pNew->random = p->random->next;
        p = pNew->next;
    }
}
RandomListNode* splitNode(RandomListNode* pHead)
{
    RandomListNode* pre = pHead;
    RandomListNode* pNewHead = pHead->next;
    RandomListNode* newPre = pNewHead;
    RandomListNode* p = pNewHead->next;
    RandomListNode* newP = NULL;
    while(p)
    {
        pre->next = p;
        pre = p;
        newP = p->next;
        newPre->next = newP;
        newPre = newP;
        p = newP->next;
    }
    pre->next = NULL;
    newPre->next = NULL;
    return pNewHead;
}

// 链表判环
int chkLoop(ListNode* head, int adjust) {
    int res = -1;
    if(head == NULL)
        return res;
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    if(slow == fast)
    {
        fast = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        res = slow->val;
    }
    return res;
}

// 无环单链表判相交
bool chkIntersect(ListNode* headA, ListNode* headB) {
    if(headA == NULL || headB == NULL)
        return false;
    ListNode* pA = headA;
    ListNode* pB = headB;
    while(pA->next)
        pA = pA->next;
    while(pB->next)
        pB = pB->next;
    if(pA == pB)
        return true;
    return false;
}

// 有环单链表相交判断
bool chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1) {
    if(head1 == NULL || head2 == NULL)
        return false;
    ListNode* e1 = getEntrance(head1);
    ListNode* e2 = getEntrance(head2);
    if(e1 && e2)
    {
        if(e1 == e2)
            return true;
        ListNode* p = e1->next;
        while(p != e1)
        {
            if(p == e2)
                return true;
            p = p->next;
        }
    }
    return false;
}
ListNode* getEntrance(ListNode* head)
{
    if(head == NULL)
        return NULL;
    ListNode* fast = head;
    ListNode* slow = head;
    wihle(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    if(slow == fast)
    {
        fast = head;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    return NULL;
}

// 单链表相交判断
bool chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1) {
    if(head1 == NULL || head2 == NULL)
        return false;
    ListNode* e1 = getEntrance(head1);
    ListNode* e2 = getEntrance(head2);
    if(e1 == NULL && e2 == NULL)
    {
        return chkNoLoop(head1, head2);
    }
    else if(e1 && e2)
        return chkLoop(e1, e2);
    return false;
}
ListNode* getEntrance(ListNode* head)
{
    if(head == NULL)
        return NULL;
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next && fast->Next->Next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    if(slow == fast)
    {
        fast = head;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
    return NULL;
}
bool chkNoLoop(ListNode* head1, ListNode* head2)
{
    ListNode* p1 = head1;
    while(p1->next)
        p1 = p1->next;
    ListNode* p2 = head2;
    while(p2->next)
        p2 = p2->next;
    if(p1 == p2)
        return true;
    return false;
}
bool chkLoop(ListNode* head1, ListNode* head2)
{
    if(head1 == head2)
        return true;
    ListNode* p = head1->next;
    while(p != head1)
    {
        if(p == head2)
            return true;
        p = p->next;
    }
    return false;
}

// 局部最小值
int getLessIndex(vector<int> arr) {
    if(arr.empty())
        return -1;
    int n = arr.size();
    if(n == 1 || arr[0] < arr[1])
        return arr[0]
    if(arr[n-1] < arr[n-2])
        return arr[n-1];
    int left = 1, right = n-2;
    int mid = -1;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(arr[mid] > arr[mid-1])
            right = midi-1;
        else if(arr[mid] > arr[mid+1])
            left = mid+1;
        else 
            return mid;
    }
    return -1;
}

// 元素最左出现
int findPos(vector<int> arr, int n, in num) {
    if(arr.empty() || arr[0] > num || arr[n-1] < num)
        return -1;
    int res = -1;
    int left = 0, right = n-1;
    int mid;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(arr[mid] == num)
        {
            res = mid;
            right = mid - 1;
        }
        else if(arr[mid] < num)
            left = mid+1;
        else
            right = mid-1;
    }
    return res;
}

// 循环有序数组最小值
int getMin(vector<int> arr, int n) {
    if(n <= 0)
        return -1;
    int left = 0, right = n-1;
    int mid;
    while(arr[left] >= arr[right])
    {
        if(right - left == 1)
            return arr[right];
        mid = (left + right) / 2;
        if(arr[left] == arr[mid] && arr[mid] == arr[right])
        {
            int res = arr[left];
            for(int i=left+1; i<=right; i++)
            {
                if(arr[i] < res)
                    res = arr[i];
            }
            return res;
        }
        else if(arr[mid] < arr[left])
            right = mid;
        else
            left = mid;
    }
    return -1;
}

// 最左原位
int findPos(vector<int> arr, int n) {
    if(n <= 0 || arr[0] > n-1 || arr[n-1] < 0)
        return -1;
    int left = 0, right = n-1;
    int mid;
    int res = -1;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(arr[mid] == mid)
        {
            res = mid;
            right = mid -1;
        }
        else if(arr[mid] < mid)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return res;
}

// 完全二叉树计数
int count(TreeNode* root) {
    if(root == NULL)
        return 0;
    int lh = depth(root->left);
    int rh = depth(root->right);
    if(lh == rh)
        return 1 << lh + count(root->right);  // pow(2, h1)
    return count(root->left) + 1 << rh;
}
int depth(TreeNode* root)
{
    ListNode* p = root;
    int height = 0;
    while(p)
    {
        ++height;
        p = p->left;
    }
    return height;
}

// 快速N次方
int getPower(int k, int N) {
    int res = 1;
    int p = k;
    while(N)
    {
        if((N & 0x1))
            res = (res * p) % 1000000007;
        N >>= 1;
        p = (p * p) % 1000000007;
    }
    return res % 1000000007;
}

// 完全二叉树的判断
bool chk(TreeNode* root) {
    if(root == NULL)
        return true;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* p = NULL;
    bool isLeaf = false;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p->left == NULL && p->right)
            return false;
        if(isLeaf && (p->left || p->right))
            return false;
        if(!isLeaf && p->right == NULL)
            isLeaf = true;

        if(p->left)
            q.push(p->left);
        if(p->right)
            q.push(p->right);
    }
    return true;
}

// 折纸问题
vector<string> foldPager(int n) {
    vector<int> res;
    foldPagerCore(1, n, "down", res);
    return res;
}
void foldPagerCore(int k, int n, const string& s, vector<int>& res)
{
    if(k > n)
        return;
    foldPagerCore(k+1, n, "down", res);
    res.push_back(s);
    foldPagerCore(k+1, n, "up", res);
}

// 寻找错误节点
vector<int> findError(TreeNode* root) {
    if(root == NULL)
        return vector<int>();
    vector<int> data;
    inOrder(root, data);
    vector<int> res;
    res.reserve(2);
    int max = -1, min = -1;
    for(int i=1; i<n; i++)
    {
        if(arr[i] < arr[i-1])
        {
            if(max == -1)
            {
                max = arr[i-1];
                min = arr[i];
            }
            else
                min = arr[i];
        }
    }
    res.push_back(min);
    res.push_back(max);
    return res;
}
void inOrder(TreeNode* root, vector<int>& data)
{
    if(root)
    {
        inOrder(root->left, data);
        data.push_back(root->val);
        inOrder(root->right, data);
    }
}

// 树上最远距离
int findLongest(TreeNode* root) {
    if(root == NULL)
        return 0;
    int depth = 0;
    return findLongestCore(root, depth);
}
int findLongestCore(TreeNode* root, int& depth)
{
    if(root == NULL)
        reteurn 0;
    int lh = 0;
    int left = findLongestCore(root->left, lh)
    int rh = 0;
    int right = findLongestCore(root->right, rh);
    depth = max(lh, rh) + 1;
    int res = max(left, right);
    res = max(res, lh + rh + 1);
    return res;
}

// 最大二叉搜索子树
TreeNode* getMax(TreeNode* root) {
    if(root == NULL)
        return NULL;
    int maxV = INT_MIN, maxV = INT_MIN, count = 0;
    return getMaxCore(root, maxV, minV, count);
}
TreeNode* getMaxCore(TreeNode* root, int& maxV, int& minV, int& count)
{
    if(root == NULL)
        return NULL;
    int lmax = 0, lmin = 0, lcnt = 0;
    TreeNode* lTree = getMaxCore(root->left, lmax, lmin, lcnt);
    int rmax = 0, rmin = 0, rcnt = 0;
    TreeNode* rTree = getMaxCore(root->right, rmax, rmin, rcnt);
    maxV = max(rmax, root->val);
    minV = min(lmin, root->val);
    if(root->left == lTree && root->right == rTree && lmax < root->val && root->val < rmin)
    {
        count = lcnt + rcnt;
        return root;
    }
    else
    {
        if(lcnt > rcnt)
        {
            count = lcnt;
            return lTree;
        }
        else
        {
            count = rcnt;
            return rTree;
        }
    }
    return NULL;
}

// 交换练习(不使用额外变量)
vector<int> getSwap(vector<int> num) {
    if(num.empty() || num.size() < 2)
        return num;
    num[0] = num[0] ^ num[1];
    num[1] = num[0] ^ num[1];
    num[0] = num[0] ^ num[1];
    return num;
}

// 比较练习
int getMax(int a, int b) {
    int c = a - b;
    int as = sign(a);
    int bs = sign(b);
    int cs = sign(c);
    int difab = as ^ bs;
    int sameab = flip(difab);
    int returnA = difab * as + sameab * cs;
    int returnB = flip(returnA);
    return a * returnA + b * returnB; 
}
int flip(int n)
{
    return (n ^ 1);
}
int sign(int n)
{
    return flip((n >> 31) & 1);
}

// 寻找奇数次出现
int findOdd(vector<int> A, int n) {
    int res = 0;
    for(int i=0; i<n; i++)
        res ^= A[i];
    return res;
}

// 寻找奇数次出现的II
vector<int> findOdds(vector<int> arr, int n) {
    vector<int> res(2, 0);
    if(n < 2)
        return vector<int>();
    int odd = 0;
    for(int i=0; i<n; i++)
        odd ^= arr[i];
    int k = firstOne(odd);
    for(int i=0; i<n; i++)
    {
        if(isOne(arr[i], k))
            res[0] ^= arr[i];
    }
    res[1] = odd ^ res[0];
    if(res[0] > res[1])
        swap(res[0], res[1]);
    return res;
}
int firstOne(int num)
{
    int k = 0;
    // while((num >> k)) & 0x1) == 0)
    // {
    //     k++;
    // }
    while(((n & 0x1) == 0) && (k < 8 * sizeof(int)))
    {
        ++k;
        n >>= 1;
    }
    return k;
}
bool isOne(int num, int k)
{
    return ((num >> k) & 0x1);
}

// 错误信封
int countWays(int n) {
    if(n < 2)
        return 0;
    else if(n == 2)
        return 1;
    else 
    {
        long long last = 0, res = 1;
        for(int i=3; i<n; i++)
        {
            int tmp = (i - 1) * (last + res) % 1000000007;
            last = res;
            res = tmp;
        }
    }
    return res % 1000000007;
}

// 随机哈数
class Random5 {
public:
	static int randomNumber();
};

class Random7 {
public:
    int rand5() {
        return Random5::randomNumber();
    }
    // 以上内容请不要修改
    

    int randomNumber() {
        // 代码写这里,通过rand5函数随机产生[1,7]
        int val = 5 * (rand5() - 1) + (rand5() - 1);
        while(val > 20)
        {
            val = 5 * (rand5() - 1) + (rand5() - 1);
        }
        return val % 7 + 1;
    }
};

// 随机01
class RandomP {
public:
	static int f();
};

class Random01 {
public:
    // 用RandomP::f()实现等概率的01返回
    int random01() {
        int a = RandOmP::f();
        int b = RandomP::f();
        while((a ^ b) == 0)
        {
            a = RandOmP::f();
            b = RandomP::f();
        }
        if(a == 0)
            return 0;
        else 
            return 1;
    }
};

// 随机区间
class RandomSeg {
public:
    // 等概率返回[0,1)
	double f() {
	    return rand() * 1.0 / RAND_MAX;
	}
	// 通过调用f()来实现
    double random(int k, double x) {
        double res = -1;
        for(int i=0; i<k; i++)
        {
            res = max(res, f());
        }
        return res;
    }
};

// 随机数组
vector<int> print(vector<int> arr, int N, int M) {
    if(N < M)
        return vector<int>();
    vector<int> res;
    for(int i=0; i<M; i++)
    {
        int j = rand() % (N - i);
        res.push_back(arr[j]);
        swap(arr[j], arr[N-i-1]);
    }
    return res;
}

// 机器吐球
class Bag {
public:
	vector<int> ret;
    // 每次拿一个球都会调用这个函数，N表示第i次调用
    vector<int> carryBalls(int N, int k) {
        if(ret.size() < k)
            ret.push_back(N)
        else
        {
            if(rand() % N < k)
            {
                int id = rand() % k;
                ret[id] = N;
            }
        }
        return ret;
    }
};