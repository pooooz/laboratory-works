format PE console NX

entry start

include 'WIN32A.INC'

section '.bss' data readable writeable 

hInput dd ?
hOutput dd ? 

stub dd ?
dwNumber dd ? 
buf db ? 

section '.data' data readable writeable 
message db 'Hello, world!',13,10
sizeof.message = $ - message
parentheses1 db '{'
parentheses2 db '}'

section '.text' code readable executable 

start:

    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX

    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutput], EAX

    push 0              
    push stub     
    push sizeof.message
    push message       
    push [hOutput]      
    call [WriteConsole] 

  
    push NULL
    push dwNumber       
    push 1000   
    push buf       
    push [hInput]   
    call [ReadConsole] 

    sub [dwNumber], 2

    push NULL              
    push stub    
    push 1
    push parentheses1       
    push [hOutput]      
    call [WriteConsole] 
    
    push NULL              
    push stub     
    push [dwNumber]
    push buf
    push [hOutput]      
    call [WriteConsole] 

    push NULL              
    push stub     
    push 1
    push parentheses2      
    push [hOutput]      
    call [WriteConsole] 

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
