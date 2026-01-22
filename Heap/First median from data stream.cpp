class MedianFinder {
public:
    priority_queue<int> pqL;                            // Max heap
    priority_queue<int, vector<int>, greater<int>> pqR; // min heap
    MedianFinder() {}

    void addNum(int num) { // O(log n)
        pqL.push(num);

        if (!pqR.empty() && pqL.top() > pqR.top()) { // if left top is greater than right top
            pqR.push(pqL.top());
            pqL.pop();
        }

        if (pqL.size() > pqR.size()+1) { // if the difference in the size is more than 1
            pqR.push(pqL.top());
            pqL.pop();
        } else if (pqR.size() > pqL.size() + 1) { // if the difference in the size is more than 1
            pqL.push(pqR.top());
            pqR.pop();
        }
    }

    double findMedian() { // O(1)
        int Size = pqL.size() + pqR.size();

        if ((Size & 1) != 0) { // if odd
            if (pqL.size() > pqR.size())
                return pqL.top();
            else if (pqL.size() < pqR.size())
                return pqR.top();
        }

        return (pqL.top() + pqR.top()) / 2.0; // if even
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
