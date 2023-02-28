.global enable_interrupt,randomInt


.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm

    .text
enable_interrupt:
    ei
    jr $ra
    nop

randomInt:

    addi $v0, $0, 30       
    syscall                 
    add $t0, $0, $a0     

    addi $v0, $0, 40       
    addi $a0, $0, 0  
    add $a1, $0, $t0    
    syscall

    addi $v0, $zero, 42        
    add $a0, $zero, $zero   
    addi $a1, $zero, 10000     
    syscall                  
    add $v0, $zero, $a0    

    
    jr $ra
    nop