format PE console NX
entry start

include 'WIN32A.INC'

section '.data' data readable writeable 

error db 'Division by zero!!!'
sizeof.error = $ - error

xMask db 'Enter X: '
sizeof.xMask = $ - xMask

yMask db 'Enter Y: '
sizeof.yMask = $ - yMask

x2Mask db 'max(X^2, 10): '
sizeof.x2Mask = $ - x2Mask

y4Mask db 'min(Y^4, 10): '
sizeof.y4Mask = $ - y4Mask

numeratorMask db 'min(max(X^2, 10), min(Y^4, 10)): '
sizeof.numeratorMask = $ - numeratorMask

denominatorMask db 'min(X%Y, Y%X): '
sizeof.denominatorMask = $ - denominatorMask

resultMask db 'min(max(X^2, 10), min(Y^4, 10)) / min(X%Y, Y%X): '
sizeof.resultMask = $ - resultMask

newLine db 13,10
sizeof.newLine = $ - newLine

section '.bss' data readable writeable

stub dd ?
hInput dd ?
hOutput dd ?
dwNumber1 dd ?
dwNumber2 dd ?

X dd ?
szX rb 30
szX.sizeof = $-szX

Y dd ?
szY rb 30
szY.sizeof = $-szY

Max1 dd ?
szMax1 rb 30
szMax1.sizeof = $-szMax1

Min1 dd ?
szMin1 rb 30
szMin1.sizeof = $-szMin1

Numerator dd ?
szNumerator rb 30
szNumerator.sizeof = $-szNumerator

XY dd ?
szXY rb 30
szXY.sizeof = $-szXY

YX dd ?
szYX rb 30
szYX.sizeof = $-szYX

Denominator dd ?
szDenominator rb 30
szDenominator.sizeof = $-szDenominator

Result dd ?
szResult rb 30
szResult.sizeof = $-szResult

section '.text' code readable executable

max:
    cmp EAX, EBX
    jge exitMax
    mov EAX, EBX
exitMax:
    ret

min:
    cmp EAX, EBX
    jle exitMin
    mov EAX, EBX
exitMin:
    ret


ZeroDivision:
    push NULL
    push stub       
    push sizeof.error
    push error      
    push [hOutput]      
    call [WriteConsole]

    jmp ex

start:
    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX

    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutput], EAX

    push NULL
    push stub       
    push sizeof.xMask
    push xMask      
    push [hOutput]      
    call [WriteConsole]

    push 0
    push dwNumber1
    push szX.sizeof
    push szX
    push ptr hInput
    call ptr ReadConsole

    mov EBX, ptr dwNumber1
    mov byte ptr szX + EBX - 2, 0

	push szX
    call ptr atoi
    add ESP, 4

    mov [X], EAX

    push NULL
    push stub       
    push sizeof.yMask
    push yMask      
    push [hOutput]      
    call [WriteConsole]

    push 0
    push dwNumber2
    push szY.sizeof
    push szY
    push ptr hInput
    call ptr ReadConsole

    mov EBX, ptr dwNumber2
    mov byte ptr szY + EBX - 2, 0

	push szY
    call ptr atoi
    add ESP, 4

    mov [Y], EAX

    ; ---
    mov EAX, [X]
    mul [X]

    mov EBX, 10

    call max
    mov [Max1], EAX
    ; ---

    mov EAX, [Y]
    mul [Y]
    mul [Y]
    mul [Y]

    mov EBX, 10
    call min
    mov [Min1], EAX
    ; ---

    mov EAX, [Max1]
    mov EBX, [Min1]
    call min
    mov [Numerator], EAX
    ; ---

    mov EAX, [X]
    mov EDX, 0
    mov EBX, [Y]
    div EBX

    mov [XY], EDX

    mov EAX, [Y]
    mov EDX, 0
    mov EBX, [X]
    div EBX

    mov [YX], EDX

    mov EAX, [XY]
    mov EBX, [YX]
    call min

    mov [Denominator], EAX
    ; ---

    mov EAX, [Numerator]
    mov EDX, 0
    mov EBX, [Denominator]

    cmp EBX, 0
    je ZeroDivision

    div EBX

    mov [Result], EAX
    ; ---

    ; Output
    push NULL
    push stub       
    push sizeof.newLine
    push newLine      
    push [hOutput]      
    call [WriteConsole]

    push 10
    push szMax1
    push [Max1]
    call ptr itoa
    add ESP, 3 * 4 

    push [Max1]
    call ptr lstrlen

    push NULL
    push stub       
    push sizeof.x2Mask
    push x2Mask      
    push [hOutput]      
    call [WriteConsole]

    push 0
    push stub
    push [Max1]
    push szMax1
    push ptr hOutput
    call ptr WriteConsole

    push NULL
    push stub       
    push sizeof.newLine
    push newLine      
    push [hOutput]      
    call [WriteConsole]

    push 10
    push szMin1
    push [Min1]
    call ptr itoa
    add ESP, 3 * 4 

    push [Min1]
    call ptr lstrlen

    push NULL
    push stub       
    push sizeof.y4Mask
    push y4Mask      
    push [hOutput]      
    call [WriteConsole]

    push 0
    push stub
    push [Min1]
    push szMin1
    push ptr hOutput
    call ptr WriteConsole

    push NULL
    push stub       
    push sizeof.newLine
    push newLine      
    push [hOutput]      
    call [WriteConsole]

    push 10
    push szNumerator
    push [Numerator]
    call ptr itoa
    add ESP, 3 * 4 

    push [Numerator]
    call ptr lstrlen

    push NULL
    push stub       
    push sizeof.numeratorMask
    push numeratorMask      
    push [hOutput]      
    call [WriteConsole]

    push 0
    push stub
    push [Numerator]
    push szNumerator
    push ptr hOutput
    call ptr WriteConsole

    push NULL
    push stub       
    push sizeof.newLine
    push newLine      
    push [hOutput]      
    call [WriteConsole]

    push 10
    push szDenominator
    push [Denominator]
    call ptr itoa
    add ESP, 3 * 4 

    push [Denominator]
    call ptr lstrlen

    push NULL
    push stub       
    push sizeof.denominatorMask
    push denominatorMask      
    push [hOutput]      
    call [WriteConsole]

    push 0
    push stub
    push [Denominator]
    push szDenominator
    push ptr hOutput
    call ptr WriteConsole

    push NULL
    push stub       
    push sizeof.newLine
    push newLine      
    push [hOutput]      
    call [WriteConsole]

    push 10
    push szResult
    push [Result]
    call ptr itoa
    add ESP, 3 * 4 

    push [Result]
    call ptr lstrlen

    push NULL
    push stub       
    push sizeof.resultMask
    push resultMask      
    push [hOutput]      
    call [WriteConsole]

    push 0
    push stub
    push [Result]
    push szResult
    push ptr hOutput
    call ptr WriteConsole
    ; ---

ex:
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