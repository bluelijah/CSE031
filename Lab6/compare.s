.data 
    n: .word 25
    str1: .asciiz "Less than\n"
    str2: .asciiz "Less than or equal to\n"
    str3: .asciiz "Greater than\n"
    str4: .asciiz "Greater than or equal to\n"
    prompt: .asciiz "User Input: \n"
    
.text
.global main

main:
	
	lw $t0, n #store n in t0
	
	li $v0, 4 #system call for printing string
	la $a0, prompt #output prompt
	syscall
	
	li $v0, 5 #reading the user input
	syscall
	
	move $t1, $v0 #v0 acts as temp, so move to t0 for permanent storage
	
	blt $t1, $t0, less_than
	ble $t1, $t0, less_than_equal
	bgt $t1, $t0, greater_than
	#bge $t1, $t0, greater_than_equal
	
less_than: 
	li $v0, 4 
	la $a0, str1
	syscall
	j end
less_than_equal: 
	li $v0, 4 
	la $a0, str2
	syscall
	j end
greater_than: 
	li $v0, 4 
	la $a0, str3
	syscall
	j end
greater_than_equal: 
	li $v0, 4 
	la $a0, str4
	syscall
	j end
	
end: 
	li $v0, 10 #exit program
	syscall
	
