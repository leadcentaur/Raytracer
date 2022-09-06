#include <string>
#include <cmath>

string FPClass(double x)
{
    int i = _fpclass(x);
    string s;
    switch (i)
    {
    case _FPCLASS_SNAN: s = "Signaling NaN";                break;
    case _FPCLASS_QNAN: s = "Quiet NaN";                    break; 
    case _FPCLASS_NINF: s = "Negative infinity (-INF)";     break; 
    case _FPCLASS_NN:   s = "Negative normalized non-zero"; break;
    case _FPCLASS_ND:   s = "Negative denormalized";        break; 
    case _FPCLASS_NZ:   s = "Negative zero (-0)";           break; 
    case _FPCLASS_PZ:   s = "Positive 0 (+0)";              break; 
    case _FPCLASS_PD:   s = "Positive denormalized";        break; 
    case _FPCLASS_PN:   s = "Positive normalized non-zero"; break; 
    case _FPCLASS_PINF: s = "Positive infinity (+INF)";     break;
    }
    return s;
}