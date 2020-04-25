; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.asm                                      :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/04/17 11:44:37 by julnolle          #+#    #+#              ;
;    Updated: 2020/04/25 12:47:01 by julnolle         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
global ft_strlen

ft_strlen:
			xor rax, rax
			jmp compare
increment:
			inc rax
compare:
			cmp byte [rdi + rax], 0
			jne increment
			ret
