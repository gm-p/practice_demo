#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <iterator>
#include <string>
using namespace std;

#define Nchar 8
#define Nsymbols 1<<Nchar

typedef vector<bool> Huff_code;
map<char, Huff_code> Huff_dic;

class Hnode
{
public:
	char data;
	float fre;
	Hnode *left, *right;
	
	Hnode()
	{
		data='\0';
		fre=0;
		left=NULL;
		right=NULL;
	}
	Hnode(char c, float f, Hnode* l, Hnode* r)
	{
		data=c;
		fre=f;
		left=l;
		right=r;
	}		
	~Hnode()
	{
		delete left;
		delete right;
	}
	bool isLeaf()
	{
		return !left&&!right;
	}
};

class compare_node
{
public:
	bool operator()(Hnode* n1, Hnode* n2)
	{
		return n1->fre > n2->fre;
	}
};

Hnode* buildHtree(int* frequency)
{
	priority_queue<Hnode*, vector<Hnode*>, compare_node> Qtree;
	for(int i=0; i<Nsymbols; i++)
		if(frequency[i])
			Qtree.push(new Hnode((char)i, frequency[i], NULL, NULL));
	while(Qtree.size() > 1)
	{
		//���϶���Hnode*
		Hnode* lc = Qtree.top();
		Qtree.pop();
		Hnode* rc = Qtree.top();
		Qtree.pop();
		Hnode* parents = new Hnode((char)256, lc->fre + rc->fre, lc, rc);
		Qtree.push(parents);  //���һ���ǰѸ��ڵ�push��Qtree�� 
	}
	return Qtree.top();   //��󷵻ص���Huffman���ĸ��ڵ� 
}

void Huffman_coding(Hnode* root, Huff_code& curcode) 
{
	if(root->isLeaf()) 
	{
		Huff_dic[root->data] = curcode;
		return ; 
	} 
	Huff_code lcode = curcode;   //�������ӵı���
	Huff_code rcode = curcode;   //�����Һ��ӵı���
	lcode.push_back(false);
	rcode.push_back(true);
	Huffman_coding(root->left, lcode);
	Huffman_coding(root->right, rcode); 
}

int main()
{
	int freq[Nsymbols] = {0};
	char* c = "compress this is the string into Huffman code";
	while(*c != '\0')
		freq[*c++]++;
	Hnode* root = buildHtree(freq);
	Huff_code nullcode;
	nullcode.clear();
	Huffman_coding(root, nullcode);
	for(map<char, Huff_code>::iterator it=Huff_dic.begin(); it != Huff_dic.end(); it++)
	{
		cout<<(*it).first<<'\t';
		copy(it->second.begin(), it->second.end(), ostream_iterator<bool>(cout));
		cout<<endl; 
	} 
	return 0;
} 
