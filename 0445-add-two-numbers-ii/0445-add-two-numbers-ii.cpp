/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
string sum(string s1,string s2 ){
if(s1.length()>s2.length()){
while(s2.length()<s1.length()){
s2="0"+s2;
}
}

if(s2.length()>s1.length()){
while(s1.length()<s2.length()){
s1="0"+s1;
}
}

int carry=0;
string res="";
string s;

for (int i = s1.length()-1; i >0 ; --i) {
if((s1[i]-'0')+(s2[i]-'0')+carry<10){
res+='0'+(s1[i]-'0')+(s2[i]-'0')+carry;
carry=0;
}

else{
res+=to_string(((s1[i]-'0')+(s2[i]-'0')+carry)-10);
carry=1;
}
}

reverse(res.begin(),res.end());
s=to_string((s1[0]-'0')+(s2[0]-'0')+carry) +res;
return s;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       string s1,s2;
       while(l1!=NULL){
           s1+=char(l1->val+'0');
           l1=l1->next;
       }
        while(l2!=NULL){
           s2+=char(l2->val+'0');
           l2=l2->next;
       }
        ListNode* l=new ListNode();
        ListNode*cur=l;
        string s=sum(s1,s2);
        int i=0;
        while(i<s.size()){
            cur->val=s[i]-'0';
            if(i!=s.size()-1){
            cur->next=new ListNode();
            cur=cur->next;
            }
            i++;
        }
        return l;
    }
};