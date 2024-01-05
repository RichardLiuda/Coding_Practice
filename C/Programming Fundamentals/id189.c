#include <stdio.h>

int main()
{
    int t = 4;
    while (t--)
    {
        printf(t == 3 ? "####\n" : t == 2 ? " ####\n"
                               : t == 1   ? "  ####\n"
                                          : "   ####");
    }
    return 0;
}
