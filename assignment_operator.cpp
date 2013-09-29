#include <iostream>

using namespace std;
class CMyString{
public:
  CMyString(char* pData = NULL);
  CMyString(const CMyString & str);
  ~CMyString(void);
  CMyString& operator=(const CMyString &str);
  void Print();
private:
  char* m_pData;
};


CMyString::CMyString(char *pData){
    if(pData == NULL)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString &str){
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(){
    delete[] m_pData;
}

void CMyString::Print(){
    printf("%s", m_pData);
}

/*************************************************
1 Using new char and strcpy
------------------------------------
// & is read as "address of"
// * is read as "value pointed by"
// 1. Return type must be reference & : for consecutive assignment
//    like: str1 = str2 = str3
// 2. Parameter type must be const reference & 
CMyString& CMyString::operator = (const CMyString &str){
  if(this == &str ) // this holds the address of str
    return *this;   // return the value pointed by this
  
  // release memory before assign new memory space to avoid memo leak
  delete [] m_pData;
  m_pData = NULL;
  m_pData = new char[strlen(str.m_pData)+1];
  strcpy(m_pData, str.m_pData);

  return *this;
  
}
*********************************************/

CMyString& CMyString::operator=(const CMyString &str){
  if(this != &str){
    // create temp instance given parameter instance str
    CMyString strTemp(str);
    char *pTemp = strTemp.m_pData;
    strTemp.m_pData = m_pData;
    m_pData = pTemp;
  }
  return *this;
}


int main(){
  char* origData = "original data is 25";
  CMyString origStr(origData);
  cout<<" The original instance origStr contains: "<<endl;
  origStr.Print();
  CMyString newStr;
  // Test 1:  assign origStr to newStr
  newStr = origStr;
  cout<<"\n Test 1: After assginment, the new instance newStr contains:"<<endl;
  newStr.Print();
  
  // Test 2: assing to itself
  origStr = origStr;
  cout<<"\n Test 2: After assign to itself, the origStr contains:"<<endl;
  origStr.Print();

  // Test 3: consecutive assingment
  CMyString str1, str2;
  str1 = str2 = origStr;
  cout<<"\n Test 3: After consecutive assignments, the str1 contains:"<<endl;
  str1.Print();
  cout<<"\n Test 3: the str2 contains:"<<endl;
  str2.Print();
  
  return 0;
}
