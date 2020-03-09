//
// Created by 29546 on 2020/2/29.
//
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
class LinkList{
    struct ListNode{
        int val;
        ListNode* next;
        explicit ListNode(int x) : val(x), next(nullptr) {}
    };
    struct DoubleLinkNode{
        int val;
        DoubleLinkNode  *pre, *next;
        explicit DoubleLinkNode(int x) : val(x), pre(nullptr), next(nullptr) {}
    };
    struct DoubleLinkNodeWithFrequency{
        int val, freq = 0;
        DoubleLinkNodeWithFrequency  *pre, *next;
        explicit DoubleLinkNodeWithFrequency(int x) : val(x), pre(nullptr), next(nullptr), freq(0) {}
    };

/**
 * β�巨����������
 * @param pointWords
 * @return
 */
public:
    ListNode * CreateLinkList(const string& pointWords){
        cout << pointWords << endl;
        string s;
        string yes = "y";
        cin>>s;
        auto * list = new ListNode(-1);
        if(strcasecmp(s.c_str(), yes.c_str()) != 0)
            return list;
        cout << "������ڵ������";
        ListNode * rear = list;
        int len;
        cin >> len;
        cout << "������������������"<< len <<"���ڵ�ֵ: ";
        while(len--){
            int x;
            cin>>x;
            rear->next = new ListNode(x);
            rear = rear->next;
        }
        return list;
    }

/**
 * ����ѭ��������
 * @param pointWords
 * @return
 */
public:
    ListNode * CreateCirculationLinkList(const string& pointWords){
        cout << pointWords << endl;
        string s;
        string yes = "y";
        cin>>s;
        auto * list = new ListNode(-1);
        if(strcasecmp(s.c_str(), yes.c_str()) != 0)
            return list;
        cout << "������ڵ������";
        ListNode * rear = list;
        int len;
        cin >> len;
        cout << "������������������"<< len <<"���ڵ�ֵ: ";
        while(len--){
            int x;
            cin>>x;
            rear->next = new ListNode(x);
            rear = rear->next;
        }
        rear->next = list;
        return list;
    }

/**
 * β�巨����˫����
 * @param pointWords
 * @return
 */
public:
    DoubleLinkNodeWithFrequency * CreateDoubleLinkListWithFrequency(const string& pointWords){
        cout << pointWords << endl;
        string s;
        string yes = "y";
        cin>>s;
        auto * list = new DoubleLinkNodeWithFrequency(-1);
        list->next = nullptr;
        list->pre = nullptr;
        if(strcasecmp(s.c_str(), yes.c_str()) != 0)
            return list;
        cout << "������ڵ������";
        DoubleLinkNodeWithFrequency *rear = list;
        int len;
        cin >> len;
        cout << "������������������"<< len <<"���ڵ�ֵ: ";
        while(len--){
            int x;
            cin>>x;
            auto *node = new DoubleLinkNodeWithFrequency(x);
            node->next = rear->next;
            rear->next = node;
            node->pre = rear;
            rear = node;
        }
        return list;
    }

/**
 * β�巨����˫����
 * @param pointWords
 * @return
 */
public:
    DoubleLinkNode * CreateDoubleCirculationLinkList(const string& pointWords){
        cout << pointWords << endl;
        string s;
        string yes = "y";
        cin>>s;
        auto * list = new DoubleLinkNode(-1);
        list->next = list;
        list->pre = list;
        if(strcasecmp(s.c_str(), yes.c_str()) != 0)
            return list;
        cout << "������ڵ������";
        DoubleLinkNode *rear = list;
        int len;
        cin >> len;
        cout << "������������������"<< len <<"���ڵ�ֵ: ";
        while(len--){
            int x;
            cin>>x;
            auto *node = new DoubleLinkNode(x);
            node->next = rear->next;
            rear->next = node;
            node->pre = rear;
            rear = node;
            list->pre = rear;
        }
        return list;
    }

/**
 * ѭ����ӡ������Ƶ�ʵ�˫����
 */
public:
    void PrintDoubleLinkListWithFrequency(DoubleLinkNodeWithFrequency *L){
        cout << "{ adress: " << L << ", val: " << L->val << ", freq: " << L->freq <<
             ", pre: " << L->pre << ", next: " << L->next << " }" << endl;
        while(L->next != nullptr){
            L = L->next;
            cout << "{ adress: " << L << ", val: " << L->val << ", freq: " << L->freq <<
            ", pre: " << L->pre << ", next: " << L->next << " }" << endl;
        }
    }

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        int cnt = 0;
        auto* r=new ListNode(-1);
        ListNode *p = l1, *q = l2, *f = nullptr;
        if(!l1->val && !l2->val){
            return f;
        }else if(!l1->val){
            return l2;
        }else if(!l2->val){
            return l1;
        }
        while(p!=nullptr || q!= nullptr){
            cnt++;
            if( cnt == 1 ){
                if(p->val <= q->val){
                    f = new ListNode(p->val);
                    r->next = f;
                    if(p->next != nullptr) {
                        p = p->next;
                    }else{
                        while(q!= nullptr){
                            auto *node = new ListNode(q->val);
                            r->next->next = node;
                            r->next = node;
                            q = q->next;
                        }
                        break;
                    }
                }else{
                    f = new ListNode(q->val);
                    r->next = f;
                    if(q->next != nullptr){
                        q = q->next;
                    }else{
                        while(p!= nullptr){
                            auto *node = new ListNode(p->val);
                            r->next->next = node;
                            r->next = node;
                            p = p->next;
                        }
                        break;
                    }
                }
            } else{
                if(p->val <= q->val){
                    auto *node = new ListNode(p->val);
                    r->next->next = node;
                    r->next = node;
                    if(p->next != nullptr) {
                        p = p->next;
                    }else{
                        while(q!= nullptr){
                            node= new ListNode(q->val);
                            r->next->next = node;
                            r->next = node;
                            q = q->next;
                        }
                        break;
                    }
                } else{
                    auto *node = new ListNode(q->val);
                    r->next->next = node;
                    r->next = node;
                    if(q->next != nullptr){
                        q = q->next;
                    }else{
                        while(p!= nullptr){
                            node = new ListNode(p->val);
                            r->next->next = node;
                            r->next = node;
                            p = p->next;
                        }
                        break;
                    }
                }
            }
        }
        return f;
    }

/**
 * ��ͷ��㵥����͵�����
 * ����P37 �ۺ���5
 * @param L
 */
public:
    void ReversLink(ListNode *L){
        if(L->next==nullptr){
            cout << "Linklist is Empty";
            return;
        }
        ListNode *pre = L->next;
        if(pre->next==nullptr){
            cout << pre->val << endl;
            return;
        }
        ListNode *p = pre->next;
        pre->next = nullptr;
        ListNode *r = p->next;
        do{
            p->next = pre;
            if(r == nullptr)
                break;
            else{
                pre = p;
                p = r;
                r = r->next;
            }
        }while(p != nullptr);
        L->next = p;
        while(p!=nullptr){
            cout << p->val << " ";
            p = p->next;
        }
    }

/**
 * ��������������
 * ����P37 �ۺ���6
 * @return
 */
public:
    void LinkListForwardSort(ListNode *L){
        auto *NL = new ListNode(-1);
        ListNode *p = L->next;
        cout << "ԭʼ���� ";
        while(p != nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        p = L->next;
        cout << endl;
        while(p != nullptr){
            ListNode *pre = NL;
            ListNode *q = NL->next;
            do{
                if(q == nullptr){
                    q = new ListNode(L->next->val);
                    NL->next = q;
                    p = p->next;
                } else{
                    if(p->val <= q->val){
                        auto *r = new ListNode(p->val);
                        r->next = pre->next;
                        pre->next = r;
                        break;
                    } else{
                        pre  = q;
                        q = q->next;
                        if(q == nullptr){
                            pre->next = new ListNode(p->val);
                            break;
                        }
                    }
                }
            }while(NL->next != nullptr);
            p = p->next;
        }
        p = NL->next;
        cout << "�������������� ";
        while(p!=nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        cout << endl;
    }

/**
 * ɾ����ֵ����X��Y֮��Ľڵ�
 * ����P37 �ۺ���7
 * @param L
 * @param x
 * @param y
 */
public:
    void DeleteNodeBtweenXandY(ListNode *L){
        int x, y;
        cout << "��������ҷ�Χ�Ͻ�X ";
        cin >> x;
        cout << "��������ҷ�Χ�½�Y ";
        cin >> y;
        if(L->next==nullptr)
            return;
        ListNode *p = L->next;
        cout << "ԭʼ���� ";
        while(p!=nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        cout << endl;
        ListNode *pre = L;
        p = L->next;
        while(p != nullptr){
            while(x < p->val && y > p->val && p->next != nullptr)
                p = p->next;
            pre->next = p;
            pre = p;
            p = p->next;
            if(p == nullptr)
                break;
        }
        p = L->next;
        cout << "ɾ��������" << x << "��" << y << "֮��Ԫ�غ������ ";
        while(p != nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        cout << endl;
    }

/**
 * �ҵ���������ĵ�һ�������ڵ�
 * ����P37 �ۺ���8
 * @return
 */
public:
    void FindFirstCommonNode(ListNode *L1, ListNode *L2){
        ListNode *p1 = L1->next;
        ListNode *p2 = L2->next;
        int length1 = 0, length2 = 0;
        if(p1 == nullptr || p2 == nullptr){
            cout << "There is a Empty Link..." << endl;
            return;
        }
        while(p1 != nullptr || p2 != nullptr){
            if(p1 != nullptr){
                length1++;
                p1 = p1->next;
            }
            if(p2 != nullptr){
                length2++;
                p2 = p2->next;
            }
        }
        p1 = L1->next;
        p2 = L2->next;
        if(length1 <= length2){
            for(int i=0; i<length2 - length1; i++){
                p2 = p2->next;
            }
            while(length1){
                if(p1->val == p2->val){
                    cout << "��������ĵ�һ�������ڵ�Ϊ" << p1->val << endl;
                    return;
                } else{
                    p1 = p1->next;
                    p2 = p2->next;
                    length1--;
                }
            }
            cout << "����������û�й����ڵ�" << endl;
            return;
        } else{
            for(int i=0; i<length1 - length2; i++){
                p2 = p2->next;
            }
            while(length2){
                if(p1->val == p2->val){
                    cout << "��������ĵ�һ�������ڵ�Ϊ" << p1->val << endl;
                    return;
                } else{
                    p1 = p1->next;
                    p2 = p2->next;
                    length2--;
                }
            }
            cout << "����������û�й����ڵ�" << endl;
            return;
        }
    }

/**
 * ������ӡ���������нڵ�
 * ����P37 �ۺ���9
 * @return
 */
public:
    void ForwardPrintList(ListNode *L){
        ListNode *p = L->next;
        if(p == nullptr){
            cout << "���Ǹ��ձ�";
            return;
        }
        int minum;
        ListNode *pre;
        while(L->next != nullptr){
            pre = L;
            p = L->next;
            minum = p->val;
            while(p != nullptr){
                ListNode *q = p->next;
                if(q == nullptr){
                    ListNode *delNode = pre->next;
                    pre->next = delNode->next;
                    cout << "->" << delNode->val;
                    free(delNode);
                    break;
                } else{
                    if(q->val >= minum){
                        p = p->next;
                    } else{
                        pre = p;
                        p = q;
                    }
                }
            }
        }
    }

/**
 * ��������ż˳���ֳ���������
 * ����P37 �ۺ���10
 * @return
 */
public:
    void DivideListIntoAandB(ListNode *L){
        auto *A = new ListNode(-1);
        ListNode *q = A;
        auto *B = new ListNode(-1);
        ListNode *r = B;
        ListNode *p = L->next;
        if(p == nullptr){
            cout << "����һ���ձ�" << endl;
            return;
        }
        while(p != nullptr){
            q->next = new ListNode(p->val);
            q = q->next;
            p = p->next;
            if(p == nullptr)
                break;
            else{
                r->next = new ListNode(p->val);
                r = r->next;
                p = p->next;
            }
        }

        p = A->next;
        cout << "����ָ�����:" << endl << "A: ";
        while(p != nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        p = B->next;
        cout << endl << "B: ";
        while(p != nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        cout << endl;
    }

/**
 * ��������˳��ż�����ֳ���������
 * ����P37 �ۺ���11
 * @param L
 */
public:
    void DivideListIntoAandBByForwardAndBackward(ListNode *L){
        auto *A = new ListNode(-1);
        ListNode *q = A;
        auto *B = new ListNode(-1);
        ListNode *p = L->next;
        if(p == nullptr){
            cout << "����һ���ձ�" << endl;
            return;
        }
        while(p != nullptr){
            q->next = new ListNode(p->val);
            p = p->next;
            q = q->next;
            if(p == nullptr)
                break;
            else {
                auto *r = new ListNode(p->val);
                r->next = B->next;
                B->next = r;
                p = p->next;
            }
        }

        p = A->next;
        cout << "����ָ�����:" << endl << "A: ";
        while(p != nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        p = B->next;
        cout << endl << "B: ";
        while(p != nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        cout << endl;
    }

/**
 * �Ե�����ȥ��
 * ����P37 �ۺ���12
 * @param L
 */
public:
    void RemoveDuplicateNodeInList(ListNode *L){
        ListNode *p = L->next;
        ListNode *pre = p;
        if(p == nullptr){
            cout << "����һ��������" << endl;
            return;
        }
//    if(p->next == NULL){
//        cout << "ȥ�غ������:" << "->" << p->val << endl;
//        return;
//    }
        int tmp = p->val;
        p = p->next;
        while(p != nullptr){
            while(tmp == p->val){
                if(p->next != nullptr){
                    p = p->next;
                } else{
                    pre->next = nullptr;
                    break;
                }
            }
            if(p->next == nullptr)
                break;
            pre->next = p;
            tmp = p->val;
            pre = p;
            p = p->next;
        }
        p = L->next;
        cout << "ȥ�غ������: ";
        while(p != nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        cout << endl;
    }

/**
 * �͵غϲ�������������
 * ����P37 �ۺ���13
 * @return
 */
public:
    void MergeListsForward(ListNode *L1, ListNode *L2){
        ListNode *p = L1->next, *pre1 = L1;
        ListNode *q = L2->next, *pre2 = L2;
        if(p == nullptr || q == nullptr){
            cout << "���ڿ�����, ����ϲ�" << endl;
            return;
        }
        while(p != nullptr || q != nullptr){
            if(p->val >= q->val){
                pre2->next = q->next;
                q->next = p;
                pre1->next = q;
                pre1 = q;
                q = pre2->next;
                if(q == nullptr){
                    break;
                }
            } else{
                pre1 = p;
                p = p->next;
                if(p == nullptr){
                    pre1->next = q;
                    break;
                }
            }
        }
        p = L1->next;
        cout << "�ϲ��������: ";
        while(p != nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        cout << endl;
    }

/**
 * Ѱ��A��B��������Ľ���������A������
 * ����P38 �ۺ���15
 * @return
 */
public:
    void FindListsIntersection(ListNode *L1, ListNode *L2){
        ListNode *p = L1->next, *q = L2->next, *pre = L1;
        if(p == nullptr || q == nullptr){
            cout << "���ڿ�����, ����Ϊ��" << endl;
            return;
        }
        while(p != nullptr && q != nullptr){
            if(p->val > q->val){
                q = q->next;
            } else if(p->val < q->val){
                ListNode *r = p;
                p = p->next;
                pre->next = p;
                free(r);
            } else{
                pre = p;
                p = p->next;
                q = q->next;
            }
            if(p == nullptr || q == nullptr){
                pre->next = nullptr;
                break;
            }
        }
        p = L1->next;
        cout << "��������Ľ���Ϊ: ";
        while(p != nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        cout << endl;
    }

/**
 * AΪ����,BΪ�Ӵ��ļ�ª����ģʽƥ��
 * ����P38 �ۺ���16
 * @return
 */
public:
    void SimplePatternMatching(ListNode *B, ListNode *A){
        ListNode *p = A->next, *q = B->next, *pre = A;
        if(p == nullptr || q == nullptr){
            cout << "���ڿ�����, ����ϲ�" << endl;
            return;
        }
        while(p && q){
            if(p->val == q->val){
                p = p->next;
                q = q->next;
            } else {
                q = B->next;
                pre = pre->next;
                p = pre->next;
            }
        }

        if(!q)
            cout << "ƥ��ɹ�.";
        else
            cout << "δƥ��ɹ�.";
        cout << endl;
    }

/**
 * �ж�˫ѭ�������Ƿ���жԳ���
 * ����P38 �ۺ���17
 * @param DL
 * @return
 */
 public:
    bool JudgeWhetherTheDoubleLinkIsSymmetrical(DoubleLinkNode *DL){
        DoubleLinkNode *p = DL;
        DoubleLinkNode *q = DL;
        if(p->next == q){
            cout << "˫ѭ������Ϊ��" << endl;
            return false;
        }
        do{
            p = p->next;
            q = q->pre;
            if(p->val != q->val){
                cout << "��˫ѭ�������Գ�" << endl;
                return false;
            }
        }while(p != q && p->next != q);
        cout << "��˫ѭ������Գ�" << endl;
        return true;
    }

/**
 * ��Bѭ������ԭ˳��ƴ����Aѭ������֮��
 * ����P38 �ۺ���18
 * @param L1
 * @param L2
 */
public:
    void MergeBListIntoAList(ListNode* L2, ListNode* L1){
        ListNode *r1 = L1, *p = L1->next;
        ListNode *r2 = L2, *q =L2->next;
        if(p == nullptr && q == nullptr){
            cout << "���������Ϊ��, ����ϲ�" << endl;
            return;
        }
        while(p != L1){
            if(p->next == L1)
                r1 = p;
            p = p->next;
        }
        while(q != L2){
            if(q->next == L2)
                r2 = q;
            q = q->next;
        }
        r1->next = L2;
        r2->next = L1;
        p = L1->next;
        cout << "�ϲ����ѭ������: ";
        while(p != L1){
            cout << "->" << p->val;
            p = p->next;
        }
        cout << "->..." << endl;
    }

/**
 * ѭ����ӡѭ�����������Сֵ, ÿ��ӡһ���ͽ��ýڵ�ɾ��
 * ����P38 �ۺ���19
 * @param L
 */
public:
    void LoopFindMinNode(ListNode* L){
        ListNode *pre = L, *p = L->next, *q = p;
        int minimum;
        if(p == nullptr){
            cout << "ѭ������Ϊ��." << endl;
            return;
        }
        cout << "��Сֵ����Ϊ:";
        while(L->next != L){
            pre = L;
            p = L->next;
            minimum = L->next->val;
            while(p->next != L){
                q = p;
                p = p->next;
                if(p->val < minimum) {
                    minimum = p->val;
                    pre = q;
                }
            }
            q = pre->next;
            pre->next = q->next;
            cout << ' ' << q->val;
            free(q);
        }
        p = L->next;
        if(p == L){
            cout << endl << "ѭ���������ѿ�";
        }
        cout << endl;
    }

/**
 * ˫�������ָ���ڵ�, �����²���Ƶ��
 * ����P38 �ۺ���20
 * @param L
 * @param x
 */
public:
    DoubleLinkNodeWithFrequency* LocateDoubleLinkList(DoubleLinkNodeWithFrequency* &L, int x){
        DoubleLinkNodeWithFrequency *p = L->next;
        int freq = 0;
        while(p->val != x){
            p = p->next;
            if(p == L){
                cout << "������û���ҵ��ýڵ�" << endl;
                return nullptr;
            }
        }
        freq = ++ p->freq;
        DoubleLinkNodeWithFrequency *q = p;
        p->pre->next = p->next;
        if(p->next != nullptr){
            p->next->pre = p->pre;
        }
        while(p->freq <= freq){
            p = p->pre;
            if(p == L){
                q->next = p->next;
                p->next->pre = q;
                p->next = q;
                q->pre = p;
                return q;
            }
        }
        q->next = p->next;
        p->next->pre = q;
        p->next = q;
        p->pre = p;
        return q;
    }

/**
 * �������в��ҵ�����k���ڵ�
 * ����P38 �ۺ���21
 * @param L
 * @param k
 */
public:
    void FindTheLastKNodeInLinkList(ListNode *L, int k){
        ListNode *p = L, *q = L;
        if(L->next == nullptr){
            cout << "������Ϊ��" << endl;
            return;
        }
        k--;
        while(k--)
            p = p->next;
        while(p->next != nullptr){
            p = p->next;
            q = q->next;
        }
        cout << "�ҵ�������" << k << "���ڵ�Ϊ: " << q->val << endl;
    }

/**
 * �ҳ��������ʵĹ�����׺
 * ����P38 �ۺ���22
 * @param L
 * @param k
 */
public:
    void FindCommonSuffixesForWords(const string& word2, const string& word1){
        ListNode *Word1 = nullptr, *Word2 = nullptr; // ����Ӧ���ǽ������������ַ����β�תΪ����������δʵ��......
        ListNode *p = Word1->next, *q = Word2->next, *r = nullptr;
        int length1 = 0, length2 = 0, dif = 0;
        if(Word1->next == nullptr || Word2->next == nullptr){
            cout << "���ڿհ׵���." << endl;
            return;
        }
        while(p != nullptr){
            length1++;
            p = p->next;
        }
        while(q != nullptr){
            length2++;
            q = q->next;
        }

        if(length1 >= length2){
            dif = length1 - length2;
            while (dif--)
                p = p->next;
            while(length2--){
                if(p == q){
                    r = p;
                    break;
                }
                p = p->next;
                q = q->next;
            }
            if(r == nullptr){
                cout << "����������û�й�����׺." << endl;
            } else{
                cout << "���� ";
                while(Word1->next != nullptr){
                    Word1 = Word1->next;
                    cout << Word1->val;
                }
                cout << "�뵥�� ";
                while(Word2->next != nullptr){
                    Word2 = Word2->next;
                    cout << Word2->val;
                }
                cout << "�Ĺ�����׺Ϊ: ";
                while(r != nullptr){
                    cout << r->val;
                    r = r->next;
                }
                cout << endl;
            }
        }
    }

/**
 * ȥ���������о���ֵ��ͬ�Ľڵ�, �ڵ�ľ���ֵ������n
 * ����P38 �ۺ���23
 * y 35 y 8 21 15 15 -6 -15 25 30 15
 * @param L
 * @param n
 */
public:
    void RemoveNodesWithTheSameAbsoluteValue(ListNode *L, int n){
        ListNode *p = L->next, *pre = L;
        int *bucket = new int[n + 1];
        for (int i = 0; i < n + 2; i++){
            *(bucket + i) = 0;
        }
        if(p == nullptr){
            cout << "������Ϊ��." << endl;
            return;
        }
        while(p != nullptr){
            int tmp = abs(p->val);
            if(bucket[tmp] == 0){
                bucket[tmp] = 1;
                pre = p;
                p = p->next;
            } else{
                ListNode *q = p;
                p = p->next;
                pre->next = p;
                free(q);
            }
        }

        p = L->next;
        cout << "���º�ĵ�����Ϊ: ";
        while(p != nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        cout << endl;
    }

public:
    int run(){
        string s, yes = "y";
        string c0 =  "��������Ϊ������һ������������Ҫ��ȷ������Ľڵ����(y / n)";
        string c1 =  "��������Ϊ��������һ������������Ҫ��ȷ������Ľڵ����(y / n)";
        string c2 =  "��������Ϊ��������һ������������Ҫ��ȷ������Ľڵ����(y / n)";
        string c3 =  "��������Ϊ������һ��˫ѭ������������Ҫ��ȷ������Ľڵ����(y / n)";
        string c4 =  "��������Ϊ������һ����ѭ������������Ҫ��ȷ������Ľڵ����(y / n)";
        string c5 =  "��������Ϊ��������һ����ѭ������������Ҫ��ȷ������Ľڵ����(y / n)";
        string c6 =  "��������Ϊ�������ڶ�����ѭ������������Ҫ��ȷ������Ľڵ����(y / n)";
        string c7 =  "��������Ϊ������һ����¼����Ƶ�ʵ�˫����������Ҫ��ȷ������Ľڵ����(y / n)";

        cout << "����ľ͵����ã�Ҫ��ʾ��(y / n) ";
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            ReversLink(CreateLinkList(c0));

        cout << "�������������Ҫ��ʾ��(y / n)";
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            LinkListForwardSort(CreateLinkList(c0));

        cout << "ɾ����������ֵ����x��y֮��Ľڵ㣬Ҫ��ʾ��(y / n)";
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            DeleteNodeBtweenXandY(CreateLinkList(c0));

        cout << "������������Ĺ����ڵ㣬Ҫ��ʾ��(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            FindFirstCommonNode(CreateLinkList(c2), CreateLinkList(c1));

        cout << "������˳���ӡ���������нڵ㣬Ҫ��ʾ��(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            ForwardPrintList(CreateLinkList(c0));

        cout << "��������ż˳���ֳ���������Ҫ��ʾ��(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            DivideListIntoAandB(CreateLinkList(c0));

        cout << "��������˳��ż�����ֳ���������Ҫ��ʾ��(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            DivideListIntoAandBByForwardAndBackward(CreateLinkList(c0));

        cout << "�Ե�����ȥ�أ�Ҫ��ʾ��(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            RemoveDuplicateNodeInList(CreateLinkList(c0));

        cout << "�͵غϲ�������������Ҫ��ʾ��(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            MergeListsForward(CreateLinkList(c2), CreateLinkList(c1));

        cout << "Ѱ��A��B��������Ľ���������A�����У�Ҫ��ʾ��(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            FindListsIntersection(CreateLinkList(c2), CreateLinkList(c1));

        cout << "AΪ����,BΪ�Ӵ��ļ�ª����ģʽƥ�䣬Ҫ��ʾ��(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            SimplePatternMatching(CreateLinkList(c2), CreateLinkList(c1));

        cout << "�ж�˫ѭ�������Ƿ���жԳ��ԣ�Ҫ��ʾ��(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            JudgeWhetherTheDoubleLinkIsSymmetrical(CreateDoubleCirculationLinkList(c3));

        cout << "��Bѭ������ԭ˳��ƴ����Aѭ������֮��Ҫ��ʾ��(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            MergeBListIntoAList(CreateCirculationLinkList(c6), CreateCirculationLinkList(c5));

        cout << "ѭ����ӡѭ�����������Сֵ, ÿ��ӡһ���ͽ��ýڵ�ɾ����Ҫ��ʾ��(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            LoopFindMinNode(CreateCirculationLinkList(c4));

        cout << "˫�������ָ���ڵ�, �����²���Ƶ�� ,Ҫ��ʾ��(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0){
            DoubleLinkNodeWithFrequency *L = CreateDoubleLinkListWithFrequency(c7);
            DoubleLinkNodeWithFrequency *node = nullptr;
            int x;
            while(1){
                cout << "����������Ҫ���ҵĽڵ�ֵ: ";
                cin >> x;
                node = LocateDoubleLinkList(L, x);
                cout << "�ҵ��Ľڵ��ַΪ: " << node << endl << "����֮���˫����Ϊ: " << endl;
                PrintDoubleLinkListWithFrequency(L);
            }
        }

        cout << "�������в��ҵ�����k���ڵ㣬Ҫ��ʾ��(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0) {
            int k = 0;
            cout << "����������Ҫ���ҵ����ڼ����ڵ�: ";
            cin >> k;
            FindTheLastKNodeInLinkList(CreateLinkList(c0), k);
        }

        cout << "�ҳ��������ʵĹ�����׺��Ҫ��ʾ��(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0) {
            string word1, word2;
            cout << "��������Ҫ�Ƚϵĵ�һ������: ";
            cin >> word1;
            cout << "��������Ҫ�Ƚϵĵڶ�������: ";
            cin >> word2;
            FindCommonSuffixesForWords(word2, word1);
        }

        cout << "ȥ���������о���ֵ��ͬ�Ľڵ�, �ڵ�ľ���ֵ������n��Ҫ��ʾ��(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0){
            cout << "�����뵥�������ֵ�����ֵn: ";
            int n = 0;
            cin >> n;
            RemoveNodesWithTheSameAbsoluteValue(CreateLinkList(c0), n);
        }


        return 1;
    }
};
