; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.asm                                      :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/04/21 16:48:21 by julnolle          #+#    #+#              ;
;    Updated: 2020/04/22 12:18:33 by julnolle         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;
            
            section .text
            global ft_strcpy

ft_strcpy:
			xor		rax, rax
			xor		rcx, rcx
			jmp		compare
loop:
			mov 	cl, byte [rsi + rax]
			mov		byte [rdi + rax], cl
			inc		rax
compare:
			cmp		byte [rsi + rax], 0
			jne		loop	
			mov 	cl, byte [rsi + rax]
			mov		byte [rdi + rax], cl
			mov		rax, rdi
			ret
