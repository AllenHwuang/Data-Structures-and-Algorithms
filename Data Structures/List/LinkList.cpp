//
// Created by 29546 on 2020/2/29.
//
#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 头插法建立单链表
 * @param pointWords
 * @return
 */
ListNode * CreateList(string pointWords){
    cout << pointWords << endl;
    string s = "";
    string yes = "y";
    cin>>s;
    ListNode * list = new ListNode(-1);
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    int cnt = 0;
    ListNode* r=new ListNode(-1);
    ListNode *p = l1, *q = l2, *f = NULL;
    if(!l1->val && !l2->val){
        return f;
    }else if(!l1->val){
        return l2;
    }else if(!l2->val){
        return l1;
    }
    while(p!=NULL || q!=NULL){
        cnt++;
        if( cnt == 1 ){
            if(p->val <= q->val){
                f = new ListNode(p->val);
                r->next = f;
                if(p->next != NULL) {
                    p = p->next;
                }else{
                    while(q!= NULL){
                        ListNode *node = new ListNode(q->val);
                        r->next->next = node;
                        r->next = node;
                        q = q->next;
                    }
                    break;
                }
            }else{
                f = new ListNode(q->val);
                r->next = f;
                if(q->next != NULL){
                    q = q->next;
                }else{
                    while(p!= NULL){
                        ListNode *node = new ListNode(p->val);
                        r->next->next = node;
                        r->next = node;
                        p = p->next;
                    }
                    break;
                }
            }
        } else{
            if(p->val <= q->val){
                ListNode *node = new ListNode(p->val);
                r->next->next = node;
                r->next = node;
                if(p->next != NULL) {
                    p = p->next;
                }else{
                    while(q!= NULL){
                        ListNode *node = new ListNode(q->val);
                        r->next->next = node;
                        r->next = node;
                        q = q->next;
                    }
                    break;
                }
            } else{
                ListNode *node = new ListNode(q->val);
                r->next->next = node;
                r->next = node;
                if(q->next != NULL){
                    q = q->next;
                }else{
                    while(p!= NULL){
                        ListNode *node = new ListNode(p->val);
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
void ReversLink(ListNode *L){
    if(L->next==NULL){
        cout << "Linklist is Empty";
        return;
    }
    ListNode *pre = L->next;
    if(pre->next==NULL){
        cout << pre->val << endl;
        return;
    }
    ListNode *p = pre->next;
    pre->next = NULL;
    ListNode *r = p->next;
    do{
        p->next = pre;
        if(r == NULL)
            break;
        else{
            pre = p;
            p = r;
            r = r->next;
        }
    }while(p != NULL);
    L->next = p;
    while(p!=NULL){
        cout << p->val << " ";
        p = p->next;
    }
}

/**
 * 单链表正向排序
 * 王道P37 综合题6
 * @return
 */
void LinkListForwardSort(ListNode *L){
    ListNode *NL = new ListNode(-1);
    ListNode *p = L->next;
    cout << "原始链表 ";
    while(p != NULL){
        cout << "->" << p->val;
        p = p->next;
    }
    p = L->next;
    cout << endl;
    while(p != NULL){
        ListNode *pre = NL;
        ListNode *q = NL->next;
        do{
            if(q == NULL){
                q = new ListNode(L->next->val);
                NL->next = q;
                p = p->next;
            } else{
                if(p->val <= q->val){
                    ListNode *r = new ListNode(p->val);
                    r->next = pre->next;
                    pre->next = r;
                    break;
                } else{
                    pre  = q;
                    q = q->next;
                    if(q == NULL){
                        pre->next = new ListNode(p->val);
                        break;
                    }
                }
            }
        }while(NL->next != NULL);
        p = p->next;
    }
    p = NL->next;
    cout << "递增排序后的链表 ";
    while(p!=NULL){
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
void DeleteNodeBtweenXandY(ListNode *L){
    int x, y;
    cout << "请输入查找范围上界X ";
    cin >> x;
    cout << "请输入查找范围下界Y ";
    cin >> y;
    if(L->next==NULL)
        return;
    ListNode *p = L->next;
    cout << "原始链表 ";
    while(p!=NULL){
        cout << "->" << p->val;
        p = p->next;
    }
    cout << endl;
    ListNode *pre = L;
    p = L->next;
    while(p!=NULL){
        while(x < p->val && y > p->val && p->next != NULL)
            p = p->next;
        pre->next = p;
        pre = p;
        p = p->next;
        if(p == NULL)
            break;
    }
    p = L->next;
    cout << "删除了所有" << x << "和" << y << "之间元素后的链表 ";
    while(p!=NULL){
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
void FindFirstCommonNode(ListNode *L1, ListNode *L2){
    ListNode *p1 = L1->next;
    ListNode *p2 = L2->next;
    int length1 = 0, length2 = 0;
    if(p1 == NULL || p2 == NULL){
        cout << "There is a Empty Link..." << endl;
        return;
    }
    while(p1 != NULL || p2 != NULL){
        if(p1 != NULL){
            length1++;
            p1 = p1->next;
        }
        if(p2 != NULL){
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
void ForwardPrintList(ListNode *L){
    ListNode *p = L->next;
    if(p == NULL){
        cout << "这是个空表";
        return;
    }
    int minum = p->val;
    ListNode *pre = L;
    while(L->next != NULL){
        pre = L;
        p = L->next;
        minum = p->val;
        while(p != NULL){
            ListNode *q = p->next;
            if(q == NULL){
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
    return;
}

/**
 * 将链表按奇偶顺序拆分成两个链表
 * 王道P37 综合题10
 * @return
 */
void DivideListIntoAandB(ListNode *L){
    ListNode *A = new ListNode(-1);
    ListNode *q = A;
    ListNode *B = new ListNode(-1);
    ListNode *r = B;
    ListNode *p = L->next;
    if(p == NULL){
         cout << "这是一个空表" << endl;
         return;
    }
    while(p != NULL){
        q->next = new ListNode(p->val);
        q = q->next;
        p = p->next;
        if(p == NULL)
            break;
        else{
            r->next = new ListNode(p->val);
            r = r->next;
            p = p->next;
        }
    }

    p = A->next;
    cout << "链表分割如下:" << endl << "A: ";
    while(p != NULL){
        cout << "->" << p->val;
        p = p->next;
    }
    p = B->next;
    cout << endl << "B: ";
    while(p != NULL){
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
void DivideListIntoAandBByForwardAndBackward(ListNode *L){
    ListNode *A = new ListNode(-1);
    ListNode *q = A;
    ListNode *B = new ListNode(-1);
    ListNode *p = L->next;
    if(p == NULL){
        cout << "这是一个空表" << endl;
        return;
    }
    while(p != NULL){
        q->next = new ListNode(p->val);
         p = p->next;
         q = q->next;
         if(p == NULL)
             break;
         else {
             ListNode *r = new ListNode(p->val);
             r->next = B->next;
             B->next = r;
             p = p->next;
         }
    }

    p = A->next;
    cout << "链表分割如下:" << endl << "A: ";
    while(p != NULL){
        cout << "->" << p->val;
        p = p->next;
    }
    p = B->next;
    cout << endl << "B: ";
    while(p != NULL){
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
void RemoveDuplicateNodeInList(ListNode *L){
    ListNode *p = L->next;
    ListNode *pre = p;
    if(p == NULL){
        cout << "这是一个空链表" << endl;
        return;
    }
//    if(p->next == NULL){
//        cout << "去重后的链表:" << "->" << p->val << endl;
//        return;
//    }
    int tmp = p->val;
    p = p->next;
    while(p != NULL){
        while(tmp == p->val){
            if(p->next != NULL){
                p = p->next;
            } else{
                pre->next = NULL;
                break;
            }
        }
        if(p->next == NULL)
            break;
        pre->next = p;
        tmp = p->val;
        pre = p;
        p = p->next;
    }
    p = L->next;
    cout << "去重后的链表: ";
    while(p != NULL){
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
void MergeListsForward(ListNode *L1, ListNode *L2){
    ListNode *p = L1->next, *pre1 = L1;
    ListNode *q = L2->next, *pre2 = L2;
    if(p == NULL || q == NULL){
        cout << "存在空链表, 无需合并" << endl;
        return;
    }
    while(p != NULL || q != NULL){
        if(p->val >= q->val){
            pre2->next = q->next;
            q->next = p;
            pre1->next = q;
            pre1 = q;
            q = pre2->next;
            if(q == NULL){
                break;
            }
        } else{
            pre1 = p;
            p = p->next;
            if(p == NULL){
                pre1->next = q;
                break;
            }
        }
    }
    p = L1->next;
    cout << "合并后的链表: ";
    while(p != NULL){
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
void FindListsIntersection(ListNode *L1, ListNode *L2){
    ListNode *p = L1->next, *q = L2->next, *pre = L1;
    if(p == NULL || q == NULL){
        cout << "存在空链表, 交集为空" << endl;
        return;
    }
    while(p != NULL && q != NULL){
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
        if(p == NULL || q == NULL){
            pre->next = NULL;
            break;
        }
    }
    p = L1->next;
    cout << "两个链表的交集为: ";
    while(p != NULL){
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
void SimplePatternMatching(ListNode *B, ListNode *A){
    ListNode *p = A->next, *q = B->next, *pre = A;
    if(p == NULL || q == NULL){
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


int main(){
    string s = "";
    string yes = "y";

//    cout << "链表的就地逆置，要演示吗？(y / n) ";
//    cin>>s;
//    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
//        ReversLink(CreateList("接下来将为您构建一个链表，首先需要您确定链表的节点个数(y / n)"));
//
//    cout << "链表的正向排序，要演示吗？(y / n)";
//    cin>>s;
//    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
//        LinkListForwardSort(CreateList("接下来将为您构建一个链表，首先需要您确定链表的节点个数(y / n)"));
//
//    cout << "删除链表中数值介于x与y之间的节点，要演示吗？(y / n)";
//    cin>>s;
//    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
//        DeleteNodeBtweenXandY(CreateList("接下来将为您构建一个链表，首先需要您确定链表的节点个数(y / n)"));
//
//    cout << "查找两个链表的公共节点，要演示吗？(y / n)" << endl;
//    cin>>s;
//    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
//        FindFirstCommonNode(CreateList("接下来将为您构建第二个链表，首先需要您确定链表的节点个数(y / n)"),
//                            CreateList("接下来将为您构建第一个链表，首先需要您确定链表的节点个数(y / n)"));
//
//    cout << "按递增顺序打印单链表所有节点，要演示吗？(y / n)" << endl;
//    cin>>s;
//    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
//        ForwardPrintList(CreateList("接下来将为您构建一个链表，首先需要您确定链表的节点个数(y / n)"));
//
//    cout << "将链表按奇偶顺序拆分成两个链表，要演示吗？(y / n)" << endl;
//    cin>>s;
//    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
//        DivideListIntoAandB(CreateList("接下来将为您构建一个链表，首先需要您确定链表的节点个数(y / n)"));
//
//    cout << "将链表按奇顺序偶逆序拆分成两个链表，要演示吗？(y / n)" << endl;
//    cin>>s;
//    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
//        DivideListIntoAandBByForwardAndBackward(CreateList("接下来将为您构建一个链表，首先需要您确定链表的节点个数(y / n)"));
//
//    cout << "对单链表去重，要演示吗？(y / n)" << endl;
//    cin>>s;
//    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
//        RemoveDuplicateNodeInList(CreateList("接下来将为您构建一个链表，首先需要您确定链表的节点个数(y / n)"));
//
//    cout << "就地合并两个有序单链表，要演示吗？(y / n)" << endl;
//    cin>>s;
//    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
//        MergeListsForward(CreateList("接下来将为您构建第二个链表，首先需要您确定链表的节点个数(y / n)"),
//                          CreateList("接下来将为您构建第一个链表，首先需要您确定链表的节点个数(y / n)"));
//
//    cout << "寻找A与B两个链表的交集并存于A链表中，要演示吗？(y / n)" << endl;
//    cin>>s;
//    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
//        FindListsIntersection(CreateList("接下来将为您构建第二个链表，首先需要您确定链表的节点个数(y / n)"),
//                              CreateList("接下来将为您构建第一个链表，首先需要您确定链表的节点个数(y / n)"));

    cout << "A为主串,B为子串的简陋方法模式匹配，要演示吗？(y / n)" << endl;
    cin>>s;
    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
        SimplePatternMatching(CreateList("接下来将为您构建第二个链表，首先需要您确定链表的节点个数(y / n)"),
                              CreateList("接下来将为您构建第一个链表，首先需要您确定链表的节点个数(y / n)"));


}

