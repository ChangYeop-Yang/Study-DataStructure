## ⌘ C++ String Split Method

```C++
vector<string> split(const string message, const char letter) {
    
    // MARK: - Variables
    string splitMessage;
    vector<string> bucket;
    
    for (int index = 0, length = message.length(); true; index++) {
        
        if (length <= index) { bucket.push_back(splitMessage); break; }
        
        /* Compare Message With Letter - False */
        const char character = message.at(index);
        if (character != letter) { splitMessage.push_back(character); continue; }
        
        /* Compare Message with Letter - True */
        if (!splitMessage.empty()) {
            bucket.push_back(splitMessage);
            splitMessage.clear();
        }
    }
    
    return bucket;
}
```

## ⌘ C++ My String Type
