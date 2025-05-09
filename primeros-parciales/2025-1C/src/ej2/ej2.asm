extern strcmp
global invocar_habilidad

; Completar las definiciones o borrarlas (en este ejercicio NO serán revisadas por el ABI enforcer)
DIRENTRY_NAME_OFFSET EQU 0
DIRENTRY_PTR_OFFSET EQU 16
DIRENTRY_SIZE EQU 24

FANTASTRUCO_DIR_OFFSET EQU 0
FANTASTRUCO_ENTRIES_OFFSET EQU 8
FANTASTRUCO_ARCHETYPE_OFFSET EQU 16
FANTASTRUCO_FACEUP_OFFSET EQU 24
FANTASTRUCO_SIZE EQU 32

section .rodata
; Acá se pueden poner todas las máscaras y datos que necesiten para el ejercicio

section .text

; void invocar_habilidad(void* carta, char* habilidad);
; RDI --> * carta
; RSI --> string habilidad
invocar_habilidad:

	;prologo
	push RBP
	mov RBP, RSP
	push R12
	push R13
	push R14
	push R15

	mov R12, RDI ; carta en R12
	mov R13, RSI ; name habilidad en R13
	

	xor R14, R14 ; R14 es nuestro contador
	xor R15, R15 ; R15 entries
	xor R8, R8 ; en r8 vamos tener la entry de cada ciclo
	xor R9, R9 ; aca vamos a tener el directorio
	mov R15W, WORD[R12 + FANTASTRUCO_ENTRIES_OFFSET]; cant entries en R15
	mov R9, QWORD[R12 + FANTASTRUCO_DIR_OFFSET] 
	while:
		cmp R14W, R15W
		je siguiente_arquetipo

		mov R8, QWORD[R9 + DIRENTRY_NAME_OFFSET] ; name [i]  
		mov RDI, R13
		mov RSI, R8
		push R9
		sub RSP, 8
		call strcmp
		add RSP, 8
		pop R9
		cmp RAX, 0
		je if_iguales


		; si no son iguales
		inc R14W
		add R9, 8 ; R9 es un arreglo de punteros, lo vamos moviendo
		jmp while
	
	if_iguales:

		mov RDI, R12 ; carta
		mov RCX, QWORD[R9] ; directorio
		mov RCX, QWORD[RCX + DIRENTRY_PTR_OFFSET] ; ability
		call RCX ; llama a la funcion, parametros son la carta 
		jmp fin


	siguiente_arquetipo:
	mov R8, QWORD[R12 + FANTASTRUCO_ARCHETYPE_OFFSET]
	cmp R8, 0
	jne recursion
	jmp fin

	recursion:
		mov RDI, R8
		mov RSI, R13
		call invocar_habilidad


	fin:
	pop R15
	pop R14
	pop R13
	pop R12
	pop RBP
	ret 
