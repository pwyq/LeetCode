// This is also a interview problem on system design
// thanks dalao for long post
class Solution {
private:
    std::unordered_map<string, string> code_url;
    std::unordered_map<string, string> url_code;
    const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device rd;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code;
        if (url_code.count(longUrl) == 0) {
			for (int i = 0; i < 6; i++)
				code.push_back(charset[rd() % charset.size()]);
            url_code[longUrl] = code;
            code_url[code] = longUrl;
        }
        else
            code = url_code[longUrl];
        return "http://tinyurl.com/" + code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
		if (shortUrl.size() != 25 || !code_url.count(shortUrl.substr(19, 6)))
			return "";
		return code_url[shortUrl.substr(19, 6)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));