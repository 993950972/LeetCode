/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/
/*
算法思想：前缀树，也叫字典树。其数据结构很简单，next数组，is_word标记，其中next数组记录的是其孩子节点，is_word标记当前单词是否结束。
字典树一般使用在单词的快速查找上。
*/
class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;
    
    // Initialize your data structure here.
    TrieNode()
    {
        memset(next, NULL, sizeof(next));
        is_word = false;
    }
};
class Trie {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *run = root;
        for(int i = 0;i < word.size();i++)
        {
            if(run->next[word[i] - 'a'] == NULL)
                run->next[word[i] - 'a'] = new TrieNode();
            run = run->next[word[i] - 'a'];
        }
        run->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *run = root;
        for(int i = 0;i < word.size();i++)
        {
            if(run->next[word[i] - 'a'] == NULL)
                return false;
            run = run->next[word[i] - 'a'];
        }
        return run->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* run = root;
        for(int i = 0;i < prefix.size();i++)
        {
            if(run->next[prefix[i] - 'a'] == NULL)
                return false;
            run = run->next[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */