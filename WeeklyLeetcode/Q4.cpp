#include <bits/stdc++.h>
using namespace std;
using i64 = unsigned long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template <int BASE = 131>
struct StringRollingHash {
    std::vector<i64> hash, base, mod;

    StringRollingHash(const std::string& s = "") {
        int n = s.size();
        hash.resize(n + 1);
        base.resize(n + 1);
        mod.resize(n + 1);
        base[0] = 1;
        mod[0] = 1;
        for (int i = 1; i <= n; i++) {
            base[i] = (base[i - 1] * BASE);
        }
        for (int i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * BASE + s[i]);
        }
    }

    i64 get(int l, int r) {
        return (hash[r] - (hash[l] * base[r - l]));
    }

    i64 get(const std::string& s) {
        i64 h = 0;
        for (char c : s) {
            h = (h * BASE + c);
        }
        return h;
    }

    bool isprime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }

    int findPrime(int n) {
        while (!isprime(n))
            n++;
        return n;
    }
};

constexpr int sq = 100;

class Solution {
   public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int n = target.size();
        int m = words.size();
        vector<i64> dp(n + 1, 1e9);
        vector<pair<i64, int>> big;
        map<i64, int> small;
        StringRollingHash<> srh(target);
        for (int i = 0; i < m; i++) {
            if (words[i].size() <= sq) {
                if (small.find(srh.get(words[i])) == small.end()) {
                    small[srh.get(words[i])] = costs[i];
                } else {
                    small[srh.get(words[i])] = min(small[srh.get(words[i])], costs[i]);
                }
            } else {
                big.emplace_back(srh.get(words[i]), i);
            }
        }
        debug(big);
        for (auto [h, i] : big) {
            debug(words[i], costs[i]);
        }
        for (auto [h, i] : small) {
            debug(h, i);
        }
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j <= min(i + sq, n); j++) {
                if (small.find(srh.get(i, j)) != small.end()) {
                    dp[i] = min(dp[i], dp[j] + small[srh.get(i, j)]);
                }
            }
            for (auto& [h, idx] : big) {
                if (i + words[idx].size() <= n) {
                    if (h == srh.get(i, i + words[idx].size())) {
                        dp[i] = min(dp[i], dp[i + words[idx].size()] + costs[idx]);
                    }
                }
            }
        }
        return dp[0] == 1e9 ? -1 : dp[0];
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    Solution sol;
    // target = "abcdef", words = ["abdef", "abc", "d", "def", "ef"],
    // costs = [100, 1, 1, 10, 5]
    string target = "abcdef";
    vector<string> words = {"abdef", "abc", "d", "def", "ef"};
    vector<int> costs = {100, 1, 1, 10, 5};
    cout << sol.minimumCost(target, words, costs) << endl;
    debug("");

    // target = "aaaa", words = ["z","zz","zzz"], costs = [1,10,100]
    target = "aaaa";
    words = {"z", "zz", "zzz"};
    costs = {1, 10, 100};
    // cout << sol.minimumCost(target, words, costs) << endl;

    target =
        "tjtornevodvexwkrursbtuycuzouthfbgkyrxiekefazajqaeezkoklimdldgornzscewhzyzhqrjkziaxvgqntlrasfgfbpgukeimcoapotxd"
        "ufjyiyurwznrrxtprcqrpklmprqbwlkigvxqdfkbmduxhkdaxjnnyddlvwfmlrebxeaeorqmpjeoqojtvohvdwknkjetlqixnbdopcabrehbjw"
        "bncbvlvulanogpexzdrjpkeoftqfdohzpebzbsfjnozqnvuituiugtdahdgjcwpitgtddusrbiwwdmuzdhlkxriurtwgkdpspunykmeivqryit"
        "pgkscqllkdqqgdhnqodqwwqofrslvmqbgltbegymlrzmcyuybxhmeniuwglpyqyntskrryuzfwvjwctgzkuwyidmagzhguypqaqnvgzlhsxmig"
        "farxboeeocdounvwncyywuscuhskoaoskmtnnjvextnbzffkzjufxqxociobheuhgswhwgaryuholwdjzqmkxkrzueqefyxmkqlryortlzldjs"
        "oqclbdnltokxfymtrbtinxhgzoghgvwmohmcwujyqnrrapvphiazlczbnnpgbgptnqwqzxohgsycmwipyutnzcaecwryoccnskcfobuhtzkwug"
        "rteloidkaolzfhtvkvjfwrhzkhjcxdasvxbbvecxvnidbkcdfmxrpkginlmtoyhlfcmfdfgmcmrudzdjwikgpfqtdsotsgmextillmzpcdolkd"
        "hrfxpbsicwppatupugdxlpuhjssymvjhuvejzkbuwzojnqymmeprliarunawcjlaonvmttibsheqxtnzihzqppwoxdaeokiwopemrclwipcwbi"
        "myumbelyahxkisuvttpwubxguulgujiplidfquonwdqoliiljmegzpdxfracvpctxvbrpbtzkozmlifwegvhjzmkkmwwivvdwyhkkkvulpmbds"
        "imebzpmcnzqjluwwtgnjochvupnccugoqkvyyngkdypedmxtuvbtjirpsuicaylkihvocllqovuggimimnhumfpbusbiasgypwozuoxsqzfwix"
        "ehteiohipqwishtjmuyvbnsuysgygvchlxvubphzuduckdclijkkxmgkobhhoxcgrodxnyoqrlasjlqzzcwkshpapqggxrgfnnajwiynpedqgb"
        "lpmylotzahfaautrtejqkhwgrgkakqpkzmiffbqdkbviroburcqzhvbwxpydaivxhigqnvexnitgbxrjkygkhqvbwdcfdpkearcnoblpepihv";
    words = {
        "chvupnccugoqkvyyngkdypedmxtuvbtjirpsuicaylkihvocllqovuggimimnhumfpbusbiasgypwozuoxsqzfwixehteiohipqwishtjmuyvb"
        "ns"
        "uysgygvchlxvubphzuduckdclijkkxmgkobhhoxcgrodxnyoqrlasjlqzzcwkshpapqggxrgf",
        "ivqryitpgkscqllkdqqgdhnqodqwwqofrslvmqbgltbegymlrzmcyuybxhmeniuwglpyqyntskrryuzfwvjwctgzkuwyidmagzhguypqaqnvgz"
        "lh"
        "sxmigfarxboeeocdounvwncyywuscuhskoaoskmtnnjvextnbzffkzjufxqxociobheuhgswhwgaryuholwdjzqmkxkrzueqefyxmkqlryortl"
        "zl"
        "djsoqclbdnltokxfymtrbtinxhgzoghgvwmohmcwujyqnrrapvphiazlczbnnpgbgptnqwqzxohgsycmwipyutnzcaecwryoccnskcfobuhtzk"
        "wu"
        "grteloidkaolzfhtvkvjfwrhzkhjcxdasvxbbvecxvnidbkcdfmxrpkginlmtoyhlfcmfdfgmcmrudzdjwikgpfqtdsotsgmextillmzpcdolk"
        "dh"
        "rfxpbsicwppatupugdxlpuhjssymvjhuvejzkbuwzojnqymmeprliarunawcjlaonvmttibsheqxtnzihzqppwoxdaeokiwopemrclwipcwbim"
        "yu"
        "mbelyahxkisuvttpwubxguulgujiplidfquonwdqoliiljmegzpdxfracvpctxvbrpbtzkozmlifwegvhjzmkkmwwivvdwyhkkkvulpmbdsime"
        "bz"
        "pmcnzqjluwwtgnjochvupnccugoqkvyyngkdypedmxtuvbtjirpsuicaylkihvocllqovuggimimnhumfpbusbiasgypwozuoxsqzfwixehtei"
        "oh"
        "ipqwishtjmuyvbnsuysgygvchlxvubphzuduckdclijkkxmgkobhhoxcgrodxnyoqrlasjlq",
        "gvhjzmkkmwwivvdwyhkkkvulpmbdsimebzpmcnzqjluwwtgnjochvupnccugoqkvyyngkdypedmxtuvbtjirpsuicaylkihvocllqovuggimim"
        "nh"
        "umfpbusbiasgypwozuoxsqzfwixehteiohipqwishtjmuyvbnsuysgygvchlxvubphzuduckdclijkkxmgkobhh",
        "caecwryoccnskcfobuhtzkwugrteloidkaolzfhtvkvjfwrhzkhjcxdasvxbbvec",
        "mcyuybxhmeniuwglpyqyntskrryuzfwvjwctgzkuwyidmagzhguypqaqnvgzlhsxmigfarxboeeocdounvwncyywuscuhskoaoskmtnnjvextn"
        "bz"
        "ffkzjufxqxociobheuhgswhwgaryuholwdjzqmkxkrzueqefyxmkqlryortlzldjsoqclbdnltokxfymtrbtinxhgzoghgvwmohmcwujyqnrra"
        "pv"
        "phiazlczbnnpgbgptnqwqzxohgsycmwipyutnzcaecwryoccnskcfobuhtzkwugrteloidkaolzfhtvkvjfwrhzkhjcxdasvxbbvecxvnidbkc"
        "df"
        "mxrpkginlmtoyhlfcmfdfgmcmrudzdjwikgpfqtdsotsgmextillmzpcdolkdhrfxpbsicwppatupugdxlpuhjssymvjhuvejzkbuwzojnqymm"
        "ep"
        "rliarunawcjlaonvmttibsheqxtnzihzqppwoxdaeokiwopemrclwipcwbimyumbelyahxkisuvttpwubxguulgujiplidfquonwdqoliiljme"
        "gz"
        "pdxfracvpctxvbrpbtzkozmlifwegvhjzmkkmwwivvdwyhkkkvulpmbdsimebzpmcnzqjluwwtgnjochvupnccugoqkvyyngkdypedmxtuvbtj"
        "ir"
        "psuicaylkihvocllqovuggimimnhumfpbusbiasgypwozuoxsqzfwixehteiohipqwishtjmuyvbnsuysgygvchlxvubphzuduc",
        "bhhoxcgrodxnyoqrlasjlqzzcwkshpapqggxrgfnnajwiynpedqgblpmylotzahfaautrtejqkhwgrgkakqpkzmiffbqdkbviroburcqzhvbwx"
        "py"
        "daivxhigqnvexnitgbxrjkygkhqvbwdcfdpkearcnoblpepihv",
        "dldgornzscewhzyzhqrjkziaxvgqntlrasfgfbpgukeimcoapotxdufjyiyurwznrrxtprcqrpklmprqbwlkigvxqdfkbmduxhkdaxjnnyddlv"
        "wf"
        "mlrebxeaeorqmpjeoqojtvohvdwknkjetlqixnbdopcabrehbjwbncbvlvulanogpexzdrjpkeoftqfdohzpebzbsfjnozqnvuituiugtdahdg"
        "jc"
        "wpitgtddusrbiwwdmuzdhlkxriurtwgkdpspunykmeivqryitpgkscqllkdqqgdhnqodqwwqofrslvmqbgltbegymlrzmcyuybxhmeniuwglpy"
        "qy"
        "ntskrryuzfwvjwctgzkuwyidmagzhguypqaqnvgzlhsxmigfarxboeeocdounvwncyywuscuhskoaoskmtnnjvextnbzffkzjufxqxociobheu"
        "hg"
        "swhwgaryuholwdjzqmkxkrzueqefyxmkqlryortlzldjsoqclbdnltokxfymtrbtinxhgzoghgvwmohmcwujyqnrrapvphiazlczbnnpgbgptn"
        "qw"
        "qzxohgsycmwipyutnzcaecwryoccnskcfobuhtzkwugrteloidkaolzfhtvkvjfwrhzkhjcxdasvxbbvecxvnidbkcdfmxrpkginlmtoyhlfcm"
        "fd"
        "fgmcmrudzdjwikgpfqtdsotsgmextillmzpcdolkdhrfxpbsicwppatupugdxlpuhjssymvjhuvejzkbuwzojnqymmeprliarunawcjlaonvmt"
        "t"
        "i",
        "urtwgkdpspunykmeivqryitpgkscqllkdqqgdhnqodqwwqofrslvmqbgltbegymlrzmcyuybxhmeniuwglpyqyntskrryuzfwvjwctgzkuwyid"
        "ma"
        "gzhguypqaqnvgzlhsxmigfarxboeeocdounvwncyywuscuhskoaoskmtnnjvextnbzffkzjufxqxociobheuhgswhwgaryuholwdjzqmkxkrzu"
        "eq"
        "efyxmkqlryortlzldjsoqclbdnltokxfymtrbtinxhgzoghgvwmohmcwujyqnrrapvphiazlczbnnpgbgptnqwqzxohgsycmwipyutnzcaecwr"
        "yo"
        "ccnskcfobuhtzkwugrteloidkaolz",
        "rapvphiazlczbnnpgbgptnqwqzxohgsycmwipyutnzcaecwryoccnskcfobuhtzkwugrteloidkao",
        "odqwwqofrslvmqbgltbegymlrzmcyuybxhmeniuwglpyqyntskrryuzfwvjwctgzkuwyidmagzhguypqaqnvgzlhsxmigfarxboeeocdounvwn"
        "cy"
        "ywuscuhskoaoskmtnnjvextnbzffkzjufxqxociobheuhgswhwgaryuholwdjzqmkxkrzueqefyxmkqlryortlzldjsoqclbdnltokxfymtrbt"
        "in"
        "xhgzoghgvw",
        "ymvjhuvejzkbuwzojnqymmeprliarunawcjlaonvmttibsheqxtnzihzqppwoxdaeokiwopemrclwipcwbimyumbelyahxkisuvttpwubxguul"
        "gu"
        "jiplidfquonwdqoliiljmegzpdxfracvpctxvbrpbtzkozmlifwegvhjzmkkmwwivvdwyhkkkvulpmbdsimebzpmcnzqjluwwtgnjochvupncc"
        "ug"
        "oqkvyyngkdypedmxtuvbtjirpsuicaylkihvocllqovugg",
        "obheuhgswhwgaryuholwdjzqmkxkrzueqefyxmkqlryortlzldjsoqclbdnltokxfymtrbtinxhgzoghgvwmohmcwujyqnrrapvphiazlczbnn"
        "pg"
        "bgptnqwqzxohgsycmwipyutnzcaecwryoccnskcfobuhtzkwugrteloidkaolzfhtvkvjfwrhzkhjcxdasvxbbvecxvnidbkcdfmxrpkginlmt"
        "oy"
        "hlfcmfdfgmcmrudzdjwikgpfqtdsotsgmextillmzpcdolkdhrfxpbsicwppatupugdxlpuhjssymvjhuvejzkbuwzojnqymmeprliarunawcj"
        "la"
        "onvmttibsheqxtnzihzqppwoxdaeokiwopemrclwipcwbimyumbelyahxkisuvttpwubxguulgujiplidfquonwdqoliiljmegzpdxfracvpct"
        "xv"
        "brpbtzkozmlifwegvhjzmkkmwwivvdwyhkkkvulpmbdsimebzpmcnzqjluwwtgnjochvupnccugoqkvyyngkdypedmxtuvbtjirpsuicaylkih"
        "vo"
        "cllqovuggimimnhumfpbusbiasgypwozuoxsqzfwi",
        "jluwwtgnjochvupnccugoqkvyyngkdypedmxtuvbtjirpsuicaylkihvocllqovuggimimnhumfpbusbiasgypwozuoxsq",
        "apqggxrgfnnajwiynpedqgblpmylotzahfaa",
        "nsuysgygvchlxvubphzuduckdclijkkxmgko",
        "obuhtzkwugrteloidkaolzfhtvkvjfwrhzkhjcxdasvxbbvecxvnidbkcdfmxrpkginlmtoyhlfcmfdfgmcmrudzdjwikgpfqtdsotsgmextil"
        "lm"
        "zpcdolkdhrfxpbsicwppatupugdxlpuhjssymvjhuvejzkbuwzojnqymmeprliarunawcjlaonvmttibsheqxtnzihzqppwoxdaeokiwopemrc"
        "lw"
        "ipcwbimyumbelyahxkisuvttpwubxguulgujiplidfquonwdqoliiljmegzpdxfracv",
        "wegvhjzmkkmwwivvdwyhkkkvulpmbdsimebzpmcnzqjluwwtgnjochvupnccugoqkvyyngkdypedmxtuvbtjirpsuicaylkihvocllqovuggim"
        "im"
        "nhumfpbusbiasgypwozuoxsqzfwixehteiohipqwishtjmuyvbnsuysgygvchlxvubphzuduckdclijk",
        "tjtornevodvexwkrursbtuycuzouthfbgkyrxiekefazajqaeezkoklimdldgornzscewhzyzhqrjkziaxvgqntlrasfgfbpgukeimcoapotxd"
        "uf"
        "jyiyurwznrrxtprcqrpklmprqbwlkigvxqdfkbmduxhkdaxjnnyddlvwfmlrebxeaeorqmpjeoqojtvohvdwknkjetlqixnbdopcabrehbjwbn"
        "cb"
        "vlvulanogpexzdrjpkeoftqfdohzpebzbsfjnozqnvuituiugtdahdgjcwpitgtddusrbiwwdmuzdhlkxriurtwgkdpspunykmeivqryitpgks"
        "cq"
        "llkdqqgdhnqodqwwqofrslvmqbgltbegymlrzmcyuybxhmeniuwglpyqyntskrryuzfwvjwctgzkuwyidmagzhguypqaqnvgzlhsxmigfarxbo"
        "ee"
        "ocdounvwncyywuscuhskoaoskmtnnjvextnbzffkzjufxqxociobheuhgswhwgaryuholwdjzqmkxkrzueqefyxmkqlryortlzldjsoqclbdnl"
        "to"
        "kxfymtrbtinxhgzoghgvwmohmcwujyqnrrapvphiazlczbnnpgbgptnqwqzxohgsycmwipyutnzcaecwryoccnskcfobuhtzkwugrteloidkao"
        "lz"
        "fhtvkvjfwrhzkhjcxdasvxbbvecxvnidbkcdfmxrpkginlmtoyhlfcmfdfgmcmrudzdjwikgpfqtdsotsgmextillmzpcdolkdhrfxpbsicwpp"
        "at"
        "upugdxlpuhjssymvjhuvejzkbuwzojnqymmeprliarunawcjlaonvmttibsheqxtnzihzqppwoxdaeokiwopemrclwipcwbimyumbelyahxkis"
        "uv"
        "ttpwubxguulgujiplidfquonwdqoliiljmegzpdxfracvpctxvbrpbtzkozmlifwegvhjzmkkmwwivvdwyhkkkvulpmbdsimebzpmcnzqjluww"
        "tg"
        "njochvupnccugoqkvyyngkdypedmxtuvbtjirpsuicaylkihvocllqovuggimimnhumfpbusbiasgypwozuoxsqzfwixehteiohipqwishtjmu"
        "yv"
        "bnsuysgygvchlxvubphzuduckdclijkkxmgko",
        "dgjcwpitgtddusrbiwwdmuzdhlkxriurtwgkdpspunykmeivqryitpgkscqllkdqqgdhnqodqwwqofrslvmqbgltbegymlrzmcyuybxhmeniuw"
        "gl"
        "pyqyntskrryuzfwvjwctgzkuwyidmagzhguypqaqnvgzlhsxmigfarxboeeocdounvwncyywuscuhskoaoskmtnnjvextnbzffkzjufxqxocio"
        "bh"
        "euhgswhwgary"};
    costs = {1557, 1582, 2271, 1157, 877,  1137, 1555, 832,  2060, 1447,
             954,  1473, 1676, 2283, 2530, 765,  1387, 1036, 2346};
    cout << sol.minimumCost(target, words, costs) << endl;
    // "ababababab"
    // ["ab", "abab", "babab"][2, 2, 5]
    target = "ababababab";
    words = {"ab", "abab", "babab"};
    costs = {2, 2, 5};
    cout << sol.minimumCost(target, words, costs) << endl;
    return 0;
}