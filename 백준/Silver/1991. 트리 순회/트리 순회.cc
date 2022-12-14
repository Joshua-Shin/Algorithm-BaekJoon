#include <iostream>
using namespace std;
struct Node
{
    int left;
    int right;
};
Node a['Z'];

void preorder(int n)
{
    if(n==-1)
        return;
    cout << (char)(n + 'A');
    preorder(a[n].left);
    preorder(a[n].right);
}
void inorder(int n)
{
    if(n==-1)
        return;
    inorder(a[n].left);
    cout << (char)(n + 'A');
    inorder(a[n].right);
}
void postorder(int n)
{
    if(n==-1)
        return;
    postorder(a[n].left);
    postorder(a[n].right);
    cout << (char)(n + 'A');
}
int main()
{
    int n;
    cin >> n;
    for(int i =0; i<n; i++)
    {
        char x, y, z;
        cin >> x >> y >> z;
        if(y!='.')
            a[x-'A'].left = y - 'A';
        else
            a[x-'A'].left = -1;

        if(z!='.')
            a[x-'A'].right = z - 'A';
        else
            a[x-'A'].right = -1;
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';
    return 0;
}