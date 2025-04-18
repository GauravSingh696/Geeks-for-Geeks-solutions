class Trie {
  public:
    struct trieNode{
        bool isEndOfWord;
        trieNode* children[26];
    };
    
    trieNode* getNode() {
        trieNode* new_node = new trieNode();
        
        new_node->isEndOfWord = false;
        
        for(int i=0;i<26;i++) {
            new_node->children[i] = false;
        }
        
        return new_node;
    }
    
    trieNode *root;

    Trie() {
        root = getNode();
    }

    void insert(string &word) {
        trieNode *crawler = root;
        
        for(int i=0;i<word.size();i++) {
            char ch = word[i];
            int idx = ch-'a';
            
            if(crawler->children[idx] == NULL) {
                crawler->children[idx] = getNode();
            }
            
            crawler = crawler->children[idx];
        }
        
        crawler->isEndOfWord = true;
    }

    bool search(string &word) {
        trieNode *crawler = root;
        
        for(int i=0;i<word.size();i++) {
            char ch = word[i];
            int idx = ch-'a';
            
            if(crawler->children[idx] == NULL)
                return false;
            
            crawler = crawler->children[idx];
        }
        
        if(crawler->isEndOfWord)
            return true;
        
        return false;
    }

    bool isPrefix(string &word) {
        trieNode *crawler = root;
        int i=0;
        
        for(;i<word.size();i++) {
            char ch = word[i];
            int idx = ch-'a';
            
            if(crawler->children[idx] == NULL)
                return false;
            
            crawler = crawler->children[idx];
        }
        return true;
    }
};
