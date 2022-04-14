format PE console NX
  
entry start

include 'WIN32A.INC'

section '.bss' data readable writeable 

hInput dd ?
hOutput dd ? 

stub dd ?
numberOfChars1 dd ? 
numberOfChars2 dd ? 
numberOfChars3 dd ?

section '.data' data readable writeable 
newLine db 13,10

firstStr db 256 dup (0x15)
secondStr db 256 dup (0x15)
thirdStr db 256 dup (0x15)


frame1 db 0xDA, 12 dup (0xC4), 0xBF, 13, 10, 0xB3, 12 dup (" "), \
0xB3, 13, 10, 0xB3, ' '
sizeof.frame1 = $ - frame1

frame2 db 0xDA, 0xC1, 11 dup (0xC4), 0xBF, 13, 10, 0xB3, 11 dup (" "), \
0xB3, 12 dup (" "), 0xB3, 13, 10, 0xC0, 11 dup (0xC4), 0xB4, ' '
sizeof.frame2 = $ - frame2

frame3 db ' ', 0xB3, 13, 10, 6 dup (" "), 0xC9, 5 dup (0xCD), 0xCF, \
6 dup (0xCD), 0xBB, 5 dup (" "), 0xB3, 13, 10, 6 dup (" "), 0xBA, 12 dup (" "), \
0xC7, 5 dup (0xC4), 0xD9, 13, 10, 6 dup (" "), 0xBA, ' '
sizeof.frame3 = $ - frame3

frame4 db ' ', 0xBA, 13, 10, 6 dup (" "), 0xBA, 12 dup (" "), 0xBA, 13, 10, \
6 dup (" "), 0xC8, 12 dup (0xCD), 0xBC, 13, 10
sizeof.frame4 = $ - frame4

section '.text' code readable executable 

start:

    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX

    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutput], EAX

    ; Ввод первой строки
    push NULL
    push numberOfChars1       
    push 1000
    push firstStr       
    push [hInput]   
    call [ReadConsole] 

    ; Ввод второй строки
    push NULL
    push numberOfChars2   
    push 1000   
    push secondStr       
    push [hInput]   
    call [ReadConsole] 

    ; Ввод третьей строки
    push NULL
    push numberOfChars3  
    push 1000   
    push thirdStr       
    push [hInput]   
    call [ReadConsole] 

    mov EBX, firstStr
    mov EAX, [numberOfChars1]
    mov byte [ EBX + EAX - 1 ], 0x15
    mov byte [ EBX + EAX - 2 ], 0x15

    mov EBX, secondStr
    mov EAX, [numberOfChars2]
    mov byte [ EBX + EAX - 1 ], 0x15
    mov byte [ EBX + EAX - 2 ], 0x15

    mov EBX, thirdStr
    mov EAX, [numberOfChars3]
    mov byte [ EBX + EAX - 1 ], 0x15
    mov byte [ EBX + EAX - 2 ], 0x15

    ; Вывод новой строки
    push NULL              
    push stub    
    push 2
    push newLine       
    push [hOutput]      
    call [WriteConsole]

    ; -----------
    push NULL
    push stub       
    push sizeof.frame1
    push frame1      
    push [hOutput]      
    call [WriteConsole]
    ; -----------

    ; Вывод первой строки
    push NULL              
    push stub    
    push 10
    push firstStr       
    push [hOutput]      
    call [WriteConsole]

    ; -----------
    push NULL
    push stub       
    push sizeof.frame2
    push frame2      
    push [hOutput]      
    call [WriteConsole]
    ; -----------

    ;Вывод второй строки
    push NULL              
    push stub    
    push 10
    push secondStr       
    push [hOutput]      
    call [WriteConsole] 

    ; -----------
    push NULL
    push stub       
    push sizeof.frame3
    push frame3      
    push [hOutput]      
    call [WriteConsole]
    ; -----------

    ; Вывод третьей строки
    push NULL              
    push stub    
    push 10
    push thirdStr       
    push [hOutput]      
    call [WriteConsole] 

    ; -----------
    push NULL
    push stub       
    push sizeof.frame4
    push frame4
    push [hOutput]      
    call [WriteConsole]
    ; -----------
    
    push 0              
    call [ExitProcess]  

section '.idata' import data readable writeable

library kernel32, 'KERNEL32.DLL'

import kernel32,\
    ExitProcess, 'ExitProcess',\    
    GetStdHandle, 'GetStdHandle',\
    WriteConsole, 'WriteConsoleA',\
    ReadConsole, 'ReadConsoleA' 

section '.reloc' fixups data readable discardable 
