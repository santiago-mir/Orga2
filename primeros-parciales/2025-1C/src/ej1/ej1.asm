extern malloc
extern sleep
extern wakeup
extern create_dir_entry

section .rodata
; Acá se pueden poner todas las máscaras y datos que necesiten para el ejercicio
sleep_name: DB "sleep", 0
wakeup_name: DB "wakeup", 0

section .text
; Marca un ejercicio como aún no completado (esto hace que no corran sus tests)
FALSE EQU 0
; Marca un ejercicio como hecho
TRUE  EQU 1

; Marca el ejercicio 1A como hecho (`true`) o pendiente (`false`).
;
; Funciones a implementar:
;   - init_fantastruco_dir
global EJERCICIO_1A_HECHO
EJERCICIO_1A_HECHO: db TRUE ; Cambiar por `TRUE` para correr los tests.

; Marca el ejercicio 1B como hecho (`true`) o pendiente (`false`).
;
; Funciones a implementar:
;   - summon_fantastruco
global EJERCICIO_1B_HECHO
EJERCICIO_1B_HECHO: db TRUE ; Cambiar por `TRUE` para correr los tests.

;########### ESTOS SON LOS OFFSETS Y TAMAÑO DE LOS STRUCTS
; Completar las definiciones (serán revisadas por ABI enforcer):
DIRENTRY_NAME_OFFSET EQU 0
DIRENTRY_PTR_OFFSET EQU 16
DIRENTRY_SIZE EQU 24

FANTASTRUCO_DIR_OFFSET EQU 0
FANTASTRUCO_ENTRIES_OFFSET EQU 8
FANTASTRUCO_ARCHETYPE_OFFSET EQU 16
FANTASTRUCO_FACEUP_OFFSET EQU 24
FANTASTRUCO_SIZE EQU 32

; void init_fantastruco_dir(fantastruco_t* card);
global init_fantastruco_dir
; RDI --> puntero a la card
init_fantastruco_dir:
	; prologo
	push RBP
	mov RBP, RSP
	push R12 
	push R13 ; preservamos no volatiles que vamos a usar

	mov R12, RDI ; movemos la card a R12

	; quiero llamar a malloc, asi reservo 16 bytes de memoria
	; 8 (size del dir) * 2 (lugares q quiero)
	xor RDI, RDI ; limpiamos
	mov RDI, 16
	call malloc ; en RAX, el puntero al arreglo de punteros

	mov R13, RAX ; arr de punteros en R13

	; ahora queremos crear las entradas e ir metiendolas a R13

	; los parametros van a venir en RDI y RSI
	; son 2 punteros *char * void entonces ocupan todo

	mov RDI, sleep_name
	mov RSI, sleep
	call create_dir_entry ; entry en RAX

	mov QWORD[R13], RAX ; movemos la entry a la primera posicion
	add R13, 8 ; siguiente posicion

	mov RDI, wakeup_name
	mov RSI, wakeup
	call create_dir_entry ; entry en RAX

	mov QWORD[R13], RAX ; movemos la entry a la primera posicion

	sub R13, 8 ; apuntamos al 1er elem otra vez
	; ya tenemos las 2 entrys
	; ahora, asignamos el __dir y __dir_entries a mi card

	mov QWORD[R12 + FANTASTRUCO_DIR_OFFSET], R13 ; movemos el puntero del dir a la card
	mov WORD[R12 + FANTASTRUCO_ENTRIES_OFFSET], 2


	; epilogo
	pop R13
	pop R12
	pop RBP
	ret 

; fantastruco_t* summon_fantastruco();
global summon_fantastruco
summon_fantastruco:
	; prologo
	push RBP
	mov RBP, RSP

	push R12 ; preservo no volatil
	sub RSP, 8 ; alineo la pila
	xor RDI, RDI ; limpiamos RDI
	mov RDI, FANTASTRUCO_SIZE
	call malloc ; puntero a la nueva card en RAX

	mov R12, RAX ; puntero a la nueva card en R12

	mov RDI, R12 ; movemos la card a RDI para armar el directorio

	call init_fantastruco_dir ; se updatea la card en R12

	mov DWORD[R12 + FANTASTRUCO_FACEUP_OFFSET], 1
	mov QWORD[R12 + FANTASTRUCO_ARCHETYPE_OFFSET], 0 ; null
	
	mov RAX, R12
	add RSP, 8
	pop R12
	pop RBP
	ret 
