冒泡
void bubbleSort(int a[], int n)
{
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<n-i; j++)
		{
			if(a[j] > a[j+1])
				swap(a[j], a[j+1]);
		}
	}
}

选择
void selectSort(int a[], int n)
{
	for(int i=1; i<n; i++)
	{
		int k = i-1;
		for(int j=i; j<n; j++)
		{
			if(a[j] < a[k])
				k = j;
		}
		if(k != i-1)
			swap(a[k], a[i-1]);
	}
}

插入
void insertSort(int a[], int n)
{
	for(int i=1; i<n; i++)
	{
		int tmp = a[i];
		int j = i-1;
		for( ; j>=0 && a[j]>tmp; j--)
		{
			a[j+1] = a[j];
		}
		a[j+1] = tmp;
	}
}

希尔
void shellSort(int a[], int n)
{
	int gap = n / 2;
	while(gap > 0)
	{
		for(int i=gap; i<n; i++)
		{
			int tmp = a[i];
			int j = i - gap;
			for(; j>0 && a[j]>tmp; j-=gap)
			{
				a[j+gap] = a[j];
			}
			a[j+gap] = tmp;
		}
		gap /= 2;
	}
}

快排
int partition(int a[], int start, int end)
{
	if(start < end)
	{
		int tmp = a[start];
		while(start < end)
		{
			while(start < end && a[end] >= tmp)
				end--;
			a[start] = a[end];
			while(start < end && a[start] <= tmp)
				start++;
			a[end] = a[start];
		}
		a[start] = tmp;
		return start;
	}
}
void quickSortCore(int a[], int start, int end)
{
	int mid = partition(a, start, end);
	quickSort(a, start, mid-1);
	quickSort(a, mid+1, end);
}
void quickSort(int a[], int n)
{
	quickSortCore(a, 0, n-1);
}

归并
void merge(int a[], int start, int mid, int end)
{
	int* b = new int[end - start + 1];
	int i = mid, j = end, k = end-start;
	while(i >= 0 && j > mid)
	{
		if(a[i] > a[j])
		{
			b[k--] = a[i--];
		}
		else if(a[i] == a[j])
		{
			b[k--] = a[j--];
			b[k--] = a[i--];
		}
		else
		{
			b[k--] = a[j--];
		}
	}
	while(j > mid)
		b[k--] = a[j--];
	while(i >= 0)
		b[k--] = a[i--];
	for(i=start, j=0; i<=end; i++, j++)
		a[i] = b[j];
	delete[] b;
}
void mergeSortCore(int a[], int start, int end)
{
	if(start < end)
	{
		int mid = (start + end) / 2;
		mergeSortCore(a, start, mid);
		mergeSortCore(a, mid+1, end);
		merge(a, start, mid, end);
	}
}
void mergeSort(int a[], int n)
{
	mergeSortCore(a, 0, n-1);
}

堆排序 
void heapAdjust(int a[], int start, int end)
{
	if(start < end)
	{
		int tmp = a[start];
		int i = 2 * start + 1;
		while(i <= end && a[i] > tmp)
		{
			if(i + 1 <= end && a[i] < a[i+1])
				i++;
			if(a[i] <= tmp)
				break;
			a[start] = a[i];
			start = i;
			i = 2 * start + 1;
		}
		a[start] = tmp;
	}
}
void heapSort(int a[], int n)
{
	for(int i=n/2; i>=0; i--)
		heapAdjust(a, i, n-1);
	for(int i=1; i<n; i++)
	{
		swap(a[0], a[n-i]);
		heapAdjust(a, 0, n-i-1);
	}
}


void preOrder(TreeNode* head, vector<int>& res)
{
	if(head)
	{
		res.push_back(head->val);
		if(head->left)
			preOrder(head->left, res);
		if(head->right)
			preOrder(head->right, res);
	}
}

void inOrder(TreeNode* head, vector<int>& res)
{
	if(head)
	{
		if(head->left)
			inOrder(head->left, res);
		res.push_back(head->val);
		if(head->right)
			inOrder(head->right, res);
	}
}

void postOrder(TreeNode* head, vector<int>& res)
{
	if(head)
	{
		if(head->left)
			postOrder(head->left, res);
		if(head->right)
			postOrder(head->right, res);
		res.push_back(head->val);
	}
}

void preOrder(TreeNode* head, vector<int>& res)
{
	if(head)
	{
		stack<TreeNode*> s;
		s.push(head);
		while(!s.empty())
		{
			TreeNode* p = s.top();
			s.pop();
			res.push_back(p->val);
			if(p->right)
				s.push(p->right);
			if(p->left)
				s.push(p->left);
		}
	}
}

void inOrder(TreeNode* head, vector<int>& res)
{
	if(head)
	{
		stack<pair<TreeNode*, int> > s;
		s.push(make_pair(head, 0));
		while(!s.empty())
		{
			TreeNode* p = s.top().first;
			int time = s.top().second;
			s.pop();
			if(time == 0)
			{
				if(p->right)
					s.push(make_pair(p->right, 0));
				s.push(make_pair(p, 1));
				if(p->left)
					s.push(make_pair(p->left, 0));
			}
			else
				res.push_back(p->val);
		}
	}
}

void postOrder(TreeNode* head, vector<int>& res)
{
	if(head)
	{
		stack<pair<TreeNode*, int> > s;
		s.push(make_pair(head, 0));
		while(!s.empty())
		{
			TreeNode* p = s.top().first;
			int time = s.top().second;
			s.pop();
			if(time == 0)
			{
				s.push(make_pair(p, 1));
				if(p->right)
					s.push(make_pair(p->right, 0));
				if(p->left)
					s.push(make_pair(p->left, 0));
			}
			else
				res.push_back(p->val);
		}
	}
}


计数排序
int* countingSort(int* a, int n)
{
	int minA = a[0];
	int maxA = a[0];
	for(int i=1; i<n; i++)
	{
		if(a[i] < minA)
			minA = a[i];
		if(a[i] > maxA)
			maxA = a[i];
	}
	vector<int> B(maxA-minA+1, 0);
	for(int i=0; i<n; i++)
		B[a[i] - minA]++;
	for(int i=0, k=0; i<B.size(); i++)
	{
		for(int j=0; j<B[i]; j++)
			a[k++] = i + minA; 
	}
	return A;
}

基数排序
int* radixSort(int* a, int n)
{
	queue<int> q[10];
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<n; j++)
		{
			int digit = a[j];
			for(int k=0; k<i; k++)
				digit /= 10
			digit %= 10;
			q[digit].push(a[j]);
		}
		
		int k = 0;
		for(int j=0; j<10; j++)
		{
			while(!q[j].empty())
			{
				a[k++] = q[j].front();
				q[j].pop();
			}
		}
	}
	return a;
}

几乎有序的数组排序 
vector<int> sortElement(vector<int> A, int n, int k)
{
	if(A.empty() || n < k)
		return A;
	vector<int> maxHeap(k);
	for(int i=0; i<k; i++)
		maxHeap[i] = A[n-i-1];
	for(int i=k/2; i>=0; i--)
		adjust(maxHeap, i, k-1);
	
	for(int i=n-1; i>=k; i--)
	{
		A[i] = maxHeap[0];
		maxHeap[0] = A[i-k];
		adjustHeap(A, 0, k-1);
	}
	for(int i=k-1; i>=0; i--)
	{
		A[i] = maxHeap[0];
		swap(maxHeap[0], maxHeap[i]);
		adjustHeap(maxHeap, 0, i-1);
	}
	return A;
}
void adjustHeap(int a[], int start, int end)
{
	if(start < end)
	{
		int tmp = a[start];
		int i = 2 * start + 1;
		while(i <= end)
		{
			if(i + 1 <= end && a[i] < a[i+1])
				i++;
			if(a[i] <= tmp)
				break;
			a[start] = a[i];
			start = i;
			i = 2 * start + 1; 
		}
		a[start] = tmp;
	}
}

bool checkDuplication(vector<int> a, int n)
{
	sort(a.begin(), a.end());
	for(int i=1; i<n; i++)
		if(a[i] == a[i-1])
			return true;
	return false;
}

int* mergeAB(int* A, int* B, int n, int m)
{
	int i = n-1, j = m-1;
	int k = n + m - 1;
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

三角排序（荷兰国旗）
vector<int> sortThreeColor(vector<int> a, int n)
{
	int i = -1, j = n;
	int k = 0;
	while(k < j)
	{
		if(a[k] == 1)
			k++;
		else if(a[k] == 0)
		{
			swap(a[k], a[++i]);
			k++;
		}	
		else
			swap(a[k], a[--j]);
	}
	return A;
}

有序矩阵查找
bool findX(vector<vector<int> > mat, int n, int m, int x) {
	int i = 0;
	int j = m-1;
	while(i < n && i>= 0 && j >= 0 && j < m)
	{
		if(mat[i][j] == x)
			return true;
		else if(mat[i][j] > x)
			j--;
		else
			i++;
	}
	return false;
}

最短子数组
int shortestSubsequence(vector<int> A, int n) {
	int left = -1, maxL = A[0];
	for(int i=1; i<n; i++)
	{
		if(A[i] > A[left])
			maxL = A[i];
		else if(A[i] < maxL)
			left = i;
	}
	int right = -1, minR = A[n-1];
	for(int i=n-2; i>=0; i--)
	{
		if(A[i] < A[right])
			minR = A[i];
		else if(A[i] > minR)
			right = i;
	}
	if(left == -1 && right == -1)
		return 0;
	return right - left + 1;
}

相邻两数最大差值
int maxGap(vector<int> A, int n) {
	int maxA = A[0], minA = A[0];
	for(int i=1; i<n; i++)
	{
		if(A[i] < minA)
			minA = A[i];
		if(A[i] > maxA)
			maxA = A[i];
	}
	vector<bool> hasNum(n+1, 0);
	vector<int> maxb(n+1, INT_MIN);
	vector<int> minb(n+1, INT_MAX);
	for(int i=0; i<n; i++)
	{
		int bid = bucket(a[i], n, maxA, minA);
		maxb[bid] = max(maxb[bid], a[i]);
		minb[bid] = min(minb[bid], a[i]);
		hasNum[bid] = true;
	}
	int i = 0;
	while(!hasNum[i])
		i++;
	int res = 0;
	int last = maxb[i];
	while(i < n)
	{
		if(hasNum[i])
		{
			res = max(res, minb[i] - last);
			last = maxb[i];
		}
	}
	return res;
}
int bucket(int a, int len, int maxV, int minV)
{
	return (int)((a - minV) * len / (maxV - minV));
}

拓扑结构相同的子树
bool chkIdentical(TreeNode* A, TreeNode* B) {
	string strA = serial(A);
	string strB = serial(B);
	return KMP(strA, strB);
}
string serial(TreeNode* A)
{
	string res = "";
	if(A == NULL)
		return "#!";
	res += serial(A->left);
	res += to_string(A->val) + "!";
	res += serial(A->right);
	return res;
}
bool KMP(string strA, string strB)
{
	if(strA.empty() || strB.empty() || strB.size() < 1 || strA.size() < strB.size()) 
		return false;
	vector<int> next(strB.size(), 0);
	getNext(strB, next);
	int i=0, j=0;
	while(i < strA.size() && j < strB.size())
	{
		if(strA[i] == strB[j])
		{
			i++;
			j++;
		}
		else if(next[j] > -1)
			j = next[j];
		else
		{
			i++;
			//j=0;
		}
	}
	if(j == strB.size())
		return true;
	return false;
}
void getNext(string strB, vector<int>& next)
{
	int n = strB.size();
	next[0] = -1;
	int i=0, k=-1;
	while(i < n-1)
	{
		if(k == -1 || strB[i] == strB[k])
			next[++i] == ++k;
		else
			k = next[k];
	}
}

词语变形
bool chkTransform(string A, int lena, string B, int lenb) {
	if(A.empty() || B.emptyl() || lena != lenb)
		return false;
	vector<int> flag(256, 0);
	for(int i=0; i<lena; i++)
		flag[A[i]]++;
	for(int i=0; i<lenb; i++)
		flag[B[i]]--;
	for(int i=0; i<256; i++)
		if(flag[i] != 0)
			return false;
	return true;
}

两串旋转
bool chkRotation(string A, int lena, string B, int lenb) {
	if(A.empty() || B.empty() || lena != lenb)
		return false;
	string s = A + A;
	return KMP(s, B);
}
book KMP(const string& s, const string& strB)
{
	if(s.empty() || strB.empty() || s.size() < strB.size())
		return false;
	int lS = s.size();
	int lB = strB.size();
	vector<int> next(lB, 0);
	getNext(strB, next);
	int i=0, j=0;
	while(i < lS && j < lB)
	{
		if(s[i] == strB[j])
		{
			i++;
			j++;
		}
		else if(next[j] == -1)
			i++;
		else
			j = next[j];
	}
	if(j == lB)
		return true;
	return false;
}
void getNext(const string& match, vector<int>& next)
{
	n = match.size();
	next[0] = -1;
	int i = 0, k = -1;
	while(i < n-1)
	{
		if(k == -1 || match[i] == match[k])
			next[++i] == ++k;
		else
			 k = next[k];
	}
}

句子的逆序
string reverseSentence(string A, int n) {
	if(A.empty())
		return A;
	reverse(A, 0, n-1);
	int last=0, i=0;
	while(i <= n)
	{
		if(A[i] == ' ' || A[i] == '\0')
		{
			reverse(A, last, i-1);
			last = i + 1;
		}	
		i++;
	}
}
void reverse(string& A, int start, int end)
{
	int i=start, j=end;
	while(i < j)
	{
		swap(A[i], A[j]);
		i++;
		j--;
	}
}

字符串移位
string stringTranslation(string A, int n, int len) {
	if(A.empty())
		return A;
	reverse(A, 0, len-1);
	reverse(A, len, n-1);
	reverse(A, 0, n-1);
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

拼接最小字典序
static bool cmp(const string& s1, const string& s2)
{
	string sA = s1 + s2;
	string sB = s2 + s1;
	return sA < sB;
}
string findSmallest(vector<string> strs, int n) {
	if(n < 1)
		return ""
	sort(strs.begin(), strs.end(), cmp);
	string res = "";
	for(int i=0; i<n; i++)
		res += strs[i];
	return res;
}

空格替换
string replaceSpace(string iniString, int length) {
	if(iniString.empty())
		return "";
	int cnt = 0;
	for(int i=0; i<length; i++)
		if(iniString[i] == ' ')
			cnt++;
	int newLength = length + cnt * 2;
	int i = length, j = newLength;
	iniString.resize(newLength);
	while(j > i)
	{
		if(iniString[i] == ' ')
		{
			iniString[j--] = '0';
			iniString[j--] = '2';
			iniString[j--] = '%';
		}
		else
			iniString[j--] = iniString[i]
		i--;
	}
	return iniString;
}

合法括号序列判断
bool chkParenthesis(string A, int n) {
	if(A.empty())
		return true;
	int cnt = 0;
	for(int i=0; i<n; i++)
	{
		if(A[i] == '(')
			cnt++;	
		else
		{
			cnt--;
			if(cnt < 0)
				return false;
		}
	}	
	if(cnt == 0)
		return true;
	return false;
}

最大无重复字符子串
int longestSubstring(string A, int n) {
	if(A.empty())
		return 0;
	int len = 0;
	int cur = 0;
	vector<int> cnt(256, -1);
	int pre = -1;
	for(int i=0; i<n; i++)
	{
		pre = max(pre, cnt[A[i]]);
		cur = i - pre;
		len = max(cur, len);
		cnt[A[i]] = i;
	}
	return len;
}

可查询最值的栈
class Solution {
public:
	stack<int> sData;
	stack<int> sMin;
	void push(int value){
		sData.push(value);
		if(sMin.empty() || sMin.top() >= value)
			sMin.push(value);
		else
			sMin.push(sMin.top());
	}
	void pop()
	{
		sData.pop();
		sMin.pop();
	}
	int top()
	{
		return sData.top();
	}
	int min(){
		return sMin.top();
	}
};

双栈队列
class Solution {
public:
	stack<int> s1;
	stack<int> s2;
	vector<int> twoStack(vector<int> ope, int n) {
		vector<int> res;
		for(int i=0; i<n; i++)
		{
			if(op[i] == 1)
				s1.push(op[i]);
			else
			{
				if(s2.empty())
				{
					while(!s1.empty())
					{
						s2.push(s1.top());
						s1.pop();
					}
				}
				res.push_back(s2.top());
				s2.pop();
			}
		return res;
	}
};

栈的反转
vector<int> reverseStack(vector<int> A, int n) {
	reverse(A);
	return A;
}
int getLast(vector<int>& A)
{
	int res = A.back();
	A.pop_back();
	if(A.size() == 0)
		return res;
	else
	{
		int last = getLast(A);
		A.push_back(result);
		return last;
	}
}
void reverse(vector<int>& A)
{
	if(A.size() == 0)
		return ;
	int last = getLast(A);
	reverse(A);
	A.push_back(last);
}

双栈排序
vector<int> twoStacksSort(vector<int> numbers) {
	if(numbers.empty() || numbers.size() < 2)
		return numbers;	
	stack<int> help;
	int n = numbers.size();
	int cur = numbers.back();
	numbers.pop_back();
	while(numbers.size() < n)
	{
		if(help.empty() || cur < help.top())
			help.push(cur);
		else
		{
			while(help.top() < cur)
			{
				numbers.push_back(help.top());
				help.pop();
			}
			help.push(cur);
		}
		if(help.size() == n)
		{
			while(!help.empty())
			{
				numbers.push_back(help.top());
				help.pop();
			}
		}
		if(numbers.size() == n)
			break;
		cur = number.back();
		number.pop_back();
	}
	return numbers;
}

滑动窗口
vector<int> slide(vector<int> arr, int n, int w) {
	vector<int> res(n-w+1);
	deque<int> dq;
	for(int i=0; i<w; i++)
	{
		if(dq.empty() || arr[dq.back()] >= arr[i])
			dq.push_back(i);
		else
		{
			while(!dq.empty() && arr[dq.back()] <= arr[i])
				dq.pop_back();
			dq.push_back(i);
		}	
	}
	res[0] = arr[dq.front()];
	for(int i=w; i<n; i++)
	{
		if(dq.empty() || arr[dq.back()] >= arr[i])
			dq.push_back(i);
		else
		{
			while(!dq.empty() && arr[dq.back()] <= arr[i])
				dq.pop_back();
			dq.push_back(i);
		}
		if(i - dq.front() >= w)
			dq.pop_front();
		res[i-w+1] = arr[dq.front()];
	}
	return res;	
}

数组变树
vector<int> buildMaxTree(vector<int> A, int n) {
	vector<int> res(n);
	stack<int> left, right;
	vector<int> lMax(n), rMax(n);
	for(int i=0; i<n; i++)
	{
		while(!left.empty() && A[left.top()] <= A[i])
			left.pop();
		if(left.empty())
			lMax[i] = -1;
		else
			lMax[i] = left.top();
		left.push(i);
	}
	for(int i=n-1; i>=0; i--)
	{
		while(!right.empty() && A[right.top()] <= A[i])
			right.pop();
		right.push(i);
		if(right.empty())
			rMax[n-i-1] = -1;
		else
			rMax[n-i-1] = right.top();
		right.push(i);
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
			res[i] = A[lMax[i]] < A[rMax[i]] ? lMax[i] : rMax[i];
	}
	return res;
}

环形链表插值
ListNode* insert(vector<int> A, vector<int> nxt, int val) {
	if(A.empty())
	{
		ListNode* p = new ListNode(val);
		p->next = p;
		return p;
	}	
	ListNode* head = NULL;
	if(A[0] > val)
	{
		ListNode* p = new ListNode(val);
		head = p;
		for(int i=0; i<A.size(); i++)
		{
			ListNode* q = new ListNode(A[i]);
			p->next = q;
			p = q;
		}
		p->next = head;
	}
	else
	{
		ListNode* p = new ListNode(A[0]);
		head = p;
		for(int i=1; i<A.size(); )
		{
			if(A[i] > val)
			{
				ListNode* q = new ListNode(val);
				p->next = q;
				p = q;
			}
			else
			{
				ListNode* q = new ListNode(A[i]);
				p->next = q;
				p = q;
				i++;
			}
		}
		p->next = head;
	}
	return head;
}

访问单个节点的删除
ListNode* removeNode(ListNode* pHead, int delVal) {
	if(pHead == NULL)
		return pHead;
	ListNode* pre = pHead;
	ListNode* p = pHead->next;
	if(pHead->val == delVal)
	{
		delete pre;
		return p;
	}
	while(p && p->val != delval)
	{
		pre = p;
		p = p->next;
	}
	if(p == NULL)
		pre->next = NULL;
	else
		pre->next = p->next;
	delete p;
	return pHead;
}

链表的分化
ListNode* listDivide(ListNode* head, int val) {
	if(head == NULL)
		return new ListNode(val);	
	ListNode* less = NULL;
	ListNode* great = NULL;
	ListNode* lHead = NULL;
	ListNode* gHead = NULL;
	ListNode* p = head;
	while(p)
	{
		if(p->val < val)
		{
			if(lHead == NULL)
			{
				lHead = less = p;
			}
			else
			{
				less->next = p;
				less = p;
			}
		}
		else
		{
			if(gHead == NULL)
			{
				gHead = great = p;
			}
			else
			{
				great->next = p;
				great = p;
			}
		}
		p = p->next;
	}
	if(lHead == NULL)
		return gHead;
	less->next = gHead;
	if(gHead)
		great->next = NULL;
	return lHead;
}

打印两个链表的公共值
vector<int> findCommonParts(ListNode* headA, ListNode* headB) {
	if(headA == NULL || headB == NULL)
		return vector<int>();
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

链表的k逆序
ListNode* inverse(ListNode* head, int k) {
	int len = getLength(head);
	if(k > len || k < 2)
		return head;
	int n = len / k;
	ListNode* newHead = NULL, *tail = NULL;
	ListNode* s = NULL, *e = NULL;
	ListNode* pn = NULL;
	s = e = head;
	for(int i=0; i<n; i++)
	{
		for(int j=1; j<k; j++)
			e = e->next;
		pn = e->next;
		reverse(s, e);
		if(newHead == NULL)
		{
			newHead = s;
			tail = e;
		}
		else
		{
			tail->next = s;
			tail = e;
		}
		s = e = pn;
	}
	tail->next = pn;
	return newHead;
}
int getLength(ListNode* head)
{
	int len = 0;
	ListNode* p = head;
	while(p)
	{
		len++;
		p = p->next;
	}
	return len;
}
void reverse(ListNode*& s, ListNode*& e)
{
	ListNode* pre = NULL;
	ListNode* p = s;
	while(p != e)
	{
		ListNode* pn = p->next;
		p->next = pre;
		pre = p;
		p = pn;
	}
	p->next = pre;
	e = s;
	s = p;
}

链表指定值清除
ListNode* clear(ListNode* head, int val) {
	ListNode* p = head;	
	ListNode* pre = NULL;
	ListNode* newHead = NULL;
	while(p)
	{
		if(p->val != val)
		{
			if(pre == NULL)
			{
				pre = p;
				if(newHead == NULL)
					newHead = pre;
			}
			else
			{
				pre->next = p;
				pre = p;
			}
		}
		p = p->next;
	}
	pre->next = NULL;
	return newHead;
}

链表的回文结构
bool isPalindrome(ListNode* pHead) {
	if(pHead == NULL)
		return false;
	ListNode* slow = pHead;
	ListNode* fast = pHead;
	bool res = true;
	while(fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	if(fast->next == NULL) // 奇数
	{
		ListNode* start = slow;
		ListNode* end = fast;
		reverse(start, end);
		ListNode* p = pHead, *q = start;
		while(p != slow)
		{
			if(p->val != q->val)
			{
				res = false;
				break;
			}
			p = p->next;
			q = q->next;
		}
		reverse(start, end);
	}
	else
	{
		ListNode* start = slow->next;
		ListNode* end = fast->next;
		reverse(start, end);
		ListNode* p = pHead, *q = start;
		while(p != slow->next)
		{
			if(p->val != q->val)
			{
				res = false;
				break;
			}
			p = p->next;
			q = q->next;
		}
		reverse(start, end);
	} 
}
void reverse(ListNode*& head, ListNode*& tail)
{
	ListNode* pre = NULL;
	ListNode* p = head;
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
	head = p;
}

复杂链表的复制
RandomListNode* Clone(RandomListNode* pHead) {
	if(pHead == NULL)
		return pHead;
	cloneNode(pHead);
	copyRandom(pHead);
	return splitRandomList(pHead);
}
void cloneNode(RandomListNode*& pHead)
{
	RandomListNode* p = pHead;
	RandomListNode* pn = NULL;
	while(p)
	{
		pn = p->next;
		RandomListNode* q = new RandomListNode(p->val);
		p->next = q;
		q->next = pn;
		p = pn;
	}
}
void copyRandom(RandomListNode*& pHead)
{
	RandomListNode* pre = pHead;
	RandomListNode* p = NULL;
	while(pre)
	{
		p = pre->next;
		p->random = pre->random->next;
		pre = p->next;
	}
}
RandomListNode* splitRandomList(RandomListNode*& pHead)
{
	RandomListNode* newHead = NULL;
	RandomListNode* p1 = pHead;
	RandomListNode* pre1 = NULL, pre2 = NULL, p2 = NULL, *pn = NULL;
	while(p1)
	{
		p2 = p1->next;
		pn = p2->next;
		if(pre1 == NULL)
		{
			pre1 = p1;
			pre2 = p2;
			newHead = pre2;
		}
		else
		{
			pre1->next = p1;
			pre1 = p1;
			pre2->next = p2;
			pre2 = p2;
		}
		p1 = pn;
	}
	pre1->next = NULL;
	return newHead;
}

链表判环
int chkLoop(ListNode* head, int adjust) {
	if(head == NULL)
		return -1;
	ListNode* slow = head;
	ListNode* fast = head;
	while(fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			break;
	}
	if(fast == NULL || fast->next == NULL)
		return -1;
	fast = head;
	while(fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}	
	return slow->val;
}

无环单链表判相交
bool chkIntersect(ListNode* headA, ListNode* headB) {
	if(headA == NULL || headB == NULL)
		return false;
	ListNode* pA = headA;
	while(pA->next)
		pA = pA->next;	
	ListNode* pB = headB;
	while(pB->next)
		pB = pB->next;
	if(pA == pB)
		return true;
	return false;
}

有环单链表相交判断
bool chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1) {
	ListNode* e1 = getEntryPoint(head1);
	ListNode* e2 = getEntryPoint(head2);
	if(e1 == NULL || e2 == NULL)
		return false;
	if(e1 == e2)
		return true;
	ListNode* p = e1->next;
	while(p != e1)
	{
		if(p == e2)
			return true;
		p = p->next;	
	}	
	return false;
}
ListNode* getEntryPoint(ListNode* head)
{
	if(head == NULL)
		return NULL;
	ListNode* slow = head;
	ListNode* fast = head;
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
		while(fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
	return NULL;
}

单链表相交判断(有换+无环)
bool chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1) {
	if(head1 == NULL || head2 == NULL)
		return false;
	ListNode* e1 = getEntryPoint(head1)
	ListNode* e2 = getEntryPoint(head2);
	if(e1 == NULL && e2 == NULL)
	{
		return chkInterNoLoop(head1, head2);
	}
	else if(e1 == NULL)
		return false;
	else if(e2 == NULL)
		return false;
	else
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
		return false;
	}
}
ListNode* getEntryPoint(ListNode* head)
{
	if(head == NULL)
		return NULL;
	ListNode* slow = head;
	ListNode* fast = head;
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
		while(fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
	}
	return NULL;
}
bool chkInterNoLoop(ListNode* head1, ListNode* head2)
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

局部最小值位置
int getLessIndex(vector<int> arr) {
	int n = arr.size();
	if(n < 1)
		return -1;
	if(n == 1 || arr[0] < arr[1])
		return 0;
	if(arr[n-1] < arr[n-2])
		return n-1;
	int i = 1, j = n-2;
	while(i < j)
	{
		int mid = (i + j) / 2;
		if(arr[mid] > arr[mid-1])
			j = mid - 1;
		else if(arr[mid] > arr[mid+1])
			i = mid + 1;  	
		else
			return mid;
	}	
	return i;
}

元素最左出现
int findPos(vector<int> arr, int n, int num) {
	if(n < 1)
		return -1;
	int i = 0, j = n-1;
	int res = -1;
	while(i <= j)
	{
		int mid = (i + j)/2;
		if(a[mid] > num)
			j = mid - 1;
		else if(a[mid] == num)
		{
			res = mid;
			j = mid - 1;
		}	
		else
			i = mid + 1;
	}	
	return res;
}

循环有序数组最小值
int getMin(vector<int> arr, int n) {
	if(n < 1)
		return -1;
	if(n == 1 || a[0] < arr[n-1])
		return arr[0];
	int left = 0, right = n-1;
	int res = arr[0];
	while(arr[left] >= arr[right])
	{
		if(right - left == 1)
		{
			res = arr[right];
			break;		
		}
		int mid = (left + right) / 2;
		if(arr[left] == arr[mid] && arr[mid] == arr[right])
		{
			while(left <= right)
			{
				if(arr[left] < res)
					res = arr[left];
				left++;	
			}
		}
		if(arr[left] > arr[mid])
			right = mid;
		else if(arr[mid] > arr[right])
			left = mid;
	}
	return res;
}

最左原位
int findPos(vector<int> arr, int n) {
	if(n < 1 || arr[0] > n-1 || arr[n-1] < 0)
		return -1;
	int res = -1;
	int left = 0, right = n-1;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if(arr[mid] == mid)
		{
			res = mid;
			right = mid - 1;
		}	
		else if(arr[mid] < mid)
			left = mid + 1;
		else
			right = mid - 1;
	} 
	return res;
}

完全二叉树计数
int count(TreeNode* root) {
	if(root == NULL)
		return 0;
	int leftDeep = getDepth(root->left);
	int rightDeep = getDepth(root->right);
	if(leftDeep == rightDeep)
		return 1 << leftDeep + count(root->right);
	return count(root->left) + 1 << rightDeep;	
}
int getDepth(TreeNode* root)
{
	if(root == NULL)
		return 0;
	TreeNode* p = root;
	int deep = 0;
	while(p)
	{
		deep++;
		p = p->left;
	}
	return deep;
}

快速N次方
int getPower(int k, int N) {
	long res = 1;
	if(N == 0)
		return 1;
	long prod = k;
	while(N)
	{
		if(N % 1)
			res *= prod;
		res = res % 1000000007;
		N = N / 2;
		prod = prod * prod % 1000000007;
	}	
	return res % 1000000007;
}

二叉树按层打印
vector<vector<int> > printTree(TreeNode* root) {
	vector<vector<int> > res;
	if(root == NULL)
		return res;
	queue<TreeNode*> q;
	q.push(root);
	TreeNode* last = root;
	TreeNode* nlast = NULL;
	vector<int> level;
	while(!q.empty())
	{
		TreeNode* p = q.front();
		q.pop();
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
		level.push_back(nlast->val);
		if(p == last)
		{
			res.push_back(level);
			level.clear();
			last = nlast;
		}
	}
	return res;
}

二叉树的序列化
string toString(TreeNode* root) {
	if(root == NULL)
		return "#!";
	string res = to_string(root->val) + "!";
	res += to_string(root->left);
	res += to_string(root->right);
	return res;	
}

平衡二叉树判断
bool check(TreeNode* root) {
	int depth = 0;
	return checkBalance(root, depth);		
}
bool checkBalance(TreeNode* root, int& depth)
{
	if(root == NULL)
		return true;
	int lDepth = 0, rDepth = 0;
	bool left = checkBalance(root->left, lDepth);
	if(!left)
		return false;
	bool right = checkBalance(root->right, rDepth);
	if(!right)
		return false;
	depth = 1 + max(lDepth, rDepth);
	if(abs(lDepth - rDepth) <= 1)
		return true;
	return false;
}


完全二叉树判断
bool chk(TreeNode* root) {
	bool isLeaf = false;
	if(root == NULL)
		return true;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty())
	{
		TreeNode* p = q.front();
		q.pop();
		if(p->left == NULL && p->right)
			return false;
		if(!isLeaf)
		{
			if(p->right == NULL)
				isLeaf = true;
		}
		else
		{
			if(p->left || p->right)
				return false;
		}	
		if(p->left)
			q.push(p->left);
		if(p->right)
			q.push(p->right);
	}
	return true;
}

折纸问题
vector<string> foldPaper(int n) {
	vector<string> res;
	foldPaperCore(1, n, "down", res);
	return res;
}
void foldPaperCore(int k, int n, string s, vector<string>& res)
{
	if(k > n)
		return;
	foldPaper(k+1, n, "down", res);
	res.push_back(s);
	foldPaper(k+1, n, 'up', res);
}

寻找错误结点
vector<int> findError(TreeNode* root) {
	vector<int> res;
	if(root == NULL)
		return res;
	vector<int> nodes;
	getInOrder(root, nodes);
	bool isFirst = false;
	for(int i=1; i<nodes.size(); i++)
	{
		if(nodes[i] < nodes[i-1])
		{
			res.push_back(nodes[i]);
			isFirst = true;
		}
		if(isFirst)
		{
			if(nodes[i] < nodes[i-1])
			{
				res.push_back(nodes[i]);
				break;
			}	
		}
	}
	swap(res[0], res[1]);
	return res;
}
void getInOrder(TreeNode* root, vector<int>& nodes)
{
	if(root == NULL)
		return;
	getInOrder(root->left, nodes);
	nodes.push_back(nodes->val);
	getInOrder(root->right, nodes);
}

树上最远距离
int findLongest(TreeNode* root) {
	int deep = 0;
	return getLongest(root, deep);
}
int getLongest(TreeNode* root, int& deep)
{
	if(root == NULL)
		return 0;
	int lDepth = 0;
	int lDist = getLongest(root->left, lDepth);
	int rDepth = 0;
	int rDist = getLongest(root->right, rDepth);
	deep = 1 + max(lDepth, rDepth);
	return max(max(lDist, rDist), lDepth + rDepth + 1);
}

最大二叉搜索子树
TreeNode* getMax(TreeNode* root) {
	int count = 0, Max = INT_MIN, Min = INT_MAX;
	return getMaxTree(root, count, Max, Min);
}
TreeNode* getMaxTree(TreeNode* root, int& count, int& Max, int& Min)
{
	if(root == NULL)
		return NULL;
	int lcnt = 0, lmax = INT_MIN, lmin = INT_MAX;
	TreeNode* lRoot = getMaxTree(root->left, lcnt, lmax, lmin);
	int rcnt = 0, rmax=INT_MIN, rmin = INT_MAX;
	TreeNode* rRoot = getMaxTree(root->right, rcnt, rmax, rmin);
	TreeNode* res = NULL;
	Max = max(root->val, rmax);
	Min = min(lmin, root->val);
	if(lRoot == root->left && rRoot == root->right && lmax < root->val && root->val < rmin)
	{
		res = root;
		count = lcnt + 1 + rcnt;
	}
	else if(lcnt > rcnt)
	{
		res = lRoot;
		count = lcnt;
	}
	else
	{
		res = rRoot;
		count = rcnt;
	}
	return res;
}

交换练习
vector<int> getSwap(vector<int> num) {
	if(num.empty())
		return num;
	num[0] = num[0] ^ num[1];
	num[1] = num[0] ^ num[1];
	num[0] = num[0] ^ num[1];		
	return num;
}

比较练习
int getMax(int a, int b) {
	int c = a - b;
	int as = sign(a);
	int bs = sign(b);
	int cs = sign(c);
	int difab = as ^ bs;
	int sameab = flip(difab);
	int returnA = difab * as + sameab * cs;
	int	returnB = flip(returnA);
	return a * returnA + b * returnB;
} 
int sign(int n)
{
	return flip((n >> 31) & 1);
}
int flip(int a)
{
	return a ^ 1;
}

寻找奇数次出现
int findOdd(vector<int> A, int n) {
	int res = 0;
	for(int i=0; i<n; i++)
		res ^= A[i];
	return res;	
}

寻找奇数次出现的II
vector<int> findOdds(vector<int> arr, int n) {
	vector<int> res;
	res.reserve(2);
	int orV = 0;
	for(int i=0; i<n; i++)
		orV ^= arr[i];
	int k = findFirst(orV);
	int tmp = 0;
	for(int i=0; i<n; i++)
	{
		if(isOne(arr[i], k))
			tmp ^= arr[i];	
	}		
	res.push_back(tmp);
	res.push_back(tmp ^ orV);
	if(res[0] > res[1])
		swap(res[0], res[1]);
	return res;
}
int findFirst(int n)
{
	int i = 0;
	while(n)
	{
		if((n & 1) == 1)
			return i;
		n >>= 1;
		i++;
	}
	return -1;
}
bool isOne(n, k)
{
	n = n >> k;
	return (n & 1);
}

方格移动
int countWays(int x, int y) {
	int res = 1;
	--x;
	--y;
	int i = x + y;
	for(; i>y; i--)
		res *= i;
	for(i=x; i>0; i--)
		res /= i;
	return res;
}

站队问题
vector<int> getWays(int n, int a, int b) {
	vector<int> res(2);
	res[0] = 1;
	for(int i=1; i<=n; i++)
		res[0] *= i;
	res[0] /= 2;
	
	--n;
	res[1] = 1;
	for(int i=1; i<=n; i++)
		res[1] *= i;
	return res;
}

孤傲的A
int getWays(int n, int A, int b, int c) {
	return 2 * (n-3) * permutation(n-2, n-2) + (n-2) * permutation(n-3, 2) * permutation(n-3, n-3);	
}
int permutation(int n, int m)
{
	int res = 1;
	for(int i=n; i>n-m; i--)
		res *= i;
	return res;
}

分糖果
int getWays(int n, int m) {
	--n;
	--m;
	int res = 1;
	int i = n;
	for(; i>n-m; i--)
		res *= i;
	for(i=m; i>0; i--)
		res /= i;
	return res;	
}

括号序列
int countLegalWays(int n) { // C(n, 2n)* 1/(n+1)
	int res = 1;
	int i = 2*n;
	for(; i>n; i--)
		res *= i;
	for(i=n; i>0; i--)
		res /= i;
	res /= (n+1);
	return res;
}

进出栈
int countWays(int n) {
	int res = 1;
	int i = 2*n;
	for(; i>n; i--)
		res *= i;
	for(i=n; i>0; i--)
		res /= i;
	res /= (n+1);
	return res;	
}

排队买票
int countWays(int n) {
	int res = 1;
	int i = 2*n; 
	for(; i>n; i--)
		res *= i;
	for(i=n; i>0; i--)
		res /= i;
	res /= (n+1);
	return res;	
}

二叉树统计
int countWays(int n) {
	int res = 1;
	int i = 2*n; 
	for(; i>n; i--)
		res *= i;
	for(i=n; i>0; i--)
		res /= i;
	res /= (n+1);
	return res;	
}

高矮排列
int countWays(int n) {
	int res = 1;
	int i = 2*n;
	for(; i>n; i--)
		res *= i;
	for(i=n; i>0; i--)
		res /= i;
	res /= (n+1);
	return res;	
}

错误信封
int countWays(int n) {
	if(n <= 1)
		return 0;
	else if(n == 2)
		return 1;
	else
	{
		long long last = 0, res = 1;
		for(int i=3; i<=n; i++)
		{
			int tmp = (i - 1) * (last + res) % 1000000007;
			last = res;
			res = tmp;	
		}	
		return res % 1000000007;
	}	
}

足球比赛
vector<int> calc(int k) {
	vector<int> res(2, 1);
	for(int i=k; i>0; i--)
		res[1] *= (2 * i - 1);
	for(int i=k+1; i>2; i--)
		res[0] *= i;
	res[0] = res[1] - res[0];
	int com = gcd(res[1], res[0]);
	res[0] /= com;
	res[1] /= com;
	return res;	
}
int gcd(int a, int b)
{
	if(a < b)
		swap(a, b);
	while(b)
	{
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

蚂蚁碰头
vector<int> collision(int n) {
	vector<int> res(2);
	res[1] = 1 << n;//pow(2, n);	
	res[0] = res[1] - 2;
	int com = gcd(res[1], res[0]);
	res[0] /= com;
	res[1] /= com;
	return res;
}
int gcd(int a, int b)
{
	if(a < b)
		swap(a, b);
	while(b)
	{
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

随机函数
// 以下内容请不要修改
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
		int res = 5 * (rand5() - 1) + rand5() - 1;
		while(res > 20)
			res = 5 * (rand5() - 1) + rand5() - 1;
		return res % 7 + 1;
	}
};

随机01
class RandomP {
public:
	static int f();
};

class Random01 {
public:
    // 用RandomP::f()实现等概率的01返回
    int random01() {
    	int a = RandomP::f();
    	int b = RandomP::f();
    	while((a ^ b) == 0)
    	{
    		a = RandomP::f();
    	    b = RandomP::f();
		}
		if(a == 0)
			return 0;
		return 1;
    }
};

随机区间
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

随机数组
vector<int> print(vector<int> arr, int N, int M) {
	vector<int> res;
	if(N < M)
		return res;
	while(M > 0)
	{
		int i = rand() % N;
		res.push_back(arr[i]);
		--N;
		swap(arr[i], arr[N]);
		--M;
	}
	return res;
}

机器吐球
class Bag {
public:
	vector<int> ret;
    // 每次拿一个球都会调用这个函数，N表示第i次调用
    vector<int> carryBalls(int N, int k) {
    	if(ret.size() < k)
    		ret.push_back(N);
    	else
    	{
    		int id = rand() % k;
    		ret[id] = N;
		}
		return ret;
    }
};

找零钱
int countWays(vector<int> penny, int n, int aim) {
	if(n <= 0 || aim < 0)
		return 0;
	vector<vector<int> > dp(n, vector<int>(aim+1, 0));
	for(int j=penny[0]; j<=aim; j+=penny[0])
		dp[0][j] = 1;
	for(int i=0; i<n; i++)
		dp[i][0] = 1;
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<=aim; j++)
		{
			if(j - penny[i] >= 0)
				dp[i][j] = dp[i-1][j] + dp[i][j-penny[i]];
			else
				dp[i][j] = dp[i-1][j];	
		}	
	}		
	return dp[n-1][aim];
}

台阶问题
int countWays(int n) {
	if(n == 1)
		return 1;
	else if(n == 2)
		return 2;
	int a = 1, b = 2;
	int tmp;
	for(int i=3; i<=n; i++)
	{
		tmp = (a + b) % 1000000007;
		a = b;
		b = tmp;
	}	
	return b % 1000000007;
}

矩阵最小路径
int getMin(vector<vector<int> > map, int n, int m) {
	vector<vector<int> > dp(n, vector<int>(m, 0));
	dp[0][0] = map[0][0];
	for(int i=1; i<n; i++)
		dp[i][0] = dp[i-1][0] + map[i][0];
	for(int j=1; j<m; j++)
		dp[0][j] = dp[0][j-1] + map[0][j];	
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<m; j++)
		{
			dp[i][j] = map[i][j] + min(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n-1][m-1];
}

LIS最长递增子序列
int getLIS(vector<int> A, int n) {
	vector<int> dp(n, 1);
	int maxL = 1;
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<i; j++)
			if(A[j] < A[i])
				dp[i] = max(dp[i], dp[j] + 1);
		maxL = max(maxL, dp[i]);	
	}
	return maxL;
}

LCS最长公共子序列
int findLCS(string A, int n, string B, int m) {
	if(n <= 0 || m <= 0)
		return 0;
	vector<vector<int> > dp(n, vector<int>(m, 0));
	if(A[0] == B[0])  
		dp[0][0] = 1;
	
	for(int i=1; i<n; i++)
		if(dp[i-1][0] == 1 || A[i] == B[0])	
			dp[i][0] = 1;
	for(int j=1; j<m; j++)
		if(dp[0][j-1] == 1 || A[0] == B[j])
			dp[0][j] = 1;
	
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

01背包
int maxValue(vector<int> w, vector<int> v, int n, int cap) {
	vector<vector<int> > dp(n, vector<int>(cap+1, 0));
	for(int j=w[0]; j<=cap; j++)
		dp[0][j] = v[0];
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<=cap; j++)
		{
			if(j - w[i] >= 0)
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n-1][cap];
} 
   /* 空间压缩技巧 */
    vector<int> dp(cap+1, 0);
    for(int i=w[0]; i<=cap; i++)
	    dp[i] = v[0];
	for(int i=1; i<n; i++)
	{
		for(int j=cap; j>=w[i]; j--)
		{
			//if(j - w[i] >= 0)
			dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
		}
	}
	return dp[cap];
	

最优编辑代价
int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
	vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
	for(int i=1; i<=n; i++)
	{
		dp[i][0] = i * c1;
	}	
	for(int j=1; j<=m; j++)
	{
		dp[0][j] = j * c0;
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			dp[i][j] = min(dp[i-1][j]+c1, dp[i][j-1]+c0);
			if(A[i] == B[j])
				dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
			else
				dp[i][j] = min(dp[i][j], dp[i-1][j-1]+c2);
		}
	}
	return dp[n][m];
}
