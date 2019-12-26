// AArch32 boot section
.section ".text.boot"

.global _start
_start:
				// Halt co-processors
				mrc p15, #0, r1, c0, c0, #5
				and r1, r1, #3
				cmp r1, #0
				bne halt	

				// Setup stack register
				ldr sp, =_start
				
				// BSS initialization
				ldr r4, =__bss_start
				ldr r9, =__bss_end

				// ===== BEGIN CLEAR BSS =====
				ldr r4, =__bss_start
				ldr r9, =__bss_end
				mov r5, #0
				mov r6, #0
				mov r7, #0
				mov r8, #0
				b       2f
			 
			1:
				// store multiple at r4.
				stmia r4!, {r5-r8}
			 
				// If we are still below bss_end, loop.
			2:
				cmp r4, r9
				blo 1b
			 
				// ===== END CLEAR BSS =====

				// Initialize kernel and start main process
				ldr r3, =ker_init
				blx r3
			 
				// halt
			halt:
				wfe
				b halt
