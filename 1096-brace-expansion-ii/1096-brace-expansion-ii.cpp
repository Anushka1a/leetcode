class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> result;
        set<string> current;
        current.insert("");

        while (i < s.size() && s[i] != '}') {
            
            if (s[i] == ',') {
                for (string x : current)
                    result.insert(x);

                current.clear();
                current.insert("");
                i++;
            }
            
            else if (s[i] == '{') {
                i++;

                set<string> inside = parse(s, i);

                i++; // skip '}'

                set<string> temp;

                for (string x : current) {
                    for (string y : inside) {
                        temp.insert(x + y);
                    }
                }

                current = temp;
            }
            
            else {
                char c = s[i];

                set<string> temp;

                for (string x : current) {
                    temp.insert(x + c);
                }

                current = temp;
                i++;
            }
        }

        for (string x : current)
            result.insert(x);

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};