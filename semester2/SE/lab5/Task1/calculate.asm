format PE console NX
entry start

include 'WIN32A.INC'

section '.data' data readable writeable 
sumMask db '+: '
sizeof.sumMask = $ - sumMask

subMask db '-: '
sizeof.subMask = $ - subMask

divMask db '/: '
sizeof.divMask = $ - divMask

multMask db '*: '
sizeof.multMask = $ - multMask

newLine db 13,10
sizeof.newLine = $ - newLine

section '.bss' data readable writeable

stub dd ?
hInput dd ?
hOutput dd ?
dwNumber1 dd ?
dwNumber2 dd ?

Num1 dd ?
szNum1 rb 30
szNum1.sizeof = $-szNum1

Num2 dd ?
szNum2 rb 30
szNum2.sizeof = $-szNum2

Sum dd ?
szSum rb 30
szSum.sizeof = $-szSum

Diff dd ?
szDiff rb 30
szDiff.sizeof = $-szDiff

Prod dd ?
szProd rb 30
szProd.sizeof = $-szProd

Quot1 dd ?
szQuot1 rb 30
szQuot1.sizeof = $-szQuot1

Quot2 dd ?
szQuot2 rb 30
szQuot2.sizeof = $-szQuot2

section '.text' code readable executable

start:

    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX
    
    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutput], EAX

    ; ввод первой строки
    push 0
    push dwNumber1
    push szNum1.sizeof
    push szNum1
    push ptr hInput
    call ptr ReadConsole

    ; заменяем предпоследний символ стоки на \0 (символ с кодом 0)
    mov EBX, ptr dwNumber1
    mov byte ptr szNum1 + EBX - 2, 0
    
	; преобразуем строку в число
	push szNum1
    call ptr atoi
    add ESP, 4

    mov [Num1], EAX

    ; ввод второй строки  
    push 0
    push dwNumber2
    push szNum2.sizeof
    push szNum2
    push ptr hInput
    call ptr ReadConsole

    ; заменяем предпоследний символ стоки на \0 (символ с кодом 0)
    mov EBX, ptr dwNumber2
    mov byte ptr szNum2 + EBX - 2, 0

    ; преобразуем строку в число
	push szNum2
    call ptr atoi
    add ESP, 4

    mov [Num2], EAX

    ; ---
    mov EAX, [Num1]
    mov EBX, [Num2]

    add EAX, EBX
    mov [Sum], EAX

    push 10
    push szSum
    push [Sum]
    call ptr itoa
    add ESP, 3 * 4 

    push [Sum]
    call ptr lstrlen

    push NULL
    push stub       
    push sizeof.sumMask
    push sumMask      
    push [hOutput]      
    call [WriteConsole]

    push 0
    push stub
    push [Sum]
    push szSum
    push ptr hOutput
    call ptr WriteConsole

    push NULL
    push stub       
    push sizeof.newLine
    push newLine      
    push [hOutput]      
    call [WriteConsole]
    ; ---

    mov EAX, [Num1]
    mov EBX, [Num2]

    sub EAX, EBX
    mov [Diff], EAX

    push 10
    push szDiff
    push [Diff]
    call ptr itoa
    add ESP, 3 * 4 

    push [Diff]
    call ptr lstrlen

    push NULL
    push stub       
    push sizeof.subMask
    push subMask      
    push [hOutput]      
    call [WriteConsole]

    push 0
    push stub
    push [Diff]
    push szDiff
    push ptr hOutput
    call ptr WriteConsole

    push NULL
    push stub       
    push sizeof.newLine
    push newLine      
    push [hOutput]      
    call [WriteConsole]
    ; ---

    mov EAX, [Num1]
    mov EBX, [Num2]

    mul EBX

    mov [Prod], EAX

    push 10
    push szProd
    push [Prod]
    call ptr itoa
    add ESP, 3 * 4 

    push [Prod]
    call ptr lstrlen

    push NULL
    push stub       
    push sizeof.multMask
    push multMask      
    push [hOutput]      
    call [WriteConsole]

    push 0
    push stub
    push [Prod]
    push szProd
    push ptr hOutput
    call ptr WriteConsole

    push NULL
    push stub       
    push sizeof.newLine
    push newLine      
    push [hOutput]      
    call [WriteConsole]
    ; ---

    mov EAX, [Num1]
    mov EDX, 0
    mov EBX, [Num2]

    div EBX

    mov [Quot1], EAX
    mov [Quot2], EDX

    push 10
    push szQuot2
    push [Quot2]
    call ptr itoa
    add ESP, 3 * 4 

    push [Quot2]
    call ptr lstrlen

    push 10
    push szQuot1
    push [Quot1]
    call ptr itoa
    add ESP, 3 * 4 

    push [Quot1]
    call ptr lstrlen

    push NULL
    push stub       
    push sizeof.divMask
    push divMask      
    push [hOutput]      
    call [WriteConsole]

    push 0
    push stub
    push [Quot1]
    push szQuot1
    push ptr hOutput
    call ptr WriteConsole

    push NULL
    push stub       
    push sizeof.newLine
    push newLine      
    push [hOutput]      
    call [WriteConsole]

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