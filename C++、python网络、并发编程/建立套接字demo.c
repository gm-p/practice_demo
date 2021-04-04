#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int sockfd;
    struct sockaddr_in mysock;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&mysock, sizeof(mysock));
    mysock.sin_family = AF_INET;
    mysock.sin_port = htons(800);
    mysock.sin_addr.s_addr = inet_addr("192.168.1.0");

    bind(sockfd, (struct sockaddr*)&mysock, sizeof(struct sockaddr));
    return 0;
}

int GetLargestN(const vector<int>& data, int k)
{
    int n = data.size();
    if(n == 0 || n < k || k <= 0)
        return -1;
    multiset<int, less<int>> heap;
    for(int i=0; i<n; i++)
    {
        if(i < k)
            heap.insert(data[i]);
        else
        {
            multiset<int, less<int>>::const_iterator it = heap.begin();
            if(*it < data[i])
            {
                heap.erase(it);
                heap.insert(data[i]);
            }
        }
    }
    return *heap.begin();
}