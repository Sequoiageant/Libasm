; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.asm                                      :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/04/21 16:48:21 by julnolle          #+#    #+#              ;
;    Updated: 2020/04/23 16:41:26 by julnolle         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;
            
            section .text
            global ft_strcpy

ft_strcpy:
			xor		rax, rax
			xor		rcx, rcx
			jmp		compare
loop:
			mov 	ah, byte [rsi + rcx]
			mov		byte [rdi + rcx], ah
			inc		rcx
compare:
			cmp		byte [rsi + rcx], 0
			jne		loop	
			mov 	ah, byte [rsi + rcx]
			mov		byte [rdi + rcx], ah
			mov		rax, rdi
			ret
