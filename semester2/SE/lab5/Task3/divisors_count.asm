format PE console NX
entry start

include 'WIN32A.INC'

section '.data' data readable writeable 

frame1 db 'Input N: '
sizeof.frame1 = $ - frame1

frame3 db 'Divisors of N count: '
sizeof.frame3 = $ - frame3

Divisor dd 1, 0
szDivisor rb 30
szDivisor.sizeof = $-Divisor

DivisorsCount dd 1, 0
szDivisorsCount rb 30
szDivisorsCount.sizeof = $-DivisorsCount

section '.bss' data readable writeable

hInput dd ?
hOutput dd ?
dwNumber dd ?
stub dd ?

szNum rb 30
szNum.sizeof = $-szNum

N dd ?
szN rb 30
szN.sizeof = $-szN

section '.text' code readable executable

incCount:
    inc [DivisorsCount]
    jmp back

Cycle:
    mov EAX, [N]
    mov EDX, 0
    div [Divisor]
    cmp EDX, 0
    je incCount
back:
    inc [Divisor]
divisors:
    mov EAX, [Divisor]
    mov EDX, [N]
    cmp EAX, EDX
    je EndDivisors
    jle Cycle

EndDivisors:
    ret

start:
    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX
    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutput], EAX

    push NULL
    push stub       
    push sizeof.frame1
    push frame1      
    push [hOutput]      
    call [WriteConsole]

    mov [N], EAX

    push 0
    push dwNumber
    push szN.sizeof
    push szN
    push ptr hInput
    call ptr ReadConsole

    mov EBX, ptr dwNumber
    mov byte ptr szN + EBX - 2, 0
    
    push szN
    call ptr atoi
    add ESP, 4

    mov [N], EAX

    call divisors

    push NULL
    push stub       
    push sizeof.frame3
    push frame3     
    push [hOutput]      
    call [WriteConsole]

    push 10
    push szDivisorsCount
    push [DivisorsCount]
    call ptr itoa
    add ESP, 3 * 4 ; 

    push [DivisorsCount]
    call ptr lstrlen

    push 0
    push dwNumber
    push [DivisorsCount]
    push szDivisorsCount
    push ptr hOutput
    call ptr WriteConsole

    push 0
    call [ExitProcess]

section '.idata' import data readable writeable

library kernel32, 'KERNEL32.DLL', \
    msvcrt, 'MSVCRT.DLL'

import kernel32,\
    lstrlen, 'lstrlenA',\
    ExitProcess, 'ExitProcess',\    
    GetStdHandle, 'GetStdHandle',\
    WriteConsole, 'WriteConsoleA',\
    ReadConsole, 'ReadConsoleA'

import msvcrt, \
    atoi, 'atoi',\
    itoa, '_itoa'

section '.reloc' fixups data readable discardable