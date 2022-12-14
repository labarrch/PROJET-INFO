using namespace std;

#include <vector>
#include <iostream>

struct Value
{
    virtual void whoami()=0;
};
class CharValue : public Value
{ public : virtual void whoami() {cout << "char";} };
class LongValue : public Value
{public : virtual void whoami() {cout << "long";} };
class FloatValue : public Value
{public : virtual void whoami() {cout << "float";} };
typedef vector<Value*> ValueVector;
int main( int,char**)
{
    CharValue cv;
    LongValue cl;
    FloatValue cf;
    ValueVector v;
    v.push_back(&cv);
    v.push_back(&cl);
    v.push_back(&cf);
    // Acces au elements
    Value* it = v.begin();
    while( it != v.end() )
    {
        *it->whoami();
          it++;
    }
    return 0;
}
