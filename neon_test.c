#include <stdio.h>
#include <string.h>

typedef struct
{
    unsigned long long parts[8]; // 512비트 크기
} u512;

// u512 덧셈 함수 (NEON 최적화가 자동으로 적용되도록 작성)
void add_u512(u512 a, u512 b, u512 *result)
{
    // 각 64비트 요소를 덧셈
    for (int i = 0; i < 8; i++)
    {
        result->parts[i] = a.parts[i] + b.parts[i];
    }
}

int main()
{
    // 두 개의 u512 변수 초기화
    u512 num1 = {{0x123456789abcdef0, 0x23456789abcdef1, 0x3456789abcdef2, 0x456789abcdef3,
                  0x56789abcdef4, 0x6789abcdef5, 0x789abcdef6, 0x89abcdef7}};

    u512 num2 = {{0xabcdef0123456789, 0xbcdef012345678a, 0xcdef012345678b, 0xdef0123456788c,
                  0xef0123456788cd, 0xf0123456788cde, 0x0123456788cdef, 0x1234567888def0}};

    
    u512 sum = {0};
    
    add_u512(num1, num2, &sum);
    printf("Addition result: OK %p\n", &sum);

    return 0;
}
