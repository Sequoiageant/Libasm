; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.asm                                      :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/04/22 12:29:39 by julnolle          #+#    #+#              ;
;    Updated: 2020/04/24 22:52:31 by julnolle         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
global ft_strcmp

ft_strcmp:
			xor		rax, rax
			xor		rcx, rcx
			jmp		compare

is_below:
			mov		rax, -1
			ret

is_above:
			mov		rax, 1
			ret

is_same:
			mov		rax, 0
			ret

increment:
			cmp		byte [rsi + rcx], 0
			je		is_same
			inc		rcx

compare:
			mov 	ah, byte [rdi + rcx]
			cmp		ah, byte [rsi + rcx]
			jb		is_below
			cmp		ah, byte [rsi + rcx]
			ja		is_above
			jmp		increment
