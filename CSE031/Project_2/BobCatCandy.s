.data 
tagline: .asciiz "Welcome to BobCat Candy, home to the famous BobCat Bars!\n"
cond1:   .asciiz "Please enter the price of a BobCat Bar:\n"
cond2:	 .asciiz "Please enter the number of wrappers needed to exchange for a new bar:\n"
cond3:	 .asciiz "How much do you have?\n"
state1:	 .asciiz "Good! Let me run the number...\n"
first:	 .asciiz "You first buy "
bars:	 .asciiz " bars.\n"
then:	 .asciiz "Then, you will get another "
part1:	 .asciiz "With $"
part2:	 .asciiz ", you will receive a maximum of "
part3:   .asciiz " Bobcat Bars!"
.text

main:
	la	$a0, tagline
	li	$v0, 4
	syscall
	
	la	$a0, cond1	#$a1 = price
	syscall
	li	$v0, 5
	syscall
	move	$a1, $v0
	
	la	$a0, cond2	#$a2 = wrappers
	li	$v0, 4
	syscall
	li	$v0, 5
	syscall
	move	$a2, $v0
	
	la	$a0, cond3	#a3 = amount of money
	li	$v0, 4
	syscall	
	li	$v0, 5
	syscall
	move	$a3, $v0
	
	la	$a0, state1
	li	$v0, 4
	syscall
	
	addi	$sp, $sp -4	# Feel free to change the increment if you need for space.

	jal 	maxBars 	# Call maxBars to calculate the maximum number of BobCat Bars

				# Print out final statement here
	la	$a0, part1
	li	$v0, 4
	syscall
	add	$a0, $a3, $0
	li	$v0, 1
	syscall
	la	$a0, part2
	li	$v0, 4
	syscall
	add	$a0, $v1, $0
	li	$v0, 1
	syscall
	la	$a0, part3
	li	$v0, 4
	syscall
	
	j	end			# Jump to end of program



maxBars:
		# This function calculates the maximum number of BobCat Bars.
		# It takes in 3 arguments ($a2, $a1, $a3) as n, price, and money. It returns the maximum number of bars
	sw	$ra, 0($sp)
	div	$a3, $a1
	mflo	$t0		#$t0 = chocolates; initial total number of chocolates able to be bought, remainder should not matter.
	add	$v1, $t0, $0	#$v1 = total
	add	$t1, $t0, $0	#$t1 = wrappers
	
	beq	$t0, $0, return
	
	la	$a0, first
	syscall
	add	$a0, $v1, $0
	li	$v0, 1
	syscall
	la	$a0, bars
	li	$v0, 4
	syscall

	jal newBars 	# Call a helper function to keep track of the number of bars.
		
	lw	$ra, 0($sp)
		
	jr $ra
		# End of maxBars

newBars:
		# This function calculates the number of BobCat Bars a user will receive based on n.
		# It takes in 2 arguments ($a0, $a1) as number of bars so far and n.
	add	$sp, $sp, -4
	sw	$ra, 0($sp)
	div	$t1, $a2
	mflo	$t0
	
	blt	$t1, $a2, return
	
	la	$a0, then
	li	$v0, 4
	syscall
	add	$a0, $t0, $0
	li	$v0, 1
	syscall
	la	$a0, bars
	li	$v0, 4
	syscall
	
	add	$v1, $v1, $t0
	mul	$t2, $t0, $a2
	sub	$t2, $t1, $t2
	add	$t1, $t0, $t2
	
	jal	newBars

		# End of newBars
return:
	lw	$ra, 0($sp)
	add	$sp, $sp, 4
	jr	$ra

end: 
		# Terminating the program
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	li $v0, 10 
	syscall

#This is the main program.
#It first asks user to enter the price of each BobCat Bar.
#It then asks user to enter the number of bar wrappers needed to exchange for a new bar.
#It then asks user to enter how much money he/she has.
#It then calls maxBars function to perform calculation of the maximum BobCat Bars the user will receive based on the information entered. 
#It then prints out a statement about the maximum BobCat Bars the user will receive.
