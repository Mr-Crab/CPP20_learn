#define __CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
    #ifndef DBG_NEW
        #define DBG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)
        #define new DBG_NEW
    #endif
#endif

class Simple {
public:
    Simple() { m_intPtr = new int(); }
    ~Simple() { delete m_intPtr; }
    void setValue(int value) {*m_intPtr = value;}
private:
    int* m_intPtr;
};

void doSomething(Simple*& outSimplePtr) {
    outSimplePtr = new Simple();
}

int main() {
    // below line enables memory leak report to terminal when the application exits
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Simple* simplePtr{new Simple()};
    doSomething(simplePtr);
    delete simplePtr;
    return 0;
}