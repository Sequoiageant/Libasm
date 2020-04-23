; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_stdup.asm                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/04/22 16:19:39 by julnolle          #+#    #+#              ;
;    Updated: 2020/04/23 16:44:37 by julnolle         ###   ########.fr        ;
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
			call	malloc
			pop		rdi			; retrieve rdi (char *str)
			mov		rsi, rdi
			mov		rdi, rax
			call	ft_strcpy
			ret

