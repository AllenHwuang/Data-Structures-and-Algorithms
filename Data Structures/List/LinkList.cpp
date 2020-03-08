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

/**
 * 尾插法建立单链表
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
        cout << "请输入节点个数：";
        ListNode * rear = list;
        int len;
        cin >> len;
        cout << "请您依次输入该链表的"<< len <<"个节点值: ";
        while(len--){
            int x;
            cin>>x;
            rear->next = new ListNode(x);
            rear = rear->next;
        }
        return list;
    }

public:
    ListNode * CreateCirculationLinkList(const string& pointWords){
        cout << pointWords << endl;
        string s;
        string yes = "y";
        cin>>s;
        auto * list = new ListNode(-1);
        if(strcasecmp(s.c_str(), yes.c_str()) != 0)
            return list;
        cout << "请输入节点个数：";
        ListNode * rear = list;
        int len;
        cin >> len;
        cout << "请您依次输入该链表的"<< len <<"个节点值: ";
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
 * 尾插法建立双链表
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
        cout << "请输入节点个数：";
        DoubleLinkNode *rear = list;
        int len;
        cin >> len;
        cout << "请您依次输入该链表的"<< len <<"个节点值: ";
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
 * 带头结点单链表就地逆置
 * 王道P37 综合题5
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
 * 单链表正向排序
 * 王道P37 综合题6
 * @return
 */
public:
    void LinkListForwardSort(ListNode *L){
        auto *NL = new ListNode(-1);
        ListNode *p = L->next;
        cout << "原始链表 ";
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
        cout << "递增排序后的链表 ";
        while(p!=nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        cout << endl;
    }

/**
 * 删除数值介于X和Y之间的节点
 * 王道P37 综合题7
 * @param L
 * @param x
 * @param y
 */
public:
    void DeleteNodeBtweenXandY(ListNode *L){
        int x, y;
        cout << "请输入查找范围上界X ";
        cin >> x;
        cout << "请输入查找范围下界Y ";
        cin >> y;
        if(L->next==nullptr)
            return;
        ListNode *p = L->next;
        cout << "原始链表 ";
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
        cout << "删除了所有" << x << "和" << y << "之间元素后的链表 ";
        while(p != nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        cout << endl;
    }

/**
 * 找到两个链表的第一个公共节点
 * 王道P37 综合题8
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
                    cout << "两个链表的第一个公共节点为" << p1->val << endl;
                    return;
                } else{
                    p1 = p1->next;
                    p2 = p2->next;
                    length1--;
                }
            }
            cout << "这两个链表没有公共节点" << endl;
            return;
        } else{
            for(int i=0; i<length1 - length2; i++){
                p2 = p2->next;
            }
            while(length2){
                if(p1->val == p2->val){
                    cout << "两个链表的第一个公共节点为" << p1->val << endl;
                    return;
                } else{
                    p1 = p1->next;
                    p2 = p2->next;
                    length2--;
                }
            }
            cout << "这两个链表没有公共节点" << endl;
            return;
        }
    }

/**
 * 递增打印单链表所有节点
 * 王道P37 综合题9
 * @return
 */
public:
    void ForwardPrintList(ListNode *L){
        ListNode *p = L->next;
        if(p == nullptr){
            cout << "这是个空表";
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
 * 将链表按奇偶顺序拆分成两个链表
 * 王道P37 综合题10
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
            cout << "这是一个空表" << endl;
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
        cout << "链表分割如下:" << endl << "A: ";
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
 * 将链表按奇顺序偶逆序拆分成两个链表
 * 王道P37 综合题11
 * @param L
 */
public:
    void DivideListIntoAandBByForwardAndBackward(ListNode *L){
        auto *A = new ListNode(-1);
        ListNode *q = A;
        auto *B = new ListNode(-1);
        ListNode *p = L->next;
        if(p == nullptr){
            cout << "这是一个空表" << endl;
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
        cout << "链表分割如下:" << endl << "A: ";
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
 * 对单链表去重
 * 王道P37 综合题12
 * @param L
 */
public:
    void RemoveDuplicateNodeInList(ListNode *L){
        ListNode *p = L->next;
        ListNode *pre = p;
        if(p == nullptr){
            cout << "这是一个空链表" << endl;
            return;
        }
//    if(p->next == NULL){
//        cout << "去重后的链表:" << "->" << p->val << endl;
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
        cout << "去重后的链表: ";
        while(p != nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        cout << endl;
    }

/**
 * 就地合并两个有序单链表
 * 王道P37 综合题13
 * @return
 */
public:
    void MergeListsForward(ListNode *L1, ListNode *L2){
        ListNode *p = L1->next, *pre1 = L1;
        ListNode *q = L2->next, *pre2 = L2;
        if(p == nullptr || q == nullptr){
            cout << "存在空链表, 无需合并" << endl;
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
        cout << "合并后的链表: ";
        while(p != nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        cout << endl;
    }

/**
 * 寻找A与B两个链表的交集并存于A链表中
 * 王道P38 综合题15
 * @return
 */
public:
    void FindListsIntersection(ListNode *L1, ListNode *L2){
        ListNode *p = L1->next, *q = L2->next, *pre = L1;
        if(p == nullptr || q == nullptr){
            cout << "存在空链表, 交集为空" << endl;
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
        cout << "两个链表的交集为: ";
        while(p != nullptr){
            cout << "->" << p->val;
            p = p->next;
        }
        cout << endl;
    }

/**
 * A为主串,B为子串的简陋方法模式匹配
 * 王道P38 综合题16
 * @return
 */
public:
    void SimplePatternMatching(ListNode *B, ListNode *A){
        ListNode *p = A->next, *q = B->next, *pre = A;
        if(p == nullptr || q == nullptr){
            cout << "存在空链表, 无需合并" << endl;
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
            cout << "匹配成功.";
        else
            cout << "未匹配成功.";
        cout << endl;
    }

/**
 * 判断双循环链表是否具有对称性
 * 王道P38 综合题17
 * @param DL
 * @return
 */
 public:
    bool JudgeWhetherTheDoubleLinkIsSymmetrical(DoubleLinkNode *DL){
        DoubleLinkNode *p = DL;
        DoubleLinkNode *q = DL;
        if(p->next == q){
            cout << "双循环链表为空" << endl;
            return false;
        }
        do{
            p = p->next;
            q = q->pre;
            if(p->val != q->val){
                cout << "该双循环链表不对称" << endl;
                return false;
            }
        }while(p != q && p->next != q);
        cout << "该双循环链表对称" << endl;
        return true;
    }

/**
 * 将B循环链表按原顺序拼接在A循环链表之后
 * 王道P38 综合题18
 * @param L1
 * @param L2
 */
public:
    void MergeBListIntoAList(ListNode* L2, ListNode* L1){
        ListNode *r1 = L1, *p = L1->next;
        ListNode *r2 = L2, *q =L2->next;
        if(p == nullptr && q == nullptr){
            cout << "两个链表均为空, 无需合并" << endl;
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
        cout << "合并后的循环链表: ";
        while(p != L1){
            cout << "->" << p->val;
            p = p->next;
        }
        cout << "->..." << endl;
    }

/**
 * 循环打印循环单链表的最小值, 每打印一个就将该节点删除
 * 王道P38 综合题19
 * @param L
 */
public:
    void LoopFindMinNode(ListNode* L){
        ListNode *pre = L, *p = L->next, *q = p;
        int minimum;
        if(p == nullptr){
            cout << "循环链表为空." << endl;
            return;
        }
        cout << "最小值依次为:";
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
            cout << endl << "循环单链表已空";
        }
        cout << endl;
    }

public:
    int run(){
        string s, yes = "y";
        string c0 =  "接下来将为您构建一个链表，首先需要您确定链表的节点个数(y / n)";
        string c1 =  "接下来将为您构建第一个链表，首先需要您确定链表的节点个数(y / n)";
        string c2 =  "接下来将为您构建第一个链表，首先需要您确定链表的节点个数(y / n)";
        string c3 =  "接下来将为您构建一个双循环链表，首先需要您确定链表的节点个数(y / n)";
        string c4 =  "接下来将为您构建一个单循环链表，首先需要您确定链表的节点个数(y / n)";
        string c5 =  "接下来将为您构建第一个单循环链表，首先需要您确定链表的节点个数(y / n)";
        string c6 =  "接下来将为您构建第二个单循环链表，首先需要您确定链表的节点个数(y / n)";
        cout << "链表的就地逆置，要演示吗？(y / n) ";
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            ReversLink(CreateLinkList(c0));

        cout << "链表的正向排序，要演示吗？(y / n)";
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            LinkListForwardSort(CreateLinkList(c0));

        cout << "删除链表中数值介于x与y之间的节点，要演示吗？(y / n)";
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            DeleteNodeBtweenXandY(CreateLinkList(c0));

        cout << "查找两个链表的公共节点，要演示吗？(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            FindFirstCommonNode(CreateLinkList(c2), CreateLinkList(c1));

        cout << "按递增顺序打印单链表所有节点，要演示吗？(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            ForwardPrintList(CreateLinkList(c0));

        cout << "将链表按奇偶顺序拆分成两个链表，要演示吗？(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            DivideListIntoAandB(CreateLinkList(c0));

        cout << "将链表按奇顺序偶逆序拆分成两个链表，要演示吗？(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            DivideListIntoAandBByForwardAndBackward(CreateLinkList(c0));

        cout << "对单链表去重，要演示吗？(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            RemoveDuplicateNodeInList(CreateLinkList(c0));

        cout << "就地合并两个有序单链表，要演示吗？(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            MergeListsForward(CreateLinkList(c2), CreateLinkList(c1));

        cout << "寻找A与B两个链表的交集并存于A链表中，要演示吗？(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            FindListsIntersection(CreateLinkList(c2), CreateLinkList(c1));

        cout << "A为主串,B为子串的简陋方法模式匹配，要演示吗？(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            SimplePatternMatching(CreateLinkList(c2), CreateLinkList(c1));

        cout << "判断双循环链表是否具有对称性，要演示吗？(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            JudgeWhetherTheDoubleLinkIsSymmetrical(CreateDoubleCirculationLinkList(c3));

        cout << "将B循环链表按原顺序拼接在A循环链表之后，要演示吗？(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            MergeBListIntoAList(CreateCirculationLinkList(c6), CreateCirculationLinkList(c5));

        cout << "循环打印循环单链表的最小值, 每打印一个就将该节点删除，要演示吗？(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            LoopFindMinNode(CreateCirculationLinkList(c4));

        return 1;
    }
};
