/**
 *  2017程序设计夏季学期练习题 编程题＃5 古代密码
 *
 * @file: AncientRomanCipher.cpp
 * @description: 古罗马帝国有一个拥有各种部门的强大政府组织。其中一个部门就是保密服务部门。为了保险起见，在省与省之
                间传递的重要文件中的大写字母是加密的。当时最流行的加密方法是替换和重新排列。

                替换方法是将所有出现的字符替换成其它的字符。有些字符会替换成它自己。例如：替换规则可以是将 'A' 到
                'Y'替换成它的下一个字符，将 'Z' 替换成 'A'，如果原词是 "VICTORIOUS" 则它变成 "WJDUPSJPVT"。

                排列方法改变原来单词中字母的顺序。例如：将顺序 <2, 8=""> 应用到 "VICTORIOUS" 上，则得到
                "IVOTCIRSUO"。

                人们很快意识到单独应用替换方法或排列方法加密，都是很不保险的。但是如果结合这两种方法，在当时就可以得
                到非常可靠的加密方法。所以，很多重要信息先使用替换方法加密，再将加密的结果用排列的方法加密。用两种方
                法结合就可以将"VICTORIOUS" 加密成"JWPUDJSTVP"。

                考古学家最近在一个石台上发现了一些信息。初看起来它们毫无意义，所以有人设想它们可能是用替换和排列的方
                法被加密了。人们试着解读了石台上的密码，现在他们想检查解读的是否正确。他们需要一个计算机程序来验证，
                你的任务就是写这个验证程序。
 * @input: 输入有两行。第一行是石台上的文字。文字中没有空格，并且只有大写英文字母。第二行是被解读出来的加密前的文字。
        第二行也是由大写英文字母构成的。两行字符数目的长度都不超过 100。
 * @output: 如果第二行经过某种加密方法后可以产生第一行的信息，输出 "YES"，否则输出"NO"。
 * @sample_input:
    JWPUDJSTVP
    VICTORIOUS
 * @sample_output:
    YES
 * @note: 明文里的不同字母可能替换的间距不同，相同的字母一定替换成相同的。
 *
 * @author: Du Ang
 * @date: Sep. 2nd, 2017
 */

#include <iostream>
#include <algorithm>

using namespace std;

void getCount(int *a, string &s) {
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'A';
        a[c]++;
    }
}

bool isSame(int *a, int *b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    string plainString;
    string cipherString;
    cin >> cipherString;
    cin >> plainString;
    int plainCount[26] = {0};
    int cipherCount[26] = {0};
    getCount(cipherCount, cipherString);
    getCount(plainCount, plainString);
    sort(cipherCount, cipherCount + 26);    // not 25 here
    sort(plainCount, plainCount + 26);
    if (isSame(cipherCount, plainCount, 26)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
