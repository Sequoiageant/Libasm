; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_stdup.asm                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/04/22 16:19:39 by julnolle          #+#    #+#              ;
;    Updated: 2020/04/25 18:32:52 by julnolle         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
global  ft_strdup
extern  ft_strlen
extern  ft_strcpy
extern  malloc


ft_strdup:
			xor		rax, rax
			push	rdi			; save rdi (char *str)in order to use it later
			call	ft_strlen
			mov		rdi, rax	; the len of str is in rx, copy to rcx
			inc		rdi			; rdi + 1 to malloc len + 1
			call	malloc
			cmp		rax, 0		; if malloc failed, ret null
			je		return
			pop		rdi			; retrieve rdi (char *str)
			mov		rsi, rdi
			mov		rdi, rax
			call	ft_strcpy
return:
			ret
