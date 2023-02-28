.global enable_interrupt,randomInt,time2string,hexasc


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


time2string:

	PUSH $s0
	PUSH $s1

	move 	$s0, $a0
	move 	$s1, $a1



	srl 	$a0, $s1, 12
	
	
	addi	$sp,$sp,-4
	sw	$ra,0($sp)
	addi	$sp,$sp,-4
	sw	$s0,0($sp)
	addi	$sp,$sp,-4
	sw	$s1,0($sp)

	jal hexasc
	nop
	
	lw	$s1,0($sp)
	addi	$sp,$sp,4
	lw	$s0,0($sp)
	addi	$sp,$sp,4
	lw	$ra,0($sp)
	addi	$sp,$sp,4
	
	sb 	$v0, 0($s0)
	
	#1m digits

	srl 	$a0, $s1, 8
	
	
	addi	$sp,$sp,-4
	sw	$ra,0($sp)
	addi	$sp,$sp,-4
	sw	$s0,0($sp)
	addi	$sp,$sp,-4
	sw	$s1,0($sp)
	
	jal hexasc
	nop
	
	lw	$s1,0($sp)
	addi	$sp,$sp,4
	lw	$s0,0($sp)
	addi	$sp,$sp,4
	lw	$ra,0($sp)
	addi	$sp,$sp,4
	
	sb 	$v0, 1($s0)
	
	addi 	$t0, $zero, 0x3a
	sb	$t0, 2($s0)

	# 10s digits
	
	
	srl 	$a0, $s1, 4
	
	
	addi	$sp,$sp,-4
	sw	$ra,0($sp)
	addi	$sp,$sp,-4
	sw	$s0,0($sp)
	addi	$sp,$sp,-4
	sw	$s1,0($sp)

	jal hexasc
	nop
	
	lw	$s1,0($sp)
	addi	$sp,$sp,4
	lw	$s0,0($sp)
	addi	$sp,$sp,4
	lw	$ra,0($sp)
	addi	$sp,$sp,4
	
	sb 	$v0, 3($s0)

	# 1s digits
	
	srl 	$a0, $s1, 0
	
	
	addi	$sp,$sp,-4
	sw	$ra,0($sp)
	addi	$sp,$sp,-4
	sw	$s0,0($sp)
	addi	$sp,$sp,-4
	sw	$s1,0($sp)
	
	jal hexasc
	nop
	
	lw	$s1,0($sp)
	addi	$sp,$sp,4
	lw	$s0,0($sp)
	addi	$sp,$sp,4
	lw	$ra,0($sp)
	addi	$sp,$sp,4
	
	sb 	$v0, 4($s0)
	
	addi 	$t0, $zero, 0x00
	sb	$t0, 5($s0)
	
	#jump back

	POP $s1
	POP $s0

	jr 	$ra
	nop


hexasc:
	move	$t0, $a0
	andi	$t0, $t0, 0xf
	ble 	$t0, 9, hexnumb
	nop
	addi 	$v0, $t0, 0x37
	jr	$ra
	nop	
	
hexnumb:
	addi	$v0, $t0, 0x30
	jr 	$ra
	nop