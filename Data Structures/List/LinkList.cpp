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
        ListNode(int x) : val(x), next(NULL) {}
    };

/**
 * ͷ�巨����������
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
 * ��ͷ��㵥����͵�����
 * ����P37 �ۺ���5
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
 * ��������������
 * ����P37 �ۺ���6
 * @return
 */
    void LinkListForwardSort(ListNode *L){
        ListNode *NL = new ListNode(-1);
        ListNode *p = L->next;
        cout << "ԭʼ���� ";
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
        cout << "�������������� ";
        while(p!=NULL){
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
    void DeleteNodeBtweenXandY(ListNode *L){
        int x, y;
        cout << "��������ҷ�Χ�Ͻ�X ";
        cin >> x;
        cout << "��������ҷ�Χ�½�Y ";
        cin >> y;
        if(L->next==NULL)
            return;
        ListNode *p = L->next;
        cout << "ԭʼ���� ";
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
        cout << "ɾ��������" << x << "��" << y << "֮��Ԫ�غ������ ";
        while(p!=NULL){
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
    void ForwardPrintList(ListNode *L){
        ListNode *p = L->next;
        if(p == NULL){
            cout << "���Ǹ��ձ�";
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
 * ��������ż˳���ֳ���������
 * ����P37 �ۺ���10
 * @return
 */
    void DivideListIntoAandB(ListNode *L){
        ListNode *A = new ListNode(-1);
        ListNode *q = A;
        ListNode *B = new ListNode(-1);
        ListNode *r = B;
        ListNode *p = L->next;
        if(p == NULL){
            cout << "����һ���ձ�" << endl;
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
        cout << "����ָ�����:" << endl << "A: ";
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
 * ��������˳��ż�����ֳ���������
 * ����P37 �ۺ���11
 * @param L
 */
    void DivideListIntoAandBByForwardAndBackward(ListNode *L){
        ListNode *A = new ListNode(-1);
        ListNode *q = A;
        ListNode *B = new ListNode(-1);
        ListNode *p = L->next;
        if(p == NULL){
            cout << "����һ���ձ�" << endl;
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
        cout << "����ָ�����:" << endl << "A: ";
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
 * �Ե�����ȥ��
 * ����P37 �ۺ���12
 * @param L
 */
    void RemoveDuplicateNodeInList(ListNode *L){
        ListNode *p = L->next;
        ListNode *pre = p;
        if(p == NULL){
            cout << "����һ��������" << endl;
            return;
        }
//    if(p->next == NULL){
//        cout << "ȥ�غ������:" << "->" << p->val << endl;
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
        cout << "ȥ�غ������: ";
        while(p != NULL){
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
    void MergeListsForward(ListNode *L1, ListNode *L2){
        ListNode *p = L1->next, *pre1 = L1;
        ListNode *q = L2->next, *pre2 = L2;
        if(p == NULL || q == NULL){
            cout << "���ڿ�����, ����ϲ�" << endl;
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
        cout << "�ϲ��������: ";
        while(p != NULL){
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
    void FindListsIntersection(ListNode *L1, ListNode *L2){
        ListNode *p = L1->next, *q = L2->next, *pre = L1;
        if(p == NULL || q == NULL){
            cout << "���ڿ�����, ����Ϊ��" << endl;
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
        cout << "��������Ľ���Ϊ: ";
        while(p != NULL){
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
    void SimplePatternMatching(ListNode *B, ListNode *A){
        ListNode *p = A->next, *q = B->next, *pre = A;
        if(p == NULL || q == NULL){
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


public:
    int run(){
        string s = "";
        string yes = "y";

    cout << "����ľ͵����ã�Ҫ��ʾ��(y / n) ";
    cin>>s;
    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
        ReversLink(CreateList("��������Ϊ������һ������������Ҫ��ȷ������Ľڵ����(y / n)"));

    cout << "�������������Ҫ��ʾ��(y / n)";
    cin>>s;
    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
        LinkListForwardSort(CreateList("��������Ϊ������һ������������Ҫ��ȷ������Ľڵ����(y / n)"));

    cout << "ɾ����������ֵ����x��y֮��Ľڵ㣬Ҫ��ʾ��(y / n)";
    cin>>s;
    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
        DeleteNodeBtweenXandY(CreateList("��������Ϊ������һ������������Ҫ��ȷ������Ľڵ����(y / n)"));

    cout << "������������Ĺ����ڵ㣬Ҫ��ʾ��(y / n)" << endl;
    cin>>s;
    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
        FindFirstCommonNode(CreateList("��������Ϊ�������ڶ�������������Ҫ��ȷ������Ľڵ����(y / n)"),
                            CreateList("��������Ϊ��������һ������������Ҫ��ȷ������Ľڵ����(y / n)"));

    cout << "������˳���ӡ���������нڵ㣬Ҫ��ʾ��(y / n)" << endl;
    cin>>s;
    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
        ForwardPrintList(CreateList("��������Ϊ������һ������������Ҫ��ȷ������Ľڵ����(y / n)"));

    cout << "��������ż˳���ֳ���������Ҫ��ʾ��(y / n)" << endl;
    cin>>s;
    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
        DivideListIntoAandB(CreateList("��������Ϊ������һ������������Ҫ��ȷ������Ľڵ����(y / n)"));

    cout << "��������˳��ż�����ֳ���������Ҫ��ʾ��(y / n)" << endl;
    cin>>s;
    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
        DivideListIntoAandBByForwardAndBackward(CreateList("��������Ϊ������һ������������Ҫ��ȷ������Ľڵ����(y / n)"));

    cout << "�Ե�����ȥ�أ�Ҫ��ʾ��(y / n)" << endl;
    cin>>s;
    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
        RemoveDuplicateNodeInList(CreateList("��������Ϊ������һ������������Ҫ��ȷ������Ľڵ����(y / n)"));

    cout << "�͵غϲ�������������Ҫ��ʾ��(y / n)" << endl;
    cin>>s;
    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
        MergeListsForward(CreateList("��������Ϊ�������ڶ�������������Ҫ��ȷ������Ľڵ����(y / n)"),
                          CreateList("��������Ϊ��������һ������������Ҫ��ȷ������Ľڵ����(y / n)"));

    cout << "Ѱ��A��B��������Ľ���������A�����У�Ҫ��ʾ��(y / n)" << endl;
    cin>>s;
    if(strcasecmp(s.c_str(), yes.c_str()) == 0)
        FindListsIntersection(CreateList("��������Ϊ�������ڶ�������������Ҫ��ȷ������Ľڵ����(y / n)"),
                              CreateList("��������Ϊ��������һ������������Ҫ��ȷ������Ľڵ����(y / n)"));

        cout << "AΪ����,BΪ�Ӵ��ļ�ª����ģʽƥ�䣬Ҫ��ʾ��(y / n)" << endl;
        cin>>s;
        if(strcasecmp(s.c_str(), yes.c_str()) == 0)
            SimplePatternMatching(CreateList("��������Ϊ�������ڶ�������������Ҫ��ȷ������Ľڵ����(y / n)"),
                                  CreateList("��������Ϊ��������һ������������Ҫ��ȷ������Ľڵ����(y / n)"));

        return 1;
    }
};
