#include <bits/stdc++.h>

class kdt
{
private:
    vector<int> data;
    int k;

    kdt *left, *right;

public:
    kdt(int d) { this->k = d; }
    kdt(vector<int> &arr) : data(arr), left(nullptr), right(nullptr)
    {
        if (data.size() != k)

            cout << "Error: Data dimension does not match the specified dimension k = " << k << endl;
    }

    kdt *insert(kdt *root, vector<int> arr, int depth)
    {
        if (!root)
            return new kdt(arr);

        if (arr[depth % k] < root->data[depth % k])
            root->left = insert(root->left, arr, depth + 1);
        else
            root->right = insert(root->right, arr, depth + 1);
        return root;
    }
    double distance_parameter(vector<int> p1, vector<int> p2)
    {
        double interspace = 0;
        for (int i = 0; i < p1.size(); i++)
            interspace += (p1[i] - p2[i]) * (p1[i] - p2[i]);

        return sqrt(interspace);
    }

    kdt *search(kdt *root, vector<int> arr, int depth)
    {
        if (!root)
            return root;

        if (root->data[depth % k] == arr[depth % k])
        {
            int flag = 1;

            for (int i = 0; i < arr.size(); i++)
            {
                if (root->data[i] != arr[i])
                {
                    flag = 0;
                    break;
                }
                else
                    continue;
            }

            if (flag)
                return root;
        }
        if (root->data[(depth + 1) % k] > arr[(depth + 1) % k])
            return search(root->left, arr, depth + 1);
        return search(root->right, arr, depth + 1);
    }

    void func(kdt *x, vector<int> source, int d, int K, vector<double> &k_distances, vector<kdt *> &k_nearest)
    {
        double dist_x = distance_parameter(x->data, source);

        for (int i = 0; i < K; i++)
        {
            if (dist_x < k_distances[i])
            {
                for (int j = K - 1; j > i; j--)
                {
                    k_distances[j] = k_distances[j - 1];
                    k_nearest[j] = k_nearest[j - 1];
                }

                k_distances[i] = dist_x;
                k_nearest[i] = x;
                break;
            }
        }
    }

    void k_nearest(kdt *root, vector<int> &source, int d, int K, int *num_neighbours, vector<double> &k_distances, vector<kdt *> &k_nearest)
    {

        if (!root)
            return;

        kdt *nextbranch = nullptr, *otherbranch = nullptr;
        if (source[d % k] < root->data[d % k])
            nextbranch = root->left,
            otherbranch = root->right;
        else
            nextbranch = root->right,
            otherbranch = root->left;

        k_nearest(nextbranch, source, d + 1, K, num_neighbours, k_distances, k_nearest);
    }
};

using namespace std;
int main()
{

    return 0;
}