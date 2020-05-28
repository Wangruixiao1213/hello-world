{\rtf1\ansi\ansicpg936\cocoartf2511
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;\f1\fnil\fcharset134 PingFangSC-Regular;}
{\colortbl;\red255\green255\blue255;\red109\green109\blue109;\red32\green32\blue32;\red173\green169\blue32;
\red88\green118\blue71;\red125\green122\blue28;\red86\green132\blue173;\red191\green100\blue38;\red166\green165\blue220;
\red153\green168\blue186;\red254\green187\blue91;\red171\green173\blue198;\red128\green93\blue148;\red78\green122\blue119;
}
{\*\expandedcolortbl;;\csgenericrgb\c42745\c42745\c42745;\csgenericrgb\c12549\c12549\c12549;\csgenericrgb\c67843\c66275\c12549;
\csgenericrgb\c34510\c46275\c27843;\csgenericrgb\c49020\c47843\c10980;\csgenericrgb\c33725\c51765\c67843;\csgenericrgb\c74902\c39216\c14902;\csgenericrgb\c65098\c64706\c86275;
\csgenericrgb\c60000\c65882\c72941;\csgenericrgb\c99608\c73333\c35686;\csgenericrgb\c67059\c67843\c77647;\csgenericrgb\c50196\c36471\c58039;\csgenericrgb\c30588\c47843\c46667;
}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx560\tx1120\tx1680\tx2240\tx2800\tx3360\tx3920\tx4480\tx5040\tx5600\tx6160\tx6720\pardirnatural\partightenfactor0

\f0\fs24 \cf2 \cb3 //
\f1 \'d7\'f7\'d2\'b5\'a3\'ba\'b4\'f3\'d5\'fb\'ca\'fd\'a3\'ac\'b1\'c8\'c8\'e7
\f0 9081321110693270343633073697474256143563558458718976746753830538032062222085722974121768604305613921745580037409259811952655310075487163797179490457039169594160088430571674960498834085812920457916453747019461644031395307920624947349951053530086146486307198155590763466429392673709525428510973272600608981219760099374675982933766845473509473676470788342281338779191792495900393751209539300628363443012 6538005862664913074813656220643842443844131905754565672075358391135537108795991638155474452610874309742867231360502542308382199053675592825240788613991898567277116881793749340807728335795394301261629479870548736450984003401594705923178314906195914825136973281314862289454100745237769034410057080703111299605127114594552921209928891515242515620324828055912854227507525717981351447473570262981491527798\
//
\f1 \'d6\'d8\'d0\'c2\'c9\'e8\'bc\'c6\'cf\'c2\'c3\'e6\'b5\'c4\'b4\'fa\'c2\'eb\'a3\'ac\'ca\'b9\'c6\'e4\'bf\'c9\'d2\'d4\'b4\'a6\'c0\'ed\'b4\'f3\'d5\'fb\'ca\'fd\'b5\'c4\'cb\'d8\'ca\'fd\'d3\'eb\'b3\'ac\'bc\'b6\'cb\'d8\'ca\'fd
\f0 \
//
\f1 \'cd\'ac\'ca\'b1\'d7\'d0\'cf\'b8\'c0\'ed\'bd\'e2\'c3\'e6\'cf\'f2\'b6\'d4\'cf\'f3\'b5\'c4\'b1\'e0\'b3\'cc\'b7\'bd\'ca\'bd
\f0 \
\cf4 #include\cf5 <iostream>\
\cf4 #include\cf5 <string>\
\cf4 #define \cf6 MAX \cf7 100\
\cf8 using namespace \cf9 std\cf8 ;\
class \cf9 BigInt \cf10 \{\
\cf8 public\cf10 :\
    \cf11 BigInt\cf10 () \{\
    \}\
    \cf11 BigInt\cf10 (\cf12 string \cf10 num) \{\
        \cf8 this\cf10 ->\cf13 num\cf10 .resize(num.size())\cf8 ;\
        for \cf10 (\cf8 int \cf10 i = \cf7 0\cf8 ; \cf10 i < num.length()\cf8 ; \cf10 i++) \{\
            \cf8 this\cf10 ->\cf13 num\cf14 [\cf10 i] = num\cf14 [\cf10 i] - \cf5 '0'\cf8 ;\
        \cf10 \}\
    \}\
    \cf11 BigInt\cf10 (\cf8 int \cf10 lenth) \{\
        \cf13 num\cf10 .resize(\cf13 num\cf10 .size()+lenth)\cf8 ;\
        \cf13 num\cf10 .replace(\cf7 0\cf8 , \cf10 lenth\cf8 , \cf10 lenth\cf8 , \cf7 0\cf10 )\cf8 ;\
    \cf10 \}\
    \cf11 ~BigInt\cf10 () \{\
    \}\
    \cf8 friend \cf9 BigInt \cf14 operator\cf10 - (\cf9 BigInt \cf10 a\cf8 ,int \cf10 b)\cf8 ;\
    friend \cf9 BigInt \cf14 operator\cf10 * (\cf9 BigInt \cf10 a\cf8 , \cf9 BigInt \cf10 b)\cf8 ;\
    friend \cf9 BigInt \cf14 operator\cf10 / (\cf9 BigInt \cf10 a\cf8 , \cf9 BigInt \cf10 b)\cf8 ;\
    friend \cf9 BigInt \cf14 operator\cf10 % (\cf9 BigInt \cf10 a\cf8 , \cf9 BigInt \cf10 b)\cf8 ;\
\
\
\
    \cf12 string \cf13 num\cf8 ;\
private\cf10 :\
    \cf9 BigInt \cf11 sub\cf10 (\cf9 BigInt \cf10 a\cf8 , \cf9 BigInt \cf10 b) \{\
        \cf8 int \cf10 len_a = a.\cf13 num\cf10 .size()\cf8 , \cf10 len_b = b.\cf13 num\cf10 .size()\cf8 ;\
        \cf9 BigInt \cf10 c(len_a)\cf8 ;\
        for \cf10 (\cf8 int \cf10 i = \cf7 1\cf8 ; \cf10 i <= len_a\cf8 ; \cf10 i++) \{\
            \cf8 if \cf10 (i <= len_b) \{\
                \cf8 if \cf10 (a.\cf13 num\cf14 [\cf10 len_a-i] < b.\cf13 num\cf14 [\cf10 len_b-i]) \{\
                    c.\cf13 num\cf14 [\cf10 len_a-i] = a.\cf13 num\cf14 [\cf10 len_a-i]+\cf7 10\cf10 -b.\cf13 num\cf14 [\cf10 len_b-i]\cf8 ;\
                    \cf10 a.\cf13 num\cf14 [\cf10 len_a-i-\cf7 1\cf10 ] -= \cf7 1\cf8 ;\
                \cf10 \} \cf8 else \cf10 \{\
                    c.\cf13 num\cf14 [\cf10 len_a-i] = a.\cf13 num\cf14 [\cf10 len_a-i]-b.\cf13 num\cf14 [\cf10 len_b-i]\cf8 ;\
                \cf10 \}\
            \} \cf8 else \cf10 \{\
                c.\cf13 num\cf14 [\cf10 len_a-i] = a.\cf13 num\cf14 [\cf10 len_a-i]\cf8 ;\
            \cf10 \}\
        \}\
\
        a.c_zero(c)\cf8 ;\
        return \cf10 c\cf8 ;\
    \cf10 \}\
    \cf8 int \cf11 compare\cf10 (\cf9 BigInt \cf10 &a\cf8 , \cf9 BigInt \cf10 &b) \{\
        \cf8 int \cf10 len_a = a.\cf13 num\cf10 .size()\cf8 , \cf10 len_b = b.\cf13 num\cf10 .size()\cf8 ;\
        if \cf10 (len_a > len_b) \{\
            \cf8 return \cf7 1\cf8 ;\
        \cf10 \} \cf8 else if \cf10 (len_a < len_b) \{\
            \cf8 return \cf10 -\cf7 1\cf8 ;\
        \cf10 \} \cf8 else \cf10 \{\
            \cf8 int \cf10 i = \cf7 0\cf8 ;\
            while \cf10 ((a.\cf13 num\cf14 [\cf10 i] == b.\cf13 num\cf14 [\cf10 i]) && i < len_a) \{\
                i += \cf7 1\cf8 ;\
            \cf10 \}\
            \cf8 if \cf10 (i == len_a) \{\
                \cf8 return \cf7 0\cf8 ;\
            \cf10 \} \cf8 else if \cf10 (a.\cf13 num\cf14 [\cf10 i] < b.\cf13 num\cf14 [\cf10 i]) \{\
                \cf8 return \cf10 -\cf7 1\cf8 ;\
            \cf10 \} \cf8 else if \cf10 (a.\cf13 num\cf14 [\cf10 i] > b.\cf13 num\cf14 [\cf10 i]) \{\
                \cf8 return \cf7 1\cf8 ;\
            \cf10 \}\
        \}\
    \}\
    \cf8 void \cf11 c_zero\cf10 (\cf9 BigInt \cf10 &r) \{\
        \cf8 for \cf10 (\cf8 int \cf10 i = \cf7 0\cf8 ; \cf10 i <= r.\cf13 num\cf10 .size()\cf8 ; \cf10 i++) \{\
            \cf8 if \cf10 (r.\cf13 num\cf14 [\cf10 i] != \cf7 0\cf10 ) \{\
                r.\cf13 num\cf10 .erase(\cf7 0\cf8 , \cf10 i)\cf8 ;\
                break;\
            \cf10 \}\
        \}\
        \
    \}\
\}\cf8 ;\
\cf9 BigInt \cf14 operator\cf10 - (\cf9 BigInt \cf10 a\cf8 , int \cf10 b) \{\
    \cf8 int \cf10 len = a.\cf13 num\cf10 .length()\cf8 ;\
    while \cf10 (a.\cf13 num\cf14 [\cf10 len-\cf7 1\cf10 ] == \cf7 0\cf10 ) \{\
        a.\cf13 num\cf14 [\cf10 len-\cf7 1\cf10 ] = \cf7 9\cf8 ;\
        \cf10 len -= \cf7 1\cf8 ;\
    \cf10 \}\
    a.\cf13 num\cf14 [\cf10 len-\cf7 1\cf10 ] -= \cf7 1\cf8 ;\
    if \cf10 (a.\cf13 num\cf14 [\cf7 0\cf10 ] == \cf7 0\cf10 ) \{\
        a.\cf13 num\cf14 [\cf7 0\cf10 ] = \cf7 9\cf8 ;\
        \cf10 a.\cf13 num\cf10 .resize(a.\cf13 num\cf10 .size()-\cf7 1\cf10 )\cf8 ;\
    \cf10 \}\
    \cf8 return \cf10 a\cf8 ;\
\cf10 \}\
\cf9 BigInt \cf14 operator\cf10 * (\cf9 BigInt \cf10 a\cf8 , \cf9 BigInt \cf10 b) \{\
    \cf8 int \cf10 len_a\cf8 , \cf10 len_b\cf8 , \cf10 len\cf8 ;\
    \cf10 len_a = a.\cf13 num\cf10 .size()\cf8 ;\
    \cf10 len_b = b.\cf13 num\cf10 .size()\cf8 ;\
    \cf10 len = len_a + len_b\cf8 ;\
    \cf9 BigInt \cf10 c(len)\cf8 ;\
\
    long long int \cf10 array[len] \cf8 ;\
    for \cf10 (\cf8 int \cf10 i = \cf7 1\cf8 ; \cf10 i <= len_a\cf8 ; \cf10 i++) \{\
        \cf8 for \cf10 (\cf8 int \cf10 j = \cf7 1\cf8 ; \cf10 j <= len_b\cf8 ; \cf10 j++) \{\
            array[len-i-j+\cf7 1\cf10 ] += (a.\cf13 num\cf14 [\cf10 len_a-i] * b.\cf13 num\cf14 [\cf10 len_b-j])\cf8 ;\
        \cf10 \}\
    \}\
\
    \cf8 for \cf10 (\cf8 int \cf10 i = \cf7 1\cf8 ; \cf10 i < len\cf8 ; \cf10 i++) \{\
        array[len-i-\cf7 1\cf10 ] += (array[len-i]/\cf7 10\cf10 )\cf8 ;\
        \cf10 array[len-i] = (array[len-i] % \cf7 10\cf10 )\cf8 ;\
    \cf10 \}\
    \cf8 for \cf10 (\cf8 int \cf10 i = \cf7 0\cf8 ; \cf10 i < len\cf8 ; \cf10 i++) \{\
        c.\cf13 num\cf14 [\cf10 i] = (\cf8 char\cf10 )array[i]\cf8 ;\
    \cf10 \}\
\
    c.c_zero(c)\cf8 ;\
\
    return \cf10 c\cf8 ;\
\cf10 \}\
\cf9 BigInt \cf14 operator\cf10 % (\cf9 BigInt \cf10 a\cf8 , \cf9 BigInt \cf10 b) \{\
    \cf9 BigInt \cf10 abcd(\cf7 1\cf10 )\cf8 , \cf10 b1 = b\cf8 ;\
    int \cf10 i = \cf7 0\cf8 , \cf10 j = \cf7 0\cf8 ;\
    int \cf10 len_a = a.\cf13 num\cf10 .size()\cf8 , \cf10 len_b = b.\cf13 num\cf10 .size()\cf8 , \cf10 len\cf8 ;\
\
    switch \cf10 (abcd.compare(a\cf8 , \cf10 b)) \{\
        \cf8 case \cf10 -\cf7 1\cf10 : \cf8 return \cf10 a\cf8 ; break;\
        case \cf7 0\cf10 : \cf8 return \cf10 abcd\cf8 ; break;\
        case \cf7 1\cf10 : len = len_a-len_b\cf8 ; \cf9 BigInt \cf10 r(len+\cf7 1\cf10 )\cf8 ; break;\
    \cf10 \}\
    len = len_a-len_b\cf8 ;\
    \cf9 BigInt \cf10 r(len+\cf7 1\cf10 )\cf8 ;\
\
    for \cf10 (j = \cf7 0\cf8 ; \cf10 j < len\cf8 ; \cf10 j++) \{\
        b.\cf13 num \cf14 += \cf10 (\cf8 char\cf10 ) \cf7 0\cf8 ;\
    \cf10 \}\
    \cf8 while \cf10 (abcd.compare(a\cf8 , \cf10 b1) > \cf7 0\cf10 ) \{\
        \cf8 if \cf10 (abcd.compare(a\cf8 , \cf10 b) > \cf7 0\cf10 ) \{\
            a = abcd.sub(a\cf8 , \cf10 b)\cf8 ;\
        \cf10 \}  \cf8 else if \cf10 (abcd.compare(a\cf8 , \cf10 b) == \cf7 0\cf10 ) \{\
            \cf8 return \cf10 abcd\cf8 ;\
        \cf10 \} \cf8 else if \cf10 (abcd.compare(a\cf8 , \cf10 b) < \cf7 0\cf10 ) \{\
            b.\cf13 num\cf10 .erase(b.\cf13 num\cf10 .end()\cf14 -\cf7 1\cf10 )\cf8 ;\
            \cf10 i += \cf7 1\cf8 ;\
        \cf10 \}\
    \}\
    \cf8 if \cf10 (abcd.compare(a\cf8 , \cf10 b1) == \cf7 0\cf10 ) \{\
        \cf8 return \cf10 abcd\cf8 ;\
    \cf10 \} \cf8 else if \cf10 (abcd.compare(a\cf8 , \cf10 b1) < \cf7 0\cf10 ) \{\
        \cf8 return \cf10 a\cf8 ;\
    \cf10 \}\
\}\
\cf9 BigInt \cf14 operator\cf10 / (\cf9 BigInt \cf10 a\cf8 , \cf9 BigInt \cf10 b) \{\
    \cf9 BigInt \cf10 abcd(\cf7 1\cf10 )\cf8 , \cf10 b1 = b\cf8 ;\
    int \cf10 i = \cf7 0\cf8 , \cf10 j = \cf7 0\cf8 ;\
    int \cf10 len_a = a.\cf13 num\cf10 .size()\cf8 , \cf10 len_b = b.\cf13 num\cf10 .size()\cf8 , \cf10 len\cf8 ;\
    int \cf10 result = abcd.compare(a\cf8 ,\cf10 b)\cf8 ;\
    if \cf10 (result == -\cf7 1\cf10 ) \cf8 return \cf10 abcd\cf8 ;\
    if \cf10 (result == \cf7 0\cf10 )\{\
        abcd.\cf13 num\cf14 [\cf7 0\cf10 ] = \cf7 1\cf8 ;\
        return \cf10 abcd\cf8 ;\
    \cf10 \}\
    len = len_a-len_b\cf8 ;\
    \cf9 BigInt \cf10 bigint1(len+\cf7 1\cf10 )\cf8 ;\
\
    for \cf10 (j = \cf7 0\cf8 ; \cf10 j < len\cf8 ; \cf10 j++) \{\
        b.\cf13 num \cf14 += \cf10 (\cf8 char\cf10 ) \cf7 0\cf8 ;\
    \cf10 \}\
    \cf8 while \cf10 (abcd.compare(a\cf8 , \cf10 b1) > \cf7 0\cf10 ) \{\
        \cf8 if \cf10 (abcd.compare(a\cf8 , \cf10 b) > \cf7 0\cf10 ) \{\
            a = abcd.sub(a\cf8 , \cf10 b)\cf8 ;\
            \cf10 bigint1.\cf13 num\cf14 [\cf10 i] += \cf7 1\cf8 ;\
        \cf10 \}  \cf8 else if \cf10 (abcd.compare(a\cf8 , \cf10 b) == \cf7 0\cf10 ) \{\
            bigint1.\cf13 num\cf14 [\cf10 i] += \cf7 1\cf8 ;\
            \cf10 abcd.c_zero(bigint1)\cf8 ;\
            return \cf10 bigint1\cf8 ;\
        \cf10 \} \cf8 else if \cf10 (abcd.compare(a\cf8 , \cf10 b) < \cf7 0\cf10 ) \{\
            b.\cf13 num\cf10 .erase(b.\cf13 num\cf10 .end()\cf14 -\cf7 1\cf10 )\cf8 ;\
            \cf10 i += \cf7 1\cf8 ;\
        \cf10 \}\
    \}\
    \cf8 if \cf10 (abcd.compare(a\cf8 , \cf10 b1) == \cf7 0\cf10 ) \{\
        bigint1.\cf13 num\cf14 [\cf10 len] += \cf7 1\cf8 ;\
        \cf10 abcd.c_zero(bigint1)\cf8 ;\
        return \cf10 bigint1\cf8 ;\
    \cf10 \} \cf8 else if \cf10 (abcd.compare(a\cf8 , \cf10 b1) < \cf7 0\cf10 ) \{\
        abcd.c_zero(bigint1)\cf8 ;\
        return \cf10 bigint1\cf8 ;\
    \cf10 \}\
\}\
\cf8 class \cf9 BigPrime \cf10 : \cf8 public \cf9 BigInt\cf10 \{\
\cf8 public\cf10 :\
    \cf13 BigPrime\cf10 (\cf12 string \cf10 t) : \cf9 BigInt\cf10 (t)\{\
        \cf13 n\cf10 .\cf13 num \cf14 = \cf8 this\cf10 ->\cf13 num\cf8 ;\
    \cf10 \}\
    \cf8 virtual bool \cf11 isPrime\cf10 () \{\
        \cf8 if \cf10 (isprimee(\cf13 n\cf10 )) \{\
            \cf8 return true;\
        \cf10 \}\
        \cf8 return false;\
    \cf10 \}\
\cf8 private\cf10 :\
    \cf9 BigInt \cf13 n\cf8 ;\
    \cf9 BigInt \cf11 pow1\cf10 (\cf9 BigInt \cf10 a\cf8 , \cf9 BigInt \cf10 b\cf8 , \cf9 BigInt \cf10 mod) \{\
        \cf9 BigInt \cf10 bigint2(\cf5 "1"\cf10 )\cf8 , \cf10 base = a\cf8 , \cf10 two(\cf5 "2"\cf10 )\cf8 ;\
        while \cf10 (b.\cf13 num\cf14 [\cf7 0\cf10 ] != \cf7 0\cf10 ) \{\
            \cf8 int \cf10 len_b\cf8 ;\
            \cf10 len_b = b.\cf13 num\cf10 .size()\cf8 ;\
            if \cf10 (((\cf8 int\cf10 )b.\cf13 num\cf14 [\cf10 len_b-\cf7 1\cf10 ] % \cf7 2\cf10 ) != \cf7 0\cf10 ) \{\
                bigint2 = bigint2\cf14 *\cf10 base\cf8 ;\
                \cf10 bigint2 = bigint2\cf14 %\cf10 mod\cf8 ;\
            \cf10 \}\
            base = base\cf14 *\cf10 base\cf8 ;\
            \cf10 base = base\cf14 %\cf10 mod\cf8 ;\
            \cf10 b = b\cf14 /\cf10 two\cf8 ;\
        \cf10 \}\
        \cf8 return \cf10 bigint2\cf8 ;\
    \cf10 \}\
    \cf8 bool \cf11 isprimee\cf10 (\cf9 BigInt \cf10 x)	\{\
        \cf9 BigInt \cf10 temp(\cf5 "30"\cf10 )\cf8 ;\
        for\cf10 (\cf8 int \cf10 i = \cf7 2\cf8 ; \cf10 i<=\cf6 MAX\cf8 ; \cf10 ++i) \{\
            \cf8 if \cf10 (((pow1(temp\cf8 ,\cf10 x\cf14 -\cf7 1\cf8 ,\cf10 x)\cf14 %\cf10 x).\cf13 num\cf10 .size() != \cf7 1\cf10 ) || ((pow1(temp\cf8 ,\cf10 x\cf14 -\cf7 1\cf8 ,\cf10 x)\cf14 %\cf10 x).\cf13 num\cf14 [\cf7 0\cf10 ] != \cf7 1\cf10 ))\
                \cf8 return false;\
            \cf10 temp = temp\cf14 -\cf7 1\cf8 ;\
        \cf10 \}\
        \cf8 return true;\
    \cf10 \}\
\
\}\cf8 ;\
class \cf9 BigSuperPrime \cf10 : \cf8 public \cf9 BigPrime \cf10 \{\
\cf8 public\cf10 :\
    \cf11 BigSuperPrime\cf10 (\cf12 string \cf10 t) : \cf9 BigPrime\cf10 (t)\{\
        \cf8 int \cf10 len = t.size()\cf8 , \cf10 i\cf8 ;\
        for \cf10 (i = \cf7 0\cf8 ; \cf10 i < len\cf8 ; \cf10 i++) \{\
            \cf13 a\cf10 [i] = t\cf14 [\cf10 i]-\cf5 '0'\cf8 ;\
        \cf10 \}\
        \cf13 a\cf10 [i] = -\cf7 1\cf8 ;\
    \cf10 \}\
    \cf8 virtual bool \cf11 isPrime\cf10 () \{\
        \cf9 BigPrime \cf10 a(sum())\cf8 , \cf10 b(Multi())\cf8 , \cf10 c(SquareSum())\cf8 ;\
        if \cf10 (\cf9 BigPrime\cf10 ::isPrime() && a.isPrime() && b.isPrime() && c.isPrime()) \{\
            \cf8 return true;\
        \cf10 \}\
        \cf8 return false;\
    \cf10 \}\
\cf8 private\cf10 :\
    \cf8 int \cf13 a\cf10 [\cf7 2000\cf10 ]\cf8 ;\
    \cf12 string \cf11 sum\cf10 () \{\
        \cf8 int \cf10 i = \cf7 0\cf8 , \cf10 sum = \cf7 0\cf8 ;\
        while \cf10 (\cf13 a\cf10 [i] >= \cf7 0\cf10 ) \{\
            sum += \cf13 a\cf10 [i]\cf8 ;\
            \cf10 i += \cf7 1\cf8 ;\
        \cf10 \}\
        \cf8 char \cf10 t[\cf7 2000\cf10 ]\cf8 ;\
        \cf10 sprintf(t\cf8 , \cf5 "\cf8 %d\cf5 "\cf8 , \cf10 sum)\cf8 ;\
        \cf12 string \cf10 r = t\cf8 ;\
        return \cf10 r\cf8 ;\
    \cf10 \}\
    \cf12 string \cf11 Multi\cf10 () \{\
        \cf9 BigInt \cf10 Multi(\cf7 1\cf10 )\cf8 ;\
        \cf10 Multi.\cf13 num\cf14 [\cf7 0\cf10 ] = (\cf8 char\cf10 )\cf7 1\cf8 ;\
        int \cf10 i = \cf7 0\cf8 ;\
        while \cf10 (\cf13 a\cf10 [i] >= \cf7 0\cf10 ) \{\
            \cf9 BigInt \cf10 temp(\cf7 1\cf10 )\cf8 ;\
            \cf10 temp.\cf13 num\cf14 [\cf7 0\cf10 ] = (\cf8 char\cf10 )\cf13 a\cf10 [i]\cf8 ;\
            \cf10 Multi = Multi \cf14 * \cf10 temp\cf8 ;\
            \cf10 i += \cf7 1\cf8 ;\
        \cf10 \}\
        \cf8 return \cf10 Multi.\cf13 num\cf8 ;\
    \cf10 \}\
    \cf12 string \cf11 SquareSum\cf10 () \{\
        \cf8 int \cf10 i = \cf7 0\cf8 , \cf10 SquareSum = \cf7 0\cf8 ;\
        while \cf10 (\cf13 a\cf10 [i] >= \cf7 0\cf10 ) \{\
            SquareSum += (\cf13 a\cf10 [i]*\cf13 a\cf10 [i])\cf8 ;\
            \cf10 i += \cf7 1\cf8 ;\
        \cf10 \}\
        \cf8 char \cf10 t[\cf7 1005\cf10 ]\cf8 ;\
        \cf10 sprintf(t\cf8 , \cf5 "\cf8 %d\cf5 "\cf8 , \cf10 SquareSum)\cf8 ;\
        \cf12 string \cf10 r = t\cf8 ;\
        return \cf10 r\cf8 ;\
    \cf10 \}\
\}\cf8 ;\
class \cf9 Set \cf10 \{\
\cf8 public\cf10 :\
    \cf11 Set\cf10 (\cf8 int \cf10 sz)\cf8 ;\
    \cf11 ~Set\cf10 ()\cf8 ;\
    bool \cf11 add\cf10 (\cf9 BigPrime \cf10 *bp)\cf8 ;\
    bool \cf11 remove\cf10 (\cf9 BigPrime \cf10 *bp)\cf8 ;\
    int \cf11 count\cf10 () \cf8 const \cf10 \{\
        \cf8 int \cf10 ret = \cf7 0\cf8 ;\
        for \cf10 (\cf8 int \cf10 i = \cf7 0\cf8 ; \cf10 i < \cf13 index\cf8 ; \cf10 i++) \{\
            \cf8 if \cf10 (\cf13 pset\cf10 [i]->isPrime())\
                ret += \cf7 1\cf8 ;\
        \cf10 \}\
        \cf8 return \cf10 ret\cf8 ;\
    \cf10 \}\
    \cf8 int \cf11 sum\cf10 () \cf8 const \cf10 \{\
        \cf8 return \cf7 0\cf8 ;\
    \cf10 \}\
\cf8 private\cf10 :\
    \cf9 BigPrime \cf10 **\cf13 pset\cf8 ;\
    int \cf13 size\cf8 , \cf13 index\cf8 ;\
\cf10 \}\cf8 ;\
int \cf11 main\cf10 () \{\
    \cf9 Set \cf10 set(\cf7 1000\cf10 )\cf8 ;\
    \cf9 BigSuperPrime \cf10 bp(\cf5 "256432154654564132145464"\cf10 )\cf8 , \cf10 bp1(\cf5 "3564321354564697894658974564"\cf10 )\cf8 ;\
    \cf10 set.add(&bp)\cf8 ;\
    \cf10 set.add(&bp1)\cf8 ;\
    \cf10 cout \cf14 << \cf10 set.count() \cf14 << \cf10 endl\cf8 ;\
    return \cf7 0\cf8 ;\
\cf10 \}\
\
\cf9 Set\cf10 ::\cf11 Set\cf10 (\cf8 int \cf10 sz):\cf13 size\cf10 (sz) \{\
    \cf13 index \cf10 = \cf7 0\cf8 ;\
    \cf13 pset \cf10 = \cf8 new \cf9 BigPrime\cf10 *[\cf13 size\cf10 ]\cf8 ;\
\cf10 \}\
\
\cf9 Set\cf10 ::\cf11 ~Set\cf10 () \{\
    \cf8 delete\cf10 [] \cf13 pset\cf8 ;\
\cf10 \}\
\cf8 bool \cf9 Set\cf10 ::\cf11 add\cf10 (\cf9 BigPrime \cf10 *bp) \{\
    \cf13 pset\cf10 [\cf13 index\cf10 ++] = bp\cf8 ;\
    return true;\
\cf10 \}\
}