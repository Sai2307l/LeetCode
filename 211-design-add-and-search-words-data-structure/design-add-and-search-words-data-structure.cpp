class WordDictionary {
public:
struct Trie{
    vector<Trie*> child = vector<Trie*>(26,nullptr);
    // string word="";
    bool end=false;
};
Trie* root1;
    WordDictionary() {
        root1=new Trie();
    }
    
    void addWord(string word1) {
        Trie* root=root1;
        for(auto i:word1){
            if(!root->child[i-'a']){root->child[i-'a']=new Trie();}
            root=root->child[i-'a'];
        }
        root->end=true;
    }
    bool dfs(int i , string &word1 ,Trie* root){
        char ch = word1[i];
        if (i == word1.size()) return root->end;
        bool b=false;
        if(ch=='.'){
            for(int j =0;j<26 ;j++){
                if(root->child[j]){b=(b|dfs(i+1,word1,root->child[j]));}
            }
        }
        else{
            if(root->child[ch-'a']){b=(b|dfs(i+1,word1,root->child[ch-'a']));}
        }
        return b;
    }    
    bool search(string word1) {
        Trie* root=root1;
        return dfs(0,word1,root);
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */