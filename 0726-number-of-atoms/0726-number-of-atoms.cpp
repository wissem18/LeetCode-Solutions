class Solution {
public:
int index = 0;

map<string, int> parseFormula(string &formula) {
    map<string, int> currMap;
    string currAtom;
    string currCount;
    while (index < formula.length()) {
        if (isupper(formula[index])) {
            if (!currAtom.empty()) {
                if (currCount.empty()) {
                    currMap[currAtom] += 1;
                } else {
                    currMap[currAtom] += stoi(currCount);
                }
            }

            currAtom = formula[index];
            currCount = "";
            index++;
        } else if (islower(formula[index])) {
            currAtom += formula[index];
            index++;
        } else if (isdigit(formula[index])) {
            currCount += formula[index];
            index++;
        } else if (formula[index] == '(') {
            index++;
            map<string, int> nestedMap = parseFormula(formula);
            for (auto &[atom, count]: nestedMap) {
                currMap[atom] += count;
            }
        }
        else if (formula[index] == ')') {
            if (!currAtom.empty()) {
                if (currCount.empty()) {
                    currMap[currAtom] += 1;
                } else {
                    currMap[currAtom] += stoi(currCount);
                }
            }
            index++;
            string multiplier;
            while (index < formula.length() && isdigit(formula[index])) {
                multiplier += formula[index];
                index++;
            }
            if (!multiplier.empty()) {
                int mult = stoi(multiplier);
                for (auto &[atom, count]: currMap) {
                    currMap[atom] = count * mult;
                }
            }

            return currMap;
        }
    }

    if (!currAtom.empty()) {
        if (currCount.empty()) {
            currMap[currAtom] += 1;
        } else {
            currMap[currAtom] += stoi(currCount);
        }
    }

    return currMap;
}

string countOfAtoms(string formula) {
    map<string, int> finalMap = parseFormula(formula);
    string ans;
    for (auto &[atom, count]: finalMap) {
        ans += atom;
        if (count > 1) {
            ans += to_string(count);
        }
    }

    return ans;
}
};