//
//  main.m
//  Test
//
//  Created by iOS on 2019/7/29.
//  Copyright © 2019 iOS. All rights reserved.
//
#import <Foundation/Foundation.h>

/*
 bss (block started by symbol segment)
 There is another section called the .bss. This section is like the data section, except that it doesn’t take up space in the executable
 
 
 
 */
int main(int argc, char * argv[]) {
    
    int a = 5%3;
    
    @autoreleasepool {
        NSString *str = @"";
        [str stringByAppendingString:@"dd"];
    }
}
 
int arr[3000];
int arr1[3000] = {1,2,3};
static int a;
static int a1;
void func() {
    
}
//bss arr a
//data arr1 a1
//code text 代码字符串常量

  TITLE    test.cpp
    .386P
include listing.inc
if @Version gt 510
.model FLAT
else
_TEXT    SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT    ENDS
_DATA    SEGMENT DWORD USE32 PUBLIC 'DATA'
_DATA    ENDS
CONST    SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST    ENDS
_BSS    SEGMENT DWORD USE32 PUBLIC 'BSS'
_BSS    ENDS
_TLS    SEGMENT DWORD USE32 PUBLIC 'TLS'
_TLS    ENDS
FLAT    GROUP _DATA, CONST, _BSS
    ASSUME    CS: FLAT, DS: FLAT, SS: FLAT
endif

PUBLIC    ?inbss@@3PAHA                    ; inbss
PUBLIC    ?fA@@3MA                    ; fA
PUBLIC    ?indata@@3PAHA                    ; indata
PUBLIC    ?dbB@@3NA                    ; dbB


_BSS    SEGMENT
?inbss@@3PAHA DD 0f4a10H DUP (?)            ; inbss
?fA@@3MA DD    01H DUP (?)                ; fA
_BSS    ENDS

_DATA    SEGMENT
?indata@@3PAHA DD 01H                    ; indata
    DD    02H
    DD    03H
    DD    04H
    DD    05H
    DD    06H
    DD    07H
    DD    08H
    DD    09H
    ORG $+4007964
?dbB@@3NA DQ    04059000000000000r        ; 100    ; dbB
_DATA    ENDS




PUBLIC    _main
EXTRN    _printf:NEAR

_DATA    SEGMENT
$SG537    DB    '%d ', 00H
_DATA    ENDS

_TEXT    SEGMENT
_run$ = -400
_i$ = -404
_main    PROC NEAR
; File test.cpp
; Line 13
    push    ebp
    mov    ebp, esp
    sub    esp, 404                ; 00000194H
    push    edi
; Line 14
    mov    DWORD PTR _run$[ebp], 1
    mov    DWORD PTR _run$[ebp+4], 2
    mov    DWORD PTR _run$[ebp+8], 3
    mov    DWORD PTR _run$[ebp+12], 4
    mov    DWORD PTR _run$[ebp+16], 5
    mov    DWORD PTR _run$[ebp+20], 6
    mov    DWORD PTR _run$[ebp+24], 7
    mov    DWORD PTR _run$[ebp+28], 8
    mov    DWORD PTR _run$[ebp+32], 9
    mov    ecx, 91                    ; 0000005bH
    xor    eax, eax
    lea    edi, DWORD PTR _run$[ebp+36]
    rep stosd
; Line 15
    mov    DWORD PTR _i$[ebp], 0
    jmp    SHORT $L534
$L535:
    mov    eax, DWORD PTR _i$[ebp]
    add    eax, 1
    mov    DWORD PTR _i$[ebp], eax
$L534:
    cmp    DWORD PTR _i$[ebp], 1002000        ; 000f4a10H
    jge    SHORT $L536
; Line 16
    mov    ecx, DWORD PTR _i$[ebp]
    mov    edx, DWORD PTR ?inbss@@3PAHA[ecx*4]
    push    edx
    push    OFFSET FLAT:$SG537
    call    _printf
    add    esp, 8
    jmp    SHORT $L535
$L536:
; Line 17
    xor    eax, eax
; Line 18
    pop    edi
    mov    esp, ebp
    pop    ebp
    ret    0
_main    ENDP
_TEXT    ENDS
END
---------------------

1 2 3 4 5 6 7 
6 1 2 3 4 5 6


3%5 = 2

f(n-1, m) = (f(n, m) + m)%n

